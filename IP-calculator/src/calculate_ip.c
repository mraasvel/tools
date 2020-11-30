/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_ip.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 19:27:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/26 22:16:43 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_netmask.h"
#include "ft_printf.h"
#include "libft.h"

void	print_basic_address(t_ipv4 ip, t_ipv4 netmask, t_ipv4 wildcard)
{
	ft_printf("Address:\t|%03u.%03u.%03u.%03u|\t", ip.n1, ip.n2, ip.n3, ip.n4);
	ft_putllu_base(ip.n1, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(ip.n2, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(ip.n3, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(ip.n4, 2, 8, 0);
	ft_printf("\n");
	ft_printf("Netmask:\t|%03u.%03u.%03u.%03u|\t", netmask.n1, netmask.n2, netmask.n3, netmask.n4);
	ft_putllu_base(netmask.n1, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(netmask.n2, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(netmask.n3, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(netmask.n4, 2, 8, 0);
	ft_printf("\n");
	ft_printf("Wildcard:\t|%03u.%03u.%03u.%03u|\t", wildcard.n1, wildcard.n2, wildcard.n3, wildcard.n4);
	ft_putllu_base(wildcard.n1, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(wildcard.n2, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(wildcard.n3, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(wildcard.n4, 2, 8, 0);
	ft_printf("\n");
}

t_ipv4	print_network_address(t_ipv4 ip, t_ipv4 netmask)
{
	t_ipv4	network_address;

	network_address.n1 = ip.n1 & netmask.n1;
	network_address.n2 = ip.n2 & netmask.n2;
	network_address.n3 = ip.n3 & netmask.n3;
	network_address.n4 = ip.n4 & netmask.n4;
	ft_printf("Network:\t|%03u.%03u.%03u.%03u|/%u|\t", network_address.n1, network_address.n2, network_address.n3, network_address.n4, netmask.netmask);
	ft_putllu_base(network_address.n1, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(network_address.n2, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(network_address.n3, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(network_address.n4, 2, 8, 0);
	if (network_address.n1 >> 7 == 0)
		ft_printf(" (Class A)");
	else if (network_address.n1 >> 6 == 2)
		ft_printf(" (Class B)");
	else if (network_address.n1 >> 5 == 6)
		ft_printf(" (Class C)");
	else if (network_address.n1 >> 4 == 14)
		ft_printf(" (Class D)");
	else if (network_address.n1 >> 4 == 15)
		ft_printf(" (Class E)");
	else
		ft_printf(" (No Class)");
	ft_printf("\n");
	return (network_address);
}

t_ipv4	print_broadcast_address(t_ipv4 network_address, t_ipv4 wildcard)
{
	t_ipv4	broadcast;

	broadcast.n1 = network_address.n1 + wildcard.n1;
	broadcast.n2 = network_address.n2 + wildcard.n2;
	broadcast.n3 = network_address.n3 + wildcard.n3;
	broadcast.n4 = network_address.n4 + wildcard.n4;
	ft_printf("Broadcast:\t|%03u.%03u.%03u.%03u|\t", broadcast.n1, broadcast.n2, broadcast.n3, broadcast.n4);
	ft_putllu_base(broadcast.n1, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(broadcast.n2, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(broadcast.n3, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(broadcast.n4, 2, 8, 0);
	ft_printf("\n");
	return (broadcast);
}

void	print_hostrange(t_ipv4 network, t_ipv4 broadcast, unsigned int netmask)
{
	ft_printf("Hostmin:\t|%03u.%03u.%03u.%03u|\t", network.n1, network.n2, network.n3, network.n4 + 1);
	ft_putllu_base(network.n1, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(network.n2, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(network.n3, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(network.n4 + 1, 2, 8, 0);
	ft_printf("\n");
	ft_printf("Hostmax:\t|%03u.%03u.%03u.%03u|\t", broadcast.n1, broadcast.n2, broadcast.n3, broadcast.n4 - 1);
	ft_putllu_base(broadcast.n1, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(broadcast.n2, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(broadcast.n3, 2, 8, 0);
	ft_printf(".");
	ft_putllu_base(broadcast.n4 - 1, 2, 8, 0);
	ft_printf("\n");
	if (netmask == 32)
		ft_printf("Hosts/net:\t|1|\n");
	else
		ft_printf("Hosts/net:\t|%.0f|\n", ft_pow(2, 32 - netmask) - 2);
}

t_ipv4	get_wildcard(t_ipv4 netmask)
{
	t_ipv4	wildcard;

	wildcard.n1 = ~netmask.n1 & 255;
	wildcard.n2 = ~netmask.n2 & 255;
	wildcard.n3 = ~netmask.n3 & 255;
	wildcard.n4 = ~netmask.n4 & 255;
	return (wildcard);
}

int	calculate_ip(void)
{
	t_ipv4	ip;
	t_ipv4	netmask;
	t_ipv4	wildcard;
	t_ipv4	network_address;
	t_ipv4	broadcast_address;

	ip = get_ip();
	if (ip.n1 > 255)
		return (-1);
	netmask = get_netmask();
	if (netmask.n1 > 255)
		return (-1);
	ip.netmask = netmask.netmask;
	wildcard = get_wildcard(netmask);
	ft_printf("\n");
	print_basic_address(ip, netmask, wildcard);
	printf("=>\n");
	network_address = print_network_address(ip, netmask);
	broadcast_address = print_broadcast_address(network_address, wildcard);
	print_hostrange(network_address, broadcast_address, netmask.netmask);
	return (0);
}
