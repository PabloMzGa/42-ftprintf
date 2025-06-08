/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:26:58 by pabmart2          #+#    #+#             */
/*   Updated: 2025/06/09 00:05:45 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

/**
 * @typedef t_printer
 * @brief A function pointer type for functions that take a va_list argument
 *        and return a char pointer.
 *
 * This typedef defines a function pointer type named t_printer. Functions of
 * this type are expected to take a single argument of type va_list and return
 * a char pointer. This is typically used for functions that perform some kind
 * of formatted output or processing based on a variable argument list.
 *
 * @param va_list A variable argument list.
 * @return A char pointer containing the string representation that should be
 *          printed. The caller is responsible for freeing the allocated memory.
 */
typedef char		*(*t_printer_fn)(va_list);

/**
 * @struct s_printers_list
 * @brief Structure to map a character to its corresponding printer function.
 *
 * This structure is used to associate a specific character with a function
 * that handles the conversion and printing of that character type.
 *
 * @param c Character representing the type of conversion.
 *
 * @param printer Function pointer to the printer function that handles the
 *                conversion.
 */
typedef struct s_printers
{
	char			c;
	t_printer_fn	printer;
}					t_printer;

/**
 * @file ft_printf.c
 * @brief Custom implementation of the printf function.
 *
 * This function mimics the behavior of the standard printf function, allowing
 * formatted output to the standard output.
 *
 * @param str The format string containing the text to be written to stdout.
 *            It can optionally contain embedded format specifiers that will
 *            be replaced by the values specified in subsequent arguments.
 * @param ... The variable arguments to be formatted and printed according to
 *            the format specifiers in the format string.
 *
 * @return The total number of characters written to the standard output.
 *
 */
int					ft_printf(char const *str,
						...) __attribute__((format(printf, 1, 2)));

t_printer			check_printer(const char c);

char				*parser(char *flags, va_list args);

/****************************** PRINTERS **************************************/

/**
 * @brief Creates a character string from a variadic argument list.
 *
 * This function retrieves a character from the provided variadic argument
 * list and returns it as a string.
 *
 * @param arg The variadic argument list containing the character to convert.
 * @return A newly allocated string containing the character.
 *         The caller is responsible for freeing the allocated memory.
 */
char				*c_printer(va_list arg);

/**
 * @brief Creates a string from a variadic argument list.
 * @param arg The variadic argument list containing the string to process.
 *
 * This function retrieves a string from the provided variadic argument list,
 * and returns a copy of it or "(null)" if the string is NULL.
 *
 * @return A newly allocated string. The caller is responsible for freeing the
 *         allocated memory.
 */
char				*s_printer(va_list arg);

/**
 * @brief Creates a pointer address string in hexadecimal format.
 *
 * This function retrieves a pointer from the provided va_list, converts it
 * to a hexadecimal string representation prefixed with "0x".
 *
 * @param arg A va_list containing the pointer to be converted.
 * @return A newly allocated string containing the pointer representation.
 *         The caller is responsible for freeing the allocated memory.
 */
char				*p_printer(va_list arg);

/**
 * @brief Creates a string representation of an integer argument.
 *
 * This function retrieves an integer from the provided va_list,
 * and converts it to a string using ft_itoa.
 *
 * @param arg A va_list containing the integer to be converted.
 * @return A newly allocated string containing the integer representation.
 *         The caller is responsible for freeing the allocated memory.
 */
char				*di_printer(va_list arg);

/**
 * @brief Creates a string representation of an unsigned integer.
 *
 * This function retrieves an unsigned integer from the provided variable
 * argument list and converts it to a string using ft_uitoa.
 *
 * @param arg The variable argument list containing the unsigned integer
 *            to convert.
 * @return A newly allocated string containing the unsigned integer
 *         representation. The caller is responsible for freeing the allocated
 *         memory.
 */
char				*u_printer(va_list arg);

/**
 * @brief Creates a string representation of an unsigned integer in lowercase
 *        hexadecimal format.
 *
 * This function retrieves an unsigned integer from the provided va_list,
 * and converts it to a string in lowercase hexadecimal format.
 *
 * @param arg A va_list containing the unsigned integer to be converted.
 * @return A newly allocated string containing the hexadecimal representation.
 *         The caller is responsible for freeing the allocated memory.
 */
char				*x_low_printer(va_list arg);

/**
 * @brief Creates a string representation of an unsigned integer in uppercase
 *        hexadecimal format.
 *
 * This function retrieves an unsigned integer from the provided va_list,
 * and converts it to a string in uppercase hexadecimal format.
 *
 * @param arg A va_list containing the unsigned integer to be converted.
 * @return A newly allocated string containing the hexadecimal representation.
 *         The caller is responsible for freeing the allocated memory.
 */
