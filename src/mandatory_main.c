/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:01:41 by arocca            #+#    #+#             */
/*   Updated: 2025/01/27 16:56:38 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	mandatory_parser(char c, va_list *args, size_t *total_len)
{
	if (c == 'd' || c == 'i' || c == 'u')
		handle_nbr(args, total_len, (c != 'u'));
	if (c == 'c')
		handle_char(args, total_len);
	if (c == 's')
		handle_string(args, total_len);
	if (c == '%')
		*total_len += ft_putchar_fd('%', 1);
	if (c == 'p')
		handle_address(args, total_len);
	if (c == 'x' || c == 'X')
		handle_hexa(args, total_len, (c == 'x'));
	return (1);
}

static int	error_detector(const char *format)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			while (authorized_c(*format) >= 0)
				format++;
			if (!check_conv(*format))
				return (-1);
		}
		format++;
	}
	return (0);
}

void	format_update(char **s, size_t	*i, size_t *len, va_list *args)
{
	write(1, *s, *i);
	*s += *i + parse_args(*s + *i + 1, args, len) + 1;
	*len += *i;
	*i = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	len;
	char	*s;

	i = 0;
	len = 0;
	if (!format || error_detector(format))
		return (-1);
	va_start(args, format);
	s = (char *)format;
	while (s[i])
	{
		if (s[i] == '%')
			format_update(&s, &i, &len, &args);
		else
			i++;
	}
	ft_putstr_fd(s, 1);
	len += i;
	return (len);
}
