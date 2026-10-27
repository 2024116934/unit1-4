#!/bin/bash
# ELEC2645 Bot test for Activity 6.

echo "#####################################"
echo "       d[o_0]b ELEC2645 Bot          "
echo "#####################################"
echo "Running tests..."
echo

failed=0

names=(
    "Mew"
    "Pikachu"
    "jIgGlYpUfF"
    "Charmander"
    "TeamRocketGrunt1234"
)

for name in "${names[@]}"; do
    expected_name=$(printf '%s' "$name" | tr '[:lower:]' '[:upper:]')

    output=$(printf '%s\n' "$name" |
        ./activity6_debug_practice.out 2>&1)

    status=$?

    if [ $status -ne 0 ]; then
        echo "Fail: Program did not run successfully for $name"
        failed=1
        continue
    fi

    mapfile -t badge_lines < <(
        printf '%s\n' "$output" |
        sed 's/^Enter your name: //' |
        grep -E '^\*'
    )

    if [ "${#badge_lines[@]}" -ne 3 ]; then
        echo "Fail: Expected three badge lines for $name"
        failed=1
        continue
    fi

    top_length=${#badge_lines[0]}
    middle_length=${#badge_lines[1]}
    bottom_length=${#badge_lines[2]}

    if [ "$top_length" -ne "$middle_length" ] ||
       [ "$top_length" -ne "$bottom_length" ]; then

        echo "Fail: Badge lines are different lengths for $name"
        echo "  Top:    $top_length"
        echo "  Middle: $middle_length"
        echo "  Bottom: $bottom_length"
        failed=1

    elif [[ "${badge_lines[1]}" != *"$expected_name"* ]]; then

        echo "Fail: Badge does not contain uppercase name $expected_name"
        failed=1

    else
        echo "Pass: Correct badge for $name"
    fi
done

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