char				*x_up_printer(va_list arg);

/**
 * @brief Creates a string containing a percent sign.
 *
 * This function creates a string containing a percent sign '%'.
 * @param arg: A va_list of arguments (unused in this function).
 * @return A newly allocated string containing "%".
 *         The caller is responsible for freeing the allocated memory.
 */
char				*prct_printer(va_list arg);

/*******************************LIBFT******************************************/

/**
 * @brief Converts a string to an integer.
 *
 * This function takes a string `nptr` and converts it to an integer. It skips
 * any leading whitespace characters and then checks for an optional sign
 * character ('-' or '+'). If a '-' sign is found, the resulting integer will
 * be negative. After that, it iterates through the string and converts each
 * digit character to its corresponding integer value. The function stops
 * converting when it encounters a non-digit character. The final result is
 * multiplied by the sign value and returned.
 *
 * @param nptr The string to be converted to an integer.
 * @return The converted integer value.
 */
int					ft_atoi(const char *nptr);


/**
 * Sets the first n bytes of the memory pointed to by s to zero.
 *
 * @param s Pointer to the memory to be zeroed.
 * @param n Number of bytes to be zeroed.
 */
void				ft_bzero(void *s, size_t n);

/**
 * @brief Allocates memory for an array of elements and initializes them to 0.
 *
 * This function allocates memory for an array of `nmemb` elements,
 * each of `size` bytes, and initializes all the allocated memory to 0.
 * The total size of the allocated memory is calculated as `nmemb * size`.
 *
 * @param nmemb The number of elements to allocate memory for.
 * @param size The size of each element in bytes.
 * @return On success, a pointer to the allocated memory is returned.
 *         If either `nmemb` or `size` is 0, or if the multiplication of
 *         `nmemb` and `size` exceeds `INT_MAX`, then`NULL` is returned.
 *
 * @note If memory allocation fails, errno is set to ENOMEM.
 */
void				*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Frees the memory pointed to by the given pointer and sets it to NULL.
 *
 * This function takes a double pointer to a memory location, frees the memory
 * it points to, and then sets the pointer to NULL to avoid dangling pointers,
 *
 * If the pointer is NULL, it does nothing.
 *
 * @param ptr A double pointer to the memory to be freed. The pointer itself
 *            must not be NULL, but the memory it points to can be NULL.
 *
 * @note It is the caller's responsibility to ensure that the pointer passed
 *       to this function was allocated dynamically (e.g., using malloc, calloc,
 *       or realloc).
 */
void				ft_free(void **ptr);

/**
 * Checks if the given character is numeric.
 *
 * @param c The character to be checked.
 * @return 1 if the character is numeric, 0 otherwise.
 */
int					ft_isdigit(int c);

/**
 * @brief Checks if a character is a whitespace character.
 *
 * This function determines if the given character is a whitespace character.
 * Whitespace characters include space (' '), horizontal tab ('\t'),
 * vertical tab ('\v'), newline ('\n'), carriage return ('\r'),
 * and form feed ('\f').
 *
 * @param c The character to check.
 * @return 1 if the character is a whitespace character, 0 otherwise.
 */
int					ft_isspace(char c);

/**
 * @brief Converts an integer to a null-terminated string.
 *
 * This function takes an integer as input and converts it to a string
 * representation. It handles special cases such as zero and the minimum
 * integer value.
 *
 * @param n The integer to be converted.
 * @return A pointer to the resulting null-terminated string. Returns NULL if
 *         memory allocation fails.
 */
char				*ft_itoa(int n);

/**
 * Sets the first n bytes of the memory area pointed to by s to the specified
 * value.
 *
 * @param s Pointer to the memory area to be filled.
 * @param c Value to be set. The value is passed as an int, but the function
 *          fills the memory area using the unsigned char conversion of this
 *          value.
 * @param n Number of bytes to be set to the value.
 * @return Pointer to the memory area s.
 */
void				*ft_memset(void *s, int c, size_t n);

/**
 * @brief Copies a block of memory from a source address to a destination
 * address.
 *
 * This function copies the values of `n` bytes from the memory area pointed
 * to by `src` to the memory area pointed to by `dest`. The memory areas must
 * not overlap.
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to be copied.
 * @return Pointer to the destination memory area (`dest`).
 */
void				*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Writes a character to the specified file descriptor.
 *
 * This function takes a character and a file descriptor as arguments and writes
 * the character to the given file descriptor.
 *
 * @param c The character to be written.
 * @param fd The file descriptor to which the character will be written.
 */
void				ft_putchar_fd(char c, int fd);

