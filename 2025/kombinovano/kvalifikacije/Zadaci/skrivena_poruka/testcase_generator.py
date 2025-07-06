import random
import os

directory = "input/"

testcase_start = 30
num_testcases = 5  # Change this to generate more or fewer test cases

# N words of random letters
N_min = 1
N_max = 500

# M letters in each word
M_min = 1
M_max = 7

all_words_capital = False
no_words_capital = False

def generate_random_word(length):
    """Generate a random word of specified length."""
    letters = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
    word = ''.join(random.choice(letters) for _ in range(length))
    
    if all_words_capital:
        word = word[0].upper() + word[1:]
    elif no_words_capital:
        word = word[0].lower() + word[1:]
    
    return word

def generate_testcase(test_number):
    """Generate a single test case with N random words."""
    N = random.randint(N_min, N_max)
    word_lengths = [random.randint(M_min, M_max) for _ in range(N)]
    words = [generate_random_word(length) for length in word_lengths]
    
    first_row = str(N)
    # Join words with spaces
    second_row = ' '.join(words)
    
    return first_row, second_row

def save_testcase(test_number, content: tuple):
    """Save test case to a file."""
    if not os.path.exists(directory):
        os.makedirs(directory)
    
    filename = f"{directory}input{test_number}.txt"
    with open(filename, 'w') as f:
        f.write('\n'.join(content))
    print(f"Generated test case: {filename}")

def main():
    """Generate multiple test cases."""
    
    for i in range(testcase_start, testcase_start + num_testcases):
        rows = generate_testcase(i)
        save_testcase(i, rows)

if __name__ == "__main__":
    main()

