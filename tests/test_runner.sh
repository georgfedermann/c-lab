declare -i TR_FAILED=0

function run_test() {
  local test_case="${1:-Test Case}"
  local input="$2"
  local expected_output="$3"
  local expected_exit_code=$4
  local expected_stderr="${5:-}"
  local actual_output
  local actual_stderr
  local -i actual_exit_code=0 # indicates success!
  local -i test_passed=0      # indicates failure!
  local test_report
  local stderr_tmp_file="$(mktemp)"

  printf -- '--------------------------------------\n'
  printf 'Running "%s" ... ' "$test_case"
  actual_output="$("$executable" <<<"$input" 2>"$stderr_tmp_file")" || actual_exit_code=$?
  # actual_output="$(tail -1 <<<"$actual_output")"
  actual_stderr="$(cat "$stderr_tmp_file")"
  rm "$stderr_tmp_file"

  if [[ "$actual_output" == "$expected_output" ]] &&
    ((actual_exit_code == expected_exit_code)) &&
    [[ "$actual_stderr" == "$expected_stderr" ]]; then
    test_passed=1
    test_report=$'passed\n'
  else
    test_report=$'failed\n'
  fi

  if [[ "$actual_output" != "$expected_output" ]]; then
    printf -v test_report "%s  Actual output     : '%s'\n" "$test_report" "$actual_output"
    printf -v test_report "%s  Expected output   : '%s'\n" "$test_report" "$expected_output"
  fi
  if ((actual_exit_code != expected_exit_code)); then
    printf -v test_report "%s  Actual exit code  : %d\n" "$test_report" $actual_exit_code
    printf -v test_report "%s  Expected exit code: %d\n" "$test_report" $expected_exit_code
  fi
  if [[ "$actual_stderr" != "$expected_stderr" ]]; then
    printf -v test_report "%s  Actual stderr     : %s\n" "$test_report" "$actual_stderr"
    printf -v test_report "%s  Expected stderr   : %s\n" "$test_report" "$expected_stderr"
  fi

  if ((test_passed)); then
    printf 'passed\n'
  else
    printf '%s' "${test_report}"
  fi

  ((test_passed))
}

function report_failed() {
  ((++TR_FAILED))
}

function report_results() {
  printf 'Number of failing tests: %d\n' $TR_FAILED
  return $((TR_FAILED))
}
