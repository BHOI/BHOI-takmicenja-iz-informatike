#!/bin/bash

script_dir="$(dirname "$0")"

# Loop over each file in the directory
for file in $script_dir/../input/input*.txt
do
  # Extract the number from the filename
  number=$(echo $file | grep -oP '\d+')
  
  # Call the run_single.sh script with the extracted number
  echo "---------------------------------"
  echo $number
  $script_dir/run_single.sh $number
done
