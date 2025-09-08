from math import floor, log, ceil
import random
import os

# Configuration constants
FIRST_TESTCASE_NUM = 17   # Starting number for testcase files
NUM_TESTCASES = 0      # Number of testcase files to generate

MIN_N, MAX_N = 1, 100_000
MIN_Q, MAX_Q = 1, 100_000

MIN_T, MAX_T = 1, 100_000_000
MIN_V, MAX_V = 1, 100_000_000


# Create input directory if it doesn't exist
os.makedirs("input", exist_ok=True)

def generate_test_case(case_num):
    n = random.randint(MIN_N, MAX_N)
    q = random.randint(MIN_Q, MAX_Q)

    arr = [random.randint(MIN_T, MAX_T) for _ in range(n)]

    queries = []
    for _ in range(q):
        # v must be a power of 2 and less than MAX_V
        # p must be less or equal to v
        ex = random.randint(ceil(log(MIN_V, 2)), floor(log(MAX_V, 2)))
        v = 2 ** ex
        assert MIN_V <= v <= MAX_V, f"v out of bounds: {v}"
        p = random.randint(1, v)

        queries.append((v, p))

    # Create the input file
    with open(f"input/input{case_num}.txt", "w") as f:
        f.write(f"{n} {q}\n")
        for value in arr:
            f.write(f"{value} ")
        f.write("\n")
        for v, p in queries:
            f.write(f"{v} {p}\n")


    print(f"Created test case {case_num}: n = {n}, q = {q}, max_t = {max(arr)}, queries[0] = {queries[0]}")

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