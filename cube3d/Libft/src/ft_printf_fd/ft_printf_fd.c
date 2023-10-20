/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:12:21 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/20 19:01:05 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_check_flag(va_list args, char flag, int fd)
{
	int	size;

	size = 0;
	if (flag == 'c')
		size = ft_print_char_fd(va_arg(args, int), fd);
	else if (flag == 's')
		size = ft_print_str_fd(va_arg(args, char *), fd);
	else if (flag == 'p')
		size = ft_print_ptr_fd(va_arg(args, uintptr_t), fd);
	else if (flag == 'd' || flag == 'i')
		size = ft_print_nbr_fd(va_arg(args, int), fd);
	else if (flag == 'u')
		size = ft_print_unbr_fd(va_arg(args, unsigned int), fd);
	else if (flag == 'x' || flag == 'X')
		size = ft_print_hex_fd(va_arg(args, unsigned int), flag, fd);
	else if (flag == '%')
		size = ft_print_char_fd('%', fd);
	return (size);
}

int	ft_printf_fd(int fd, char *str, ...)
{
	int		i;
	int		space;
	va_list	args;

	i = 0;
	space = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			space += ft_check_flag(args, str[++i], fd);
		else
		{
			ft_print_char_fd(str[i], fd);
			space += 1;
		}
		i++;
	}
	va_end(args);
	return (space);
}
