import random

NUMBER_OF_TEST_CASES = 5
FIRST_TEST_CASE_NUMBER = 20
MIN_N, MAX_N = 1, 10**14


def random_int_up_to_1_000_000_000():
    randomNumberOfDigits = random.randint(1, 9)
    randomNumber = random.randint(10**(randomNumberOfDigits - 1), 10**randomNumberOfDigits - 1)
    return randomNumber

# Function to generate test cases
def generate_test_case():
    in_file = ""
    N = random.randint(MIN_N, MAX_N)
    in_file = str(N)
    return in_file

# Generate test cases
for i in range(FIRST_TEST_CASE_NUMBER, FIRST_TEST_CASE_NUMBER + NUMBER_OF_TEST_CASES):
    in_file = generate_test_case()
    with open(f'input/input{i}.txt', 'w') as f:
        f.write(in_file)