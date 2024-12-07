/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilim <yilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:23:21 by yilim             #+#    #+#             */
/*   Updated: 2024/04/29 15:23:21 by yilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_switch(char c, va_list args);
int		ft_putchar(char c);
int		ft_print_char(va_list args);
int		ft_putstr(char *str);
int		ft_print_str(va_list args);
char	*ft_itoa_base(unsigned long long n, char *base);
int		ft_print_ptr(va_list args);
int		ft_print_dec_int(va_list args);
int		ft_print_u_int(va_list args);
int		ft_print_hex(va_list args, char c);

#endif
