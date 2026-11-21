#!/usr/bin/env bash

set -euo pipefail

# Test framework plumbing code
script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
source "$script_dir/../../tests/test_runner.sh"
executable="$script_dir/project_02"

# Project CH_06 PROJ_02
# Write a program that asks the user to enter two integers, then calculates and displays their
# greatest common divisor (GCD).
# Enter two integers: 12 28
# Greatest common divisor: 4
#
# Happy Path Tests
run_test "King's example" "12 28" "Greatest common divisor: 4" 0 || report_failed
run_test "GCD is 1" "73 97" "Greatest common divisor: 1" 0 || report_failed
run_test "Limit 32bit signed int" "73 2147483647" "Greatest common divisor: 1" 0 || report_failed
run_test "GCD is number itself" "2147483647 2147483647" "Greatest common divisor: 2147483647" 0 || report_failed
run_test "Demonstrate symmetry 105 42" "105 42" "Greatest common divisor: 21" 0 || report_failed
run_test "Demonstrate symmetry 42 105" "42 105" "Greatest common divisor: 21" 0 || report_failed
run_test "Smaller number is gcd" "21 105" "Greatest common divisor: 21" 0 || report_failed
run_test "Smaller number is gce" "105 21" "Greatest common divisor: 21" 0 || report_failed
run_test "One number is 0" "12 0" "Greatest common divisor: 12" 0 || report_failed
run_test "One number is 0" "0 12" "Greatest common divisor: 12" 0 || report_failed
run_test "0 and prime" "0 73" "Greatest common divisor: 73" 0 || report_failed
run_test "prime and 0" "73 0" "Greatest common divisor: 73" 0 || report_failed

# Negative Tests
# Bad input
run_test "Non-numerical input" "gcd(2,3)" "" 1 "Error: bad input - expected an integer number >= 0" || report_failed
run_test "Reject negative numbers" "73 -73" "" 1 "Error: bad input - expected an integer number >= 0" || report_failed
# Undefined result
run_test "Both numbers 0" "0 0" "" 2 "Error: gcd(0,0) is undefined" || report_failed

report_results
