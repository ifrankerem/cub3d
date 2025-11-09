/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:39:41 by iarslan           #+#    #+#             */
/*   Updated: 2024/10/27 18:00:24 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find(char *set, char s1)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*final;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (ft_find((char *)set, s1[start]) && s1[start])
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_find((char *)set, s1[end]) && end > start)
		end--;
	if (start > end)
		return (ft_strdup(""));
	final = ft_substr(s1, start, end - start + 1);
	if (!final)
		return (0);
	return (final);
}
