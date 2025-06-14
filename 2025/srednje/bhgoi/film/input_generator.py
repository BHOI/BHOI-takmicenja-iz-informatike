import random
import os

# Create list of names and ratings. Rating are rounded to 2 decimal places. Names and ratings are unique.

# Configuration constants
FIRST_TESTCASE_NUM = 29   # Starting number for testcase files
NUM_TESTCASES = 1       # Number of testcase files to generate
MIN_N = 1               # Minimum array length
MAX_N = 30            # Maximum array length
MIN_RATING = 0         # Minimum element value
MAX_RATING = 3          # Maximum element value
MIN_NAME_LENGTH = 1    # Minimum name length
MAX_NAME_LENGTH = 30   # Maximum name length
ALWAYS_DISPLAY_2_DECIMALS = False   # Whether to always display 2 decimal places
FIRST_SCORE_IS_HIGHEST = False  # Whether the first score is the highest
GUARANTEE_PERFECT_SCORE = False  # Whether to guarantee there's a perfect score

# Create input directory if it doesn't exist
os.makedirs("input", exist_ok=True)

def generate_test_case(case_num):
    # Determine array size
    n = random.randint(MIN_N, MAX_N)
    
    # Generate unique names from a-z and A-Z
    names = []

    while len(names) < n:
        name_length = random.randint(MIN_NAME_LENGTH, MAX_NAME_LENGTH)
        name = ''.join(random.choices('abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ', k=name_length))
        if name not in names:
            names.append(name)
    
    # Generate unique ratings
    ratings = []
    if GUARANTEE_PERFECT_SCORE:
        ratings.append(round(MAX_RATING, 2))
    while len(ratings) < n:
        rating = round(random.uniform(MIN_RATING, MAX_RATING), 2)
        if rating not in ratings:
            ratings.append(rating)
    
    # Randomly shuffle ratings
    random.shuffle(ratings)
    if FIRST_SCORE_IS_HIGHEST:
        # swap the first element with the maximum rating
        max_rating_index = ratings.index(max(ratings))
        ratings[0], ratings[max_rating_index] = ratings[max_rating_index], ratings[0]

    # Write to file
    with open(f"input/input{case_num}.txt", "w") as f:
        f.write(f"{n}\n")
        for i in range(n):
            if ALWAYS_DISPLAY_2_DECIMALS:
                f.write(f"{names[i]} {ratings[i]:.2f}\n")
            else:
                # If the rating is an integer, don't display decimal places
                if ratings[i] == int(ratings[i]):
                    f.write(f"{names[i]} {int(ratings[i])}\n")
                else:
                    f.write(f"{names[i]} {ratings[i]}\n")

    print(f"Created test case {case_num}: n = {n}, min_rating = {min(ratings)}, max_rating = {max(ratings)}")


# Generate the test cases
for i in range(FIRST_TESTCASE_NUM, FIRST_TESTCASE_NUM + NUM_TESTCASES):
    generate_test_case(i)

print(f"Successfully created {NUM_TESTCASES} test cases in the 'input' folder.")
