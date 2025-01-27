/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:26:50 by arocca            #+#    #+#             */
/*   Updated: 2025/01/27 16:55:49 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	parse_args(char *s, va_list *args, size_t *total_len)
{
	if (check_conv(s[0]))
		return (mandatory_parser(s[0], args, total_len));
	else if (!check_conv(s[0]))
		return (*total_len += ft_putstr_fd("%", 1));
	return (0);
}
