import random
import os

# Configuration constants
NUM_TESTCASES = 18       # Number of testcase files to generate
FIRST_TESTCASE_NUM = 7   # Starting number for testcase files
MIN_N, MAX_N = 5, 9
MIN_H, MAX_H = 1, 100
MIN_W, MAX_W = 1, 100

# Create input directory if it doesn't exist
os.makedirs("input", exist_ok=True)

def generate_test_case(case_num):
    h = random.randint(MIN_H, MAX_H)
    w = random.randint(MIN_W, MAX_W)

    n = random.randint(MIN_N, MAX_N)
    if n % 2 == 0:
        n += 1  # Ensure n is odd

    # Matrix full of * and .
    mat = [['*' if random.random() < 0.5 else '.' for _ in range(w)] for _ in range(h)]

    # Replace a random spot with 'B'
    b_row = random.randint(0, h - 1)
    b_col = random.randint(0, w - 1)
    mat[b_row][b_col] = 'B'
    
    # Create the input file
    with open(f"input/input{case_num}.txt", "w") as f:
        f.write(f"{h} {w} {n}\n")
        for row in mat:
            f.write(''.join(row) + '\n')
    
    print(f"Created test case {case_num}: n = {n}, h = {h}, w = {w}, B at ({b_row}, {b_col})")

# Generate the test cases
for i in range(FIRST_TESTCASE_NUM, FIRST_TESTCASE_NUM + NUM_TESTCASES):
    generate_test_case(i)

print(f"Successfully created {NUM_TESTCASES} test cases in the 'input' folder.")
