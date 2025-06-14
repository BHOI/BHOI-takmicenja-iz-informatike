import random
import os

# Configuration constants
FIRST_TESTCASE_NUM = 18   # Starting number for testcase files
NUM_TESTCASES = 7       # Number of testcase files to generate
MIN_N = 1               # Minimum array length
MAX_N = 10_000              # Maximum array length
MIN_ABC = 1
MAX_ABC = 1_000_000
NO_DELETIONS = False   # Flag to ensure there will be no deletion actions
LAST_ACTION_SHOW = False
B_ALWAYS_MAX = False  # Flag to ensure the last action is always a show

# Create input directory if it doesn't exist
os.makedirs("input", exist_ok=True)

def generate_test_case(case_num):
    # Determine array size
    n = random.randint(MIN_N, MAX_N)
    total_sushi_pieces = 0

    actions = []

    while len(actions) < n:
        if len(actions) == n-1 and LAST_ACTION_SHOW:
            # If the first action was a show, the second action must be a show
            actions.append([0])
            break

        can_delete = total_sushi_pieces >= MIN_ABC and not NO_DELETIONS
        # Generate a random number action (0 for show, 1 for add, 2 for delete)
        if can_delete:
            action = random.randint(0, 2)
        else:
            action = random.randint(0, 1)
        
        if action == 0:  # Show action
            actions.append([0])
        elif action == 1:  # Add action
            # Generate a random number of sushi pieces to add
            a = random.randint(MIN_ABC, MAX_ABC)
            b = MAX_ABC if B_ALWAYS_MAX else random.randint(MIN_ABC, MAX_ABC)
            actions.append([1, a, b])
            total_sushi_pieces += a
        elif action == 2:  # Delete action
            # Generate a random number of sushi pieces to delete
            c = random.randint(MIN_ABC, min([MAX_ABC, total_sushi_pieces]))
            actions.append([2, c])
            total_sushi_pieces -= c
    
    # Write the test case to a file
    with open(f"input/input{case_num}.txt", "w") as f:
        f.write(f"{n}\n")
        for action in actions:
            f.write(" ".join(map(str, action)) + "\n")
    
    print(f"Test case {case_num} generated with {n} actions.")


# Generate the test cases
for i in range(FIRST_TESTCASE_NUM, FIRST_TESTCASE_NUM + NUM_TESTCASES):
    generate_test_case(i)

print(f"Successfully created {NUM_TESTCASES} test cases in the 'input' folder.")
