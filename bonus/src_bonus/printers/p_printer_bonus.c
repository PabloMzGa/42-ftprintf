/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_printer_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:19:38 by pabmart2          #+#    #+#             */
/*   Updated: 2025/06/08 21:41:44 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*set_nil(void)
{
	char	*result;

	result = ft_calloc(6, sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '(';
	result[1] = 'n';
	result[2] = 'i';
	result[3] = 'l';
	result[4] = ')';
	result[5] = '\0';
	return (result);
}

char	*p_printer(va_list arg)
{
	void	*p;
	char	*str;
	char	*tmp;

	p = va_arg(arg, void *);
	if (!p)
		return (set_nil());
	tmp = ft_uintptrtob((uintptr_t)p, "0123456789abcdef");
	str = ft_strjoin("0x", tmp);
	ft_free((void **)&tmp);
	return (str);
}
