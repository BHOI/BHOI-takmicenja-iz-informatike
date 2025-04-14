import tkinter as tk
from file_selector_window import FileSelectorWindow
from main_window import MainWindow
import sys
import mingw_finder

root = tk.Tk()

if len(sys.argv) >= 2:
    MainWindow(root, sys.argv[1])
else:
    FileSelectorWindow(root)

root.mainloop()
