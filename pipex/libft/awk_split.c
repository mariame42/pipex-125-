/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awk_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:48:31 by meid              #+#    #+#             */
/*   Updated: 2024/10/01 22:16:13 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**get_array(char **arr, char **s, int *parts_len)
{
	int	i;
	int	len_p;

	i = 0;
	len_p = 0;
	while (**s == ' ' && **s)
		(*s)++;
	while (**s)
	{
		arr[i] = ft_substr(*s, 0, parts_len[len_p]);
		if (!arr[i])
		{
			free_array(arr);
			return (NULL);
		}
		*s += parts_len[len_p];
		i++;
		len_p++;
		while ((**s == ' ' || **s == '\'') && **s)
			(*s)++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**split_awk(char *s, t_fixed *f)
{
	char	**arr;
	char	*str;
	int		*parts_len;
	char	*st;
	char	*soso;

	st = ft_strdup(s);
	str = st;
	soso = st;
	if (!str)
		return (NULL);
	f->part_num_awk = ft_part_num(str);
	parts_len = ft_partlen(&str, f->part_num_awk);
	arr = (char **)malloc((f->part_num_awk + 1) * sizeof(char *));
	if (!arr)
	{
		free(parts_len);
		free(st);
		return (NULL);
	}
	arr = get_array(arr, &soso, parts_len);
	free(parts_len);
	free(st);
	return (arr);
}
