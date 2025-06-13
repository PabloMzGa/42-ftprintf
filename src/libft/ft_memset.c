/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:11:59 by pabmart2          #+#    #+#             */
/*   Updated: 2025/06/13 13:11:54 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*temp_s;
	char	byte;

	temp_s = (char *)s;
	byte = (char)c;
	while (n > 0)
	{
		*temp_s = byte;
		--n;
		++temp_s;
	}
	return (s);
}
