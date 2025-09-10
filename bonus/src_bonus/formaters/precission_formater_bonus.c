/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precission_formater_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:11:33 by pablo             #+#    #+#             */
/*   Updated: 2025/09/10 21:05:04 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/**
 * @brief Generates a string of zero characters for numeric formatting.
 *
 * Calculates the number of leading zeroes needed to pad the number in
 * print to reach the desired length specified by n_pos. Handles sign
 * characters ('-' or '+') by adjusting the zero count. If the number
 * is zero and the precision is zero, returns NULL. If no zeroes are
 * needed, returns an empty string.
 *
 * @param print The string representation of the number to be formatted.
 * @param n_pos The string representation of the desired total length
 *              (precision).
 *
 * @return A newly allocated string containing the required number of
 *         zeroes, or NULL on allocation failure or if both number and
 *         precision are zero.
 */
static char	*get_zeroes(char *print, char *n_pos)
{
	int		n_zeroes;
	int		i;
	char	*zeroes;
	int		n;

	n = ft_atoi(n_pos);
	if (n == 0 && ft_atoi(print) == 0)
		return (NULL);
	n_zeroes = n - ft_strlen(print);
	if (print[0] == '-' || print[0] == '+')
		n_zeroes++;
	if (n_zeroes <= 0)
		return (ft_strdup(""));
	zeroes = malloc(sizeof(char) * n_zeroes + 1);
	if (!zeroes)
		return (NULL);
	i = 0;
	while (i < n_zeroes)
	{
		zeroes[i] = '0';
		++i;
	}
	zeroes[n_zeroes] = '\0';
	return (zeroes);
}

/**
 * @brief Formats a negative number string with leading zeroes and a minus sign.
 *
 * Pads a negative number string with zeroes and a minus sign.
 * Removes the minus sign from the number, prepends it to the zeroes,
 * and concatenates with the number. Frees intermediate strings.
 *
 * @param zeroes Zeroes to pad the number.
 * @param print  Negative number string (starts with '-').
 *
 * @return       Newly allocated string "-<zeroes><number>", or NULL on error.
 */
static char	*set_precission_negative(char *zeroes, char *print)
{
	char	*tmp;

	tmp = ft_strdup(print + 1);
	ft_free((void **)&print);
	print = tmp;
	tmp = zeroes;
	zeroes = ft_strjoin("-", zeroes);
	ft_free((void **)&tmp);
	tmp = ft_strjoin(zeroes, print);
	return (ft_free((void **)&zeroes), ft_free((void **)&print), tmp);
}

/**
 * @brief Sets numeric precision for a formatted string based on the
 * precision specifier.
 *
 * Adjusts the numeric string `print` according to the precision at
 * `dot_pos`. Prepends zeroes if needed to meet precision. Handles
 * negative numbers and sign.
 *
 * @param print    String representation of the number to format. May be
 *                 freed inside the function.
 * @param dot_pos  Pointer to the '.' in the format string.
 *
 * @return         Newly allocated string with precision applied, or
 *                 empty string on allocation failure.
 */
static char	*set_num_precission(char *print, char *dot_pos)
{
	char	*zeroes;
	char	*tmp;

	zeroes = get_zeroes(print, dot_pos + 1);
	if (!zeroes)
		return (ft_free((void **)&print), ft_strdup("\0"));
	if (print[0] == '-')
		tmp = set_precission_negative(zeroes, print);
	else
	{
		tmp = ft_strjoin(zeroes, print);
		ft_free((void **)&zeroes);
		ft_free((void **)&print);
	}
	return (tmp);
}

/**
 * @brief Truncates a string to a specified max length based on precision.
 *
 * This function takes a string and a pointer to the '.' in a format string.
 * It parses the precision value after the dot, and truncates the input string
 * to at most that many characters. If precision is zero, it frees the input
 * string and returns an empty string.
 *
 * @param print   The input string to be truncated. Freed inside the function.
 * @param dot_pos Pointer to the '.' in the format string; precision is read
 *                here.
 * @return A newly allocated string truncated to the precision, or empty if z
 *         ero.
 */
static char	*set_string_precission(char *print, char *dot_pos)
{
	int		print_len;
	int		max_len;
	char	*truncated;

	print_len = ft_strlen(print);
	max_len = ft_atoi(dot_pos + 1);
	if (max_len > print_len)
		max_len = print_len;
	if (max_len == 0)
		return (ft_free((void **)&print), ft_strdup(""));
	truncated = malloc(sizeof(char) * (max_len + 1));
	ft_strlcpy(truncated, print, max_len + 1);
	ft_free((void **)&print);
	return (truncated);
}

char	*set_precission(char *print, char *flags, t_printer printer)
{
	char	*dot_pos;
	char	*tmp;

	dot_pos = ft_strchr(flags, '.');
	if (dot_pos && (printer.c == 'd' || printer.c == 'i' || printer.c == 'u'
			|| printer.c == 'x' || printer.c == 'X'))
		tmp = set_num_precission(print, dot_pos);
	else if (dot_pos && printer.c == 's')
		tmp = set_string_precission(print, dot_pos);
	else
		tmp = print;
	return (tmp);
}
