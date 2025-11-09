/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:57:00 by iarslan           #+#    #+#             */
/*   Updated: 2024/10/27 17:31:11 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*final;
	size_t	i;
	size_t	j;
	size_t	strsize;

	strsize = ft_strlen(s);
	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (start >= strsize)
		return (ft_strdup(""));
	if (len > strsize - start)
		len = strsize - start;
	final = malloc(sizeof(char) * (len + 1));
	if (!final)
		return (NULL);
	while (i < len && s[i + start])
	{
		final[j] = s[i + start];
		j++;
		i++;
	}
	final[j] = '\0';
	return (final);
}
