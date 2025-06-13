/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_formatter_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:31:56 by pablo             #+#    #+#             */
/*   Updated: 2025/06/13 13:04:52 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*search_first_digit(char *flags)
{
	while (*flags)
	{
		if (ft_isdigit(*flags))
			return (flags);
		++flags;
	}
	return (NULL);
}

char	*create_padding(char *print, char *digit_pos, char padding_c)
{
	char	*padding;
	int		n_padding;
	int		i;
	int		width;

	while (*digit_pos && (*digit_pos == '0' || !ft_isdigit(*digit_pos)))
		++digit_pos;
	width = ft_atoi(digit_pos);
	n_padding = width - ft_strlen(print);
	if (n_padding <= 0)
		return (ft_strdup(""));
	padding = malloc(sizeof(char) * n_padding + 1);
	if (!padding)
		return (NULL);
	i = 0;
	while (i < n_padding)
	{
		padding[i] = padding_c;
		++i;
	}
	padding[n_padding] = '\0';
	return (padding);
}

static char	*get_padding(char *flags, char *print, t_printer printer)
{
	char	*digits_pos;

	digits_pos = search_first_digit(flags);
	if (digits_pos != NULL && *digits_pos == '0' && printer.c != 'c'
		&& printer.c != 's' && printer.c != '%' && !ft_strchr(flags, '-')
		&& !ft_strchr(flags, '.'))
		return (create_padding(print, digits_pos, '0'));
	else if (digits_pos != NULL && (((digits_pos != flags && *(digits_pos
						- 1) != '.')) || digits_pos == flags))
		return (create_padding(print, digits_pos, ' '));
	else
		return (NULL);
}

char	*set_padding_negative(char *padding, char *print)
{
	char	*tmp;

	tmp = ft_strdup(print + 1);
	ft_free((void **)&print);
	print = tmp;
	tmp = padding;
	padding = ft_strjoin("-", padding);
	ft_free((void **)&tmp);
	tmp = ft_strjoin(padding, print);
	return (ft_free((void **)&padding), ft_free((void **)&print), tmp);
}

char	*set_padding(char *print, char *flags, t_printer printer)
{
	char	*padding;
	char	*tmp;

	padding = get_padding(flags, print, printer);
	if (padding)
	{
		if (padding[0] == '0')
		{
			if (print[0] == '-')
				return (set_padding_negative(padding, print));
		}
		if (ft_strchr(flags, '-'))
			tmp = ft_strjoin(print, padding);
		else
			tmp = ft_strjoin(padding, print);
		return (ft_free((void **)&padding), ft_free((void **)&print), tmp);
	}
	return (NULL);
}
