#!/usr/bin/env bash

set -euo pipefail

run_test() {
  local test_case="${1:-Test Case}"
  local input="$2"
  local expected_output="$3"
  local expected_exit_code=$4
  local expected_stderr="${5:-}"
  local actual_output
  local actual_exit_code=0
  local actual_stderr=""
  local test_passed=0
  local stderr_output="$(mktemp)"

  printf 'Running "%s" ... ' "$test_case"

  actual_output="$(./project_11 <<<"$input" 2>"$stderr_output")" || actual_exit_code=$?
  if ((actual_exit_code == 0)); then
    actual_output="$(tail -1 <<<"$actual_output")"
  else
    actual_output=
  fi
  actual_stderr="$(cat "$stderr_output")"
  rm "$stderr_output"

  if [[ "$actual_output" == "$expected_output" ]] &&
    ((actual_exit_code == expected_exit_code)) &&
    [[ "$actual_stderr" == "$expected_stderr" ]]; then
    test_passed=1
    printf 'passed.\n'
  else
    printf 'failed.\n'
    printf '  Actual output   : %s\n' "$actual_output"
    printf '  Actual stderr   : %s\n' "$actual_stderr"
    printf '  Actual exit code: %d\n' "$actual_exit_code"
  fi

  ((test_passed))
}

failed=0

# Happy path testing
run_test "Kink's example" 45 "You entered the number forty-five." 0 "" || ((++failed))
run_test "ten" 10 "You entered the number ten." 0 "" || ((++failed))
run_test "eleven" 11 "You entered the number eleven." 0 "" || ((++failed))
run_test "twelve" 12 "You entered the number twelve." 0 "" || ((++failed))
run_test "thirteen" 13 "You entered the number thirteen." 0 "" || ((++failed))
run_test "fourteen" 14 "You entered the number fourteen." 0 "" || ((++failed))
run_test "fifteen" 15 "You entered the number fifteen." 0 "" || ((++failed))
run_test "sixteen" 16 "You entered the number sixteen." 0 "" || ((++failed))
run_test "seventeen" 17 "You entered the number seventeen." 0 "" || ((++failed))
run_test "eighteen" 18 "You entered the number eighteen." 0 "" || ((++failed))
run_test "nineteen" 19 "You entered the number nineteen." 0 "" || ((++failed))
run_test "twenty" 20 "You entered the number twenty." 0 "" || ((++failed))
run_test "thirty" 30 "You entered the number thirty." 0 "" || ((++failed))
run_test "sixty" 60 "You entered the number sixty." 0 "" || ((++failed))
run_test "one" 21 "You entered the number twenty-one." 0 "" || ((++failed))
run_test "two" 32 "You entered the number thirty-two." 0 "" || ((++failed))
run_test "three" 43 "You entered the number forty-three." 0 "" || ((++failed))
run_test "four" 54 "You entered the number fifty-four." 0 "" || ((++failed))
run_test "five" 65 "You entered the number sixty-five." 0 "" || ((++failed))
run_test "six" 76 "You entered the number seventy-six." 0 "" || ((++failed))
run_test "seven" 87 "You entered the number eighty-seven." 0 "" || ((++failed))
run_test "eight" 98 "You entered the number ninety-eight." 0 "" || ((++failed))
run_test "nine" 99 "You entered the number ninety-nine." 0 "" || ((++failed))

# Error path testing
# text input
run_test "F: text input" "twenty" "" 1 "Error: bad input - expected a two digit integer number" || ((++failed))
run_test "F: input < 10" "9" "" 1 "Error: bad input - expected a two digit integer number" || ((++failed))
run_test "F: input > 99" "100" "" 1 "Error: bad input - expected a two digit integer number" || ((++failed))

printf 'Number of failing tests: %d\n' "$failed"
((failed == 0))
