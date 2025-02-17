/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mananton <telesmanuel@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:25:40 by mananton          #+#    #+#             */
/*   Updated: 2025/01/27 15:37:32 by mananton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int	ft_specifier(char c, va_list ap)
{
	if (c == 'c')
		return (ft_char(ap));
	if (c == 's')
		return (ft_string(ap));
	if (c == 'i' || c == 'd')
		return (ft_int(ap));
	if (c == 'u')
		return (ft_unsigned(ap));
	if (c == 'p')
		return (ft_pointer(ap));
	if (c == 'x')
		return (ft_hexlower(ap));
	if (c == 'X')
		return (ft_hexupper(ap));
	else if (c == '%')
		return (ft_percent());
	return (write(1, &c, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format)
		return (0);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && !*(format + 1))
			break ;
		else if (*format == '%')
			count += ft_specifier(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
