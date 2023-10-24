#!/bin/bash

find "$PWD/cpp/" -type d -exec sh -c '
  cd "$0"

  if [ -f "solution.cpp" ] && grep -q "TODO:" "solution.cpp"; then
    dir_name=$(basename "$0")
    echo "Problem $dir_name uncompleted."
  fi
' {} \;
