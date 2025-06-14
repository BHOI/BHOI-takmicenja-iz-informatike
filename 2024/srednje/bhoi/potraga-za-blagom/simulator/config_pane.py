import tkinter as tk
from tkinter import ttk
from island_config import IslandConfig, presets, from_line
import random

from utils import is_auto_play

def parseInt(v: str):
    try:
        return int(v)
    except ValueError:
        return 0

class ConfigPane:
    def __init__(self, parent):
        self.config_pane = tk.Frame(parent, width=300, bg="lightgray")
        self.config_pane.pack(side=tk.RIGHT, fill=tk.Y)
        self.config_pane.pack_propagate(False)  # Prevent the config pane from resizing

        self.config_change_callback = None
        self.used_test = None
        self.setup_configuration_pane()

    def set_config_change_callback(self, callback):
        self.config_change_callback = callback

    def notify_config_change(self):
        if self.config_change_callback:
            self.config_change_callback()

    def setup_configuration_pane(self):
        config_frame = tk.Frame(self.config_pane, bg="lightgray")
        config_frame.pack(fill=tk.BOTH, expand=True)

        # Field configuration
        tk.Label(config_frame, text="Veličina otoka", bg="lightgray").pack(pady=5)
        self.width_entry = self.create_numeric_entry(config_frame, "Širina (S)", 1, 100)
        self.height_entry = self.create_numeric_entry(config_frame, "Visina (V)", 1, 100)

        tk.Label(config_frame, text="Odakle počinjete na otoku", bg="lightgray").pack(pady=5)
        self.start_x_entry = self.create_numeric_entry(config_frame, "X0", 0, 100)
        self.start_y_entry = self.create_numeric_entry(config_frame, "Y0", 0, 100)

        tk.Label(config_frame, text="Lokacija blaga", bg="lightgray").pack(pady=5)
        self.target_x_entry = self.create_numeric_entry(config_frame, "Cilj X", 0, 100)
        self.target_y_entry = self.create_numeric_entry(config_frame, "Cilj Y", 0, 100)

        tk.Label(config_frame, text="Broj mogućih komandi 'idi'", bg="lightgray").pack(pady=5)
        self.retries_entry = self.create_numeric_entry(config_frame, "N", 0, 10000)

        tk.Label(config_frame, text="Vaš program neće znati lokaciju blaga, već će ovaj simulator da šalje vašem programu očitanje radara na osnovu unesenih parametara ovdje", wraplength=250, bg="lightgray").pack(pady=10, padx=10)

        tk.Label(config_frame, text="Učitajte primjer kliknom na dugme ispod, ili uredite sami parametre modifikujuci brojeve iznad.", wraplength=250, bg="lightgray").pack(pady=5)
        tk.Label(config_frame, text="Pogledajte kako napraviti svoje primjere u tekstu zadatka, sekcija 'modifikovanje testnih primjera'", wraplength=250, bg="lightgray").pack(pady=5)

        # Preset Buttons
        preset_frame = tk.Frame(config_frame, bg="lightgray")
        preset_frame.pack(side=tk.BOTTOM, fill=tk.X, pady=5)

        # Arrange preset buttons in a grid with a maximum of 4 buttons per row
        self.preset_buttons = []
        if not is_auto_play:
            max_buttons_per_row = 4
            for i in range(len(presets)):
                row = i // max_buttons_per_row
                col = i % max_buttons_per_row
                btn = tk.Button(preset_frame, text=f"Primjer {i + 1}", command=lambda i=i: self.load_preset(i))
                btn.grid(row=row, column=col, padx=2, pady=2, sticky='ew')
                self.preset_buttons.append(btn)
        else:
            presets.clear()
            num = random.randint(0, 99)
            f = open("../input/input%d.txt" % num)
            preset = from_line(f.read())
            presets.append(preset)
            self.used_test = "Subtask %d, Testcase %d" % ((num / 10) + 1, (num % 10) + 1)
        
        self.load_preset(0)
    
    def set_enabled(self, enabled):
        for btn in self.preset_buttons:
            btn.config(state=tk.NORMAL if enabled else tk.DISABLED)
        self.width_entry.config(state=tk.NORMAL if enabled else tk.DISABLED)
        self.height_entry.config(state=tk.NORMAL if enabled else tk.DISABLED)
        self.start_x_entry.config(state=tk.NORMAL if enabled else tk.DISABLED)
        self.start_y_entry.config(state=tk.NORMAL if enabled else tk.DISABLED)
        self.target_x_entry.config(state=tk.NORMAL if enabled else tk.DISABLED)
        self.target_y_entry.config(state=tk.NORMAL if enabled else tk.DISABLED)
        self.retries_entry.config(state=tk.NORMAL if enabled else tk.DISABLED)

    def create_numeric_entry(self, parent, label_text, min_value, max_value):
        frame = tk.Frame(parent, bg="lightgray")
        frame.pack(pady=5, padx=10, fill=tk.X)

        tk.Label(frame, text=label_text, width=10, anchor='w', bg="lightgray").pack(side=tk.LEFT)
        entry = ttk.Spinbox(frame, from_=min_value, to=max_value, width=5)
        entry.pack(side=tk.RIGHT, fill=tk.X, expand=True)

        def notify_after_update(event):
            self.config_pane.after(100, self.notify_config_change)

        entry.bind("<<Increment>>", notify_after_update)
        entry.bind("<<Decrement>>", notify_after_update)
        entry.bind("<KeyPress>", notify_after_update)
        return entry

    def load_preset(self, preset_index):
        preset = presets[preset_index]
        self.width_entry.set(preset.W)
        self.height_entry.set(preset.H)
        self.start_x_entry.set(preset.X0)
        self.start_y_entry.set(preset.Y0)
        self.target_x_entry.set(preset.XS)
        self.target_y_entry.set(preset.YS)
        self.retries_entry.set(preset.N)
        self.notify_config_change()

    def get_island_config(self):
        W = parseInt(self.width_entry.get())
        H = parseInt(self.height_entry.get())
        X0 = parseInt(self.start_x_entry.get())
        Y0 = parseInt(self.start_y_entry.get())
        XS = parseInt(self.target_x_entry.get())
        YS = parseInt(self.target_y_entry.get())
        N = parseInt(self.retries_entry.get())
        return IslandConfig(W, H, X0, Y0, XS, YS, N)
