import random
import os

# Configuration constants
NUM_TESTCASES = 3       # Number of testcase files to generate
FIRST_TESTCASE_NUM = 22   # Starting number for testcase files
MIN_N = round(5e4)                # Minimum array length
MAX_N = round(1e5)               # Maximum array length
MIN_VALUE = round(-1e9)         # Minimum element value
MAX_VALUE = round(1e9)          # Maximum element value
UNIQUE_ELEMENTS = False   # Flag to ensure all array elements are different

# Create input directory if it doesn't exist
os.makedirs("input", exist_ok=True)

def generate_test_case(case_num):
    # Determine array size
    n = random.randint(MIN_N, MAX_N)
    
    # Generate array elements
    if UNIQUE_ELEMENTS:
        # If we need unique elements and the range is too small, adjust n
        possible_values = MAX_VALUE - MIN_VALUE + 1
        if n > possible_values:
            raise ValueError(f"Cannot generate {n} unique elements in the range [{MIN_VALUE}, {MAX_VALUE}]")
            
        # Generate unique random numbers
        arr = random.sample(range(MIN_VALUE, MAX_VALUE + 1), n)
    else:
        # Generate random numbers (may contain duplicates)
        arr = [random.randint(MIN_VALUE, MAX_VALUE) for _ in range(n)]
    
    # Create the input file
    with open(f"input/input{case_num}.txt", "w") as f:
        f.write(f"{n}\n")
        f.write(' '.join(map(str, arr)))
    
    print(f"Created test case {case_num}: n = {n}, min = {min(arr)}, max = {max(arr)}")

# Generate the test cases
for i in range(FIRST_TESTCASE_NUM, FIRST_TESTCASE_NUM + NUM_TESTCASES):
    generate_test_case(i)

print(f"Successfully created {NUM_TESTCASES} test cases in the 'input' folder.")
