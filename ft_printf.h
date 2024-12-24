/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:53:18 by ishaaq            #+#    #+#             */
/*   Updated: 2024/12/24 14:52:50 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
void    ft_putchar(char c, int *characters);
int	    validate(char c);
void    ft_putstr(char *s, int *characters);
void    ft_putint(long n, int *characters);
void    ft_putpointer(void *p, int *characters);
void	ft_itoh(unsigned long n, int upper, int *characters);
void    ft_putlhex(unsigned long p, int *characters);
void    ft_putuhex(unsigned long p, int *characters);
void    ft_putuint(unsigned int n, int *characters);

#endif