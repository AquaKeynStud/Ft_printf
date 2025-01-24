/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:50:50 by keyn              #+#    #+#             */
/*   Updated: 2025/01/24 15:24:09 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
