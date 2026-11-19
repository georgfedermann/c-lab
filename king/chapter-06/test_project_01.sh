#!/usr/bin/env bash

set -euo pipefail

run_test() {
  local test_case="${1:-Test Case}"
  local input="$2"
  local expected_output="$3"
  local expected_exit_code=$4
  local actual_output
  local actual_exit_code=0
  local -i test_passed=0

  printf 'Running "%s" ... ' "$test_case"
  actual_output="$(./project_01 <<<"$input")" || actual_exit_code=$?
  actual_output="$(tail -1 <<<"$actual_output")"

  if [[ "$actual_output" == "$expected_output" ]] &&
    ((expected_exit_code == actual_exit_code)); then
    test_passed=1
  fi

  if ((test_passed)); then
    printf 'passed\n'
  else
    printf 'failed.\n'
    printf '  actual_output   : %s\n' "$actual_output"
    printf '  actual_exit_code: %d\n' "$actual_exit_code"
  fi

  ((test_passed))
}

declare -i failed=0

# Happy Path
run_test "Simple Happy Path" "1 2 3 4 5 0" 'The largest number entered was 5.000000' 0 || ((++failed))


# Negative tests
run_test "Negative Number first" "-5" 'No nonnegative numbers were entered.' 0 || ((++failed))
run_test "Ignore rest of line after read error" "1 2 3x 7 8 0" "The largest number entered was 3.000000" 0 || ((++failed))
run_test "Pick up at next line if previous line contains error" $'1 2 3x 7 8 0\n9 10' "The largest number entered was 10.000000" 0 || ((++failed))

printf 'Number of failing tests: %d\n' $failed

((failed == 0))
