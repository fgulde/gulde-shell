#!/bin/sh

set -e # Exit early if any commands fail

(
  cd "$(dirname "$0")" # Ensure compile steps are run within the repository directory

  cmake -G Ninja -B build -S . -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE="${VCPKG_ROOT}"/scripts/buildsystems/vcpkg.cmake

  cmake --build ./build
)

# Run the test binary via CTest
cd "$(dirname "$0")/build" && ctest --output-on-failure "$@"