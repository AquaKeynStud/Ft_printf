/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_printers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:32:37 by arocca            #+#    #+#             */
/*   Updated: 2025/01/15 14:52:55 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_sign(int *n, size_t *total_len, int (*f)[8])
{
	if ((*f)[4] && !(*f)[3])
	{
		*total_len += write(1, " ", 1);
		(*f)[7] -= 1;
	}
	if ((*f)[3] && (*n) >= 0)
	{
		*total_len += write(1, "+", 1);
		if ((*f)[7] <= 0)
			(*f)[6] -= 1;
		else
			(*f)[7] -= 1;
	}
	else if ((*n) < 0)
	{
		*total_len += write(1, "-", 1);
		(*n) *= -1;
		if ((*f)[7])
			(*f)[7] -= 1;
		else if (!(*f)[7] && (*f)[1])
			(*f)[6] -= 1;
	}
}

void	print_nb_bonus(int n, size_t *total_len, int (*f)[8])
{
	int	fs;

	if ((*f)[0])
	{
		write_sign(&n, total_len, f);
		if ((*f)[6])
			*total_len += fill('0', (*f)[6] - c_d(n), f, 1);
		ft_putnbr_fd(n, 1, total_len, f);
		if ((*f)[7])
			*total_len += fill(' ', (*f)[7] - c_d(n), f, 1);
		return ;
	}
	if ((*f)[3])
		(*f)[7] -= 1;
	fs = (*f)[7] - c_d(n) - (((*f)[6] - c_d(n)) * ((*f)[6] > c_d(n)));
	if ((*f)[7])
		*total_len += fill(' ', fs - (*f)[4] - ((n < 0) * !(*f)[3]), f, 0);
	write_sign(&n, total_len, f);
	if ((*f)[6])
		*total_len += fill('0', (*f)[6] - c_d(n), f, 1);
	if (!(*f)[5] && !(*f)[6] && !(*f)[7] && !(*f)[1] && !(*f)[2])
		return ;
	ft_putnbr_fd(n, 1, total_len, f);
}

void	print_char_bonus(int n, size_t *total_len, int (*f)[8])
{
	if ((*f)[0])
	{
		*total_len += ft_putchar_fd(n, 1);
		if ((*f)[7])
			*total_len += fill(' ', (*f)[7] - 1, f, 1);
		else
			*total_len += fill(' ', (*f)[6] - 1, f, 1);
		return ;
	}
	if ((*f)[7])
		*total_len += fill(' ', (*f)[7] - 1, f, 1);
	else
		*total_len += fill(' ', (*f)[6] - 1, f, 1);
	*total_len += ft_putchar_fd(n, 1);
	return ;
}

void	ft_print_memory_bonus(void *addr, size_t *total_len, int (*f)[8])
{
	unsigned long	a;

	a = (unsigned long)addr;
	write(1, "0x", 2);
	if (f && ((*f)[1] || (*f)[2]) && !(*f)[0])
	{
		while ((*f)[6] - addr_len(addr) + (2 * (*f)[2]))
		{
			*total_len += write(1, "0", 1);
			(*f)[6] -= 1;
		}
	}
	*total_len += 2;
	convert_to(a, "0123456789abcdef", total_len);
	return ;
}

void	print_uint_bonus(unsigned int arg, size_t *total_len, int (*f)[8])
{
	int	fs;

	if ((*f)[0])
	{
		if ((*f)[6])
			*total_len += fill('0', (*f)[6] - c_d(arg), f, 1);
		ft_putunbr_fd(arg, 1, total_len, f);
		if ((*f)[7])
			*total_len += fill(' ', (*f)[7] - c_d(arg), f, 1);
		return ;
	}
	if ((*f)[3] && !(*f)[7])
		(*f)[7] -= 1;
	fs = (*f)[7] - c_d(arg) - (((*f)[6] - c_d(arg)) * ((*f)[6] > c_d(arg)));
	if ((*f)[7])
		*total_len += fill(' ', fs, f, 0);
	if ((*f)[6])
		*total_len += fill('0', (*f)[6] - c_d(arg), f, 1);
	if (!(*f)[5] && !(*f)[6] && !(*f)[7] && !(*f)[1] && !(*f)[2] && !(*f)[4])
		return ;
	ft_putunbr_fd(arg, 1, total_len, f);
}
