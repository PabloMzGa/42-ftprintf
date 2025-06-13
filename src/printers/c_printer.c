/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_printer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:15:53 by pabmart2          #+#    #+#             */
/*   Updated: 2025/06/13 13:21:52 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_printer(va_list arg)
{
	char	c;

	c = (char)va_arg(arg, int);
	ft_putchar_fd(c, 1);
	return (1);
}
