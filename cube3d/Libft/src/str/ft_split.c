/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:27:34 by recozzi           #+#    #+#             */
/*   Updated: 2023/05/02 14:12:27 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static size_t	ft_countstr(char *s, char c)
{
	size_t	n_str;
	size_t	i;

	n_str = 0;
	i = 0;
	if (!s)
		return (n_str);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i - 1] != c)
			n_str += 1;
	}
	return (n_str);
}

static char	*ft_strtrim_decorator(char const *s, char c)
{
	char	*input;
	char	*output;

	input = (char *)malloc(sizeof(char) * 2);
	if (!input)
		return (0);
	input[0] = c;
	input[1] = '\0';
	output = ft_strtrim(s, (const char *)input);
	free(input);
	return (output);
}

/*!
 * @brief 
	Allocates (with malloc(3)) and returns an array	of strings obtained by 
	splitting ’s’ using the	character ’c’ as a delimiter;
	The array must end with a NULL pointer.
 * @param s 
	The string to be split.
 * @param c 
	The delimiter character.
 * @return 
	The array of new strings resulting from the split.
	NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	t_var	var;

	var.i = 0;
	var.k = 0;
	var.j = 0;
	var.trim = ft_strtrim_decorator(s, c);
	if (!var.trim)
		return (0);
	var.nb_str = ft_countstr(var.trim, c);
	var.array_p = (char **)malloc(sizeof(char *) * (var.nb_str + 1));
	if (!var.array_p)
		return (0);
	while (var.i < var.nb_str)
	{
		if (var.trim[++var.j] == c || var.trim[var.j] == '\0')
		{	
			var.array_p[var.i++] = ft_substr(var.trim, var.k, (var.j - var.k));
			while (var.trim[var.j] == c)
				var.j++;
			var.k = var.j;
		}
	}
	var.array_p[var.i] = 0;
	free(var.trim);
	return (var.array_p);
}
