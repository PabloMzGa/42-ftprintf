/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:26:58 by pabmart2          #+#    #+#             */
/*   Updated: 2025/06/08 21:33:37 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft.h"
# include <stdarg.h>
# include <stddef.h>

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
