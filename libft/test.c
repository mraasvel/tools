/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:52:25 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/24 16:07:51 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "libft.h"

long long int	ft_strtoll(const char *nptr);

void	test(void)
{
	int	i;
	char	*str = "12'abcd'12345";

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			i = ft_strchr(str + i + 1, '\'') - str + 1;
		printf("%c", str[i]);
		i++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	test();
	return (0);
}
