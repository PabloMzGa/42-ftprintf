/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:59:18 by pabmart2          #+#    #+#             */
/*   Updated: 2025/06/08 21:41:35 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static const char	g_valid_end_flags[] = {'c', 's', 'p', 'd', 'i', 'u', 'x',
	'X', 0};

static char	is_valid_flag(char flag)
{
	int	size;

	size = ft_strlen(g_valid_end_flags) - 1;
	while (size >= 0)
	{
		if (flag == g_valid_end_flags[size])
			return (1);
		--size;
	}
	return (0);
}

static char	*get_flags_end(char *str)
{
	if (*str == '%')
		return (str);
	while (str && !is_valid_flag(*str))
		++str;
	return (str);
}

static char	*extract_flags(char const *str)
{
	char	*flags;
	char	*flag_end;
	size_t	flags_size;
	size_t	i;

	flag_end = get_flags_end((char *)str);
	flags_size = flag_end - str + 1;
	flags = calloc((flags_size + 1), sizeof(char));
	if (!flags)
		return (NULL);
	i = 0;
	while (i < flags_size)
	{
		flags[i] = str[i];
		++i;
	}
	return (flags);
}

static int	call_printer(char **str, va_list args)
{
	char	*formated;
	char	*flags;
	int		formated_len;

	flags = extract_flags(*str);
	formated = parser(flags, args);
	ft_putstr_fd(formated, STDOUT_FILENO);
	*str += ft_strlen(flags);
	formated_len = ft_strlen(formated);
	if (*formated == '\0' && ft_strchr(flags, 'c'))
		formated_len = 1;
	ft_free((void **)&formated);
	ft_free((void **)&flags);
	return (formated_len);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		char_counter;

	char_counter = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			++char_counter;
		}
		else
		{
			++str;
			char_counter += call_printer((char **)&str, args);
		}
		if (*str)
			++str;
	}
	va_end(args);
	return (char_counter);
}
