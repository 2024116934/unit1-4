#!/bin/bash
echo "#####################################"
echo "       d[o_0]b ELEC2645 Bot          "
echo "#####################################"
echo "Running tests..."
echo
output=$(./activity5_camera_buffer.out)
status=$?
expected=(
 "Original image:"
 "0 25 80 120 150 180 200 220 240 250 100 50"
 "Brightest pixel: 250"
 "Inverted image:"
 "255 230 175 135 105 75 55 35 15 5 155 205"
 "Threshold image:"
 "255 255 255 255 255 0 0 0 0 0 255 255"
)
failed=0
if [ $status -ne 0 ]; then echo "Fail: Program crashed"; exit 1; fi
mapfile -t lines <<< "$output"
for i in "${!expected[@]}"; do
 if [ "${lines[$i]}" = "${expected[$i]}" ]; then echo "Pass [Line $((i+1))]: '${expected[$i]}'"; else echo "Fail [Line $((i+1))]: Got '${lines[$i]}', Expected '${expected[$i]}'"; failed=1; fi
done
echo
if [ $failed -eq 0 ]; then echo "#####################################"; echo "     d[o_0]b All tests passed :D     "; echo "#####################################"; exit 0; else echo "#####################################"; echo "     d[o_0]b Some tests failed :(    "; echo "#####################################"; exit 1; fi
