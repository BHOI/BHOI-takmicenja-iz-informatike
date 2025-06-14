import random
import os

# Configuration constants
NUM_TESTCASES = 10       # Number of testcase files to generate
FIRST_TESTCASE_NUM = 50   # Starting number for testcase files
MIN_N = round(1)                # Minimum array length
MAX_N = round(1e5)               # Maximum array length
MIN_K = round(0)         # Minimum element value
MAX_K = round(1e6)          # Maximum element value
MIN_M = round(1)         # Minimum value for M 
MAX_M = round(7e10)        # Maximum value for M

SUM_LIMITED_TO_MILLION = False  # If True, the sum of the array will be limited to 1 million

# Create input directory if it doesn't exist
os.makedirs("input", exist_ok=True)

def generate_test_case(case_num):
    # Determine array size
    n = random.randint(MIN_N, MAX_N)
    m = random.randint(MIN_M, MAX_M)
    
    # Generate random array of integers
    arr = [random.randint(MIN_K, MAX_K) for _ in range(n)]

    if SUM_LIMITED_TO_MILLION:
        # Limit the sum of the array to 1 million
        total_sum = sum(arr)
        num_reductions = 0
        new_max_k = MAX_K
        while total_sum > 1_000_000:
            new_max_k = round(new_max_k * 0.7)  # Reduce the maximum value by 10%
            arr = [random.randint(MIN_K, new_max_k) for _ in range(n)]
            total_sum = sum(arr)
            num_reductions += 1
        print(f"Reduced sum of array to {total_sum} after {num_reductions} adjustments.")

    if sum(arr) < m:
        print(f"Warning: Sum of array elements {sum(arr)} is less than m = {m}. Adjusting m.")
        m = sum(arr)
    
    # Create the input file
    with open(f"input/input{case_num}.txt", "w") as f:
        f.write(f"{n} {m}\n")
        f.write(' '.join(map(str, arr)))
    
    print(f"Created test case {case_num}: n = {n}, m = {m}, min = {min(arr)}, max = {max(arr)}")

# Generate the test cases
for i in range(FIRST_TESTCASE_NUM, FIRST_TESTCASE_NUM + NUM_TESTCASES):
    generate_test_case(i)

print(f"Successfully created {NUM_TESTCASES} test cases in the 'input' folder.")
