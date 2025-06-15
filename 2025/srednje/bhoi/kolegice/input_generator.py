import random
import os


# Configuration constants
FIRST_TESTCASE_NUM = 0  # Starting number for testcase files
NUM_TESTCASES = 0  # Number of testcase files to generate

MIN_N, MAX_N = 2, 1000
MIN_M, MAX_M = 1, 1000
MIN_E, MAX_E = 1, round(1e15)

ALWAYS_BORROW_FROM_HANA = False

# Create input directory if it doesn't exist
os.makedirs("input", exist_ok=True)


def generate_test_case(case_num):
    n = random.randint(MIN_N, MAX_N)
    m = random.randint(MIN_M, MAX_M)

    actions = []
    for _ in range(m):
        a = random.randint(0, n-1)
        b = random.randint(0, n-1)
        while a == b:
            b = random.randint(0, n-1)

        if ALWAYS_BORROW_FROM_HANA:
            a = random.randint(1, n-1)
            b = 0
        
        e = random.randint(MIN_E, MAX_E)
        actions.append(f"{a} {b} {e}")

    # Write to file
    with open(f"input/input{case_num}.txt", "w") as f:
        f.write(f"{n} {m}\n")
        f.write("\n".join(actions) + "\n")

    print(f"Created test case {case_num}: n = {n}, m = {m}, max_d = {MAX_E}")

# Generate the test cases
for i in range(FIRST_TESTCASE_NUM, FIRST_TESTCASE_NUM + NUM_TESTCASES):
    generate_test_case(i)

print(f"Successfully created {NUM_TESTCASES} test cases in the 'input' folder.")
