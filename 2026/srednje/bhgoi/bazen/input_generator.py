import random
import os

# Configuration constants
TASK_DIR = "bazen"
FIRST_TESTCASE_NUM = 0
NUM_TESTCASES = 0  # Set to 30 to generate, resets to 0 after running

MAX_D = 1000

INPUT_DIR = os.path.join(TASK_DIR, "input")
os.makedirs(INPUT_DIR, exist_ok=True)


def write_test(case_num, n, m, grid):
    with open(os.path.join(INPUT_DIR, f"input{case_num}.txt"), "w") as f:
        f.write(f"{n} {m}\n")
        for row in grid:
            f.write(" ".join(str(x) for x in row) + "\n")
    print(f"Created test case {case_num}: n={n}, m={m}")


def make_grid(n, m, min_d=1, max_d=MAX_D):
    """Generate an N*M grid with every-3rd-row (1-indexed) = 0."""
    grid = []
    for i in range(n):
        if (i + 1) % 3 == 0:  # 1-indexed row divisible by 3
            grid.append([0] * m)
        else:
            grid.append([random.randint(min_d, max_d) for _ in range(m)])
    return grid


def generate_all():
    case = FIRST_TESTCASE_NUM

    # === ST1 (5pts): M=1 (tests 0-4) ===
    write_test(case, 1, 1, [[5]])
    case += 1
    write_test(case, 10, 1, make_grid(10, 1))
    case += 1
    write_test(case, 100, 1, make_grid(100, 1))
    case += 1
    write_test(case, random.randint(500, 1000), 1, make_grid(random.randint(500, 1000), 1))
    case += 1  # regenerate with same n
    n = random.randint(500, 1000)
    # fix: rewrite previous
    case -= 1
    write_test(case, n, 1, make_grid(n, 1))
    case += 1
    write_test(case, 1000, 1, make_grid(1000, 1))
    case += 1

    # === ST2 (12pts): N=1, N*M<=20 (tests 5-9) ===
    write_test(case, 1, 1, [[7]])
    case += 1
    write_test(case, 1, 3, [[3, 7, 2]])
    case += 1
    for _ in range(3):
        m = random.randint(5, 20)
        write_test(case, 1, m, make_grid(1, m))
        case += 1

    # === ST3 (9pts): N*M<=20 (tests 10-14) ===
    write_test(case, 2, 2, make_grid(2, 2))
    case += 1
    write_test(case, 3, 3, make_grid(3, 3))
    case += 1
    write_test(case, 4, 5, make_grid(4, 5))
    case += 1
    write_test(case, 5, 4, make_grid(5, 4))
    case += 1
    write_test(case, 2, 10, make_grid(2, 10))
    case += 1

    # === ST4 (23pts): N=1 (tests 15-19) ===
    write_test(case, 1, 100, make_grid(1, 100))
    case += 1
    write_test(case, 1, 500, make_grid(1, 500))
    case += 1
    write_test(case, 1, 1000, make_grid(1, 1000))
    case += 1
    write_test(case, 1, 1000, make_grid(1, 1000))
    case += 1
    # All same values stress test
    write_test(case, 1, 1000, [[500] * 1000])
    case += 1

    # === ST5 (25pts): N<=3 (tests 20-24) ===
    write_test(case, 2, 500, make_grid(2, 500))
    case += 1
    write_test(case, 3, 500, make_grid(3, 500))
    case += 1
    write_test(case, 2, 1000, make_grid(2, 1000))
    case += 1
    write_test(case, 3, 1000, make_grid(3, 1000))
    case += 1
    write_test(case, 3, 1000, make_grid(3, 1000))
    case += 1

    # === ST6 (27pts): full N,M<=1000 (tests 25-29) ===
    write_test(case, 500, 500, make_grid(500, 500))
    case += 1
    write_test(case, 1000, 1000, make_grid(1000, 1000))
    case += 1
    write_test(case, 1000, 100, make_grid(1000, 100))
    case += 1
    write_test(case, 100, 1000, make_grid(100, 1000))
    case += 1
    # Max with all values = 1000
    n, m = 1000, 1000
    grid = []
    for i in range(n):
        if (i + 1) % 3 == 0:
            grid.append([0] * m)
        else:
            grid.append([1000] * m)
    write_test(case, n, m, grid)
    case += 1

    print(f"\nGenerated {case - FIRST_TESTCASE_NUM} test cases total.")


if NUM_TESTCASES > 0:
    generate_all()

    # Reset NUM_TESTCASES to 0 to avoid accidental re-generation
    with open(__file__, "r") as f:
        content = f.read()
    content = content.replace(
        f"NUM_TESTCASES = {NUM_TESTCASES}", "NUM_TESTCASES = 0"
    )
    with open(__file__, "w") as f:
        f.write(content)
else:
    print("NUM_TESTCASES is 0. Set it to 30 to generate test cases.")
