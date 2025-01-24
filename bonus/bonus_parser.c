/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:32:27 by arocca            #+#    #+#             */
/*   Updated: 2025/01/24 15:11:05 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_forbidden(int *last_is_dot, int *has_space, char s)
{
	if (s == '.')
		(*last_is_dot) = 1;
	else
		(*last_is_dot) = 0;
	if (s == ' ')
		(*has_space) = 1;
}

static int	error_tab(char *s)
{
	int	value;
	int	last_is_dot;
	int	has_space;

	value = 0;
	has_space = 0;
	while (*s && !check_conversion(*s) && authorized_c(*s) >= 0)
	{
		if (authorized_c(*s) >= 6 && ft_isdigit(*s))
		{
			if (value && (!last_is_dot || has_space))
				return (1);
			else
			{
				value = 1;
				has_space = 0;
				while (ft_isdigit(*s) || *s == '0')
					s++;
			}
		}
		check_forbidden(&last_is_dot, &has_space, *s);
		s++;
	}
	return (0);
}

static void	init_tab(char *s, int (*f)[8], int tab_len)
{
	while (tab_len >= 0)
		(*f)[tab_len--] = 0;
	while (*s && !check_conversion(*s) && authorized_c(*s) >= 0)
	{
		if (authorized_c(*s) >= 6 && ft_isdigit(*s))
		{
			(*f)[7] = ft_atoi(s);
			s += c_d((*f)[7]) - 1;
		}
		else
		{
			(*f)[authorized_c(*s)] = 1;
			if (authorized_c(*s) == 2)
			{
				(*f)[6] = ft_atoi(s + 1);
				s += c_d((*f)[6]);
			}
		}
		s++;
	}
	if ((*f)[7] && (*f)[1] && !(*f)[2])
		(*f)[6] = (*f)[7];
	if ((*f)[7] < (*f)[6])
		(*f)[7] = (*f)[6];
	(*f)[7] *= ((*f)[7] > (*f)[6]) + ((*f)[6] * ((*f)[7] < (*f)[6]));
}

int	bonus_parser(char c, va_list *args, size_t *total_len, int (*f)[8])
{
	if (c == 'i' || c == 'd' || c == 'c' || c == 'x' || c == 'X')
		create_nbr(c, args, total_len, f);
	if (c == 'p')
		create_addr(args, total_len, f);
	if (c == 'u')
		create_nbr(c, args, total_len, f);
	if (c == '%')
		*total_len += write(1, "%", 1);
	if (c == 's')
		create_string(args, total_len, f);
	return (0);
}

int	parse_args(char *s, va_list *args, size_t *total_len)
{
	size_t	len;
	int		f[8];

	len = 0;
	if (error_tab(s) || authorized_c(s[len]) == -1)
	{
		*total_len += write(1, "%", 1);
		while (authorized_c(s[len]) >= 0)
		{
			if (!(len == 0 && s[len] == '0'))
				*total_len += write(1, &s[len], 1);
			if (s[len] == '.' && s[len + 1] == ' ')
				*total_len += write(1, "0", 1);
			len++;
		}
		return (len);
	}
	init_tab(s, &f, 7);
	while (s[len] && !check_conversion(s[len]) && authorized_c(s[len]) >= 0)
		len++;
	if (len == 0)
		mandatory_parser(s[0], args, total_len);
	bonus_parser(s[len], args, total_len, &f);
	return (len + 1);
}
