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

  printf 'Running "%s" ... ' "${test_case}"

  actual_output="$(./project_09 <<<"$input" 2>&1)" || actual_exit_code=$?
  actual_output="$(tail -1 <<<"$actual_output")"

  if [[ "$actual_output" == "$expected_output" ]] &&
    ((actual_exit_code == expected_exit_code)); then
    test_passed=1
    printf 'passed\n'
  else
    printf 'failed\n'
    printf '  Actual output   : %s\n' "$actual_output"
    printf '  Actual exit code: %d\n' $actual_exit_code
  fi

  ((test_passed))
}

failed=0

# Standard global convention used across Unix, POSIX, and financial systems
# - Years 00 through 68 are assumed to belong to the 2000s (2000-2068)
# - Years 69 through 99 are assumed to belong to the 1900s (1900-1999)
run_test "Kink's test case" "3/6/08 5/17/07" "5/17/07 is earlier than 3/6/08" 0 || ((++failed))
run_test "Same date" "3/6/08 3/6/08" "Received same date twice: 3/6/08" 0 || ((++failed))
run_test "Same year m1" "3/6/08 3/7/08" "3/6/08 is earlier than 3/7/08" 0 || ((++failed))
run_test "Same year m2" "3/6/08 3/5/08" "3/5/08 is earlier than 3/6/08" 0 || ((++failed))
run_test "99 is in the past" "3/6/08 3/5/99" "3/5/99 is earlier than 3/6/08" 0 || ((++failed))
run_test "Before posix switch" "12/31/68 01/01/69" "1/1/69 is earlier than 12/31/68" 0 || ((++failed))
run_test "Bad input date1" foobar "Error: bad input - expected date in US format" 1 || ((++failed))
run_test "Bad input date2" "12/31/68 foobar" "Error: bad input - expected date in US format" 1 || ((++failed))
run_test "Bad input month" "3/6/08 13/6/08" "Error: bad input - expected date in US format" 1 || ((++failed))

printf 'Number of failing tests: %d\n' $failed
((failed == 0))
