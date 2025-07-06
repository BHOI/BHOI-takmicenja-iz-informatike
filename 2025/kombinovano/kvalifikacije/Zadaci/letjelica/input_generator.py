import os

filename = "testcases.txt"

if not os.path.exists(filename):
    # Logarithmically spaced points

    NUM_POINTS = 50
    MIN_VALUE = 1
    MAX_VALUE = 1000

    # Generate logarithmically spaced points
    log_points = [int(MIN_VALUE * (MAX_VALUE / MIN_VALUE) ** (i / (NUM_POINTS - 1))) for i in range(NUM_POINTS)]
    print("Logarithmically spaced points:")
    for point in log_points:
        print(point)
    
    with open(filename, "w") as f:
        for point in log_points:
            f.write(f"{point}\n")
    print(f"Logarithmically spaced points written to {filename}.")
else:
    # If the file already exists, create the input files
    # input0.txt, input1.txt, ...
    folder_name = "input"
    os.makedirs(folder_name, exist_ok=True)

    with open(filename, "r") as f:
        lines = f.readlines()
        for i, line in enumerate(lines):
            with open(f"{folder_name}/input{i}.txt", "w") as input_file:
                input_file.write(line)

    print(f"Input files created in the '{folder_name}' folder.")
