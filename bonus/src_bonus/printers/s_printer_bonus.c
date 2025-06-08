/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_printer_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:15:53 by pabmart2          #+#    #+#             */
/*   Updated: 2025/06/08 14:01:02 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*set_null(void)
{
	char	*result;

	result = ft_calloc(7, sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '(';
	result[1] = 'n';
	result[2] = 'u';
	result[3] = 'l';
	result[4] = 'l';
	result[5] = ')';
	result[6] = '\0';
	return (result);
}

char	*s_printer(va_list arg)
{
	char	*str;
	char	*result;
	size_t	len;
	size_t	i;

	str = (char *)va_arg(arg, int *);
	if (str)
	{
		len = ft_strlen(str);
		result = ft_calloc(len + 1, sizeof(char));
		if (!result)
			return (NULL);
		i = 0;
		while (i < len)
		{
			result[i] = str[i];
			i++;
		}
		result[len] = '\0';
		return (result);
	}
	else
		return (set_null());
}
