#!/usr/bin/env bash

set -euo pipefail
# set -x
run_test(){
  local test_case="${1:-Test Case}"
  local input="$2"
  local expected_result="$3"
  local expected_exit_code=${4:-0}
  local actual_result
  local actual_exit_code
  local test_passed

  printf 'Running %s ... ' "$test_case"

  actual_exit_code=0
  actual_result=$(./project_06 <<< "$input") || actual_exit_code=$?

  actual_result="$(tail -1 <<< "$actual_result")"
  if [[ "$actual_result" == "$expected_result" ]]; then
    test_passed=1
  else
    test_passed=0
  fi

  if (( actual_exit_code != expected_exit_code )); then
    test_passed=0
  fi

  if (( test_passed )); then
    printf 'passed\n'
  else
    printf 'failed\n'
    printf '  Expected result: %s\n' "$expected_result"
    printf '  Actual result  : %s\n' "$actual_result"
    printf '  Expected exit c: %d\n' "$expected_exit_code"
    printf '  Actual exit cod: %d\n' "$actual_exit_code"
  fi

  (( test_passed ))
}

failed=0

run_test "EAN 8691484260008" 8691484260008 "VALID" 0 || ((++failed))
run_test "EAN 0000000000000" 0000000000000 "VALID" 0 || ((++failed))
run_test "EAN 4044186408454" 4044186408454 "VALID" 0 || ((++failed))
run_test "Invalid check digit" 4044186408453 "NOT VALID" 1 || ((++failed))
run_test "Invalid EAN" "foobar" "Error: bad input - expected 13 digits" 2 || ((++failed))

printf 'Number of failed tests: %d\n' $failed

((failed==0))
