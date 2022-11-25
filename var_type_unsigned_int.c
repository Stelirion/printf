/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_type_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:44:31 by ngennaro          #+#    #+#             */
/*   Updated: 2022/11/24 17:11:53 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0 && nb != -2147483648)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb >= 10 && nb != -2147483648)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar(nb % 10 + '0');
}

void	puthexa(unsigned int number, char type)
{
	long	i;
	char	*base;
	char	res[250];

	i = 0;
	if (type == 'x')
		base = "0123456789abcdef";
	if (type == 'X')
		base = "0123456789ABCDEF";
	if (number == 0)
		ft_putchar(base[0]);
	while (number > 0)
	{
		res[i++] = base[number % 16];
		number /= 16;
	}
	i--;
	while (i >= 0)
		ft_putchar(res[i--]);
}

int	var_type_unsigned_int(char type, unsigned int arg)
{
	if (type == 'u')
	{
		ft_putnbr(arg);
		return (0); //return a definir
	}
	else if (type == 'x' || type == 'X')
	{
		puthexa(arg, type);
		return (0); //return a definir
	}
	return (0);
}
