#!/usr/bin/env bash

set -euo pipefail

run_test() {
  local test_case="${1:-Test Case}"
  local input="$2"
  local expected_output="$3"
  local expected_exit_code=${4:-0}
  local actual_output
  local actual_exit_code
  local test_passed=0

  printf 'Running %s ... ' "$test_case"

  actual_exit_code=0
  actual_output="$(./project_07 <<<"$input")" || actual_exit_code=$?

  actual_output="$(tail -2 <<<"$actual_output")"

  if [[ "$actual_output" == "$expected_output" ]]; then
    test_passed=1
  fi

  if ((actual_exit_code != expected_exit_code)); then
    test_passed=0
  fi

  if ((test_passed)); then
    printf 'succeeded\n'
  else
    printf 'failed\n'
    printf 'Expected output   : %s\n' "$expected_output"
    printf 'Actual output     : %s\n' "$actual_output"
    printf 'Expected exit code: %s\n' "$expected_exit_code"
    printf 'Actual exit code  : %s\n' "$actual_exit_code"
  fi

  ((test_passed))
}

failed=0
run_test "Kink's challenge" "21 43 10 35" $'Largest: 43\nSmallest: 10' 0 || ((++failed))
run_test "4 different numbers, if branches" "10 20 30 40" $'Largest: 40\nSmallest: 10' 0 || ((++failed))
run_test "4 different numbers, else branches" "7 5 3 1" $'Largest: 7\nSmallest: 1' 0 || ((++failed))
run_test "4 times same number" "-1 -1 -1 -1" $'Largest: -1\nSmallest: -1' 0 || ((++failed))
run_test "2 times same number per pair" "4 4 3 3" $'Largest: 4\nSmallest: 3' 0 || ((++failed))
run_test "2 times same number cross pair" "4 3 4 3" $'Largest: 4\nSmallest: 3' 0 || ((++failed))
run_test "Bad input" "foobar" $'Error: bad input\nexpected four integer numbers' 1 || ((++failed))

printf 'Number of tests failed: %d' $failed
((failed == 0))
