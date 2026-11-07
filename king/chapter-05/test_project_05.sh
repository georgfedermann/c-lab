#!/usr/bin/env bash

# Simple C program test harness:
# - A simple test function accepts
#   - input
#   - expected output
#   - expected exit code
# - Each call to this function represents one test case.

set -euo pipefail
# set -x

run_test(){
  local test_case_name="${1:-Test}"
  local input="$2"
  local expected_result="$3"
  local expected_exit_code=${4:-0}
  local actual_result
  local actual_exit_code
  local test_passed=0

  printf 'Running "%s" ... ' "$test_case_name"
  if actual_result="$(./project_05 <<< "$input")"; then
    actual_exit_code=$?
  else
    actual_exit_code=$?
  fi

  actual_result="$(tail -1 <<< "$actual_result" | awk 'END { print $(NF-1), $NF}')"

  if [[ "$expected_result" == "$actual_result" ]] && (( expected_exit_code == actual_exit_code )); then
    test_passed=1
  fi

  if (( test_passed )); then
    printf ' passed\n'
  else
    printf ' failed.\n'
    printf '  Expected result: %s\n' "$expected_result"
    printf '  Actual   result: %s\n' "$actual_result"
    printf '  Expected exit c: %s\n' "$expected_exit_code"
    printf '  Actual   exit c: %s\n' "$actual_exit_code"
  fi

  if (( test_passed )); then
    return 0;
  else
    return 1;
  fi
}

failed=0

run_test "Negative Income -> no tax" -50 "USD 0.00" 0 || ((failed += 1))
run_test "Zero Income -> no tax" 0 "USD 0.00" 0 || ((failed += 1))
run_test "Mid first income bracket" 500 "USD 5.00" 0 || ((failed += 1))
run_test "End first bracket -1" 749 "USD 7.49" 0 || ((failed += 1))
run_test "End first bracket" 750 "USD 7.50" 0 || ((failed += 1))
run_test "End first bracket +1" 751 "USD 7.52" 0 || ((failed += 1))
run_test "Mid second bracket" 1750 "USD 27.50" 0 || ((failed += 1))

printf 'Number of failed tests: %d\n' $failed

if (( failed > 0 )); then
  exit 1
fi
