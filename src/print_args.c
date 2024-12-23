/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:53:16 by ishaaq            #+#    #+#             */
/*   Updated: 2024/12/23 07:56:55 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	total;

	i = 0;
	sign = 1;
	total = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i ++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = sign * -1;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		total = (total * 10) + (nptr[i] - 48);
		i ++;
	}
	return (sign * total);
}

void    ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		write(1, &s[i++], 1);
}
void    ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putint(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putint(n / 10);
	ft_putchar(n % 10 + '0');
}
void    ft_putuint(unsigned int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putint(n / 10);
	ft_putchar(n % 10 + '0');
}
void	ft_itoh(unsigned long n, int upper)
{
	char *lhex;
	char *uhex;
	char *hex;
	lhex = "0123456789abcdef";
	uhex = "0123456789ABCDEF";
	hex = upper ? uhex : lhex;
	if (n >=16)
	{
		ft_itoh(n / 16, upper);
		write(1, &hex[n % 16], 1);
	}
	else
		write(1, &hex[n], 1);
}
void   ft_putlhex(unsigned long p)
{
	ft_putstr("0x");
	ft_itoh((unsigned long) p, 0);
}
void   ft_putuhex(unsigned long p)
{
	ft_putstr("0x");
	ft_itoh((unsigned long) p, 1);
}
void	ft_putpointer(void *p)
{
	ft_putstr("0x");
	ft_itoh((unsigned long) p, 0);
}