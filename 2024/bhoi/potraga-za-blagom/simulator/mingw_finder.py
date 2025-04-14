from os import path, remove, environ, listdir, getcwd
import shutil
import requests
import zipfile
from progressbar import progressbar

found_compiler = None

def download_file(url, local_filename):
  # Stream the download to prevent loading the entire file into memory
  with requests.get(url, stream=True) as r:
    r.raise_for_status()
    with open(local_filename, 'wb') as f:
      for chunk in r.iter_content(chunk_size=8192):
        f.write(chunk)
  return local_filename

def extract_mingw_from_zip(zip_path, extract_to):
  with zipfile.ZipFile(zip_path, 'r') as zip_ref:
    # List all contents of the zip file
    all_files = zip_ref.namelist()
    # Filter out files that are in the MinGW folder
    mingw_files = [f for f in all_files if f.startswith('MinGW/')]
    # Extract only the MinGW files
    for file in progressbar(mingw_files):
      zip_ref.extract(file, extract_to)

def copy_dll_files(source_folder):
  current_directory = getcwd()
  
  # List all files in the source folder
  files = listdir(source_folder)
  
  # Filter out the .dll files
  dll_files = [f for f in files if f.endswith('.dll')]
  
  # Copy each .dll file to the current directory
  for dll_file in progressbar(dll_files):
    full_file_path = path.join(source_folder, dll_file)
    if path.isfile(full_file_path):
      shutil.copy(full_file_path, current_directory)

def download_mingw():
  url = "https://altushost-swe.dl.sourceforge.net/project/codeblocks/Binaries/20.03/Windows/codeblocks-20.03mingw-nosetup.zip"
  zip_filename = "codeblocks-20.03mingw-nosetup.zip"
  
  # Download the file
  print("Preuzimanje kompajlera...")
  download_file(url, zip_filename)
  
  # Extract MinGW folder
  print("Ekstraktovanje ...")
  extract_mingw_from_zip(zip_filename, ".")

  remove(zip_filename)

def check_gpp(folder_path):
  gpp_path = path.join(folder_path, 'g++')
  if path.isfile(gpp_path) or path.isfile(gpp_path + '.exe'):
    return gpp_path

def find_gpp():
  paths_to_check = [
    # MSYS, MSYS2, and Cygwin
    path.join('C:\\', 'msys', 'bin'),
    path.join('C:\\', 'msys2', 'MinGW64', 'bin'),
    path.join('C:\\', 'msys2', 'MinGW32', 'bin'),
    path.join('C:\\', 'msys2', 'usr', 'bin'),
    path.join('C:\\', 'msys64', 'MinGW64', 'bin'),
    path.join('C:\\', 'msys64', 'MinGW32', 'bin'),
    path.join('C:\\', 'msys64', 'usr', 'bin'),
    path.join('C:\\', 'cygwin', 'bin'),
    path.join('C:\\', 'cygwin64', 'bin'),

    # Code::Blocks admin and non-admin installations
    path.join(environ.get('PROGRAMFILES', 'C:\\Program Files'), 'CodeBlocks\\MinGW\\bin'),
    path.join(environ.get('PROGRAMFILES(X86)', 'C:\\Program Files (x86)'), 'CodeBlocks\\MinGW\\bin'),
    path.join(environ.get('APPDATA', 'C:\\Users\\%USERNAME%\\AppData\\Roaming'), 'CodeBlocks\\MinGW\\bin'),
    
    # Dev-C++ installations
    #path.join(environ.get('PROGRAMFILES', 'C:\\Program Files'), 'Dev-Cpp\\MinGW64\\bin'),
    #path.join(environ.get('PROGRAMFILES(X86)', 'C:\\Program Files (x86)'), 'Dev-Cpp\\MinGW64\\bin'),
    #path.join(environ.get('PROGRAMFILES', 'C:\\Program Files'), 'Dev-Cpp\\MinGW\\bin'),
    #path.join(environ.get('PROGRAMFILES(X86)', 'C:\\Program Files (x86)'), 'Dev-Cpp\\MinGW\\bin'),
    #path.join(environ.get('PROGRAMFILES', 'C:\\Program Files'), 'Dev-Cpp\\MinGW32\\bin'),
    #path.join(environ.get('PROGRAMFILES(X86)', 'C:\\Program Files (x86)'), 'Dev-Cpp\\MinGW32\\bin'),
    
    # g++ on unix
    path.join('/', 'usr', 'bin'),

    # Local MINGW
    path.join('MinGW', 'bin'),
  ]
  
  found = None
  for test_path in paths_to_check:
    test = check_gpp(test_path)
    if test:
      print(f'g++ kompajler pronađen: {test}')

      found = test
  

  if not found:
    resp = input("Kompajler nije pronađen na računaru. Želite li ga preuzeti? Ovo će omogućiti da proslijedite .cpp fajl u simulator. Cijeli proces je automatski. Zauzeće dodatno nekih 100MB prostora. Ukucajte D za 'DA', a bilo šta drugo za 'NE'. Preporučujemo da odaberete DA samo ako ste na Windowsu: ")
    if resp.lower() in ['d', 'da', 'y', 'yes']:
      download_mingw()
      found = path.join("MinGW", "bin", "g++")

  if found:
    print("Odabrani kompajler:", found)
    # copy_dll_files(path.dirname(found))
  else:
    print("Kompajler nije pronađen na ovom računaru ... simulator nastavlja bez podrške za .cpp fajlove")
  return found

found_compiler = find_gpp()