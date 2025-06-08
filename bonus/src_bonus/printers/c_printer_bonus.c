/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_printer_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:15:53 by pabmart2          #+#    #+#             */
/*   Updated: 2025/06/08 18:47:33 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*c_printer(va_list arg)
{
	char	c;
	char	*result;

	c = (char)va_arg(arg, int);
	result = ft_calloc(2, sizeof(char));
	if (!result)
		return (NULL);
	result[0] = c;
	result[1] = '\0';
	return (result);
}
