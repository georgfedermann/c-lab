#!/usr/bin/env bash

set -euo pipefail

# Test framework plumbing code
script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
source "$script_dir/../../tests/test_runner.sh"
executable="$script_dir/project_05"

# Programming Project in Chapter 4:
# Write a program that asks the user to enter a two-digit number, then prints the number with
# its digits reversed. A session with the program should have the following appearance:
#
# Enter a two-digit number: 28
# The reversal is: 82
#
# ---
#
# Generalize the program so that the number can have one,
# two, three, or more digits.
#
# ---
#
# Restrictions:
# 1.
# King does not specify a specific limit within which the input is valid.
# So, let's use unsigned int and allow UINT_MAX = 4294967295
# 2.
# Since we are still using `scanf` the program does not accept
# leading 0. If present they will be ignored with the exception of input 
# being exactly 0. If numbers end in 0s they will result in leading 0s though.

# Happy Path Tests
run_test "King's example" "28" $'Enter a nonnegative integer number (max 4294967295): \nThe reversal is: 82' 0 || report_failed
run_test "1234567890" "1234567890" $'Enter a nonnegative integer number (max 4294967295): \nThe reversal is: 0987654321' 0 || report_failed
run_test "UINT_MAX 4294967295" "4294967295" $'Enter a nonnegative integer number (max 4294967295): \nThe reversal is: 5927694924' 0 || report_failed
run_test "0" "0" $'Enter a nonnegative integer number (max 4294967295): \nThe reversal is: 0' 0 || report_failed
run_test "012345" "012345" $'Enter a nonnegative integer number (max 4294967295): \nThe reversal is: 54321' 0 || report_failed

# Negative Tests
run_test "Non-numeric input" "foo" $'Enter a nonnegative integer number (max 4294967295): ' 1 'Error: bad input - expected a nonnegative integer number <= 4294967295' || report_failed
run_test "Ignore non-numeric garbage after int" "0foo" $'Enter a nonnegative integer number (max 4294967295): \nThe reversal is: 0' 0 || report_failed
run_test "-1" "-1" $'Enter a nonnegative integer number (max 4294967295): \nThe reversal is: 5927694924' 0 || report_failed

report_results
