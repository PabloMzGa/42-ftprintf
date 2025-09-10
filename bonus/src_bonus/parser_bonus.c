/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 13:03:00 by pablo             #+#    #+#             */
/*   Updated: 2025/09/10 21:08:05 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/**
 * @brief Applies formatting flags to the output of a printer function.
 *
 * This function takes a set of formatting flags, a variable argument list,
 * and a printer structure. It generates the initial output using the printer,
 * then sequentially applies precision, positive symbol, positive space, and
 * alternate format modifications according to the provided flags.
 *
 * @param flags   A string containing formatting flags.
 * @param args    The variable argument list to be printed.
 * @param printer The printer structure containing the printing function.
 *
 * @return        A newly allocated string with all formatting applied.
 */
static char	*set_print(char *flags, va_list args,
		t_printer printer)
{
	char	*print;

	print = printer.printer(args);
	print = set_precission(print, flags, printer);
	print = set_positive_symbol_format(print, flags, printer);
	print = set_positive_space_format(print, flags, printer);
	print = set_alternate_format(print, flags, printer);
	return (print);
}

int	parser(char *flags, int flags_size, va_list args)
{
	t_printer	printer;
	char		*print;
	char		*formated;
	int			size;

	printer = check_printer(flags[flags_size - 1]);
	if (printer.printer == NULL)
		return (0);
	else if (printer.c == '%')
	{
		formated = printer.printer(args);
		size = 1;
	}
	else
	{
		print = set_print(flags, args, printer);
		size = set_padding(print, flags, printer, &formated);
		if (formated != NULL)
			ft_putstr_fd(formated, STDOUT_FILENO);
	}
	ft_free((void **)&formated);
	return (size);
}
