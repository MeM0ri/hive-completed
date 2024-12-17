/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:47:48 by alfokin           #+#    #+#             */
/*   Updated: 2024/12/17 17:08:31 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_set_field_width(const char **format, t_format *pf)
{
	pf->field_width = 0;
	while (**format >= '0' && **format <= '9')
	{
		pf->field_width = pf->field_width * 10 + (**format - '0');
		(*format)++;
	}
}

void	ft_set_precision(const char **format, t_format *pf)
{
	pf->precision = 0;
	while (**format >= '0' && **format <= '9')
	{
		pf->precision = pf->precision * 10 + (**format - '0');
		(*format)++;
	}
}

void	ft_parse_format(const char **format, t_format *pf)
{
	pf->left_align = 0;
	pf->zero_padding = 0;
	pf->field_width = 0;
	pf->precision = -1;
	while (**format == '-' || **format == '0' || **format == '.')
	{
		if (**format == '-')
			pf->left_align = 1;
		else if (**format == '0')
			pf->zero_padding = 1;
		else if (**format == '.')
		{
			(*format)++;
			ft_set_precision(format, pf);
			continue;
		}
		ft_set_field_width(format, pf);
	}
	pf->specifier = **format;
}
