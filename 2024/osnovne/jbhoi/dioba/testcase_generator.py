# Ok je napraviti normalan slucaj, N do 20, K do 10, S do 10, gdje posljednji S se stave iz suprotnih timova


import random

NUMBER_OF_TEST_CASES = 1
FIRST_TEST_CASE_NUMBER = 19
MIN_R, MAX_R = 100, 100
MIN_N, MAX_N = 5, 3*10**3
MIN_K, MAX_K = 1, 10**3
# MIN_K, MAX_K = 0, 0
MIN_S, MAX_S = 1, 5*10**2
# MIN_S, MAX_S = 0, 0
MAX_SUM_K_S = 10**5
MAX_SUM_N = 10**6

# Function to generate test cases
def generate_test_case(test_case_number=FIRST_TEST_CASE_NUMBER):
    R = random.randint(MIN_R, MAX_R)
    sum_K_S = 0
    sum_N = 0
    true_R = None
    in_file = ""
    out_file = ""

    for current_R in range(R):
        N = random.randint(MIN_N, MAX_N)
        K = random.randint(MIN_K, MAX_K)
        S = random.randint(MIN_S, MAX_S)
        print(f"Generating test case {test_case_number} - {current_R}/R - N: {N}, K: {K}, S: {S}")
        sum_K_S += K + S
        if sum_K_S > MAX_SUM_K_S:
            true_R = current_R
            break
        sum_N += N
        if sum_N > MAX_SUM_N:
            true_R = current_R
            break

        if K > 0 and S > 0:
            assert N > 1
            in_file += str(N) + " " + str(K) + " " + str(S) + "\n"
            for _ in range(K+S):
                i = random.randint(1, N)
                j = random.randint(1, N)
                while i == j:
                    j = random.randint(1, N)
                in_file += str(i) + " " + str(j) + "\n"
            continue

        answer = "DA"
        out_file += answer + "\n"

        # Generate two teams
        # Make K pairs with players in the same team
        # Make S pairs with players in opposite teams

        # List of length N with random values
        team = [random.randint(0, 1) for _ in range(N)]
        while 0 not in team or 1 not in team:
            team = [random.randint(0, 1) for _ in range(N)]
        team0 = [i for i in range(N) if team[i] == 0]
        team1 = [i for i in range(N) if team[i] == 1]

        in_file += str(1000000) + " " + str(K) + " " + str(S) + "\n"

        # Make K pairs with players in the same team
        for _ in range(K-1):
            print(f"Generating K pairs {test_case_number} - {_}/{K}")
            # Choose team 0 or 1
            t = random.randint(0, 1)
            if t == 0 and len(team0) > 1:
                i = random.choice(team0)
                j = random.choice(team0)
                while i == j:
                    j = random.choice(team0)
                in_file += str(i+1) + " " + str(j+1) + "\n"
            elif len(team1) > 1:
                i = random.choice(team1)
                j = random.choice(team1)
                while i == j:
                    j = random.choice(team1)
                in_file += str(i+1) + " " + str(j+1) + "\n"
            elif len(team0) > 1:
                i = random.choice(team0)
                j = random.choice(team0)
                while i == j:
                    j = random.choice(team0)
                in_file += str(i+1) + " " + str(j+1) + "\n"
            else:
                assert False
        
        # DELETE THIS
        # if S == 0:
        i = random.choice(team0)
        j = random.choice(team1)
        in_file += str(i+1) + " " + str(j+1) + "\n"
            # continue

        add_conflicting_pair = random.choice([True, False])
        
        # Make S pairs with players in opposite teams
        for _ in range(S-int(add_conflicting_pair)):
            i = random.choice(team0)
            j = random.choice(team1)
            in_file += str(i+1) + " " + str(j+1) + "\n"

        # Potentially add conflicting pair
        if add_conflicting_pair:
            if len(team0) > 1:
                i = random.choice(team0)
                j = random.choice(team0)
                while i == j:
                    j = random.choice(team0)
                in_file += str(i+1) + " " + str(j+1) + "\n"
            else:
                i = random.choice(team1)
                j = random.choice(team1)
                while i == j:
                    j = random.choice(team1)
                in_file += str(i+1) + " " + str(j+1) + "\n"

    if true_R is None:
        true_R = R
    return str(true_R) + "\n" + in_file, out_file

# Generate test cases
for i in range(FIRST_TEST_CASE_NUMBER, FIRST_TEST_CASE_NUMBER + NUMBER_OF_TEST_CASES):
    in_file, out_file = generate_test_case(i)
    with open(f'input/input{i}.txt', 'w') as f:
        f.write(in_file)
    # with open(f'veliki_probable_output{i}.txt', 'w') as f:
    #     f.write(out_file)