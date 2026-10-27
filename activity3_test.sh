#!/bin/bash
# Bash shell script to run tests.
# Lines beginning with ### are explanatory output and are ignored by the test.
#
# Note to students: You don't need to fully understand this!

echo "#####################################"
echo "       d[o_0]b ELEC2645 Bot          "
echo "#####################################"
echo "Running tests..."
echo

echo "Checking that the program ran..."

raw_output=$(./activity3_pointers_structs.out)
status=$?

if [ $status -eq 0 ]; then
  echo "Pass: Program ran without crashing"
else
  echo "Fail: Program crashed"
  exit 1
fi

# Remove explanatory and blank lines before checking the predictable output.
output=$(printf '%s\n' "$raw_output" | grep -v -E '^(###|[[:space:]]*$)')

expected=(
  "Snack: Hobnob          | Type: biscuit  | Price: £0.99"
  "Snack: Hobnob          | Type: biscuit  | Price: £1.19"
  "Snack: Salt & Vinegar  | Type: crisps   | Price: £1.25"
  "Snack: Victoria Sponge | Type: cake     | Price: £2.00"
  "Snack: Pocky           | Type: biscuit  | Price: £1.50"
  "Snack: Pocky           | Type: biscuit  | Price: £1.40"
  "Snack: Hobnob          | Type: biscuit  | Price: £1.09"
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
