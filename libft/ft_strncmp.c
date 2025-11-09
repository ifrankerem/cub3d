/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:08:30 by iarslan           #+#    #+#             */
/*   Updated: 2024/10/27 02:52:37 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (unsigned char)s1[i] && (unsigned char)s2[i])
	{
		if (s1[i] != s2[i])
			return (((unsigned char)(s1[i])) - (((unsigned char)s2[i])));
		i++;
	}
	if (i < n)
		return (((unsigned char)(s1[i])) - (((unsigned char)s2[i])));
	return (0);
}
