/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prct_printer_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:15:53 by pabmart2          #+#    #+#             */
/*   Updated: 2025/06/08 13:13:12 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*prct_printer(va_list arg)
{
	char	*result;

	(void)arg;
	result = ft_calloc(2, sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '%';
	result[1] = '\0';
	return (result);
}
