import random
import os

# Configuration constants
NUM_TESTCASES = 20       # Number of testcase files to generate
FIRST_TESTCASE_NUM = 0   # Starting number for testcase files
MIN_N, MAX_N = 2, 20

# Create input directory if it doesn't exist
os.makedirs("input", exist_ok=True)

def generate_test_case(case_num):
    n = random.randint(MIN_N, MAX_N)  # Random size of the matrix

    # Random string of length n, any characters from 'a' to 'z' or 'A' to 'Z'
    row_chars = [random.choice('abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ') for _ in range(n)]
    word = ''.join(row_chars)

    # first letter has a 50% change of being changed to r, R, d, or R
    if random.random() < 0.5:
        word = random.choice(['r', 'R', 'd', 'D']) + word[1:]  
    
    # Create the input file
    with open(f"input/input{case_num}.txt", "w") as f:
        f.write(f"{n}\n")
        f.write(f"{word}\n")
    
    print(f"Created test case {case_num}: n = {n})")

# Generate the test cases
for i in range(FIRST_TESTCASE_NUM, FIRST_TESTCASE_NUM + NUM_TESTCASES):
    generate_test_case(i)

print(f"Successfully created {NUM_TESTCASES} test cases in the 'input' folder.")
