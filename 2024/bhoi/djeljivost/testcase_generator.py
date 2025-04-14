import random
import numpy as np

NUMBER_OF_TEST_CASES = 6
FIRST_TEST_CASE_NUMBER = 19
MIN_N, MAX_N = 50, 100


def random_int_up_to_1_000_000_000():
    randomNumberOfDigits = random.randint(1, 9)
    randomNumber = random.randint(10**(randomNumberOfDigits - 1), 10**randomNumberOfDigits - 1)
    return randomNumber

# Function to generate test cases
def generate_test_case():
    in_file = ""
    out_file = ""
    N = random.randint(MIN_N, MAX_N)
    in_file = str(N)
    for _ in range(N):
        # ok = False
        B = random.randint(2, 16)
        # X = 0
        # X_in_base_B = ""
        # while not ok:
        X = random_int_up_to_1_000_000_000()
        X_in_base_B = np.base_repr(X, B)
        #     # If sum of digits in base B is less than B then ok = True
        #     if sum([int(x, B) for x in str(X_in_base_B)]) < B:
        #         ok = True
        in_file += f"\n{B} {X_in_base_B}"
        if (X % (B-1)) == 0:
            out_file += "DA\n"
        else:
            out_file += "NE\n"
    return in_file, out_file

# Generate test cases
for i in range(FIRST_TEST_CASE_NUMBER, FIRST_TEST_CASE_NUMBER + NUMBER_OF_TEST_CASES):
    in_file, out_file = generate_test_case()
    with open(f'input/input{i}.txt', 'w') as f:
        f.write(in_file)
    # with open(f'probable_output{i}.txt', 'w') as f:
    #     f.write(out_file)