# Unit Converter CLI & Test Suite

A modular, high-performance C++20 command-line unit converter built using **strongly-typed `enum class` definitions**, **`std::unordered_map`**, and functional lambdas (`std::function`). Includes an automated **GoogleTest** suite integrated via CMake.

![C++20](https://img.shields.io/badge/C%2B%2B-20-blue.svg?style=flat-square&logo=c%2B%2B)
![CMake](https://img.shields.io/badge/CMake-3.22%2B-064F8C.svg?style=flat-square&logo=cmake)
![GoogleTest](https://img.shields.io/badge/GoogleTest-1.14.0-green.svg?style=flat-square)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey.svg?style=flat-square)

---

## Key Features

- **Modular Category Architecture**: Strongly-typed `enum class` definitions separated into dedicated headers (`length_type.hpp`, `weight_type.hpp`, `temp_type.hpp`, `data_type.hpp`).
- **Constant-Time Hash Lookups**: Uses `std::unordered_map` to map units to base multipliers and lambdas.
- **Lambda-Based Offsets**: Handles non-linear unit transformations (e.g., Celsius/Fahrenheit degree offsets) via `std::function`.
- **Smart Short-Code Aliases**: Supports full unit names and intuitive abbreviations (`KM`, `FT`, `C`, `LB`, `MB`).
- **Interactive REPL Interface**: Command-line loop supporting `CONVERT`, `LIST`, and `HELP`.
- **Automated Unit Testing**: Unit test suite powered by GoogleTest and CTest.

---

## Conversion Architecture

```text
       ┌─────────────────────────┐
       │   CLI (CommandHandler)  │  <-- Parses string input & short-codes
       └────────────┬────────────┘
                    │
       ┌────────────▼────────────┐
       │     UnitConverter       │  <-- Map lookup & conversion math
       └────────────┬────────────┘
                    │
       ┌────────────▼────────────┐
       │     category::parser    │  <-- String <-> Enum class mapping
       └─────────────────────────┘

```

---

## Build & Setup

### Prerequisites

* **C++ Compiler**: GCC 10+, Clang 11+, or MSVC (supporting C++20)
* **Build Tool**: CMake (>= 3.22) & Ninja / Make

### 1. Build Executable & Tests

```bash
# Configure the build directory
cmake -B build -DCMAKE_BUILD_TYPE=Release

# Build both the main executable and test suite
cmake --build build

```

---

## Running Unit Tests

GoogleTest is automatically downloaded and built via CMake `FetchContent`.

```bash
# Run tests using CTest
ctest --test-dir build --output-on-failure

# Alternatively, run the test binary directly for detailed output
./build/unit_tests

```

**Sample Test Output:**

```text
100% tests passed, 0 tests failed out of 5
Total Test time (real) = 0.08 sec

```

---

## Usage & Command Examples

Launch the interactive CLI:

```bash
./build/convertor_cli

```

### REPL Commands

```text
=========================================
        Unit Converter CLI Ready         
=========================================
Type HELP to view available commands.

converter> CONVERT LENGTH 1000 METER KILOMETER
1000 METER = 1 KILOMETER

converter> CONVERT LENGTH 1 IN KM
1 INCH = 2.54e-05 KILOMETER

converter> CONVERT TEMP 32 FAHRENHEIT CELSIUS
32 FAHRENHEIT = 0 CELSIUS

converter> CONVERT DATA 1 TB GB
1 TERABYTE = 1024 GIGABYTE

converter> LIST LENGTH
LENGTH Units: METER (MT), KILOMETER (KM), CENTIMETER (CM), MILLIMETER (MM), MILE (MI), FOOT (FT), INCH (IN)

converter> LIST *
Supported Categories & Units:
  • LENGTH:      METER, KILOMETER, CENTIMETER, MILLIMETER, MILE, FOOT, INCH
  • WEIGHT:      GRAM, KILOGRAM, MILLIGRAM, POUND, OUNCE
  • TEMPERATURE: KELVIN, CELSIUS, FAHRENHEIT
  • DATA:        BYTE, KILOBYTE, MEGABYTE, GIGABYTE, TERABYTE

```

---

## Project Structure

```text
convertor/
├── CMakeLists.txt
├── include/
│   ├── category/
│   │   ├── category_type.hpp
│   │   ├── data_type.hpp
│   │   ├── length_type.hpp
│   │   ├── temp_type.hpp
│   │   ├── unit_parser.hpp
│   │   └── weight_type.hpp
│   ├── cli/
│   │   └── command_handler.hpp
│   └── convertor/
│       └── unit_convertor.hpp
├── src/
│   ├── main.cpp
│   ├── category/
│   │   ├── category_type.cpp
│   │   └── unit_parser.cpp
│   ├── cli/
│   │   └── command_handler.cpp
│   └── convertor/
│       └── unit_convertor.cpp
└── tests/
    ├── test_unit_convertor.cpp
    └── test_unit_parser.cpp

```