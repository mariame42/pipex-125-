/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:20:24 by meid              #+#    #+#             */
/*   Updated: 2024/10/01 22:13:19 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	free_array(char **array)
{
	int	i;

	if (!array)
		return (0);
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

static int	ft_partnum(char *str, char c)
{
	int		num;
	int		i;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			num++;
		i++;
	}
	return (num);
}

static char	*get_word(char **arr, char **s, char c)
{
	size_t	word_len;
	char	*word;

	while (**s == c && **s)
		(*s)++;
	if (!**s)
		return (NULL);
	if (!ft_strchr(*s, c))
		word_len = ft_strlen(*s);
	else
		word_len = ft_strchr(*s, c) - *s;
	word = ft_substr(*s, 0, word_len);
	if (!word)
	{
		free(arr);
		return (NULL);
	}
	*s += word_len;
	return (word);
}

char	**ft_split(char *s, char c)
{
	char	**arr;
	char	*word;
	int		i;
	int		parts;

	if (!s)
		return (NULL);
	parts = ft_partnum(s, c);
	arr = (char **)malloc((parts + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	word = get_word(arr, &s, c);
	while (word != NULL)
	{
		arr[i] = word;
		if (!arr[i])
		{
			free_array(arr);
		}
		i++;
		word = get_word(arr, &s, c);
	}
	return (arr[i] = NULL, arr);
}
