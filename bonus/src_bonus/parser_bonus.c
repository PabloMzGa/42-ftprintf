/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 13:03:00 by pablo             #+#    #+#             */
/*   Updated: 2025/06/18 19:22:08 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
		print = printer.printer(args);
		print = set_precission(print, flags, printer);
		print = set_positive_symbol_format(print, flags, printer);
		print = set_positive_space_format(print, flags, printer);
		print = set_alternate_format(print, flags, printer);
		size = set_padding(print, flags, printer, &formated);
		ft_putstr_fd(formated, STDOUT_FILENO);
	}
	ft_free((void **)&formated);
	return (size);
}
