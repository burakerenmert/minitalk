/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buramert <buramert@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 23:29:01 by buramert          #+#    #+#             */
/*   Updated: 2024/10/18 16:57:34 by buramert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			len_s;
	size_t			i;
	unsigned char	*str;

	i = 0;
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if ((start + len) > len_s)
		len = (len_s - start);
	str = malloc(sizeof(char) * (len) + 1);
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return ((char *)str);
}
