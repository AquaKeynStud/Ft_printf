/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_printers_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:32:32 by arocca            #+#    #+#             */
/*   Updated: 2025/01/27 19:15:13 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_x_2(unsigned int n, size_t *total_len, int (*f)[8], char *b)
{
	if (!(*f)[5] && !(*f)[6] && (*f)[2] && n == 0)
		*total_len += write(1, " ", 1);
	else
	{
		if ((*f)[5] && n > 0)
		{
			*total_len += write(1, "0x", 2);
			(*f)[7] -= 2;
		}
		if ((*f)[6])
			*total_len += fill('0', (*f)[6] - hexa_len(n), f, 1);
		if (!(*f)[1] && !(*f)[2] && !(*f)[3] && !(*f)[4]
			&& !(*f)[5] && !(*f)[6] && !(*f)[7] && !(*f)[0])
			return ;
		convert_to(n, b, total_len);
	}
	if ((*f)[7])
		*total_len += fill(' ', (*f)[7] - hexa_len(n), f, 1);
	return ;
}

void	print_x_bonus(unsigned int n, size_t *total_len, int (*f)[8], char *b)
{
	int	fd;

	if ((*f)[0])
		return (print_x_2(n, total_len, f, b));
	fd = (((*f)[6] - hexa_len(n)) * ((*f)[6] > hexa_len(n)));
	if ((*f)[7])
		*total_len += fill(' ', (*f)[7] - hexa_len(n) - fd, f, 0);
	if ((*f)[5] && n > 0)
	{
		*total_len += write(1, "0x", 2);
		(*f)[7] -= 2;
	}
	if ((*f)[6])
		*total_len += fill('0', (*f)[6] - hexa_len(n), f, 1);
	if (!(*f)[5] && !(*f)[2] && !(*f)[3] && !(*f)[4]
		&& !(*f)[1] && !(*f)[6] && !(*f)[7] && !(*f)[0])
		return ;
	if (!(*f)[5] && !(*f)[6] && !(*f)[3] && n == 0)
	{
		*total_len += write(1, " ", 1);
		return ;
	}
	convert_to(n, b, total_len);
}

static void	ajust_len(char *str, size_t *total_len, int (*f)[8])
{
	if ((*f)[2])
	{
		while (*str && (*f)[6])
		{
			*total_len += write(1, &(*str), 1);
			str++;
			(*f)[6]--;
			(*f)[7]--;
		}
	}
	else
	{
		while (*str)
		{
			*total_len += write(1, &(*str), 1);
			str++;
			(*f)[7]--;
		}
	}
}

void	print_str_bonus(char *str, size_t *total_len, int (*f)[8])
{
	if ((*f)[0])
	{
		ajust_len(str, total_len, f);
		if ((*f)[7])
			*total_len += fill(' ', (*f)[7], f, 1);
		return ;
	}
	if ((*f)[7])
		*total_len += fill(' ', (*f)[7] - ft_strlen(str), f, 1);
	ajust_len(str, total_len, f);
}

void	print_addr_bonus(void *arg, size_t *total_len, int (*f)[8])
{
	if ((*f)[0])
	{
		if ((*f)[3])
			write_sign(&(*f)[3], total_len, f);
		ft_print_memory_bonus(arg, total_len, f);
		if ((*f)[7] < (*f)[6])
			(*f)[7] = (*f)[6];
		if ((*f)[7])
			*total_len += fill(' ', (*f)[7] - addr_len(arg), f, 1);
		return ;
	}
	if ((*f)[7])
		*total_len += fill(' ', (*f)[7] - addr_len(arg), f, 1);
	if ((*f)[3] || (*f)[4])
		write_sign(&(*f)[3], total_len, f);
	ft_print_memory_bonus(arg, total_len, f);
	return ;
}
