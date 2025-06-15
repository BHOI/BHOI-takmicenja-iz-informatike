import os
import subprocess
import time

# Configuration constants
START_TEST = 0          # First test case number
END_TEST = 24           # Last test case number (inclusive)
SOLUTION_PATH = "sol/main"  # Path to the compiled solution
INPUT_DIR = "input"     # Directory containing input files
OUTPUT_DIR = "output"   # Directory for output files
TIMEOUT = 2            # Timeout in seconds for each test case

# Create output directory if it doesn't exist
os.makedirs(OUTPUT_DIR, exist_ok=True)

def generate_output(test_num):
    input_file = f"{INPUT_DIR}/input{test_num}.txt"
    output_file = f"{OUTPUT_DIR}/output{test_num}.txt"
    
    # Check if the input file exists
    if not os.path.exists(input_file):
        print(f"Warning: Input file {input_file} doesn't exist. Skipping.")
        return False
    
    print(f"Generating output for test case {test_num}...", end=' ')
    
    try:
        # Start timing
        start_time = time.time()
        
        # Run the solution with the input file
        with open(input_file, 'r') as infile, open(output_file, 'w') as outfile:
            process = subprocess.run(
                [SOLUTION_PATH],
                stdin=infile,
                stdout=outfile,
                stderr=subprocess.PIPE,
                timeout=TIMEOUT
            )
        
        # Calculate execution time
        execution_time = time.time() - start_time
        
        if process.returncode == 0:
            print(f"Success! Output written to {output_file} (Time: {execution_time:.4f}s)")
            return True
        else:
            print(f"Failed. Exit code: {process.returncode} (Time: {execution_time:.4f}s)")
            if process.stderr:
                print(f"Error message: {process.stderr.decode().strip()}")
            return False
            
    except subprocess.TimeoutExpired:
        print(f"Timeout after {TIMEOUT} seconds")
        return False
    except Exception as e:
        print(f"Error: {str(e)}")
        return False

# Generate all outputs
success_count = 0
total_time = 0
start_total_time = time.time()

for i in range(START_TEST, END_TEST + 1):
    test_start_time = time.time()
    success = generate_output(i)
    test_time = time.time() - test_start_time
    
    if success:
        success_count += 1
        total_time += test_time

total_elapsed_time = time.time() - start_total_time
print(f"\nGenerated {success_count} output files out of {END_TEST - START_TEST + 1} test cases.")
print(f"Total execution time: {total_elapsed_time:.4f}s")
print(f"Average time per successful test: {total_time/success_count:.4f}s" if success_count > 0 else "No successful tests.")