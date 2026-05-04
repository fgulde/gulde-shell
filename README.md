# Gulde Shell in C

![CI](https://github.com/fgulde/gulde-shell/actions/workflows/ci.yml/badge.svg)

**Gulde Shell** (_GShell_) is a private systems-programming learning project focused on building a shell from scratch in modern C.

## Goal

This project exists to deepen practical systems-level C skills by implementing a shell and exploring low-level software concepts such as process handling, command execution, parsing, and interactive terminal behavior.

## Current Status

Already implemented:
_TBD_

Planned:
- Interactive REPL loop with prompt rendering and input handling.
- Command parser (tokenization, quoting/escaping, argument handling).
- Builtin commands (e.g., `cd`, `pwd`, `echo`, `exit`, `type`).
- External command execution with `fork`/`exec` and proper exit status propagation.
- Environment variable expansion, redirections, and piping.
- Improved test coverage for parser, builtins, and process execution paths.

## Tech Stack

- **Language:** C23
- **Build system:** CMake
- **Dependency management:** vcpkg (manifest mode)
- **Line editing:** readline
- **Testing:** cmocka

## Building
Use the provided script:
```bash
./program.sh
```

## Testing
To build and run tests:
```bash
./run_tests.sh
```

## Architecture

_TBD — this section will be documented as the module boundaries and execution flow stabilize._

## Project Structure

_TBD_

