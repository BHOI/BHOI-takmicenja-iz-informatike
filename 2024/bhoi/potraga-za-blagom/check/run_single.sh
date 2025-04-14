# Usage: run_single.sh TEST_NUMBER
# For example: run_single.sh 0
# This will run test on input0.txt
script_dir="$(dirname "$0")"
mkfifo /tmp/contestant_input /tmp/contestant_output
cp "$script_dir"/../input/input$1.txt input.txt
"$script_dir"/../build/main < /tmp/contestant_input > /tmp/contestant_output &
main_pid=$!
"$script_dir"/manager /tmp/contestant_input /tmp/contestant_output
wait $main_pid
rm /tmp/contestant_input /tmp/contestant_output input.txt