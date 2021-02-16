/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putull_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/15 21:08:54 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/15 23:30:25 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Basic base conversion
** Technically works for base 2-36
*/

static void	fill_string(char *result, unsigned long long num, int base, int i)
{
	i--;
	while (i >= 0)
	{
		result[i] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[num % base];
		num = num / base;
		i--;
	}
}

char	*ft_ulltoa_base(unsigned long long num, int base)
{
	int		len;
	char	*result;

	if (!ft_inrange(base, 2, 36))
		return (NULL);
	len = ft_unumlen_base(num, base);
	result = (char*)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	fill_string(result, num, base, len);
	result[len] = '\0';
	return (result);
}
