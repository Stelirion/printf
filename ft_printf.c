/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:30:56 by ngennaro          #+#    #+#             */
/*   Updated: 2022/11/25 11:12:43 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	size;
	va_list	args;

	i = 0;
	size = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c' || str[i] == 'i'|| str[i] == 'd')
				size += var_type_int(str[i], (int)va_arg(args, int));
			else if (str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
				size += var_type_unsigned_int(str[i], (unsigned int)va_arg(args, unsigned int));
			else if (str[i] == 's')
				size += var_type_str(str[i], (char *)va_arg(args, char *));
			else
				write (1, &str[i], 1);
		}
		else
		{
			write (1, &str[i], 1);
			size ++;
		}
		i++;
	}
	return (size);
}
