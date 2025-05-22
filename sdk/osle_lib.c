#include "osle_lib.h"

void print(const char* str) {
    // Print a string to the screen.
    // The string must be null-terminated.
    // The function will stop printing when it reaches the null terminator.
    // The string is stored in the data segment, so it must be in the format
    // "string" or 'string'.
    // The function will not check for buffer overflows, so make sure the string
    // is not too long.
    asm volatile (
        "mov di, %0\n"
        "int %1\n"
        :
        : "r"(str), "i"(INT_RETURN)
    );
}

void println(const char* str) {
    // Print a string to the screen and add a new line at the end.
    // The string must be null-terminated.
    // The function will stop printing when it reaches the null terminator.
    // The string is stored in the data segment, so it must be in the format
    // "string" or 'string'.
    print(str);
    print("\n");
}

void print_hex(u32 num) {
    // Print a number in hexadecimal format.
    // The number is stored in the data segment, so it must be in the format
    // "0x00000000".
    // The function will not check for buffer overflows, so make sure the number
    // is not too long.
    asm volatile (
        "mov eax, %0\n"
        "int %1\n"
        :
        : "r"(num), "i"(INT_RETURN)
    );
}

u32 string_lenght(const char* str) {
    // Returns the length of a string.
    // The string must be null-terminated.
    // The function will stop counting when it reaches the null terminator.
    // The string is stored in the data segment, so it must be in the format
    // "string" or 'string'.
    u32 len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void string_copy(char* dest, const char* src) {
    // Copies a string from src to dest.
    // The string must be null-terminated.
    // The function will stop copying when it reaches the null terminator.
    // The string is stored in the data segment, so it must be in the format
    // "string" or 'string'.
    while ((*dest++ = *src++) != '\0');
}