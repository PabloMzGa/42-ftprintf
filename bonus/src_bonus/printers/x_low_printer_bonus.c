/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_low_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:08:11 by pabmart2          #+#    #+#             */
/*   Updated: 2025/03/29 16:35:51 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*x_low_printer(va_list arg)
{
	char			*str;
	unsigned int	un;

	un = (unsigned int)va_arg(arg, int);
	str = ft_uitob(un, "0123456789abcdef");
	return (str);
}
