import random

NUMBER_OF_TEST_CASES = 10
FIRST_TEST_CASE_NUMBER = 0
NUMBER_OF_DECIMALS = 0
MAX_N = 1
MAX_M = 10**5

# Function to generate a random float with 3 decimal places
def random_float(start, end):
    if NUMBER_OF_DECIMALS == 0:
        return random.randint(start, end)
    return round(random.uniform(start, end), NUMBER_OF_DECIMALS)

# Function to generate test cases
def generate_test_cases(num_cases):
    for i in range(FIRST_TEST_CASE_NUMBER, FIRST_TEST_CASE_NUMBER + num_cases):
        N = random.randint(1, MAX_N)  # Number of movies
        X = [random_float(0, 10) for _ in range(N)]  # Movie ratings
        M = random.randint(1, MAX_M)  # Number of queries
        queries = [(random_float(0, 10), random_float(0, 10)) for _ in range(M)]  # Queries

        # Write the test cases to a file
        with open(f'input{i}.txt', 'w') as f:
            f.write(str(N) + '\n')
            f.write(' '.join(map(str, X)) + '\n')
            f.write(str(M) + '\n')
            for query in queries:
                f.write(' '.join(map(str, query)) + '\n')

# Generate 10 test cases
generate_test_cases(NUMBER_OF_TEST_CASES)
