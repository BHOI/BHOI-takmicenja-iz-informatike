MAX_WH = 100
MAX_N = 10000

class IslandConfig:
    def __init__(self, W, H, X0, Y0, XS, YS, N):
        self.W = W  # Width of the island
        self.H = H  # Height of the island
        self.X0 = X0  # Starting X coordinate
        self.Y0 = Y0  # Starting Y coordinate
        self.XS = XS  # Treasure X coordinate
        self.YS = YS  # Treasure Y coordinate
        self.N = N  # Number of retries

    def raise_if_config_is_invalid(self):
        if not (1 <= self.W <= MAX_WH):
            raise ValueError("Širina otoka (S) mora biti između 1 i 100.")
        if not (1 <= self.H <= MAX_WH):
            raise ValueError("Visina otoka (V) mora biti između 1 i 100.")
        if not (0 <= self.X0 < self.W):
            raise ValueError("Početna X koordinata (X0) mora biti između 0 i širine otoka - 1.")
        if not (0 <= self.Y0 < self.H):
            raise ValueError("Početna Y koordinata (Y0) mora biti između 0 i visine otoka - 1.")
        if not (0 <= self.XS < self.W):
            raise ValueError("X koordinata blaga mora biti između 0 i širine otoka - 1.")
        if not (0 <= self.YS < self.H):
            raise ValueError("Y koordinata blaga mora biti između 0 i visine otoka - 1.")
        if not (0 <= self.N <= MAX_N):
            raise ValueError("Broj mogućih komandi 'idi' (N) mora biti između 0 i 10000.")

def from_line(line: str):
    W, H, X0, Y0, XS, YS, N = line.split()
    return IslandConfig(int(W), int(H), int(X0), int(Y0), int(XS), int(YS), int(N))

presets = []

try:
    f = open("primjeri.txt")
    for line in f:
        line = line.strip()
        if line != "":
            try:
                presets.append(from_line(line))
            except ValueError:
                print("UPOZORENJE: Greska pri citanju linije za primjere:", line)
                print("Provjerite da li je pravilnog formata. Format je: S V X0 Y0 XS YS N")
                print("Pri tom XS i YS su rjesenje za ovaj primjer")
    print("Uspjesno ucitano:", len(presets), "primjera iz primjeri.txt")
except FileNotFoundError:
    print("UPOZORENJE: Simulator nije mogao otvoriti primjeri.txt fajl.")

if len(presets) == 0:
    presets.append(IslandConfig(5, 6, 1, 2, 1, 4, 15))
