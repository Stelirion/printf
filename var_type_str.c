/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_type_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:44:31 by ngennaro          #+#    #+#             */
/*   Updated: 2022/11/24 14:04:40 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int var_type_str(char type, char *arg)
{
	size_t	i;

	i = 0;
	if (type == 's')
	{
		if (!arg)
			return (0);
		while (arg[i])
		{
			write (1, &arg[i], 1);
			i++;
		}
	}
	return (i);
}
