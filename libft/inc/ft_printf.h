/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mananton <telesmanuel@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:29:23 by mananton          #+#    #+#             */
/*   Updated: 2025/01/27 15:37:16 by mananton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_char(va_list ap);
int		ft_string(va_list ap);
int		ft_int(va_list ap);
int		ft_unsigned(va_list ap);
int		ft_pointer(va_list ap);
int		ft_hexlower(va_list ap);
int		ft_hexupper(va_list ap);
int		ft_percent(void);
int		ft_putchar(char c);
int		ft_putnbr_base(unsigned long long nb, const char *base);

#endif
