/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_formatter_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:31:56 by pablo             #+#    #+#             */
/*   Updated: 2025/06/18 20:00:55 by pablo            ###   ########.fr       */
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
		return (create_padding(print, digits_pos, '0', printer));
	else if (digits_pos != NULL && (((digits_pos != flags && *(digits_pos
						- 1) != '.')) || digits_pos == flags))
		return (create_padding(print, digits_pos, ' ', printer));
	else
		return (NULL);
}

char	*set_padding_negative(char *padding, char *print)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin("-", padding);
	result = ft_strjoin(tmp, print + 1);
	ft_free((void **)&tmp);
	return (result);
}

int	set_padding(char *print, char *flags, t_printer printer, char **formatted)
{
	char	*padding;
	int		size;

	padding = get_padding(flags, print, printer);
	if (padding)
	{
		if (padding[0] == '0' && print[0] == '-')
			*formatted = set_padding_negative(padding, print);
		else if (ft_strchr(flags, '-'))
			*formatted = ft_strjoin(print, padding);
		else
			*formatted = ft_strjoin(padding, print);
		if (printer.c == 'c' && print[0] == '\0')
			size = ft_strlen(*formatted) + 1;
		else
			size = ft_strlen(*formatted);
		return (ft_free((void **)&padding), ft_free((void **)&print), size);
	}
	*formatted = print;
	if (printer.c == 'c' && print[0] == '\0')
		size = ft_strlen(*formatted) + 1;
	else
		size = ft_strlen(*formatted);
	return (size);
}
