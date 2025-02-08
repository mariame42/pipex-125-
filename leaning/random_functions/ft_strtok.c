/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:42:01 by meid              #+#    #+#             */
/*   Updated: 2025/02/08 15:33:56 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*my_strtok(char *str, const char *delim)
{
	static char	*next_token;
	char		*token_start;

	next_token = NULL;
	if (str != NULL)
		next_token = str;
	if (next_token == NULL)
		return (NULL);
	while (*next_token && strchr(delim, *next_token))
		next_token++;
	if (*next_token == '\0')
		return (NULL);
	token_start = next_token;
	while (*next_token && !strchr(delim, *next_token))
		next_token++;
	if (*next_token)
	{
		*next_token = '\0';
		next_token++;
	}
	return (token_start);
}

int main()
{
    char *str;
    char *delim;
	
	delim = ft_strdup(" ,!?");
	
	str = strdup("Hello, world! How are you?");
    char *token = my_strtok(str, delim);

    while (token != NULL){
        printf("%s\n", token);  // Print each token
        token = my_strtok(NULL, delim);  // Continue tokenizing the same string
	}
	free (str);
}
