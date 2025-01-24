/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:27:17 by arocca            #+#    #+#             */
/*   Updated: 2025/01/15 14:27:17 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdint.h>

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

char	check_conversion(char c)
{
	char	*types;

	types = "cspdiuxX%";
	while (*types)
	{
		if (*types == c)
			return (*types);
		types++;
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

int	ft_atoi(const char *nptr)
{
	unsigned long long	res;
	int					sign;

	res = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr++ - '0');
		if (res > LLONG_MAX && sign < 0)
			return (0);
		if (res > LLONG_MAX)
			return (-1);
	}
	return (((int)res) * sign);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size || size > SIZE_MAX / nmemb)
		return (NULL);
	tab = malloc(size * nmemb);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, size * nmemb);
	return (tab);
}
