#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024

/* FLAGS */
enum flags {
	F_MINUS = 1,
	F_PLUS = 2,
	F_ZERO = 4,
	F_HASH = 8,
	F_SPACE = 16
};

/* SIZES */
enum sizes {
	S_LONG = 2,
	S_SHORT = 1
};

/**
 * struct format_specifier - Struct to hold format specifier and its handler function
 *
 * @specifier: The format specifier
 * @handler: The function pointer to the handler function for this specifier
 */
struct format_specifier {
	char specifier;
	int (*handler)(va_list, char[], int, int, int, int);
};

typedef struct format_specifier format_specifier_t;

/* Functions to print characters and strings */
int print_char(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list args, char buffer[], int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_hexa_upper(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_pointer(va_list args, char buffer[], int flags, int width, int precision, int size);

/* Function to print non-printable characters */
int print_non_printable(va_list args, char buffer[], int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list args);
int get_precision(const char *format, int *i, va_list args);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
		int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
		int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
		char buffer[],
		int flags, int width, int precision, int size);

/* UTILS */
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
