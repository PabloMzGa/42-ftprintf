/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 13:03:00 by pablo             #+#    #+#             */
/*   Updated: 2025/06/13 12:37:41 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*parser(char *flags, int flags_size, va_list args)
{
	t_printer	printer;

	char		*print;
	char		*formated;


	printer = check_printer(flags[flags_size - 1]);
	if (printer.printer == NULL)
		return (NULL);
	else if (printer.c == '%')
		return (printer.printer(args));
	print = printer.printer(args);
	print = set_precission(print, flags, printer);
	print = set_positive_symbol_format(print, flags, printer);
	print = set_positive_space_format(print, flags, printer);
	print = set_alternate_format(print, flags, printer);
	formated = set_padding(print, flags, printer);
	if (formated)
		return (formated);
	else
		return (print);
}
