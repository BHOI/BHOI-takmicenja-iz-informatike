import tkinter as tk
from tkinter import filedialog, messagebox
from main_window import MainWindow

class FileSelectorWindow:
    def __init__(self, root):
        self.root = root
        self.root.title("Izaberi fajl za zadatak \"Potraga za Blagom\"")
        self.root.geometry("400x50")
        self.root.resizable(False, False)

        # Bind the ESC key to close the window
        self.root.bind('<Escape>', self.close_window)

        # Frame for buttons
        button_frame = tk.Frame(self.root)
        button_frame.pack(fill=tk.BOTH, expand=True)

        # .exe file button
        exe_button = tk.Button(button_frame, text="Izaberi .exe fajl", command=self.select_exe_file)
        exe_button.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        # .cpp file button
        cpp_button = tk.Button(button_frame, text="Izaberi .cpp fajl", command=self.select_cpp_file)
        cpp_button.pack(side=tk.RIGHT, fill=tk.BOTH, expand=True)

    def select_exe_file(self):
        file_path = filedialog.askopenfilename(filetypes=[("Exe fajlovi", "*.exe")])
        if file_path:
            self.open_main_window(file_path)

    def select_cpp_file(self):
        file_path = filedialog.askopenfilename(filetypes=[("C++ fajlovi", "*.cpp")])
        if file_path:
            self.open_main_window(file_path)

    def close_window(self, event=None):
        self.root.destroy()

    def open_main_window(self, file_path):
        self.root.destroy()  # Close the current window
        new_root = tk.Tk()
        MainWindow(new_root, file_path)
        new_root.mainloop()