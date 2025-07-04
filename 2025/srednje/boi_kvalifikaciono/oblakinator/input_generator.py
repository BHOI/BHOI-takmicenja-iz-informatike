import random
import os

# Configuration constants
FIRST_TESTCASE_NUM = 46   # Starting number for testcase files
NUM_TESTCASES = 0      # Number of testcase files to generate

MIN_N, MAX_N = 1, 2_000
MIN_P, MAX_P = 1, 100
MIN_Q, MAX_Q = 1, 100

WIDTH = 1_000_000_000

# Create input directory if it doesn't exist
os.makedirs("input", exist_ok=True)

def generate_test_case(case_num):
    n = random.randint(MIN_N, MAX_N)
    p = random.randint(MIN_P, MAX_P)
    q = random.randint(MIN_Q, MAX_Q)

    a = [random.randint(1, WIDTH) for _ in range(n)]

    # Create the input file
    with open(f"input/input{case_num}.txt", "w") as f:
        f.write(f"{n} {p} {q}\n")
        for value in a:
            f.write(f"{value}\n")

    print(f"Created test case {case_num}: n = {n}, p = {p}, q = {q}, a = {a[:10]}... (total {len(a)} values)")

# Generate the test cases
for i in range(FIRST_TESTCASE_NUM, FIRST_TESTCASE_NUM + NUM_TESTCASES):
    generate_test_case(i)

print(f"Successfully created {NUM_TESTCASES} test cases in the 'input' folder.")

# Change NUM_TESTCASES to 0 in the source code to avoid generating more test cases
with open("input_generator.py", "r") as f:
    content = f.read()
    content = content.replace(f"NUM_TESTCASES = {NUM_TESTCASES}", "NUM_TESTCASES = 0")
with open("input_generator.py", "w") as f:
    f.write(content)