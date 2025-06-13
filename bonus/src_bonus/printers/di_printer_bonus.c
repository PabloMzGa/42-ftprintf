/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_printer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:57:48 by pabmart2          #+#    #+#             */
/*   Updated: 2025/06/13 12:17:28 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*di_printer(va_list arg)
{
	char	*str;

	str = ft_itoa(va_arg(arg, int));
	return (str);
}
