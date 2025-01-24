/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:33:12 by arocca            #+#    #+#             */
/*   Updated: 2025/01/15 14:33:24 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill(char c, int len, int (*f)[8], int both)
{
	int	i;

	i = 0;
	if (len < 0)
		return (0);
	while (i < len)
	{
		write(1, &c, 1);
		(*f)[7] -= 1;
		if (both == 1)
			(*f)[6] -= 1;
		i++;
	}
	return (len);
}

int	c_d(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		nb *= -1;
	while (nb / 10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	addr_len(void *addr)
{
	unsigned long	a;
	int				count;

	a = (unsigned long)addr;
	count = 2;
	while (a > 16)
	{
		count += 1;
		a /= 16;
	}
	return (count + 1);
}

int	hexa_len(unsigned int nb)
{
	int				count;

	count = 0;
	while (nb > 16)
	{
		count += 1;
		nb /= 16;
	}
	return (count + 1);
}

int	authorized_c(char c)
{
	char	*conv;
	int		i;

	i = 0;
	conv = "-0.+ #123456789";
	while (conv[i])
	{
		if (conv[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
