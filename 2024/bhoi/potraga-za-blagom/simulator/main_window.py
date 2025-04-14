import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
from config_pane import ConfigPane
from simulator_wrapper import SimulatorWrapper
from utils import is_auto_play

FLATUI_RED = "#e74c3c"
FLATUI_LIGHT_RED = "#ff6f61"
FLATUI_YELLOW = "#f1c40f"
FLATUI_LIGHT_YELLOW = "#f7e282"

class MainWindow:
    def __init__(self, root, file_path):
        self.root = root
        self.file_path = file_path
        self.is_running = False
        self.simulation = None
        self.root.title("Simulator za zadatak 'Potraga za blagom'")
        self.root.geometry("900x800")  # Initial size
        self.root.minsize(750, 700)    # Minimum size

        self.disable_field_draw = False

        if is_auto_play:
            self.root.state('zoomed')
            self.root.after(1000, self.toggle_simulation)

        # Bind the ESC key to close the window
        self.root.bind('<Escape>', self.close_window)
        self.root.bind('<Configure>', self.on_resize)

        # Setup main layout
        self.setup_layout()

    def close_window(self, event=None):
        self.root.destroy()

    def setup_layout(self):
        # Create main frames
        self.button_toolbox = tk.Frame(self.root)
        self.main_screen = tk.Frame(self.root)
        self.status_bar = tk.Frame(self.root)

        self.button_toolbox.pack(side=tk.TOP, fill=tk.X)
        self.main_screen.pack(side=tk.TOP, fill=tk.BOTH, expand=True)
        self.status_bar.pack(side=tk.BOTTOM, fill=tk.X)

        # Button Toolbox
        self.play_button = tk.Button(self.button_toolbox, command=self.toggle_simulation)
        self.next_step_button = tk.Button(self.button_toolbox, text="⏭️ Sljedeći korak", command=self.next_step)
        self.stop_button = tk.Button(self.button_toolbox, text=" program", command=self.next_step)
        self.progress = ttk.Progressbar(self.button_toolbox, orient="horizontal", length=300, mode="determinate")
        self.remaining_retries_text = tk.Label(self.button_toolbox, text="")
        self.play_button.pack(side=tk.LEFT, padx=10, pady=5)
        self.next_step_button.pack(side=tk.LEFT, padx=10, pady=5)
        self.progress.pack(side=tk.LEFT, padx=10, pady=5)
        self.remaining_retries_text.pack(side=tk.LEFT, padx=10, pady=5)

        # Main Screen Layout
        self.play_field = tk.Canvas(self.main_screen, bg="white")
        self.config_pane = ConfigPane(self.main_screen)
        self.config_pane.set_config_change_callback(self.draw_field)

        self.play_field.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        # Status Bar
        self.status_label_file_path = tk.Label(self.status_bar, text=self.file_path)
        self.status_label_variable = tk.Label(self.status_bar, text="Status: Ready")

        self.status_label_file_path.pack(side=tk.LEFT, padx=10)
        self.status_label_variable.pack(side=tk.RIGHT, padx=10)

        self.update_button_states()

    def update_progress(self):
        if self.is_running and self.simulation:
            self.progress["maximum"] = self.simulation.config.N
            self.progress["value"] = self.simulation.N
        else:
            config = self.config_pane.get_island_config()
            self.progress["maximum"] = config.N
            self.progress["value"] = config.N
        self.remaining_retries_text.config(
            text="Preostalo pokušaja (N): " + str(self.progress["value"]) + "/" + str(self.progress["maximum"]))

    def update_button_states(self):
        if self.is_running:
            self.play_button.config(text="🛑 Zaustavi")
            self.next_step_button.config(state=tk.NORMAL)
            self.status_label_variable.config(text="Status: Program je pokrenut")
        else:
            self.play_button.config(text="▶️ Pokreni")
            self.next_step_button.config(state=tk.DISABLED)
            self.status_label_variable.config(text="Status: Spremno za pokretanje")
        self.config_pane.set_enabled(not self.is_running)

    def toggle_simulation(self):
        if self.is_running:
            self.stop_simulation()
        else:
            try:
                if self.simulation:
                    self.simulation.stop_simulation()
                config = self.config_pane.get_island_config()
                config.raise_if_config_is_invalid()
                self.simulation = SimulatorWrapper(config, self.file_path)
                self.is_running = True
                self.update_button_states()
                self.draw_field()
                
                if is_auto_play:
                    self.root.after(1000, self.next_step)
            except Exception as e:
                self.handle_exception(e)

    def next_step(self):
        try:
            if self.simulation:
                ret_msg = self.simulation.next_step()
                self.draw_field()
                if ret_msg:
                    self.simulation.stop_simulation()
                    self.is_running = False
                    self.update_button_states()
                    self.display_message(ret_msg, False)
                elif is_auto_play:
                    self.root.after(1000, self.next_step)
        except Exception as e:
            self.handle_exception(e)

    def on_resize(self, event):
        self.draw_field()

    def draw_field(self):
        if self.disable_field_draw:
            return
        self.play_field.delete("all")
        config = self.config_pane.get_island_config()
        if config.W > 0 and config.H > 0:
            self.draw_grid()
            self.draw_treasure()
            self.draw_player()
        self.update_progress()
        if self.config_pane.used_test:
            y = self.play_field.winfo_height() - 50
            self.play_field.create_text(
                300, y, text=self.config_pane.used_test, font=("Purisa", 20)
            )
        if is_auto_play:
            y = self.play_field.winfo_height() - 100
            self.play_field.create_text(
                300, y, text=self.file_path, font=("Purisa", 20)
            )

    def draw_grid(self):
        width = self.play_field.winfo_width()
        height = self.play_field.winfo_height()
        config = self.config_pane.get_island_config()

        # Calculate the size of each cell
        cell_width = width / config.W
        cell_height = height / config.H

        # Draw vertical lines
        for i in range(config.W + 1):
            x = i * cell_width
            self.play_field.create_line(x, 0, x, height, fill="gray")

        # Draw horizontal lines
        for i in range(config.H + 1):
            y = i * cell_height
            self.play_field.create_line(0, y, width, y, fill="gray")
    
    def draw_player(self):
        config = self.config_pane.get_island_config()
        if self.is_running:
            x = self.simulation.X
            y = self.simulation.Y
            color = FLATUI_RED
        else:
            x = config.X0
            y = config.Y0
            color = FLATUI_LIGHT_RED

        width = self.play_field.winfo_width()
        height = self.play_field.winfo_height()
        cell_width = width / config.W
        cell_height = height / config.H

        # Calculate the center of the circle
        center_x = (x + 0.5) * cell_width
        center_y = (y + 0.5) * cell_height
        radius = min(cell_width, cell_height) / 4

        # Draw the circle
        self.play_field.create_oval(
            center_x - radius, center_y - radius,
            center_x + radius, center_y + radius,
            fill=color, outline=color
        )

    def draw_treasure(self):
        if self.is_running:
            config = self.simulation.config
            color = FLATUI_YELLOW
        else:
            config = self.config_pane.get_island_config()
            color = FLATUI_LIGHT_YELLOW

        xs = config.XS
        ys = config.YS

        width = self.play_field.winfo_width()
        height = self.play_field.winfo_height()
        cell_width = width / config.W
        cell_height = height / config.H

        # Calculate the position of the rectangle
        top_left_x = xs * cell_width
        top_left_y = ys * cell_height
        bottom_right_x = (xs + 1) * cell_width
        bottom_right_y = (ys + 1) * cell_height

        # Draw the rectangle
        self.play_field.create_rectangle(
            top_left_x, top_left_y,
            bottom_right_x, bottom_right_y,
            fill=color, outline=color
        )
    
    def stop_simulation(self):
        if self.simulation:
            self.simulation.stop_simulation()
        self.is_running = False
        self.update_button_states()

    def handle_exception(self, ex):
        self.stop_simulation()
        self.display_message(ex, True)
    
    def display_message(self, text, is_error):
        if not is_auto_play:
            if is_error:
                messagebox.showerror("Greška", str(text))
            else:
                messagebox.showinfo("Info", str(text))
        else:
            color = "#AA3333" if is_error else "#33AA33"
            self.play_field.create_text(400, 50, text=text, font=("Purisa", 20), fill=color)
            self.disable_field_draw = True
            self.root.after(2000, self.close_window)

if __name__ == "__main__":
    root = tk.Tk()
    app = MainWindow(root, "path/to/file.exe")
    root.mainloop()
