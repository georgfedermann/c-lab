#!/usr/bin/env bash

set -euo pipefail

run_test() {
  local test_case="${1:-Test Case}"
  local input="$2"
  local expected_output="$3"
  local expected_exit_code=$4
  local actual_output
  local actual_exit_code=0
  local test_passed=0

  printf 'Running "%s" ... ' "$test_case"

  actual_output="$(./project_10 <<<"$input" 2>&1)" || actual_exit_code=$?
  actual_output="$(tail -1 <<<"$actual_output")"

  if [[ "$actual_output" == "$expected_output" ]] &&
    ((actual_exit_code == expected_exit_code)); then
    test_passed=1
    printf 'passed\n'
  else
    test_passed=0
    printf 'failed\n'
    printf '  Actual value    : %s\n' "$actual_output"
    printf '  Actual exit code: %d\n' $actual_exit_code
  fi

  ((test_passed))
}

failed=0

# Happy Path
run_test "Kink's example" 84 "B" 0 || ((++failed))
run_test "0" 0 "F" 0 || ((++failed))
run_test "Mid F" 50 "F" 0 || ((++failed))
run_test "59" 59 "F" 0 || ((++failed))
run_test "60" 60 "D" 0 || ((++failed))
run_test "Mid D" 65 "D" 0 || ((++failed))
run_test "69" 69 "D" 0 || ((++failed))
run_test "70" 70 "C" 0 || ((++failed))
run_test "Mid C" 75 "C" 0 || ((++failed))
run_test "79" 79 "C" 0 || ((++failed))
run_test "80" 80 "B" 0 || ((++failed))
run_test "Mid B" 85 "B" 0 || ((++failed))
run_test "89" 89 "B" 0 || ((++failed))
run_test "90" 90 "A" 0 || ((++failed))
run_test "Mid A" 95 "A" 0 || ((++failed))
run_test "99" 99 "A" 0 || ((++failed))
run_test "100" 100 "A" 0 || ((++failed))

# Error Paths
# Text input
run_test "F-A" "A" "Error: bad input - expected an integer between 0 and 100 inclusive" 1 || ((++failed))

# Out of range input
run_test "F-101" 101 "Error: bad input - expected an integer between 0 and 100 inclusive" 1 || ((++failed))
run_test "F-minus" -1 "Error: bad input - expected an integer between 0 and 100 inclusive" 1 || ((++failed))

printf 'Number of failing tests: %d\n' $failed
((failed == 0))
