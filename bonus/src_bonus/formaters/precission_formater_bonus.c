/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precission_formater_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:11:33 by pablo             #+#    #+#             */
/*   Updated: 2025/06/08 21:12:38 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*get_zeroes(char *print, char *n_pos)
{
	int		n_zeroes;
	int		i;
	char	*zeroes;
	int		n;

	n = ft_atoi(n_pos);
	if (n == 0 && ft_atoi(print) == 0)
		return (NULL);
	n_zeroes = n - ft_strlen(print);
	if (print[0] == '-' || print[0] == '+')
		n_zeroes++;
	if (n_zeroes <= 0)
		return (ft_strdup(""));
	zeroes = malloc(sizeof(char) * n_zeroes + 1);
	if (!zeroes)
		return (NULL);
	i = 0;
	while (i < n_zeroes)
	{
		zeroes[i] = '0';
		++i;
	}
	zeroes[n_zeroes] = '\0';
	return (zeroes);
}

char	*set_precission_negative(char *zeroes, char *print)
{
	char	*tmp;

	tmp = ft_strdup(print + 1);
	ft_free((void **)&print);
	print = tmp;
	tmp = zeroes;
	zeroes = ft_strjoin("-", zeroes);
	ft_free((void **)&tmp);
	tmp = ft_strjoin(zeroes, print);
	return (ft_free((void **)&zeroes), ft_free((void **)&print), tmp);
}

char	*set_num_precission(char *print, char *dot_pos)
{
	char	*zeroes;
	char	*tmp;

	zeroes = get_zeroes(print, dot_pos + 1);
	if (!zeroes)
		return (ft_free((void **)&print), ft_strdup("\0"));
	if (print[0] == '-')
		tmp = set_precission_negative(zeroes, print);
	else
	{
		tmp = ft_strjoin(zeroes, print);
		ft_free((void **)&zeroes);
		ft_free((void **)&print);
	}
	return (tmp);
}

char	*set_string_precission(char *print, char *dot_pos)
{
	int		print_len;
	int		max_len;
	char	*truncated;

	print_len = ft_strlen(print);
	max_len = ft_atoi(dot_pos + 1);
	if (max_len > print_len)
		max_len = print_len;
	if (max_len == 0)
		return (ft_free((void **)&print), ft_strdup(""));
	truncated = malloc(sizeof(char) * (max_len + 1));
	ft_strlcpy(truncated, print, max_len + 1);
	ft_free((void **)&print);
	return (truncated);
}

char	*set_precission(char *print, char *flags, t_printer printer)
{
	char	*dot_pos;
	char	*tmp;

	dot_pos = ft_strchr(flags, '.');
	if (dot_pos && (printer.c == 'd' || printer.c == 'i' || printer.c == 'u'
			|| printer.c == 'x' || printer.c == 'X'))
		tmp = set_num_precission(print, dot_pos);
	else if (dot_pos && printer.c == 's')
		tmp = set_string_precission(print, dot_pos);
	else
		tmp = print;
	return (tmp);
}
