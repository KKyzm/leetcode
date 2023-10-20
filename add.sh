#!/bin/bash

find "$PWD/cpp/" -type d -exec sh -c '
  cd "$0"

  if [ -f "solution.cpp" ] && ! grep -q "TODO:" "solution.cpp"; then
    git_status=$(git status --porcelain .)

    if [[ -n "$git_status" ]]; then
      git add .
      dir_name=$(basename "$0")
      echo "Added files in $dir_name."
    fi
  fi
' {} \;
