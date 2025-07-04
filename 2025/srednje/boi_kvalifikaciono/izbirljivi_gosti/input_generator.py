import random
import os

# Configuration constants
FIRST_TESTCASE_NUM = 19   # Starting number for testcase files
NUM_TESTCASES = 0      # Number of testcase files to generate

MIN_N, MAX_N = 1, 300_000
MIN_M, MAX_M = 1, 300_000

ALL_A_ONES = False

# Create input directory if it doesn't exist
os.makedirs("input", exist_ok=True)

def generate_test_case(case_num):
    n = random.randint(MIN_N, MAX_N)
    m = random.randint(MIN_M, MAX_M)

    if ALL_A_ONES:
        a = [1] * n
    else:
        a = [random.randint(1, m) for _ in range(n)]
    
    b = [random.randint(1, m) for _ in range(n)]

    # Make sure a[i] and b[i] are not equal
    for i in range(n):
        while a[i] == b[i]:
            b[i] = random.randint(1, m)

    # Create the input file
    with open(f"input/input{case_num}.txt", "w") as f:
        f.write(f"{n} {m}\n")
        for x, y in zip(a, b):
            f.write(f"{x} {y}\n")

    print(f"Created test case {case_num}: n = {n}, m = {m}, a_min = {min(a)}, a_max = {max(a)}, b_min = {min(b)}, b_max = {max(b)}")

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