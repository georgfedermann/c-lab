#!/usr/bin/env bash

set -euo pipefail

test_upc(){
  local input="${1}"
  local expected="${2}"
  local rc_expected="${3}"
  local actual
  local rc_actual
  local error=0

  printf 'Testing input %s ... ' "${input}"

  if actual=$(./upc_checksum <<< "$input"); then
    rc_actual=$?
  else
    rc_actual=$?
  fi
  actual=$(printf '%s\n' "$actual" | tail -n 1)

  if [[ "${actual}" != "${expected}" ]]; then
    printf 'FAIL: expected=%s actual=%s\n' \
      "$expected" "$actual"
    error=1
  fi
  if (( $rc_actual != "${rc_expected}" )) then
    printf 'FAIL: rc_expected=%s rc_actual=%s\n' \
      "$rc_expected" "$rc_actual"
    error=1
  fi
  if (( $error == 1 )); then
    printf 'FAIL: error=%s\n' "$error"
    return 1
  fi
  printf 'passed.\n'
}

test_upc "0 3 1 2 0 0 0 1 0 0 5" "0   31200 01005 6" 0
test_upc "03120001005" "0   31200 01005 6" 0
test_upc "0 31200 01005" "0   31200 01005 6" 0
test_upc "0 5 1 5 0 0 2 4 1 2 8" "0   51500 24128 8" 0
test_upc "0 0 0 0 0 0 0 0 0 0 0" "0   00000 00000 0" 0
test_upc "0 5 1 5 0 0 2 4 foo" "Expected to read 11 digits, but scanf returned 8 before that." 101
