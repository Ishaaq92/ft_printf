/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:53:18 by ishaaq            #+#    #+#             */
/*   Updated: 2024/12/23 08:13:07 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
void    ft_putchar(char c);
int	    validate(char c);
void    ft_putstr(char *s);
void    ft_putint(long n);
void    ft_putpointer(void *p);
int	    ft_atoi(const char *nptr);
void	ft_itoh(unsigned long n, int upper);
void    ft_putlhex(unsigned long p);
void    ft_putuhex(unsigned long p);
void    ft_putuint(unsigned int n);

#endif