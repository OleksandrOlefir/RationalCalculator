# 📘 Rational Calculator

## 🔧 How to Build and Run the Project

```bash
mkdir build && cd build
cmake ..
make
./bin/teletactica
./tests/unit_tests
```

## 📁 Directory Structure with File Purposes

| Path             | Purpose                                      |
|------------------|----------------------------------------------|
| `src/`           | Source files for main logic                  |
| `include/`       | Header files                                 |
| `tests/`         | GoogleTest unit tests                        |
| `main.cpp`       | CLI interface for the calculator             |
| `CMakeLists.txt` | CMake build system configuration             |

## 🛠️ Build Instructions

- **Dependencies**:
  - CMake ≥ 3.14
  - C++17-compliant compiler
  - GoogleTest (automatically linked)

- **Steps**:
  1. Clone repository
  2. Run `cmake ..`
  3. Run `make`
  4. Execute binaries from `bin/` and `tests/` folders

## 📋 Requirements and Implementation Details

The project implements a rational number calculator:
- Operations: Addition, Subtraction, Multiplication, Division
- Input: Two rational numbers via CLI
- Output: Simplified result (in rational form)
- Fully cross-platform but targeted at **Linux**

## 🧠 Techniques Used and Why the Solution Works

| Aspect         | Description                                                                 |
|----------------|-----------------------------------------------------------------------------|
| **Correctness**     | Arithmetic is implemented using common denominators and simplification |
| **Performance**     | Minimal heap usage, no dynamic allocations                             |
| **Reliability**     | Invalid input is handled gracefully                                     |
| **Portability**     | Cross-platform via CMake + modern C++17                                |
| **Maintainability** | SOLID principles + KISS + DRY                                           |

## ⚙️ Techniques Used for Optimization

- No heap allocation (stack-only structures)
- Integer arithmetic only (no floating-point)
- Reduced code repetition via helper functions
- Reuse of move semantics to avoid unnecessary copies

## ✅ Unit Testing

**How to Build and Run Tests**:
```bash
cd build
ctest
```

**Tested Operations**:
- `Addition`, `Subtraction`, `Multiplication`, `Division`
- Exception safety for invalid denominator (0)
- Edge cases (e.g. zero numerators)
- `EXPECT_NO_THROW` and `EXPECT_THROW` cases

Test file: `tests/test_teletactica.cpp`

## 🔐 Quality and Security Requirements

The project is built following strict modern C++ safety and quality guidelines:

1. **Rule of Five/Six** – Implemented copy/move constructors and assignment operators.
2. **RAII (Resource Acquisition Is Initialization)** – All resources (e.g., integer members) managed safely.
3. **SOLID** – Single responsibility (Rational class does math only), clean interface separation.
4. **MISRA C++** – Code structure designed to comply with MISRA principles (e.g. no undefined behavior, predictable operations).
5. **C++ Core Guidelines** – Followed best practices like avoiding raw pointers and ensuring strong type safety.
6. **CERT C++ Secure Coding** – No undefined behavior, arithmetic overflow is avoided, constructors do not throw exceptions.
7. **Virtual Destructors** – Present for extensibility, even though not strictly needed now.
8. **`override` / `final`** – Used where applicable (future extensibility).
9. **`noexcept`** – Used on methods that are guaranteed not to throw.
10. **`const` correctness** – All getter methods and immutable logic are marked `const`.
11. **`explicit`** – Used in constructors to avoid implicit conversions.
12. **`nullptr`** – Used over `NULL` or `0`.
13. **KISS** – Code is minimalistic, easy to understand.
14. **Input Validation** – All user input validated (e.g., zero denominators).
15. **No Exceptions in Constructors** – Input errors are printed instead of throwing inside constructors.
16. **DRY (Don’t Repeat Yourself)** – Code reuse via utility and logic isolation.
17. **Target platform** – Primary development and testing on Linux.
18. **CMake-based build system** – Easy to configure, build, and extend.
19. **README in English** – Clear documentation for external contributors.
20. **Modern C++17** – Features like `noexcept`, `explicit`, move semantics used.
21. **No raw pointers** – Not used anywhere.
22. **All actions are commented** – Each method and logic block has an English comment.

## ✅ Final Code Summary

This is a lightweight, safe, and extendable CLI calculator using rational arithmetic. Carefully tested and structured using modern C++ design and build practices, it’s easy to maintain, adapt, and expand.

## 🧩 Conclusion

This project is ideal as a clean technical demonstration of modern C++ practices, showcasing quality, correctness, and secure design with full unit test coverage and user-oriented CLI.