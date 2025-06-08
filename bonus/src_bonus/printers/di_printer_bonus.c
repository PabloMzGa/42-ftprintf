/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_printer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:57:48 by pabmart2          #+#    #+#             */
/*   Updated: 2025/06/08 13:13:09 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*di_printer(va_list arg)
{
	char	*str;

	str = ft_itoa(va_arg(arg, int));
	return (str);
}
