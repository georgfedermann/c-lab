#!/usr/bin/env bash

set -euo pipefail

# Test plumbing code:
script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
printf 'debug script_dir: %s\n' "${script_dir}"
source "$script_dir/../../tests/test_runner.sh"
executable="$script_dir/test_probe"

# Happy Path
run_test "Simple Happy Path" "foobar" "1 2 4 8 16 32 64 128 " 0 "Error: StackOverflow!" || report_failed

report_results

