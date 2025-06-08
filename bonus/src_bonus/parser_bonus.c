/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 13:03:00 by pablo             #+#    #+#             */
/*   Updated: 2025/06/08 21:33:57 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*parser(char *flags, va_list args)
{
	t_printer	printer;
	size_t		flags_size;
	char		*print;
	char		*formated;

	flags_size = ft_strlen(flags);
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
