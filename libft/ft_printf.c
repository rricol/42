/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 23:08:05 by rricol            #+#    #+#             */
/*   Updated: 2022/03/15 23:08:05 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_insert_arg(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'x')
		count += ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	else if (c == 'X')
		count += ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	return (count);
}

int	ft_printf(char *input, ...)
{
	int	i;
	int	count;
	va_list	args;

	i = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1])
			count += st_insert_arg(input[++i], args);
		else
			count += write(1, &input[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
