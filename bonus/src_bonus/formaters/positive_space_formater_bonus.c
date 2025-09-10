/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positive_space_formater_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 21:16:28 by pablo             #+#    #+#             */
/*   Updated: 2025/09/10 20:59:33 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*set_positive_space_format(char *print, char *flags, t_printer printer)
{
	char	*joined;

	if (!(printer.c == 'd' || printer.c == 'i' || printer.c == 'p')
		|| !ft_strchr(flags, ' ') || print[0] == '-' || print[0] == '+')
		return (print);
	joined = ft_strjoin(" ", print);
	ft_free((void **)&print);
	return (joined);
}
