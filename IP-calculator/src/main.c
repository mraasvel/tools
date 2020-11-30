/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 11:38:57 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/27 19:43:22 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include "ft_netmask.h"
#include "libft.h"
#include "ft_printf.h"

int		print_ip(t_ipv4 ip, FILE* stream)
{
	fprintf(stream, "%u.%u.%u.%u", ip.n1, ip.n2, ip.n3, ip.n4);
	return (0);
}

/*
** Input: netmask in dotted decimal or CIDR notation.
** Output: Netmask in dotted decimal, binary and CIDR notation,
** as well as total usable addresses (excluding network and broadcast address)
*/

int	mask_only(void)
{
	t_ipv4	netmask;

	netmask = get_netmask();
	if (netmask.n1 > 255)
		return (-1);
	ft_printf("\nNetmask:\t|%u.%u.%u.%u| = |%u| |", netmask.n1, netmask.n2, netmask.n3, netmask.n4, netmask.netmask);
	ft_putllu_base(netmask.n1, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(netmask.n2, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(netmask.n3, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(netmask.n4, 2, 8, 0);
	ft_printf("|\n");
	if (netmask.netmask == 32)
		ft_printf("Hosts/net:\t|1|\n");
	else
		ft_printf("Hosts/net:\t|%.0f|\n", ft_pow(2, 32 - netmask.netmask) - 2);
}

/*
** Input: ip1.ip2.ip3.ip4 / netmask
*/

int	main(void)
{
	t_ipv4	ip;
	t_ipv4	netmask;
	char	*test;
	int		response;

	ft_printf("Please select an option:\n");
	ft_printf("(1) - IP calculator\n");
	ft_printf("(2) - Netmask Only\n");
	scanf("%d", &response);
	if (response == 1)
	{
		if (calculate_ip() == -1)
			return (-1);
	}
	else if (response == 2)
	{
		if (mask_only() == -1)
			return (-1);
	}
	return (0);
}
