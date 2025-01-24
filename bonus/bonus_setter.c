/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_setter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:32:58 by arocca            #+#    #+#             */
/*   Updated: 2025/01/15 14:33:08 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	create_nbr(char c, va_list *args, size_t *total_len, int (*f)[8])
{
	int				arg;
	unsigned int	uarg;

	if (c == 'u' || c == 'x' || c == 'X')
		uarg = (unsigned int)va_arg(*args, unsigned int);
	else
		arg = (int)va_arg(*args, int);
	if (c == 'i' || c == 'd')
		print_nb_bonus(arg, total_len, f);
	else if (c == 'c')
		print_char_bonus(arg, total_len, f);
	else if (c == 'u')
		print_uint_bonus(uarg, total_len, f);
	else if (c == 'x')
		print_x_bonus(uarg, total_len, f, "0123456789abcdef");
	else if (c == 'X')
		print_x_bonus(uarg, total_len, f, "0123456789ABCDEF");
	return ;
}

void	create_addr(va_list *args, size_t *total_len, int (*f)[8])
{
	void	*arg;

	arg = (void *)va_arg(*args, void *);
	if (!arg)
	{
		if ((*f)[0])
		{
			*total_len += write(1, "(nil)", 5);
			*total_len += fill(' ', (*f)[7] - 5, f, 0);
			return ;
		}
		*total_len += fill(' ', (*f)[7] - 5, f, 0);
		*total_len += write(1, "(nil)", 5);
		return ;
	}
	print_addr_bonus(arg, total_len, f);
}

void	create_string(va_list *args, size_t *total_len, int (*f)[8])
{
	char	*arg;

	arg = (char *)va_arg(*args, char *);
	print_str_bonus(arg, total_len, f);
}
