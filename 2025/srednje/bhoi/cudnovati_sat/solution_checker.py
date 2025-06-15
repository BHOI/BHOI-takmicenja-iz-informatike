import os
import subprocess
import time

# Configuration constants
START_TEST = 0          # First test case number
END_TEST = 19           # Last test case number (inclusive)
SOLUTION_PATH = "sol/main"  # Path to the compiled solution
INPUT_DIR = "input"     # Directory containing input files
OUTPUT_DIR = "output"   # Directory for output files
TIMEOUT = 2             # Timeout in seconds for each test case

# Check if the solution file exists
if not os.path.exists(SOLUTION_PATH):
    print(f"Error: Solution file {SOLUTION_PATH} does not exist.")
    exit(1)

# Check if the solution gives the expected output
for test_num in range(START_TEST, END_TEST + 1):
    input_file = f"{INPUT_DIR}/input{test_num}.txt"
    output_file = f"{OUTPUT_DIR}/output{test_num}.txt"
    
    # Check if the input file exists
    if not os.path.exists(input_file):
        print(f"Warning: Input file {input_file} doesn't exist. Skipping.")
        continue
    
    if not os.path.exists(output_file):
        print(f"Warning: Output file {output_file} doesn't exist. Skipping.")
        continue

    # Create output from the solution and input file, then compare it with the expected output
    print(f"Checking output for test case {test_num}...", end=' ')
    try:
        # Start timing
        start_time = time.time()
        
        # Write the output to a temporary file
        temporary_output_file = f"{OUTPUT_DIR}/temp_output{test_num}.txt"
        with open(temporary_output_file, 'w') as outfile:
            process = subprocess.run(
                [SOLUTION_PATH],
                stdin=open(input_file, 'r'),
                stdout=outfile,
                stderr=subprocess.PIPE,
                timeout=TIMEOUT
            )
        
        # Calculate execution time
        execution_time = time.time() - start_time

        if process.returncode == 0:
            # Compare the generated output with the expected output
            with open(temporary_output_file, 'r') as temp_out, open(output_file, 'r') as expected_out:
                if temp_out.read() == expected_out.read():
                    print(f"Success! Output matches expected (Time: {execution_time:.4f}s)")
                else:
                    print(f"Mismatch! Output does not match expected (Time: {execution_time:.4f}s)")
        else:
            print(f"Failed. Exit code: {process.returncode} (Time: {execution_time:.4f}s)")
            if process.stderr:
                print(f"Error message: {process.stderr.decode().strip()}")
        
        os.remove(temporary_output_file)
    except subprocess.TimeoutExpired:
        print(f"Timeout after {TIMEOUT} seconds")
    except Exception as e:
        print(f"Error: {str(e)}")