/**
 * @brief Writes a string to the given file descriptor.
 *
 * This function takes a string and a file descriptor as arguments and writes
 * the string to the specified file descriptor using the ft_putchar_fd function.
 *
 * @param s The string to be written.
 * @param fd The file descriptor to which the string will be written.
 */
void				ft_putstr_fd(char *s, int fd);

/**
 * @brief Searches for the first occurrence of a character in a string.
 *
 * This function searches for the first occurrence of the character 'c' in the
 * string 's'. If the character is found, a pointer to the first occurrence is
 * returned. If the character is not found and 'c' is the null terminator, a
 * pointer to the null terminator of 's' is returned. If the character is not
 * found, NULL is returned.
 *
 * @param s The string to be searched.
 * @param c The character to be found.
 * @return A pointer to the first occurrence of 'c' in 's', or NULL if 'c' is
 *         not found.
 */
char				*ft_strchr(const char *s, int c);

/**
 * @brief Duplicates a string.
 *
 * This function allocates sufficient memory for a copy of the string s,
 * does the copy, and returns a pointer to it. The memory allocated for the
 * new string is obtained with malloc, and can be freed with free.
 *
 * @param s The string to duplicate.
 * @return A pointer to the duplicated string, or NULL if insufficient memory
 *         was available.
 */
char				*ft_strdup(const char *s);

/**
 * @brief Concatenates two strings into a new string.
 *
 * This function takes two null-terminated strings, `s1` and `s2`, and
 * concatenates them into a newly allocated string. The new string is
 * dynamically allocated and must be freed by the caller.
 *
 * @param s1 The first string to concatenate.
 * @param s2 The second string to concatenate.
 * @return A pointer to the newly allocated string containing the
 * concatenated result of `s1` and `s2`, or NULL if memory allocation fails.
 */
char				*ft_strjoin(char const *s1, char const *s2);

/**
 * Appends the string pointed to by `src` to the end of the string pointed to
 * by `dst`. It will append at most `size - strlen(dst) - 1` characters,
 * null-terminating the result.
 *
 * @param dst The destination string.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * @return The total length of the string that would have been created if
 *         `size` was large enough. If the return value is greater than or
 *         equal to `size`, truncation occurred.
 */
size_t				ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Copies a string to a destination buffer with a specified size.
 *
 * This function copies the string pointed to by `src` to the buffer pointed
 * to by `dst`. The copy operation will stop when either the null-terminating
 * character of `src` is reached or when `size - 1` characters have been copied
 * to `dst`. The resulting string in `dst` will always be null-terminated.
 *
 * @param dst The destination buffer where the string will be copied to.
 * @param src The source string to be copied.
 * @param size The size of the destination buffer.
 * @return The length of the source string.
 */
size_t				ft_strlcpy(char *dst, const char *src, size_t size);


/**
 * Calculates the length of a null-terminated string.
 *
 * @param str The string to calculate the length of.
 * @return The length of the string, or 0 if the string is NULL.
 */
size_t				ft_strlen(const char *str);

/**
 * Converts an integer pointer to a string representation in a specified base.
 *
 * @param nbr The integer pointer to be converted.
 * @param base The base to be used for conversion. It should be a string
 * containing all the characters representing the digits of the base.
 */
char				*ft_uintptrtob(uintptr_t nbr, char *base);

/**
 * @brief Converts an unsigned integer to a null-terminated string.
 *
 * This function takes an unsigned integer and converts it to a string
 * representation. The resulting string is dynamically allocated and
 * must be freed by the caller.
 *
 * @param n The unsigned integer to convert.
 * @return A pointer to the newly allocated string representing the number,
 *         or NULL if memory allocation fails.
 */
char				*ft_uitoa(unsigned int n);

/**
 * Converts an unsigned integer to a string representation in a specified base.
 *
 * @param nbr The unsigned integer to convert.
 * @param base The base to use for the conversion. This should be a string
 *             containing the characters representing the digits of the base
 *             (e.g., "0123456789ABCDEF" for base 16).
 * @return A pointer to the newly allocated string containing the base
 *         representation of the number. The caller is responsible for freeing
 *         the allocated memory.
 */
char				*ft_uitob(unsigned int nbr, char *base);

/****************************** FORMATERS *************************************/

char				*set_padding(char *print, char *flags, t_printer printer);
char				*get_space_padding(char *digit_pos);
char				*get_zero_padding(char *print, char *zero_pos);

char				*set_precission(char *print, char *flags,
						t_printer printer);
char				*set_alternate_format(char *print, char *flags,
						t_printer printer);
char				*set_positive_space_format(char *print, char *flags,
						t_printer printer);
char				*set_positive_symbol_format(char *print, char *flags,
						t_printer printer);
#endif
