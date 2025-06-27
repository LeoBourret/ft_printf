# 🖨️ ft_printf: A Robust C Printf Implementation

![Language: C](https://img.shields.io/badge/Language-C-blue.svg)
![Build: Makefile](https://img.shields.io/badge/Build-Makefile-green.svg)
![School: 42 Paris](https://img.shields.io/badge/School-42_Paris-orange.svg)
![Grade: 100/100](https://img.shields.io/badge/Grade-100/100-brightgreen.svg)

## ✨ Overview

`ft_printf` is a cornerstone and highly challenging project from 42 Paris, focused on **reimplementing the standard C library's `printf` function**. This project required building a custom library capable of accurately handling various data types, **essential formatting flags, and dynamic width/precision specifiers**, without relying on the original `printf`.

The core objective was to deeply understand and implement **variadic functions**, robust format string parsing, and precise formatted output generation. It was a crucial step in mastering C language intricacies and developing a well-structured, extensible, and highly compliant printing function.

## 🌟 Implemented Features & Conversions (Mandatory Part)

The custom `ft_printf` function accurately mimics the behavior of the original `printf` for the following mandatory conversions and their associated formatting options:

### **1. Supported Conversion Specifiers**

*   **`%c`**: Prints a single character.
*   **`%s`**: Prints a string (null-terminated).
*   **`%p`**: Prints `void *` pointer arguments in hexadecimal format.
*   **`%d`**: Prints a signed decimal integer.
*   **`%i`**: Prints an integer (same as `%d`).
*   **`%u`**: Prints an unsigned decimal integer.
*   **`%x`**: Prints a number in lowercase hexadecimal format.
*   **`%X`**: Prints a number in uppercase hexadecimal format.
*   **`%%`**: Prints a literal percent sign.

### **2. Supported Flags & Field Specifiers**

Implemented comprehensive handling for various combinations of the following flags and field specifications under all supported conversions:

*   **`-` (Minus Flag):** Left-justifies the output within the given field width.
*   **`0` (Zero Flag):** Pads the output with leading zeros (for numeric types) instead of spaces.
*   **`.` (Dot/Precision Flag):** Specifies precision for integers (`d`, `i`, `u`, `x`, `X`) and strings (`s`).
*   **`*` (Asterisk Flag):** Indicates that the field width is provided as an additional integer argument before the actual value to be printed.
*   **Minimum Field Width:** Specifies the minimum number of characters to be printed (can be a fixed number or dynamically provided via `*`).

### **Core Implementation Details**

*   **Variadic Arguments:** Utilizes `stdarg.h` macros (`va_start`, `va_arg`, `va_end`) to correctly process an indefinite number of arguments, including dynamic width/precision defined by `*`.
*   **Format String Parsing:** Implements a robust parser to identify conversion specifiers, flags, width (fixed or dynamic), and precision from the format string.
*   **Precise Output Generation:** Ensures accurate conversion, formatting, and printing of various data types according to their respective specifiers and flags.
*   **Modular & Extensible Code:** Designed with a modular structure, enabling a clear separation of concerns for each conversion and flag handling.

## 🛠️ Technologies Used

*   **Language:** C
*   **Build System:** Makefile
*   **Libraries:** Standard C Library, `stdarg.h` (for variadic functions).
*   **Memory Management:** Explicit `malloc` and `free` where necessary for string handling.

## 🚀 How to Use

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/yourusername/ft_printf.git
    cd ft_printf
    ```
2.  **Compile the library:**
    ```bash
    make
    ```
    This will generate `libftprintf.a`.
3.  **Include in your project:**
    To use `ft_printf` in your own C project, include the `ft_printf.h` header and link against `libftprintf.a` during compilation:
    ```bash
    gcc -Wall -Wextra -Werror your_program.c -L. -lftprintf -o your_program
    ```

## 🎓 Learning Outcomes

This project was pivotal in deepening my understanding of:

*   **Variadic Functions:** Mastered the concept and implementation of functions handling a variable number of arguments, including dynamic field width.
*   **Format String Parsing:** Developed robust logic for interpreting various flags, dynamic width, and precision specifiers.
*   **Formatted Output Generation:** Gained extensive experience in converting and formatting diverse data types into precise string representations.
*   **Modular Design:** Practiced designing extensible code for complex functionalities.
*   **C Programming Fundamentals:** Reinforced knowledge of pointers, type casting, and low-level C operations with strict attention to detail and edge cases.

---

### **Points clés de la correction pour le flag `*` :**

*   **Overview :** Ajout de "dynamic width/precision specifiers" dans l'introduction.
*   **Section "Supported Flags & Field Specifiers" :**
    *   Ajout du flag `*` avec sa description : "Indicates that the field width is provided as an additional integer argument before the actual value to be printed."
    *   Précisé pour "Minimum Field Width" qu'il peut être "dynamically provided via `*`".
*   **"Core Implementation Details" :** Mis à jour pour mentionner le traitement du "dynamic width/precision defined by `*`".
*   **"Learning Outcomes" :** Ajusté pour mentionner le "dynamic field width" dans l'apprentissage des fonctions variadiques.

Merci encore pour ta vigilance ! Le `README.md` est maintenant complet et fidèle à ton implémentation.
