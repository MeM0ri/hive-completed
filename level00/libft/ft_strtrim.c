/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:00:16 by alfokin           #+#    #+#             */
/*   Updated: 2024/11/12 15:41:08 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_check_str_start(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	i;
	unsigned int	temp;

	start = 0;
	while (s1[start])
	{
		temp = start;
		i = 0;
		while (set[i])
		{
			if (s1[start] == set[i])
			{
				start++;
				break ;
			}
			i++;
		}
		if (temp == start)
			break ;
	}
	return (start);
}

static unsigned int	ft_check_str_end(char const *s1, char const *set)
{
	unsigned int	end;
	unsigned int	i;
	unsigned int	temp;

	end = ft_strlen(s1);
	while (end > 0)
	{
		temp = end;
		i = 0;
		while (set[i])
		{
			if (s1[end - 1] == set[i])
			{
				end--;
				break ;
			}
			i++;
		}
		if (temp == end)
			break ;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;

	if (!s1)
		return (ft_strdup(""));
	if (!set || ft_strlen(s1) == 0)
		return (ft_strdup(s1));
	start = ft_check_str_start(s1, set);
	end = ft_check_str_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start));
}
