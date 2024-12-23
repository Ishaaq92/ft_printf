/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:53:13 by ishaaq            #+#    #+#             */
/*   Updated: 2024/12/23 08:26:39 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	validate(char c)
{
	int		i;
	char	*set;

	i = 0;
	set = "cspdiuxX%\0";
	while (set[i] != '\0')
		if (c == set[i++] && c != '\0')
			return (i - 1); //Greater than 0 if valid character
	return (-1);	// (-1) if not a valid character
}

int	ft_printf(const char *format, ...)
{
	va_list	args; // Saves arguments to args
	int		i;

	i = 0;
	va_start(args, format); // Initialises
	while (format[i] != '\0')
	{
		if (format[i] == '%' && validate(format[i + 1]) >= 0)
		{
			if (format[i + 1] == 'c')
				ft_putchar((char) va_arg(args, int));
			else if (format[i + 1] == 's')
				ft_putstr((char *) va_arg(args, char*));
			else if (format[i + 1] == 'p')
				ft_putpointer((unsigned long *) va_arg(args, void *));
			else if (format[i + 1] == 'd')
				ft_putuint( va_arg(args, int));
			else if (format[i + 1] == 'u')
				ft_putint((unsigned long) va_arg(args, unsigned int));
			else if (format[i + 1] == 'x')
				ft_itoh(va_arg(args, unsigned int), 0);
			else if (format[i + 1] == 'X')
				ft_itoh(va_arg(args, unsigned int), 1);
			else if (format[i + 1] == '%')
				write(1, "%", 1);
			i +=2;
		}
		else
			write(1, &format[i++], 1);
	}
	va_end(args);
	return(0);
}

int	main(void)
{
	char *s = "Ishaaq Ahmed";
	ft_printf(" %c %c %c ", '0', 0, '1');
	printf("\n");
	printf(" %c %c %c ", '0', 0, '1');
}