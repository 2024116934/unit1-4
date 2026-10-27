# Bash shell script to run tests. 
# Runs the test and then compares the output to what is expected
# Single .c file, but multiple outputs from multiple printf statements
# 
# Note to students: You dont need to fully understand this! 

echo "#####################################"
echo "       d[o_0]b ELEC2645 Bot          "
echo "#####################################"
echo "Running tests..."
echo

echo "Checking for program ran..."

output=$(./activity2_pointers_arrays.out) # run 

# Define expected output lines in order
expected=(
"Original Array: min = -10, max = 42"
"Squared Array: min = 0, max = 1764"
)

if [ $? -eq 0 ] ; then
  echo "Pass: Program ran without crashing"
else
  echo "Fail: Program crashed"
  exit 1
fi

echo
echo "Checking output..."
echo "Output was: $output"

echo
echo "Checking each line of output..."

failed=0

# split output into an array (line by line)
# mapfile makes an array called lines, each line of output is one element -t ignores newlines
mapfile -t lines <<< "$output"

# Check each expected line
for i in "${!expected[@]}"; do
  if [ "${lines[$i]}" == "${expected[$i]}" ]; then
    echo "Pass [Line $((i+1))]: '${expected[$i]}'"
  else
    echo "Fail [Line $((i+1))]: Got '${lines[$i]}', Expected '${expected[$i]}'"
    failed=1
  fi
done

# Check if program printed extra unexpected lines
if [ "${#lines[@]}" -gt "${#expected[@]}" ]; then
  echo "Fail: Program printed extra lines:"
  for ((j=${#expected[@]}; j<${#lines[@]}; j++)); do
    echo "  Extra line $((j+1)): '${lines[$j]}'"
  done
  failed=1
fi

echo
if [ $failed -eq 0 ]; then
  echo "#####################################"
  echo "     d[o_0]b All tests passed :D    "
  echo "#####################################"
  exit 0
else
  echo "#####################################"
  echo "     d[o_0]b Some tests failed :(   "
  echo "#####################################"
  exit 1
fi

exit 0
