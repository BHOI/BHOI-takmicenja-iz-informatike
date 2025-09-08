import random
import os

# Configuration constants
FIRST_TESTCASE_NUM = 25   # Starting number for testcase files
NUM_TESTCASES = 0     # Number of testcase files to generate

MIN_N, MAX_N = 2, 1_000_000
LINEAR, ALTERNATING = False, False
# Both can't be true
assert not (LINEAR and ALTERNATING)

# Create input directory if it doesn't exist
os.makedirs("input", exist_ok=True)

def generate_test_case(case_num):
    n = random.randint(MIN_N, MAX_N)
    if n % 2 == 1:
        n -= 1  # Ensure n is even
    a = random.randint(0, n)
    b = random.randint(0, n)
    while a == b:
        b = random.randint(0, n)
    
    if LINEAR:
        # UUU...DDD
        s = "U" * (n // 2) + "D" * (n - n // 2)
    elif ALTERNATING:
        # UDUD...UD
        s = "".join("U" if i % 2 == 0 else "D" for i in range(n))
    else:
        s = ""
        u_num, d_num = 0, 0
        while len(s) < n:
            if u_num == d_num:
                s += "U"
                u_num += 1
            if u_num == n // 2:
                s += "D"
                d_num += 1
            else:
                s += random.choice("UD")

    # Create the input file
    with open(f"input/input{case_num}.txt", "w") as f:
        f.write(f"{a} {b}\n")
        f.write(s + "\n")

    print(f"Created test case {case_num}: n = {n}, a = {a}, b = {b}, s = {s[:10]}... (total {len(s)} characters)")

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