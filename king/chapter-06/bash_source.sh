#!/usr/bin/env bash

set -euo pipefail

printf 'Printing contents of BASH_SOURCE array:\n'
for v in "${BASH_SOURCE[@]}"; do printf '%s\n' "$v"; done

printf 'dirname -- ${BASH_SOURCE[0]}: %s\n' \
  $(dirname -- "${BASH_SOURCE[0]}")


