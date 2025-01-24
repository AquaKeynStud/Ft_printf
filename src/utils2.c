/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:55:03 by arocca            #+#    #+#             */
/*   Updated: 2025/01/24 14:56:49 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_isdigit(int c)
{
	return (c > '0' && c <= '9');
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
		str[i++] = c;
	return (s);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ndest;
	char	*nsrc;	

	if (!dest && !src)
		return (NULL);
	ndest = (char *)dest;
	nsrc = (char *)src;
	if (nsrc < ndest && ndest < nsrc + n)
	{
		ndest += n;
		nsrc += n;
		while (n--)
			*(--ndest) = *(--nsrc);
	}
	else
	{
		while (n--)
			*ndest++ = *nsrc++;
	}
	return (dest);
}
