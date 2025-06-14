import os
import os.path
import random

files = os.listdir('autorun-fajlovi')
all_files = []

for file in files:
    full_path = os.path.join('autorun-fajlovi', file)
    all_files.append(full_path)

while True:
    program_to_run = random.choice(all_files)
    os.system('python main.py "' + program_to_run + '" --auto-play')