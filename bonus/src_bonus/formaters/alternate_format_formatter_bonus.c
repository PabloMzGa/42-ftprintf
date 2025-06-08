/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alternate_format_formatter_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:31:42 by pablo             #+#    #+#             */
/*   Updated: 2025/06/08 21:27:37 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*set_alternate_format(char *print, char *flags, t_printer printer)
{
	char	*joined;

	if (!(printer.c == 'x' || printer.c == 'X') || !ft_strchr(flags, '#')
		|| (ft_strlen(print) == 1 && print[0] == '0') || print[0] == '\0')
		return (print);
	else if (printer.c == 'x')
	{
		joined = ft_strjoin("0x", print);
		ft_free((void **)&print);
		return (joined);
	}
	else if (printer.c == 'X')
	{
		joined = ft_strjoin("0X", print);
		ft_free((void **)&print);
		return (joined);
	}
}
