#!/usr/bin/env bash

set -euo pipefail

script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
source "$script_dir/../../tests/test_runner.sh"
executable="$script_dir/project_01"

# Happy Path
run_test "Simple Happy Path" "1 2 3 4 5 0" 'The largest number entered was 5.000000' 0 || report_failed

# Negative tests
run_test "Negative Number first" "-5" 'No nonnegative numbers were entered.' 0 || report_failed
run_test "Ignore rest of line after read error" "1 2 3x 7 8 0" "The largest number entered was 3.000000" 0 || report_failed
run_test "Pick up at next line if previous line contains error" $'1 2 3x 7 8 0\n9 10' "The largest number entered was 10.000000" 0 || report_failed

report_results
