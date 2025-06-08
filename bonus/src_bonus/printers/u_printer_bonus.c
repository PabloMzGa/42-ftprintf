/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_printer_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:57:48 by pabmart2          #+#    #+#             */
/*   Updated: 2025/06/08 13:13:09 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*u_printer(va_list arg)
{
	char			*str;
	unsigned int	un;

	un = (unsigned int)va_arg(arg, int);
	str = ft_uitoa(un);
	return (str);
}
