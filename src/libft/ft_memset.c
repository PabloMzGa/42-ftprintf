/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:11:59 by pabmart2          #+#    #+#             */
/*   Updated: 2025/06/08 23:53:39 by pablo            ###   ########.fr       */
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
