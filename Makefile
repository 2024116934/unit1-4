CC := gcc
CFLAGS := -Wall -Wextra -Wpedantic -std=c11 -g -O0

.PHONY: test test1 test2 test3 test4 test5 test6 clean

test:
	@echo "Choose an activity test:"
	@echo "  make test1  Activity 1: Pointers"
	@echo "  make test2  Activity 2: Pointers with Arrays"
	@echo "  make test3  Activity 3: Pointers with Structs"
	@echo "  make test4  Activity 4: Dynamic Memory"
	@echo "  make test5  Activity 5: Camera Buffer Processing"
	@echo "  make test6  Activity 6: Debug Practice"

test1: activity1_pointers.out
	@bash activity1_test.sh

activity1_pointers.out: activity1_pointers.c
	$(CC) $(CFLAGS) $< -o $@

test2: activity2_pointers_arrays.out
	@bash activity2_test.sh

activity2_pointers_arrays.out: activity2_pointers_arrays.c
	$(CC) $(CFLAGS) $< -o $@

test3: activity3_pointers_structs.out
	@bash activity3_test.sh

activity3_pointers_structs.out: activity3_pointers_structs.c
	$(CC) $(CFLAGS) $< -o $@

test4: activity4_dynamic_memory.out
	@bash activity4_test.sh

activity4_dynamic_memory.out: activity4_dynamic_memory.c
	$(CC) $(CFLAGS) $< -o $@

test5: activity5_camera_buffer.out
	@bash activity5_test.sh

activity5_camera_buffer.out: activity5_camera_buffer.c
	$(CC) $(CFLAGS) $< -o $@

test6: activity6_debug_practice.out
	@bash activity6_test.sh

activity6_debug_practice.out: activity6_main.c activity6_badge.c activity6_badge.h
	$(CC) $(CFLAGS) activity6_main.c activity6_badge.c -o $@

clean:
	rm -f *.out
