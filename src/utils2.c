/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theodelgrange <theodelgrange@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:59:19 by theodelgran       #+#    #+#             */
/*   Updated: 2023/07/31 12:05:53 by theodelgran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write (fd, "\n", 1);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!res)
		return (0);
	while (s1[i])
		i++;
	while (j < i)
	{
		res[j] = s1[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	i = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	while (s[start + i] && i < len)
	{
		dest[i] = *(s + start + i);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_count(const char *str, char sep)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (str[index] && str[index] == sep)
		index++;
	while (str[index])
	{
		count++;
		while (str[index] && str[index] != sep)
			index++;
		while (str[index] && str[index] == sep)
			index++;
	}
	return (count);
}

static void	ft_tab(char const *s, char c, char **string)
{
	size_t	index;
	size_t	a;
	size_t	b;

	index = 0;
	b = 0;
	while (s[index])
	{
		a = 0;
		while (s[index] && s[index] == c)
			index++;
		while (s[index + a] && s[index + a] != c)
			a++;
		if (a)
		{
			string[b] = ft_substr(s, index, a);
			b++;
		}
		index = index + a;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**string;
	size_t	count;

	if (!s)
		return (0);
	count = ft_count(s, c);
	string = malloc(sizeof(char *) * (count + 1));
	if (!string)
		return (0);
	ft_tab(s, c, string);
	string[count] = 0;
	return (string);
}
