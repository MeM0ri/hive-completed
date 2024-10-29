/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:27:19 by alfokin           #+#    #+#             */
/*   Updated: 2024/10/29 12:16:43 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	return ((c > 46 && c < 58)
			|| (c > 64 && c < 91)
			|| (c > 96 && c < 123));
}
