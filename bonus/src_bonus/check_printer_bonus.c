/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_printer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:42:26 by pabmart2          #+#    #+#             */
/*   Updated: 2025/06/08 15:24:04 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/**
 * @brief This file defines an array of structures that map format specifiers
 * to their corresponding printer functions.
 *
 * The array `g_print_list` contains elements of type `t_print_list`, each of
 * which associates a character format specifier (such as 'c', 's', 'p', etc.)
 * with a function pointer that handles the printing of that specific type.
 *
 * The array is terminated with an element containing a null character and a
 * NULL function pointer.
 *
 * Format specifiers and their corresponding printer functions:
 * - 'c': c_printer
 * - 's': s_printer
 * - 'p': p_printer
 * - 'd': d_printer
 * - 'u': u_printer
 * - 'x': x_low_printer
 * - 'X': x_up_printer
 * - '%': prct_printer
 */
static const t_printer	g_print_list[] = {{'c', c_printer},
{'s', s_printer}, {'p', p_printer}, {'d', di_printer}, {'i', di_printer},
{'u', u_printer}, {'x', x_low_printer}, {'X', x_up_printer},
{'%', prct_printer}, {0, NULL}};

t_printer	check_printer(const char c)
{
	int	i;

	i = 0;
	while (g_print_list[i].c)
	{
		if (g_print_list[i].c == c)
			return (g_print_list[i]);
		++i;
	}
	return (g_print_list[i]);
}
