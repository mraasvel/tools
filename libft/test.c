/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:52:25 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/09 22:32:42 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static void	free_strings(char **strings)
{
	int	i;

	i = 0;
	while (strings[i] != NULL)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

static int	print_strings(char **strings)
{
	int	i;

	i = 0;
	while (strings[i] != NULL)
	{
		if (fprintf(stdout, "%d: %s\n", i + 1, strings[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	split_compare(const char *src, char *set)
{
	static int	cnt;
	char		**strings;

	cnt++;
	strings = ft_split_token(src, set);
	if (strings == NULL)
	{
		fprintf(stderr, "Fail at test |%d|\n", cnt);
		return (-1);
	}
	print_strings(strings);
	free_strings(strings);
	// fprintf(stderr, "Success at test |%d|\n", cnt);
	return (0);
}

int	memccpy_compare(const char *dst, const char *src, int c, size_t n)
{
	char *d1;
	char *d2;
	char *ret;
	char *ft_ret;

	d1 = ft_strdup(dst);
	if (d1 == NULL)
		return (-1);
	d2 = ft_strdup(dst);
	if (d2 == NULL)
	{
		free(d1);
		return (-1);
	}
	ft_ret = ft_memccpy(d1, src, c, n);
	ret = memccpy(d1, src, c, n);
	if (ret == ft_ret)
	{
		printf("success!\n");
	}
	else
	{
		printf("failure!\n");
		printf("%p - rl_ret\n%p - ft_ret\n\n", ret, ft_ret);
	}
	ft_free(2, d1, d2);
	return (0);
}

int	main(void)
{
	char	src[] = "abcde";
	char	dest[100];

	memccpy_compare("abcdefgh", "12345", '4', 5);
	return (0);
}
