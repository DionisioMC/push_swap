/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_selector_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:14:41 by hede-car          #+#    #+#             */
/*   Updated: 2026/05/26 14:52:53 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar(int c)
{
	write(2, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr <= 9)
		ft_putchar(nbr + '0');
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

void	ft_putdouble(double n)
{
	int	intgr;
	int	decimal;

	intgr = (int) n;
	decimal = (int)((n - intgr) * 100);
	ft_putnbr(intgr);
	ft_putchar('.');
	ft_putnbr(decimal);
	if (decimal == 0)
		ft_putchar('0');
	ft_putchar('%');
}

void	ft_printf(const char *format, ...)
{
	va_list	params;
	int		i;

	i = 0;
	va_start(params, format);
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i]);
		else
		{
			i++;
			if (format[i] == 'c')
				ft_putchar(va_arg(params, int));
			else if (format[i] == 'f')
				ft_putdouble(va_arg(params, double));
			else if (format[i] == 's')
				ft_putstr(va_arg(params, char *));
			else if (format[i] == 'd')
				ft_putnbr(va_arg(params, int));
		}
		i++;
	}
	va_end(params);
}
