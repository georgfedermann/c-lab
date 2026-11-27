#!/usr/bin/env bash

set -euo pipefail

# Test framework plumbing code
script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
source "$script_dir/../../tests/test_runner.sh"
executable="$script_dir/project_04"

# Happy Path Tests
run_test "King's example" $'30000\n20000\n0' $'Enter value of trade: \nCommission: $166.00\n\nEnter value of trade: \nCommission: $144.00\n\nEnter value of trade: ' 0 || report_failed
run_test "Finish immediately" "0" $'Enter value of trade: ' 0 || report_failed
run_test "Allow garbage after amount" $'3000foo 2000\n2000\n0\n' $'Enter value of trade: \nCommission: $75.80\n\nEnter value of trade: \nCommission: $64.00\n\nEnter value of trade: ' 0 || report_failed

# Negative Tests
run_test "Recover from non-numeric input" $'30000\nfoo\n20000\n0' $'Enter value of trade: \nCommission: $166.00\n\nEnter value of trade: Enter value of trade: \nCommission: $144.00\n\nEnter value of trade: ' 0 $'\nError: bad input - expected nonnegative floating point number' || report_failed

report_results
