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

  actual_output="$(./project_08 <<<"$input" 2>&1)" || actual_exit_code=$?
  actual_output="$(tail -1 <<<"$actual_output")"

  if [[ "$actual_output" == "$expected_output" ]] &&
    ((actual_exit_code == expected_exit_code)); then
    test_passed=1
  fi

  if ((test_passed)); then
    printf "passed.\n"
  else
    printf "failed.\n"
    printf 'Actual output   : %s\n' "$actual_output"
    printf 'Actual exit code: %d\n' $actual_exit_code
  fi

  ((test_passed))
}

failed=0

run_test "Kink's test case" "13:15" "Closest departure time is 12:47 p.m., arriving at 3:00 p.m." 0 || ((++failed))
run_test "Exact match 08:00" "08:00" "Closest departure time is 8:00 a.m., arriving at 10:16 a.m." 0 || ((++failed))
run_test "1m before switch" "08:51" "Closest departure time is 8:00 a.m., arriving at 10:16 a.m." 0 || ((++failed))
run_test "1m after switch" "08:52" "Closest departure time is 9:43 a.m., arriving at 11:52 a.m." 0 || ((++failed))
# Unspecified behavior: equidistance ... take the first one ...
run_test "Exactly in the middle" "10:31" "Closest departure time is 9:43 a.m., arriving at 11:52 a.m." 0 || ((++failed))
run_test "10:32 -> 11:19" "10:32" "Closest departure time is 11:19 a.m., arriving at 1:31 p.m." 0 || ((++failed))
run_test "After today's last flight" "22:15" "Closest departure time is 9:45 p.m., arriving at 11:58 p.m." 0 || ((++failed))
# Unspecified behavior: distance to same day flights or around midnight?
# I assume calendar day overflow allowed as an additional challenge.
run_test "Allow calendar day overflow" "00:00" "Closest departure time is 9:45 p.m., arriving at 11:58 p.m." 0 || ((++failed))
run_test "Morning after" "02:53" "Closest departure time is 8:00 a.m., arriving at 10:16 a.m." 0 || ((++failed))
run_test "Night before" "02:52" "Closest departure time is 9:45 p.m., arriving at 11:58 p.m." 0 || ((++failed))
run_test "Test flight 12:47" "12:47" "Closest departure time is 12:47 p.m., arriving at 3:00 p.m." 0 || ((++failed))
run_test "Test flight 14:00" "14:00" "Closest departure time is 2:00 p.m., arriving at 4:08 p.m." 0 || ((++failed))
run_test "Test flight 15:45" "15:45" "Closest departure time is 3:45 p.m., arriving at 5:55 p.m." 0 || ((++failed))
run_test "Test flight 19:00" "19:00" "Closest departure time is 7:00 p.m., arriving at 9:20 p.m." 0 || ((++failed))
run_test "Test flight 21:45" "21:45" "Closest departure time is 9:45 p.m., arriving at 11:58 p.m." 0 || ((++failed))
run_test "Bad input: foobar" "foobar" "Error: bad input - expected 24h format time" 1 || ((++failed))
printf 'Number of failing tests: %d\n' $failed
((failed==0))
