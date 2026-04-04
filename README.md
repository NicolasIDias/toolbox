# Toolbox

A lightweight C utility library providing essential macros and inline functions for common programming tasks.

## Description

Toolbox is a minimal header-only C library designed to simplify and standardize common operations in C programs. It provides generic macros for mathematical operations, boolean definitions, and logging utilities. The library leverages C11 `_Generic` for type-safe polymorphic operations, making it easy to work with both integer and floating-point types without code duplication.

## Features

- **Boolean Support**: Standard boolean type definitions (`bool`, `true`, `false`)
- **Generic Math Operations**: Type-safe macros that work seamlessly with both `int` and `float` types
  - `MIN()` - Minimum value
  - `MAX()` - Maximum value
  - `ABS()` - Absolute value
  - `CLAMP()` - Constrain value to range
  - `SIGN()` - Get sign of number (-1, 0, or 1)
  - `IN_RANGE()` - Check if value is within range
- **Logging Utilities**: Simple macros for formatted output
  - `LOG_INFO()` - Formatted logging to stderr
  - `LOGGER()` - Raw formatted output to stdout
- **Constants**: Mathematical constants like `EPSILON` for floating-point comparisons

## Project Structure

```
toolbox/
├── include/
│   └── toolbox/
│       ├── cadv_bool.h       # Boolean type definitions
│       ├── cadv_log.h        # Logging macros and utilities
│       └── cadv_math.h       # Mathematical macros and functions
├── src/
│   └── example.c             # Usage examples
├── LICENSE                   # MIT License
└── README.md                 # This file
```

## Usage

### Basic Example

```c
#include <toolbox/cadv_math.h>
#include <toolbox/cadv_log.h>

int main(void)
{
    int a = 10;
    int b = 42;
    
    LOG_INFO("[INFO] MIN: %d\n", MIN(a, b));
    LOG_INFO("[INFO] MAX: %d\n", MAX(a, b));
    LOG_INFO("[INFO] ABS: %d\n", ABS(-a));
    
    return 0;
}
```

### Math Operations

All mathematical operations are type-generic and work with both `int` and `float`:

```c
#include <toolbox/cadv_math.h>

// Works with integers
int min_val = MIN(10, 20);           // 10
int max_val = MAX(10, 20);           // 20
int clamped = CLAMP(15, 0, 10);      // 10
int sign = SIGN(-5);                 // -1

// Works with floats
float fmin = MIN(1.5f, 3.25f);       // 1.5
float fmax = MAX(1.5f, 3.25f);       // 3.25
float abs_val = ABS(-2.5f);          // 2.5
bool in_range = IN_RANGE(5.5f, 0.0f, 10.0f);  // true
```

### Logging

```c
#include <toolbox/cadv_log.h>

// Log to stderr with formatting
LOG_INFO("[INFO] Value: %d\n", 42);

// Raw printf-style output to stdout
LOGGER("[RAW] Debug: %d %.2f\n", 10, 3.14);
```

## Building

Since this is a header-only library, simply include the headers in your project:

```c
#include <toolbox/cadv_math.h>
#include <toolbox/cadv_log.h>
#include <toolbox/cadv_bool.h>
```

To compile the example:

```bash
gcc -I./include src/example.c -o example
./example
```

## API Reference

### Math Macros

| Macro | Description | Supported Types |
|-------|-------------|-----------------|
| `MIN(x, y)` | Returns the minimum of two values | int, float |
| `MAX(x, y)` | Returns the maximum of two values | int, float |
| `ABS(n)` | Returns the absolute value | int, float |
| `CLAMP(x, min, max)` | Constrains value between min and max | int, float |
| `SIGN(x)` | Returns -1, 0, or 1 | int, float |
| `IN_RANGE(val, low, high)` | Checks if value is in range | int, float |

### Constants

| Constant | Value | Purpose |
|----------|-------|---------|
| `EPSILON` | 1e-9 | Default tolerance for floating-point comparisons |
| `ROUND(x)` | Converts to nearest integer | Rounding macro |

### Logging Macros

| Macro | Description |
|-------|-------------|
| `LOG_INFO(fmt, ...)` | Formatted logging to stderr with variadic arguments |
| `LOGGER(fmt, ...)` | Raw formatted output to stdout with variadic arguments |

## Requirements

- C11 or later (for `_Generic` support and `_Bool` type)
- Standard C library

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.