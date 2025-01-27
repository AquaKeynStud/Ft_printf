/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:27:01 by arocca            #+#    #+#             */
/*   Updated: 2025/01/27 16:43:41 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_string(va_list *args, size_t *total_len)
{
	char	*arg;

	arg = (char *)va_arg(*args, char *);
	if (!arg)
		*total_len += ft_putstr_fd("(null)", 1);
	else
		*total_len += ft_putstr_fd(arg, 1);
	return ;
}

void	handle_char(va_list *args, size_t *total_len)
{
	char	arg;

	arg = (int)va_arg(*args, int);
	if (!arg)
	{
		write(1, &arg, 1);
		*total_len += 1;
		return ;
	}
	*total_len += ft_putchar_fd(arg, 1);
}

void	handle_nbr(va_list *args, size_t *total_len, int isInt)
{
	unsigned int	arg;

	if (isInt)
	{
		arg = (int)va_arg(*args, int);
		ft_putnbr_fd(arg, 1, total_len, NULL);
	}
	else
	{
		arg = (unsigned int)va_arg(*args, unsigned int);
		ft_putunbr_fd(arg, 1, total_len, NULL);
	}
	return ;
}

void	handle_address(va_list *args, size_t *total_len)
{
	void	*arg;

	arg = (void *)va_arg(*args, void *);
	if (!arg)
	{
		write(1, "(nil)", 5);
		*total_len += 5;
		return ;
	}
	ft_print_memory(arg, total_len);
	return ;
}

void	handle_hexa(va_list *args, size_t *total_len, int isLower)
{
	unsigned int	arg;

	arg = (unsigned int)va_arg(*args, unsigned int);
	if (isLower)
		convert_to(arg, "0123456789abcdef", total_len);
	else
		convert_to(arg, "0123456789ABCDEF", total_len);
	return ;
}
