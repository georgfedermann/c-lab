#!/usr/bin/env bash

run_test(){
  local input="$1"
  local expected="$2"
  local expected_rv="${3:-0}"
  local actual
  local return_value
  local error=0

  printf 'Running test for %s ... ' "$input"

  if actual=$(./project_01 <<< "$input"); then
    return_value=0
  else
    return_value=$?
  fi

  if (( return_value == 0 )); then
    actual=$(awk 'END { print $NF }' <<< "$actual")
  else
    actual="$(tail -n1 <<< "$actual")"
  fi

  if [[ "$expected" != "$actual" ]]; then
    printf '\nError: expected "%s" but was "%s"\n' \
      "$expected" "$actual"
    error=1
  fi

  if (( return_value != expected_rv)); then
    printf '\nError: expected return value %d but was %d\n' \
      "$expected_rv" "$return_value"
    error=1
  fi

  if (( error != 0 )); then
    return 1
  fi

  echo "success!"
}

run_test 42 24
run_test 10 01
run_test 99 99
run_test 1 "Error: Expected a two-digit integer." 102
run_test p1 "Error: Expected a single two-digit integer." 101

