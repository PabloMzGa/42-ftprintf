/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:57:48 by pabmart2          #+#    #+#             */
/*   Updated: 2025/06/13 13:21:52 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	di_printer(va_list arg)
{
	char	*str;
	size_t	len;

	str = ft_itoa(va_arg(arg, int));
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
