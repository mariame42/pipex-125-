/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cool_scanf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:58:11 by meid              #+#    #+#             */
/*   Updated: 2025/02/08 13:58:55 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	ssize_t	bytesread;
	int		value;
	char	buffer[32];

	bytesread = read(0, buffer, sizeof(buffer) - 1);
	if (bytesread <= 0)
	{
		perror("read");
		return (1);
	}
	buffer[bytesread] = '\0';
	value = atoi(buffer);
	printf("%d\n", value);
	return (0);
}
