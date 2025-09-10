/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_formatter_helpers_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:10:37 by pabmart2          #+#    #+#             */
/*   Updated: 2025/09/10 20:57:49 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*search_first_digit(char *flags)
{
	while (*flags)
	{
		if (ft_isdigit(*flags))
			return (flags);
		++flags;
	}
	return (NULL);
}

char	*create_padding(char *print, char *digit_pos, char padding_c,
		t_printer printer)
{
	char	*padding;
	int		n_padding;
	int		i;
	int		width;
	int		print_size;

	while (*digit_pos && (*digit_pos == '0' || !ft_isdigit(*digit_pos)))
		++digit_pos;
	width = ft_atoi(digit_pos);
	print_size = ft_strlen(print);
	if (print_size == 0 && printer.c == 'c')
		print_size = 1;
	n_padding = width - print_size;
	if (n_padding <= 0)
		return (ft_strdup(""));
	padding = malloc(sizeof(char) * n_padding + 1);
	if (!padding)
		return (NULL);
	i = 0;
	while (i < n_padding)
		padding[i++] = padding_c;
	padding[n_padding] = '\0';
	return (padding);
}
