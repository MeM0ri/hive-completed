/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_numbers_in_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:07:19 by alfokin           #+#    #+#             */
/*   Updated: 2024/10/27 22:09:46 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_numbers_in_str(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		if (*str > 47 && *str < 58)
			result++;
		str++;
	}
	return (result);
}
