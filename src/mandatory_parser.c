/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:26:50 by arocca            #+#    #+#             */
/*   Updated: 2025/01/15 14:30:46 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	parse_args(char *s, va_list *args, size_t *total_len)
{
	if (check_conversion(s[0]))
		return (mandatory_parser(s[0], args, total_len));
	else if (!check_conversion(s[0]))
		return (*total_len += write(1, "%", 1));
	return (0);
}

static int	error_detector(char *format)
{
	while (*format)
	{
		if (*format == '%' && (!check_conversion(*++format) || !*++format))
			return (1);
		format++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	len;
	char	*s;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	s = (char *)format;
	if (error_detector(s))
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
			format_update(&s, &i, &len, &args);
		else
			i++;
	}
	write(1, s, i);
	len += i;
	return (len);
}
