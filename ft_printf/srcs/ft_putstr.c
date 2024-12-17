/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:36:20 by alfokin           #+#    #+#             */
/*   Updated: 2024/12/17 17:07:33 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr(char *s, t_format *pf)
{
    int	count;
    int	len;

    if (s == NULL)
        s = "(null)";
    len = 0;
    while (s[len])
        len++;
    if (pf->precision >= 0 && pf->precision < len)
        len = pf->precision;
    count = 0;
    if (!pf->left_align && pf->field_width > len)
        while (pf->field_width-- > len)
            count += ft_putchar(pf->zero_padding ? '0' : ' ');
    while (*s && len--)
        count += ft_putchar(*s++);
    if (pf->left_align && pf->field_width > len)
        while (pf->field_width-- > 0)
            count += ft_putchar(' ');
    return (count);
}
