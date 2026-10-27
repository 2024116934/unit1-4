#!/bin/bash
# Bash shell script to run tests.
# Lines beginning with ### are explanatory output and are ignored by the test.
# This allows the program to display memory addresses, which vary between runs.
#
# Note to students: You don't need to fully understand this!

echo "#####################################"
echo "       d[o_0]b ELEC2645 Bot          "
echo "#####################################"
echo "Running tests..."
echo

echo "Checking that the program ran..."

raw_output=$(./activity1_pointers.out)
status=$?

if [ $status -eq 0 ]; then
  echo "Pass: Program ran without crashing"
else
  echo "Fail: Program crashed"
  exit 1
fi

# Remove explanatory lines before comparing predictable output.
output=$(printf '%s\n' "$raw_output" | grep -v '^###')

expected=(
  "Starting values: a = 10, b = 20, c = 30"
  "p points to a: *p = 10"
  "a changed to 15"
  "p now points to b: *p = 20"
  "b changed to 25"
  "p now points to c: *p = 30"
  "c changed to 35"
  "Values after changes: a = 15, b = 25, c = 35"
  "Values before swap: a = 60, b = 108, c = 35"
  "Final values: a = 35, b = 108, c = 60"
)

echo
echo "Checking output..."
failed=0
mapfile -t lines <<< "$output"

for i in "${!expected[@]}"; do
  if [ "${lines[$i]}" = "${expected[$i]}" ]; then
    echo "Pass [Line $((i+1))]: '${expected[$i]}'"
  else
    echo "Fail [Line $((i+1))]: Got '${lines[$i]}', Expected '${expected[$i]}'"
    failed=1
  fi
done

if [ "${#lines[@]}" -gt "${#expected[@]}" ]; then
  echo "Fail: Program printed extra checked lines:"
  for ((j=${#expected[@]}; j<${#lines[@]}; j++)); do
    echo "  Extra line $((j+1)): '${lines[$j]}'"
  done
  failed=1
fi

echo
if [ $failed -eq 0 ]; then
  echo "#####################################"
  echo "     d[o_0]b All tests passed :D     "
  echo "#####################################"
  exit 0
else
  echo "#####################################"
  echo "     d[o_0]b Some tests failed :(    "
  echo "#####################################"
  exit 1
fi
