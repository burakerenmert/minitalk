/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buramert <buramert@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:17:58 by buramert          #+#    #+#             */
/*   Updated: 2024/10/16 23:03:58 by buramert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t			s_len;
	size_t			i;
	unsigned char	*str1;

	s_len = (ft_strlen(s1));
	i = 0;
	str1 = malloc(sizeof(char) * (s_len + 1));
	if (str1 == NULL)
		return (NULL);
	while (i <= s_len)
	{
		str1[i] = s1[i];
		i++;
	}
	return ((char *)str1);
}
