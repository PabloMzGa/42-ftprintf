# ft_printf - Custom Printf Implementation

[![42 School](https://img.shields.io/badge/School-42-black?style=flat-square&logo=42)](https://42.fr/)
[![Language: C](https://img.shields.io/badge/Language-C-blue?style=flat-square&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Standard: C99](https://img.shields.io/badge/Standard-C99-yellow?style=flat-square)](https://en.wikipedia.org/wiki/C99)
[![Library: Static](https://img.shields.io/badge/Library-Static-green?style=flat-square)](https://en.wikipedia.org/wiki/Static_library)

A comprehensive recreation of the standard C library `printf` function, implementing formatted output with support for multiple conversion specifiers and advanced formatting flags. This project is part of the 42 School curriculum and demonstrates fundamental concepts in variadic functions, memory management, and string manipulation.

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Technical Implementation](#technical-implementation)
- [Examples](#examples)
- [Testing](#testing)
- [Requirements](#requirements)
- [42 School Norm Compliance](#42-school-norm-compliance)
- [Contributing](#contributing)
- [License](#license)

## 🎯 Overview

The `ft_printf` project is a custom implementation of the standard C library's `printf` function. It provides formatted output capabilities with support for various data types and formatting options. The implementation demonstrates advanced C programming concepts including:

- **Variadic Functions**: Handling variable argument lists using `stdarg.h`
- **Function Pointers**: Dynamic dispatch system for different conversion specifiers
- **Memory Management**: Efficient string manipulation and allocation
- **Modular Design**: Clean separation of concerns with dedicated printer functions
- **Format Parsing**: Complex flag and format specifier analysis

This project implements two versions:
- **Mandatory Part (`ft_printf`)**: Basic conversion specifiers (c, s, p, d, i, u, x, X, %)
- **Bonus Part (`ft_printf_bonus`)**: Extended functionality with formatting flags (-+#0 ), field width, and precision

## ✨ Features

### Core Functionality (Mandatory)
- **Character Output (`%c`)**: Single character printing
- **String Output (`%s`)**: Null-terminated string printing with NULL safety
- **Pointer Address (`%p`)**: Hexadecimal pointer representation with "0x" prefix
- **Signed Integers (`%d`, `%i`)**: Decimal integer conversion with sign handling
- **Unsigned Integers (`%u`)**: Unsigned decimal integer conversion
- **Hexadecimal (`%x`, `%X`)**: Lowercase and uppercase hexadecimal conversion
- **Literal Percent (`%%`)**: Literal '%' character output
- **Return Value Tracking**: Accurate character count for all output

### Advanced Features (Bonus)
- **Flag Support**: Complete implementation of format flags
  - **`-`**: Left-justify within field width
  - **`+`**: Always show sign for signed conversions
  - **` ` (space)**: Prefix positive numbers with space
  - **`#`**: Alternate form (0x prefix for hex, etc.)
  - **`0`**: Zero-padding instead of space-padding
- **Field Width**: Minimum field width specification
- **Precision**: Precision control for different data types
- **Complex Formatting**: Multiple flags combination support
- **Memory Optimization**: Efficient string building and formatting

### Implementation Highlights
- **Modular Architecture**: Separate printer functions for each conversion type
- **Function Pointer Dispatch**: O(1) printer selection using lookup tables
- **Robust Error Handling**: Comprehensive input validation and edge case management
- **Memory Safety**: Proper allocation, deallocation, and NULL pointer handling
- **Performance Optimized**: Minimal function calls and efficient algorithms

## 🚀 Installation

### Prerequisites

- **GCC compiler** (with C99 support)
- **Make** build system
- **Standard C Library** (for basic functions like `write`, `malloc`)
- **Git** for cloning the repository

### Installation Steps

1. **Clone the repository**
   ```bash
   git clone https://github.com/PabloMzGa/42-ftprintf.git
   cd 42-ftprintf
   ```

2. **Build the mandatory version**
   ```bash
   make
   ```

3. **Build the bonus version**
   ```bash
   make bonus
   ```

4. **Build both versions**
   ```bash
   make all
   make bonus
   ```

5. **Clean build artifacts**
   ```bash
   make clean      # Remove object files
   make fclean     # Remove all generated files
   make re         # Rebuild everything
   ```

## 🎮 Usage

### Integration in Your Project

**Include the header in your source files:**
```c
#include "ft_printf.h"          // For mandatory version
#include "ft_printf_bonus.h"    // For bonus version
```

**Link with the static library:**
```bash
# Compile your project with ft_printf
gcc -Wall -Wextra -Werror your_file.c -L. -lftprintf -o your_program

# Or with bonus version
gcc -Wall -Wextra -Werror your_file.c -L./build_bonus -lftprintf_bonus -o your_program
```

### Function Signature

```c
int ft_printf(const char *format, ...);
```

**Parameters:**
- `format`: Format string containing text and conversion specifiers
- `...`: Variable arguments corresponding to conversion specifiers

**Return Value:**
- Number of characters written to standard output
- Negative value on error (following standard `printf` behavior)

### Basic Conversion Specifiers

| Specifier | Description | Example Input | Example Output |
|-----------|-------------|---------------|----------------|
| `%c` | Character | `ft_printf("%c", 'A')` | `A` |
| `%s` | String | `ft_printf("%s", "Hello")` | `Hello` |
| `%p` | Pointer | `ft_printf("%p", ptr)` | `0x7fff5b2c4a10` |
| `%d` | Signed decimal | `ft_printf("%d", -42)` | `-42` |
| `%i` | Signed integer | `ft_printf("%i", 42)` | `42` |
| `%u` | Unsigned decimal | `ft_printf("%u", 42U)` | `42` |
| `%x` | Hex (lowercase) | `ft_printf("%x", 255)` | `ff` |
| `%X` | Hex (uppercase) | `ft_printf("%X", 255)` | `FF` |
| `%%` | Literal percent | `ft_printf("%%")` | `%` |

### Advanced Formatting (Bonus)

**Flag combinations:**
```c
ft_printf("%-10d", 42);      // Left-justified: "42        "
ft_printf("%+d", 42);        // With sign: "+42"
ft_printf("% d", 42);        // Space prefix: " 42"
ft_printf("%#x", 255);       // Alternate form: "0xff"
ft_printf("%010d", 42);      // Zero-padded: "0000000042"
ft_printf("%+#10x", 255);    // Multiple flags: "    +0xff"
```

**Field width and precision:**
```c
ft_printf("%10s", "hello");     // Right-aligned: "     hello"
ft_printf("%-10s", "hello");    // Left-aligned: "hello     "
ft_printf("%.3s", "hello");     // Precision: "hel"
ft_printf("%10.3s", "hello");   // Width + precision: "       hel"
ft_printf("%08.2d", 42);        // Zero-pad + precision: "00000042"
```

## 📁 Project Structure

```
ft_printf/
├── Makefile                    # Build configuration for both versions
├── include/
│   └── ft_printf.h             # Mandatory version header
├── src/                        # Mandatory implementation
│   ├── ft_printf.c             # Main printf function
│   ├── check_printer.c         # Printer function dispatcher
│   ├── libft/                  # Custom utility functions
│   │   ├── ft_bzero.c          # Memory zeroing
│   │   ├── ft_calloc.c         # Memory allocation
│   │   ├── ft_free.c           # Memory deallocation helper
│   │   ├── ft_itoa.c           # Integer to string conversion
│   │   ├── ft_memset.c         # Memory setting
│   │   ├── ft_putchar_fd.c     # Character output
│   │   ├── ft_putstr_fd.c      # String output
│   │   ├── ft_strlen.c         # String length calculation
│   │   ├── ft_uintptrtob.c     # Pointer to binary string
│   │   ├── ft_uitoa.c          # Unsigned integer to string
│   │   └── ft_uitob.c          # Unsigned integer to binary
│   └── printers/               # Conversion specifier handlers
│       ├── c_printer.c         # Character printer
│       ├── di_printer.c        # Signed integer printer
│       ├── p_printer.c         # Pointer printer
│       ├── prct_printer.c      # Percent printer
│       ├── s_printer.c         # String printer
│       ├── u_printer.c         # Unsigned integer printer
│       ├── x_low_printer.c     # Lowercase hex printer
│       └── x_up_printer.c      # Uppercase hex printer
├── bonus/                      # Bonus implementation
│   ├── include_bonus/
│   │   └── ft_printf_bonus.h   # Bonus version header
│   └── src_bonus/              # Bonus source files
│       ├── ft_printf_bonus.c   # Enhanced printf function
│       ├── check_printer_bonus.c # Enhanced printer dispatcher
│       ├── parser_bonus.c      # Format string parser
│       ├── formaters/          # Formatting engines
│       │   ├── alternate_format_formatter_bonus.c    # # flag handler
│       │   ├── padding_formatter_bonus.c             # Width/padding formatter
│       │   ├── padding_formatter_helpers_bonus.c     # Padding utilities
│       │   ├── positive_space_formater_bonus.c       # Space flag handler
│       │   ├── positive_symbol_formater_bonus.c      # + flag handler
│       │   └── precission_formater_bonus.c           # Precision formatter
│       ├── libft/              # Extended utility functions
│       │   ├── ft_atoi_bonus.c         # String to integer
│       │   ├── ft_isdigit_bonus.c      # Digit checking
│       │   ├── ft_isspace_bonus.c      # Whitespace checking
│       │   ├── ft_strchr_bonus.c       # Character search
│       │   ├── ft_strdup_bonus.c       # String duplication
│       │   ├── ft_strjoin_bonus.c      # String concatenation
│       │   ├── ft_strlcat_bonus.c      # Safe string concatenation
│       │   ├── ft_strlcpy_bonus.c      # Safe string copying
│       │   └── [other libft functions]
│       └── printers/           # Enhanced printer functions
│           ├── c_printer_bonus.c       # Enhanced character printer
│           ├── di_printer_bonus.c      # Enhanced integer printer
│           ├── p_printer_bonus.c       # Enhanced pointer printer
│           ├── prct_printer_bonus.c    # Enhanced percent printer
│           ├── s_printer_bonus.c       # Enhanced string printer
│           ├── u_printer_bonus.c       # Enhanced unsigned printer
│           ├── x_low_printer_bonus.c   # Enhanced lowercase hex
│           └── x_up_printer_bonus.c    # Enhanced uppercase hex
├── build/                      # Mandatory build directory
│   └── libftprintf.a           # Static library
└── build_bonus/                # Bonus build directory
    └── libftprintf_bonus.a     # Bonus static library
```

## 🔧 Technical Implementation

### Mandatory Implementation Architecture

#### Core Function Dispatcher
The mandatory version uses a simple yet efficient function pointer system:

```c
typedef int (*t_printer)(va_list);

typedef struct s_printers_list {
    char        c;
    t_printer   printer;
} t_print_list;
```

**Dispatch Mechanism:**
1. Parse format string character by character
2. When `%` is encountered, check next character
3. Use `check_printer()` to find corresponding function
4. Call printer function with `va_list` argument
5. Accumulate returned character count

#### Memory Management
- **Stack-based Operations**: Minimal dynamic allocation in mandatory version
- **Direct Output**: Printers write directly to file descriptor 1 (stdout)
- **Return Counting**: Each printer returns number of characters written

### Bonus Implementation Architecture

#### Enhanced String-based Approach
The bonus version employs a more sophisticated string-building approach:

```c
typedef char *(*t_printer_fn)(va_list);

typedef struct s_printers {
    char            c;
    t_printer_fn    printer;
} t_printer;
```

**Advanced Processing Pipeline:**
1. **Format Parsing**: Extract flags, width, precision from format string
2. **String Generation**: Printers return formatted strings instead of direct output
3. **Format Application**: Apply padding, precision, and flags to generated strings
4. **Output Optimization**: Batch output operations for efficiency

#### Flag Processing System

**Flag Parsing Algorithm:**
```c
// Pseudocode for flag processing
parse_flags(format_string) {
    while (is_flag_character(*format)) {
        switch (*format) {
            case '-': set_left_justify_flag(); break;
            case '+': set_show_sign_flag(); break;
            case ' ': set_space_prefix_flag(); break;
            case '#': set_alternate_form_flag(); break;
            case '0': set_zero_padding_flag(); break;
        }
        format++;
    }
    parse_width_and_precision(format);
}
```

#### Memory Management Strategy
- **Dynamic Allocation**: String building requires careful memory management
- **Cleanup Chain**: Systematic deallocation of intermediate strings
- **Memory Pool**: Efficient allocation patterns for string operations
- **Leak Prevention**: Comprehensive cleanup on all code paths

### Conversion Algorithms

#### Integer Conversion (`ft_itoa`, `ft_uitoa`)
```c
// Handles signed and unsigned integer conversion
// Supports base-10 conversion with sign handling
// Optimized for performance with minimal allocations
char *ft_itoa(int n);
char *ft_uitoa(unsigned int n);
```

#### Hexadecimal Conversion (`ft_uitob`)
```c
// Converts unsigned integers to hexadecimal
// Supports both uppercase and lowercase output
// Efficient base-16 conversion algorithm
char *ft_uitob(unsigned int nbr, int uppercase);
```

#### Pointer Conversion (`ft_uintptrtob`)
```c
// Converts pointer addresses to hexadecimal strings
// Handles architecture-specific pointer sizes
// Adds "0x" prefix for standard format
char *ft_uintptrtob(uintptr_t nbr);
```

### Performance Optimizations

#### Function Pointer Tables
- **O(1) Lookup**: Direct access to printer functions
- **Cache Friendly**: Compact data structures
- **Minimal Branching**: Reduces conditional overhead

#### String Operations
- **Length Pre-calculation**: Avoid repeated `strlen` calls
- **Buffer Reuse**: Minimize allocation/deallocation cycles
- **Batch Operations**: Group output operations when possible

## 📋 Examples

### Basic Usage Examples

**Simple formatting:**
```c
#include "ft_printf.h"

int main(void) {
    int count;

    // Character and string output
    count = ft_printf("Hello, %s!\n", "World");
    printf("Characters printed: %d\n", count);  // Output: 14

    // Integer formatting
    ft_printf("Number: %d, Hex: %x, Uppercase: %X\n", 255, 255, 255);
    // Output: Number: 255, Hex: ff, Uppercase: FF

    // Pointer output
    int x = 42;
    ft_printf("Address of x: %p\n", &x);
    // Output: Address of x: 0x7fff5b2c4a10

    return 0;
}
```

### Advanced Formatting (Bonus)

**Flag combinations:**
```c
#include "ft_printf_bonus.h"

int main(void) {
    int num = 42;

    // Left justification
    ft_printf("|%-10d|\n", num);        // |42        |

    // Sign display
    ft_printf("|%+d|\n", num);          // |+42|
    ft_printf("|% d|\n", num);          // | 42|

    // Zero padding
    ft_printf("|%010d|\n", num);        // |0000000042|

    // Hexadecimal with alternate form
    ft_printf("|%#x|\n", num);          // |0x2a|
    ft_printf("|%#X|\n", num);          // |0X2A|

    // Complex combinations
    ft_printf("|%+#10x|\n", num);       // |    +0x2a|
    ft_printf("|%-+#10x|\n", num);      // |+0x2a     |

    return 0;
}
```

### Precision and Width Examples

**String precision:**
```c
ft_printf("|%.3s|\n", "Hello");         // |Hel|
ft_printf("|%10.3s|\n", "Hello");       // |       Hel|
ft_printf("|%-10.3s|\n", "Hello");      // |Hel       |
```

**Integer precision:**
```c
ft_printf("|%.5d|\n", 42);              // |00042|
ft_printf("|%10.5d|\n", 42);            // |     00042|
ft_printf("|%-10.5d|\n", 42);           // |00042     |
```

### Edge Cases and Special Handling

**NULL pointer handling:**
```c
char *str = NULL;
ft_printf("String: %s\n", str);         // String: (null)
```

**Zero and negative numbers:**
```c
ft_printf("%d\n", 0);                   // 0
ft_printf("%+d\n", 0);                  // +0
ft_printf("% d\n", 0);                  // 0
ft_printf("%d\n", -42);                 // -42
ft_printf("%u\n", -1);                  // 4294967295 (on 32-bit systems)
```

**Large numbers:**
```c
ft_printf("%d\n", INT_MAX);             // 2147483647
ft_printf("%d\n", INT_MIN);             // -2147483648
ft_printf("%u\n", UINT_MAX);            // 4294967295
```

## 🧪 Testing

### Manual Testing

**Basic functionality test:**
```c
#include "ft_printf.h"
#include <stdio.h>

int main(void) {
    int ft_ret, std_ret;

    // Compare outputs
    printf("=== Standard printf ===\n");
    std_ret = printf("Hello %s, number: %d\n", "World", 42);
    printf("Return value: %d\n", std_ret);

    printf("=== ft_printf ===\n");
    ft_ret = ft_printf("Hello %s, number: %d\n", "World", 42);
    ft_printf("Return value: %d\n", ft_ret);

    return 0;
}
```

### Comprehensive Test Suite

**Create a test file:**
```c
// test_ft_printf.c
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void test_characters(void) {
    printf("=== Character Tests ===\n");
    ft_printf("Char: %c\n", 'A');
    ft_printf("String: %s\n", "Hello World");
    ft_printf("NULL string: %s\n", (char *)NULL);
}

void test_integers(void) {
    printf("=== Integer Tests ===\n");
    ft_printf("Positive: %d\n", 42);
    ft_printf("Negative: %d\n", -42);
    ft_printf("Zero: %d\n", 0);
    ft_printf("INT_MAX: %d\n", INT_MAX);
    ft_printf("INT_MIN: %d\n", INT_MIN);
}

void test_unsigned(void) {
    printf("=== Unsigned Tests ===\n");
    ft_printf("Unsigned: %u\n", 42U);
    ft_printf("UINT_MAX: %u\n", UINT_MAX);
    ft_printf("Zero: %u\n", 0U);
}

void test_hexadecimal(void) {
    printf("=== Hexadecimal Tests ===\n");
    ft_printf("Lowercase: %x\n", 255);
    ft_printf("Uppercase: %X\n", 255);
    ft_printf("Zero: %x\n", 0);
    ft_printf("Large: %x\n", 0xDEADBEEF);
}

void test_pointers(void) {
    printf("=== Pointer Tests ===\n");
    int x = 42;
    ft_printf("Variable address: %p\n", &x);
    ft_printf("NULL pointer: %p\n", NULL);
    ft_printf("Function address: %p\n", &main);
}

int main(void) {
    test_characters();
    test_integers();
    test_unsigned();
    test_hexadecimal();
    test_pointers();

    printf("=== Mixed Format Test ===\n");
    ft_printf("Mixed: %c %s %d %u %x %X %p %%\n",
              'A', "test", -42, 42U, 255, 255, &main);

    return 0;
}
```

**Compile and run tests:**
```bash
# Test mandatory version
make
gcc -Wall -Wextra -Werror test_ft_printf.c -L./build -lftprintf -o test_mandatory
./test_mandatory

# Test bonus version
make bonus
gcc -Wall -Wextra -Werror test_ft_printf.c -L./build_bonus -lftprintf_bonus -o test_bonus
./test_bonus
```

### Performance Testing

**Benchmark comparison:**
```c
#include <time.h>
#include <stdio.h>
#include "ft_printf.h"

void benchmark_test(void) {
    clock_t start, end;
    int iterations = 100000;

    // Test standard printf
    start = clock();
    for (int i = 0; i < iterations; i++) {
        printf("Test %d: %s %c %x\n", i, "benchmark", 'A', 255);
    }
    end = clock();
    printf("Standard printf time: %f seconds\n",
           ((double)(end - start)) / CLOCKS_PER_SEC);

    // Test ft_printf
    start = clock();
    for (int i = 0; i < iterations; i++) {
        ft_printf("Test %d: %s %c %x\n", i, "benchmark", 'A', 255);
    }
    end = clock();
    printf("ft_printf time: %f seconds\n",
           ((double)(end - start)) / CLOCKS_PER_SEC);
}
```

### Memory Leak Testing

**Using Valgrind:**
```bash
# Compile with debug flags
gcc -g -Wall -Wextra -Werror test_ft_printf.c -L./build_bonus -lftprintf_bonus -o test_debug

# Run with Valgrind
valgrind --leak-check=full --show-leak-kinds=all ./test_debug
```

## 📋 Requirements

### System Requirements
- **OS**: Linux, macOS, or other POSIX-compliant system
- **RAM**: Minimum 128MB (more for large-scale testing)
- **Disk Space**: ~50MB for source and build files

### Compiler Requirements
- **GCC 7.0+** or **Clang 6.0+**
- **C99 Standard** support
- **POSIX.1-2008** compliance for system calls

### Library Dependencies
- **Standard C Library**: `stdlib.h`, `unistd.h`, `stdarg.h`
- **System Calls**: `write()`, `malloc()`, `free()`
- **No external dependencies**: Self-contained implementation

### Development Tools (Optional)
- **Make**: For build system (GNU Make 3.81+)
- **Valgrind**: For memory leak detection
- **GDB**: For debugging
- **Static Analysis Tools**: `cppcheck`, `clang-static-analyzer`

## 🏗️ Build System

The project uses a comprehensive Makefile with multiple targets:

```bash
# Mandatory version targets
make                # Build libftprintf.a
make clean          # Remove object files
make fclean         # Remove all generated files
make re             # Rebuild everything

# Bonus version targets
make bonus          # Build libftprintf_bonus.a
make bonus-clean    # Clean bonus objects
make bonus-fclean   # Clean bonus completely
make bonus-re       # Rebuild bonus

# Utility targets
make all            # Build both versions
make help           # Show available targets
```

### Compilation Flags
- **Required**: `-Wall -Wextra -Werror` (42 School norm compliance)
- **Linking**: `-lm` (math library, if needed)
- **Standard**: Implicit C99 support

### Custom Build Options
```bash
# Debug build with symbols
make DEBUG=1

# Verbose compilation
make VERBOSE=1

# Custom compiler
make CC=clang
```

## 🔍 42 School Norm Compliance

This project strictly adheres to the 42 School coding norm:

### Code Style Requirements
- **Function Length**: Maximum 25 lines per function
- **Line Length**: Maximum 80 characters per line
- **Function Parameters**: Maximum 4 parameters per function
- **Variable Declarations**: All variables declared at function start
- **Indentation**: Tabs for indentation, spaces for alignment
- **Naming Convention**: Snake_case for functions and variables

### Structural Requirements
- **Header Guards**: All headers protected with include guards
- **Function Prototypes**: All functions declared in headers
- **Static Functions**: Helper functions declared as static
- **Global Variables**: Minimized and properly justified
- **Memory Management**: No memory leaks, proper error handling

### Forbidden Functions
The implementation only uses allowed functions:
- **Allowed**: `write`, `malloc`, `free`, `va_start`, `va_arg`, `va_copy`, `va_end`
- **Forbidden**: `printf`, `sprintf`, any standard library printf variants

### File Organization
- **Makefile**: Proper targets (all, clean, fclean, re, bonus)
- **Directory Structure**: Logical separation of source files
- **Header Files**: Single header per implementation (mandatory/bonus)

## 🤝 Contributing

This project is part of the 42 School curriculum and is primarily for educational purposes. However, suggestions and improvements are welcome!

## 📜 License

This project is part of the 42 School curriculum. The code is available for educational purposes and portfolio demonstration.

### Disclaimer
This implementation is created for learning purposes and may not be suitable for production use. While it aims to replicate `printf` behavior accurately, it may have limitations compared to the full-featured standard library implementation.

---

### 👨‍💻 Author

**Pablo Martínez García**
- GitHub: [@PabloMzGa](https://github.com/PabloMzGa)
- 42 Intra: `pabmart2`
- School: 42 Málaga

---

*This project was completed as part of the 42 School curriculum - a innovative, project-based programming school with a peer-to-peer learning methodology*
