/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:59:18 by pabmart2          #+#    #+#             */
/*   Updated: 2025/09/10 21:11:04 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
 * g_valid_end_flags is a static constant array containing the valid conversion
 * specifier characters for the custom printf implementation. These specifiers
 * include:
 *   - 'c': character
 *   - 's': string
 *   - 'p': pointer
 *   - 'd': signed decimal integer
 *   - 'i': signed decimal integer
 *   - 'u': unsigned decimal integer
 *   - 'x': unsigned hexadecimal integer (lowercase)
 *   - 'X': unsigned hexadecimal integer (uppercase)
 * The array is null-terminated for easy iteration.
 */
static const char	g_valid_end_flags[] = {'c', 's', 'p', 'd', 'i', 'u', 'x',
	'X', 0};

/**
 * @brief Checks if the given character is a valid flag.
 *
 * This function iterates through the global string `g_valid_end_flags`
 * and compares each character with the provided `flag`. If a match is found,
 * it returns 1 (true), otherwise it returns 0 (false).
 *
 * @param flag The character to check for validity as a flag.
 *
 * @return 1 if the character is a valid flag, 0 otherwise.
 */
static char	is_valid_flag(char flag)
{
	int	size;

	size = ft_strlen(g_valid_end_flags) - 1;
	while (size >= 0)
	{
		if (flag == g_valid_end_flags[size])
			return (1);
		--size;
	}
	return (0);
}

/**
 * @brief Finds the end of the flags section in a format string.
 *
 * This function scans the input string `str` to locate the position where
 * a valid flag character appears, as determined by the `is_valid_flag`
 * function. If the first character is a '%' symbol, it returns the current
 * position. Otherwise, it advances the pointer until a valid flag is found or
 * the end of the string is reached.
 *
 * @param str Pointer to the format string to be scanned.
 *
 * @return Pointer to the position in the string where a valid flag is found,
 *         or the '%' character if it is the first character.
 */
static char	*get_flags_end(char *str)
{
	if (*str == '%')
		return (str);
	while (str && !is_valid_flag(*str))
		++str;
	return (str);
}

/**
 * @brief Extracts the flags substring from a format string.
 *
 * This function locates the end of the flags section in the given format string
 * using get_flags_end(), allocates memory for the flags substring, and copies
 * the flags characters into a newly allocated string.
 *
 * @param str The format string to extract flags from.
 * @return A newly allocated string containing the flags, or NULL on
 *         allocation failure.
 */
static char	*extract_flags(char const *str)
{
	char	*flags;
	char	*flag_end;
	size_t	flags_size;
	size_t	i;

	flag_end = get_flags_end((char *)str);
	flags_size = flag_end - str + 1;
	flags = calloc((flags_size + 1), sizeof(char));
	if (!flags)
		return (NULL);
	i = 0;
	while (i < flags_size)
	{
		flags[i] = str[i];
		++i;
	}
	return (flags);
}

/**
 * @brief Calls the printer after extracting and parsing format flags.
 *
 * Extracts formatting flags from the format string pointed to by `str`,
 * parses them, and calls the appropriate printer using the variable
 * argument list `args`. Advances the format string pointer past the
 * parsed flags and frees any allocated memory for the flags.
 *
 * @param str Pointer to the format string pointer. Advanced past flags.
 * @param args Variable argument list for the printer function.
 * @return Number of characters printed by the printer function.
 */
static int	call_printer(char **str, va_list args)
{
	char	*flags;
	int		size;
	int		flags_size;

	flags = extract_flags(*str);
	flags_size = ft_strlen(flags);
	size = parser(flags, flags_size, args);
	*str += flags_size;
	ft_free((void **)&flags);
	return (size);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		char_counter;

	char_counter = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			++char_counter;
			++str;
		}
		else if (*str == '%')
		{
			++str;
			char_counter += call_printer((char **)&str, args);
		}
	}
	va_end(args);
	return (char_counter);
}
