/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:44:56 by rricol            #+#    #+#             */
/*   Updated: 2022/03/15 22:44:56 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		count += ft_putnbr(-n);
	}
	else 
	{
		if (n / 10 != 0)
			count += ft_putnbr(n / 10);
		count += ft_putchar((n % 10) + 48);
	}
	return (count);
}

int ft_putnbr_base(unsigned int n, char *base)
{
	int	count;
	int	baselen;

	baselen = ft_strlen(base);
	count = 0;
	if (n / baselen != 0)
		count += ft_putnbr(n / baselen);
	count += ft_putchar(base[n % baselen]);
	return (count);
}

int	ft_putnbr_fd(long n, int fd)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar_fd('-', fd);
		count += ft_putnbr(-n);
	}
	else 
	{
		if (n / 10 != 0)
			count += ft_putnbr(n / 10);
		count += ft_putchar_fd((n % 10) + 48, fd);
	}
	return (count);
}