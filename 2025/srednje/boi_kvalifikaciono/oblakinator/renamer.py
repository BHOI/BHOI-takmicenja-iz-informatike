import os

# Rename files by changing the prefix
DIR = "input"
OLD_PREFIX = "02-1"
NEW_PREFIX = "input4"

def rename_files_in_directory(directory, old_prefix, new_prefix):
    for filename in os.listdir(directory):
        if filename.startswith(old_prefix):
            new_filename = filename.replace(old_prefix, new_prefix, 1)
            old_file_path = os.path.join(directory, filename)
            new_file_path = os.path.join(directory, new_filename)
            os.rename(old_file_path, new_file_path)
            print(f"Renamed '{filename}' to '{new_filename}'")

if __name__ == "__main__":
    rename_files_in_directory(DIR, OLD_PREFIX, NEW_PREFIX)
    print("Renaming completed.")