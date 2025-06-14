import random
import numpy as np

NUMBER_OF_TEST_CASES = 10
FIRST_TEST_CASE_NUMBER = 30
MIN_N, MAX_N = 2, 10**5

# Function to generate test cases
def generate_test_case():
    in_file = ""
    N = random.randint(MIN_N, MAX_N)
    in_file += str(N) + '\n'
    array = np.random.randint(-10**18, 10**18, N)
    # Find the max sum of 2 adjecent elements, increase one of them by 1
    # max_sum = -100
    # max_index = 0
    # for i in range(N-1):
    #     if array[i] + array[i+1] > max_sum:
    #         max_sum = array[i] + array[i+1]
    #         max_index = i
    # array[max_index] += 1
    for i in range(N):
        in_file += str(array[i]) + ' '
    return in_file

# Generate test cases
for i in range(FIRST_TEST_CASE_NUMBER, FIRST_TEST_CASE_NUMBER + NUMBER_OF_TEST_CASES):
    in_file = generate_test_case()
    with open(f'input/input{i}.txt', 'w') as f:
        f.write(in_file)