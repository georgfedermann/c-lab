#!/usr/bin/env bash

set -euo pipefail

# Test framework plumbing code
script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
source "$script_dir/../../tests/test_runner.sh"
executable="$script_dir/project_03"

# CH_06 PROJ_03
# Write a program that asks the user to enter a fraciton, then reduces the fraction to lowest terms.
# Enter a fraction: 6/12
# In lowest terms: 1/2

run_test "King's example" "6/12" $'Enter a fraction: \nIn lowest terms: 1/2' 0 || report_failed
run_test "gcd = 1, int limit" "73/2147483647" $'Enter a fraction: \nIn lowest terms: 73/2147483647' 0 || report_failed
run_test "numerator = denominator" "11/11" $'Enter a fraction: \nIn lowest terms: 1/1' 0 || report_failed
run_test "numerator negative" "-9/12" $'Enter a fraction: \nIn lowest terms: -3/4' 0 || report_failed
run_test "denominator negative" "9/-12" $'Enter a fraction: \nIn lowest terms: -3/4' 0 || report_failed
run_test "both negative" "-9/-12" $'Enter a fraction: \nIn lowest terms: 3/4' 0 || report_failed
run_test "numerator 0" "0/12" $'Enter a fraction: \nIn lowest terms: 0/1' 0 || report_failed
run_test "Overflow check" "2/2000000000" $'Enter a fraction: \nIn lowest terms: 1/1000000000' 0 || report_failed

# Negative Tests
run_test "Non-numerical input" "three forth" "Enter a fraction: " 1 \
  "Error: invalid input - expected two integers in the form numerator/denominator" || report_failed
run_test "Zero denominator" "5/0" $'Enter a fraction: ' 2 "Error: undefined fraction" || report_failed
run_test "0/0" "0/0" "Enter a fraction: " 2 "Error: undefined fraction" || report_failed
run_test "Denominator Overflow" "1/-2147483648" "Enter a fraction: " 2 "Error: denominator out of range" || report_failed
run_test "Numerator Overflow" "-2147483648/2" "Enter a fraction: " 2 "Error: numerator out of range" || report_failed

report_results
