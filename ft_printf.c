/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:53:13 by ishaaq            #+#    #+#             */
/*   Updated: 2024/12/24 15:10:16 by isahmed          ###   ########.fr       */
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
	int		characters;

	i = 0;
	characters = 0;
	va_start(args, format); // Initialises
	while (format[i] != '\0')
	{
		if (format[i] == '%' && validate(format[i + 1]) >= 0)
		{
			if (format[i + 1] == 'c')
				ft_putchar((char) va_arg(args, int), &characters);
			else if (format[i + 1] == 's')
				ft_putstr((char *) va_arg(args, char*), &characters);
			else if (format[i + 1] == 'p')
				ft_putpointer((unsigned long *) va_arg(args, void *), &characters);
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
				ft_putint(va_arg(args, int), &characters);
			else if (format[i + 1] == 'u')
				ft_putuint((unsigned long) va_arg(args, unsigned int), &characters);
			else if (format[i + 1] == 'x')
				ft_itoh(va_arg(args, unsigned int), 0, &characters);
			else if (format[i + 1] == 'X')
				ft_itoh(va_arg(args, unsigned int), 1, &characters);
			else if (format[i + 1] == '%')
				ft_putchar('%', &characters);
			i +=2;
		}
		else
		{
			write(1, &format[i++], 1);
			characters++;
		}
	}
	va_end(args);
	return(characters);
}

// int	main(void)
// {
// 	char *s = "Ishaaq Ahmed";
// 	int num1 = ft_printf(" NULL %s NULL ", NULL);
// 	printf("\n");
// 	// int num2 = printf(" NULL %s NULL ", NULL);
 
// 	printf("\n");  

// 	printf("ft_printf: (%d)", num1);
// 	// printf("printf: (%d)", num2);
   
// 	// printf("%d", ft_printf("%c", 'k'));
// }