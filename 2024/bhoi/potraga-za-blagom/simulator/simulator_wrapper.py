import subprocess
from read_line_with_timeout import read_line_with_timeout
from os import path, getcwd, system, chdir
from mingw_finder import found_compiler

class SimulatorWrapper:
    def __init__(self, config, program_path):
        self.config = config
        self.program_path = program_path
        self.X = config.X0
        self.Y = config.Y0
        self.N = config.N
        self.process = None
        self.initialized = False
        self.start_simulation()
    
    def get_exe_path(self):
        fname, ext = path.splitext(path.basename(self.program_path))
        if ext == '.exe':
            return self.program_path
        else:
            if found_compiler is None:
                raise RuntimeError("Kompajler nije pronađen ... .cpp fajlovi nisu podržani na ovom računaru.")
            my_folder = getcwd()
            output_path = path.join(my_folder, fname + ".exe")
            print("Kompajliranje fajla ...")
            
            # command = [
            #     found_compiler, "-std=gnu++17", "-O2", "-pipe", "-static", "-s", "-o",
            #     output_path, path.abspath(self.program_path)
            # ]
            # command = [
            #     "cmd.exe", "/c", "start", "cmd.exe", "/k",
            #     f'"{found_compiler}" -std=gnu++17 -O2 -pipe -static -s -o "{output_path}" "{path.abspath(self.program_path)}"'
            # ]
            # print(" ".join(command))
            f = open("tmp-compile.bat", "w")
            # f.write(f'cd "{path.dirname(found_compiler)}"\n')
            f.write(f'"{found_compiler}" -std=gnu++17 -O2 -pipe -static -s -o "{output_path}" "{path.abspath(self.program_path)}"')
            f.close()
            # print("From", path.dirname(found_compiler))
            # proc = subprocess.run(command)
            # if proc.returncode != 0:
            returncode = system('.\\tmp-compile.bat')
            if returncode != 0:
                raise RuntimeError("Kompajliranje nije uspjelo. Provjerite konzolu za greške i ispravite ih.")
            if not path.exists(output_path):
                raise RuntimeError(".exe fajl nije pronađen nakon kompajliranja. Možda ga je obrisao anti-virus?")
            return output_path

    def start_simulation(self):
        self.stop_simulation()
        if not path.exists(self.program_path):
            raise FileNotFoundError("Fajl ne postoji: " + self.program_path)

        print("#############################################")
        self.process = subprocess.Popen(
            [self.get_exe_path()],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            text=True
        )
    
    def get_dir(self):
        XS = self.config.XS
        YS = self.config.YS
        direction = ""
        if self.Y < YS:
            direction += "J"
        elif self.Y > YS:
            direction += "S"
        if self.X < XS:
            direction += "I"
        elif self.X > XS:
            direction += "Z"
        return direction if direction else "*"

    def next_step(self):
        print("---------------------------------------------")
        if not self.initialized:
            # Prepare initialization input
            init_input = f"{self.config.W} {self.config.H} {self.X} {self.Y} {self.get_dir()} {self.N}"
            self.send_line(init_input)
            self.initialized = True
        else:
            direction = self.get_dir()
            self.send_line(direction)

        command, X, Y = self.wait_for_response()
        if command == "idi":
            if self.N <= 0:
                raise RuntimeError("Program je pokušao koristiti komandu 'idi' a svi su se pokušaji istrošili")
            self.X = X
            self.Y = Y
            self.N -= 1
        elif command == "odgovor":
            if X != self.config.XS or Y != self.config.YS:
                raise RuntimeError("Program nije dao tačan odgovor :( " + str(X) + " " + str(Y))
            else:
                return "Bravo! Program je pronašao blago u " + str(self.config.N - self.N) + " pokušaja!"

    def wait_for_response(self):
        response_line = read_line_with_timeout(self.process)
        print("Simulator <- Vaš program:", response_line)

        if response_line.strip() == "":
            print("  (prazna linija. Ignoriše se)")
            return self.wait_for_response()

        parts = response_line.split()
        if len(parts) != 3 or parts[0] not in ["idi", "odgovor"]:
            raise ValueError(f"Neispravan format odgovora: {response_line}. Ukoliko želite dodati neki vaš ispis (zbog debugiranja i sl) pogledajte sekciju 'Debugiranje' u tekstu zadatka.")
        
        command, X, Y = parts[0], parts[1], parts[2]
        
        try:
            X, Y = int(X), int(Y)
        except ValueError:
            raise ValueError(f"Neispravan format koordinata: {response_line}")
        
        if X < 0 or X >= self.config.W or Y < 0 or Y >= self.config.H:
            raise ValueError(f"Koordinate van granica: {response_line}")
        
        return command, X, Y

    def send_line(self, line):
        self.process.stdin.write(line)
        self.process.stdin.write("\n")
        self.process.stdin.flush()
        print("Simulator -> Vaš program:", line)

    def stop_simulation(self):
        if self.process:
            self.process.terminate()
            self.process = None
            print("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx")
