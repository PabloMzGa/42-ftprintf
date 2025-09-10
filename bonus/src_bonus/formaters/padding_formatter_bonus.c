/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_formatter_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:31:56 by pablo             #+#    #+#             */
/*   Updated: 2025/09/10 20:55:54 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/**
 * @brief Determines and creates the appropriate padding string for output.
 *
 * Analyzes flags and conversion char to decide whether to pad with zeros ('0')
 * or spaces (' '). Avoids zero-padding for 'c', 's', '%', and when '-' or '.'
 * flags are present.
 *
 * @param flags   String with formatting flags ('0', '-', '.', etc.).
 * @param print   String to be printed, used for padding length.
 * @param printer t_printer struct with formatting info, including conversion
 *                char.
 *
 * @return Newly allocated padding string, or NULL if no padding is needed.
 */
static char	*get_padding(char *flags, char *print, t_printer printer)
{
	char	*digits_pos;

	digits_pos = search_first_digit(flags);
	if (digits_pos != NULL && *digits_pos == '0' && printer.c != 'c'
		&& printer.c != 's' && printer.c != '%' && !ft_strchr(flags, '-')
		&& !ft_strchr(flags, '.'))
		return (create_padding(print, digits_pos, '0', printer));
	else if (digits_pos != NULL && (((digits_pos != flags && *(digits_pos
						- 1) != '.')) || digits_pos == flags))
		return (create_padding(print, digits_pos, ' ', printer));
	else
		return (NULL);
}

/**
 * Sets padding for a negative number by prepending a minus sign to the
 * padding, then appending the rest of the number (excluding the original
 * minus sign).
 *
 * @param padding  String containing the padding to be applied.
 * @param print    String representation of the number, starting with '-'.
 *
 * @return         Newly allocated string with minus sign, padding, and
 *                 number (without its original minus sign).
 */
static char	*set_padding_negative(char *padding, char *print)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin("-", padding);
	result = ft_strjoin(tmp, print + 1);
	ft_free((void **)&tmp);
	return (result);
}

/**
 * @brief Sets padding for a character according to formatting flags.
 *
 * Handles padding logic for printing a single character with optional
 * left or right alignment, based on flags. Generates padding, prints
 * character and padding in correct order, frees both padding and print,
 * and returns total printed size.
 *
 * @param print      Pointer to string with character to print (freed).
 * @param flags      Pointer to string with formatting flags (e.g., '-').
 * @param printer    Structure with printer configuration.
 * @param formatted  Pointer to string pointer for formatted result
 *                   (set to NULL).
 *
 * @return Total number of characters printed (character + padding).
 */
static int	set_c_padding(char *print, char *flags, t_printer printer,
		char **formatted)
{
	char	*padding;
	int		size;

	*formatted = NULL;
	padding = get_padding(flags, print, printer);
	if (ft_strchr(flags, '-'))
	{
		ft_putchar_fd(print[0], 1);
		ft_putstr_fd(padding, 1);
	}
	else
	{
		ft_putstr_fd(padding, 1);
		ft_putchar_fd(print[0], 1);
	}
	size = ft_strlen(padding) + 1;
	ft_free((void **)&padding);
	return (ft_free((void **)&print), size);
}

int	set_padding(char *print, char *flags, t_printer printer, char **formatted)
{
	char	*padding;
	int		size;

	if (printer.c == 'c')
		return (set_c_padding(print, flags, printer, formatted));
	padding = get_padding(flags, print, printer);
	if (padding)
	{
		if (padding[0] == '0' && print[0] == '-')
			*formatted = set_padding_negative(padding, print);
		else if (ft_strchr(flags, '-'))
			*formatted = ft_strjoin(print, padding);
		else
			*formatted = ft_strjoin(padding, print);
		size = ft_strlen(*formatted);
		return (ft_free((void **)&padding), ft_free((void **)&print), size);
	}
	*formatted = print;
	size = ft_strlen(*formatted);
	return (size);
}
