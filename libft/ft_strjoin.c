/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:35:35 by chtan             #+#    #+#             */
/*   Updated: 2024/07/24 13:11:25 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static char	*ft_strcpy(char *dest, char *src)
// {
// 	size_t	i;

// 	i = 0;
// 	while (*(src + i++))
// 		*(dest + i - 1) = *(src + i - 1);
// 	*(dest + i - 1) = '\0';
// 	return (dest);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	len;
// 	size_t	i;
// 	size_t	j;
// 	char	*result;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	i = ft_strlen(s1);
// 	j = ft_strlen(s2);
// 	len = i + j + 1;
// 	result = (char *)malloc (len);
// 	if (!result)
// 		return (NULL);
// 	ft_strcpy(result, (char *)s1);
// 	ft_strcpy(result + i, (char *)s2);
// 	return (result);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *) malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s1_len);
	ft_memcpy(str + s1_len, s2, s2_len);
	str[s1_len + s2_len] = '\0';
	free(s1);
	return (str);
}
