import random
import os

# Configuration constants
NUM_TESTCASES = 1       # Number of testcase files to generate
FIRST_TESTCASE_NUM = 9   # Starting number for testcase files
MIN_N, MAX_N = 2, 10_000
MIN_XY, MAX_XY = 1, 1000
MIN_Q, MAX_Q = 1, 10_000
MIN_L, MAX_L = 1, 1000
MIN_H, MAX_H = 1, 1000


# Create input directory if it doesn't exist
os.makedirs("input", exist_ok=True)

def generate_test_case(case_num):
    n = random.randint(MIN_N, MAX_N)

    # n random distinct 2d points
    points = set()
    while len(points) < n:
        x = random.randint(MIN_XY, MAX_XY)
        y = random.randint(MIN_XY, MAX_XY)
        points.add((x, y))
    points = list(points)

    q = random.randint(MIN_Q, MAX_Q)
    lo = random.randint(MIN_L, MAX_L)
    hi = random.randint(MIN_H, MAX_H)
    if hi < lo:
        hi, lo = lo, hi
    
    a = [random.randint(0, n-1) for _ in range(q)]
    b = [random.randint(0, n-1) for _ in range(q)]

    # Create the input file
    with open(f"input/input{case_num}.txt", "w") as f:
        f.write(f"{n}\n")
        for x, y in points:
            f.write(f"{x} {y}\n")
        f.write(f"{q} {lo} {hi}\n")
        for i in range(q):
            f.write(f"{a[i]} {b[i]}\n")
    
    print(f"Created test case {case_num}: n = {n}, q = {q}, l = {lo}, h = {hi}")

# Generate the test cases
for i in range(FIRST_TESTCASE_NUM, FIRST_TESTCASE_NUM + NUM_TESTCASES):
    generate_test_case(i)

print(f"Successfully created {NUM_TESTCASES} test cases in the 'input' folder.")
