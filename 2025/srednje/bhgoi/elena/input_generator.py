import random
import os

# Create list of names and ratings. Rating are rounded to 2 decimal places. Names and ratings are unique.

# Configuration constants
FIRST_TESTCASE_NUM = 0   # Starting number for testcase files
NUM_TESTCASES = 0       # Number of testcase files to generate
MIN_R, MAX_R = 1, 100
MIN_K, MAX_K = 1, 100
MIN_N, MAX_N = 0, 1000
BLOCK_MOVEMENT_PROBABILITY = 0.5
BLOCK_SQUARE_PROBABILITY = 0.8


# Create input directory if it doesn't exist
os.makedirs("input", exist_ok=True)

def generate_test_case(case_num):
    r = random.randint(MIN_R, MAX_R)
    k = random.randint(MIN_K, MAX_K)
    n = random.randint(MIN_N, MAX_N)
    
    king_movement_text = "***\n*K*\n***\n"
    king_movement = list(king_movement_text)
    
    for i in range(len(king_movement)):
        if king_movement[i] == "*" and BLOCK_MOVEMENT_PROBABILITY > random.random():
            king_movement[i] = "."

    king_movement = ''.join(king_movement)

    # Make matrix of size r x k filled with .
    matrix = [["." for _ in range(k)] for _ in range(r)]
    # Randomly change . for * with BLOCK_SQUARE_PROBABILITY
    for i in range(r):
        for j in range(k):
            if BLOCK_SQUARE_PROBABILITY > random.random():
                matrix[i][j] = "*"
    
    # Randomly change one field to "C"
    matrix[random.randint(0, r-1)][random.randint(0, k-1)] = "C"

    # Write to file
    with open(f"input/input{case_num}.txt", "w") as f:
        f.write(f"{r} {k} {n}\n")
        f.write(king_movement)
        for row in matrix:
            f.write(''.join(row) + "\n")
    
    print(f"Test case {case_num} generated with r={r}, k={k}, n={n}, probs = {BLOCK_MOVEMENT_PROBABILITY}, {BLOCK_SQUARE_PROBABILITY}.")


# Generate the test cases
for i in range(FIRST_TESTCASE_NUM, FIRST_TESTCASE_NUM + NUM_TESTCASES):
    generate_test_case(i)

print(f"Successfully created {NUM_TESTCASES} test cases in the 'input' folder.")
