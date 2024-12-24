/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:53:16 by ishaaq            #+#    #+#             */
/*   Updated: 2024/12/24 15:10:19 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putchar(char c, int *characters)
{
	write(1, &c, 1);
	*characters = *characters + 1;
}
void    ft_putstr(char *s, int *characters)
{
	int i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)", characters));
	while (s[i] != '\0')
		ft_putchar(s[i++], characters);
}

void    ft_putint(long n, int *characters)
{
	if (n < 0)
	{
		ft_putchar('-', characters);
		n = -n;
	}
	if (n > 9)
		ft_putint(n / 10, characters);
	ft_putchar(n % 10 + '0', characters);
}
void    ft_putuint(unsigned int n, int *characters)
{
	if (n > 9)
		ft_putint(n / 10, characters);
	ft_putchar(n % 10 + '0', characters);
}
void	ft_itoh(unsigned long n, int upper, int *characters)
{
	char *lhex;
	char *uhex;
	char *hex;

	lhex = "0123456789abcdef";
	uhex = "0123456789ABCDEF";
	hex = upper ? uhex : lhex;
	if (n >=16)
	{
		ft_itoh(n / 16, upper, characters);
		ft_putchar(hex[n % 16], characters);
	}
	else
		ft_putchar(hex[n], characters);
}
void   ft_putlhex(unsigned long p, int *characters)
{
	ft_putstr("0x", characters);
	ft_itoh((unsigned long) p, 0, characters);
}
void   ft_putuhex(unsigned long p, int *characters)
{
	ft_putstr("0x",characters);
	ft_itoh((unsigned long) p, 1, characters);
}
void	ft_putpointer(void *p, int *characters)
{
	if (!p)
		return (ft_putstr("(nil)", characters));
	ft_putstr("0x", characters);
	ft_itoh((unsigned long) p, 0, characters);
}