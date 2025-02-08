/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:44:55 by meid              #+#    #+#             */
/*   Updated: 2024/10/01 22:33:11 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	loop_len(char **str)
{
	int	len;

	len = 0;
	while (**str && **str == ' ')
		(*str)++;
	if (**str == '\'')
	{
		(*str)++;
		while (**str && **str != '\'')
		{
			len++;
			(*str)++;
		}
		(*str)++;
	}
	else
	{
		while (**str && **str != ' ')
		{
			len++;
			(*str)++;
		}
	}
	return (len);
}

int	*ft_partlen(char **str, int parts)
{
	int	*parts_len;
	int	pos;
	int	len;

	pos = 0;
	parts_len = malloc(parts * sizeof(int));
	while (**str && **str == ' ')
		(*str)++;
	while (parts)
	{
		len = loop_len(str);
		parts_len[pos] = len;
		pos++;
		parts--;
	}
	return (parts_len);
}

int	ft_part_num(char *str)
{
	int		num;
	int		i;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (str[i] == 39)
		{
			num++;
			i++;
			while (str[i] != 39)
				i++;
		}
		else if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			num++;
		i++;
	}
	return (num);
}
