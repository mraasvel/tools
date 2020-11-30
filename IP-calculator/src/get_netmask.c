/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_netmask.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 15:53:12 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/26 19:27:17 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ft_netmask.h"
#include "ft_printf.h"

static int	check_format(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != 0)
	{
		if (buffer[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

static int	netmask_error_checks(unsigned int mask)
{
	if (mask == 0 || mask > 32)
	{
		fprintf(stderr, "Illegal value for NETMASK (%d)\n", mask);
		return (-1);
	}
	return (0);
}

static int	mask_ip_error_check(t_ipv4 mask)
{
	if (mask.n1 > 255 || mask.n2 > 255 || mask.n3 > 255 || mask.n4 > 255 || mask.netmask == -1)
	{
		fprintf(stderr, "Illegal value for NETMASK (");
		print_ip(mask, stderr);
		fprintf(stderr, ")\n");
		return (-1);
	}
	return (0);
}

static t_ipv4	int_to_mask(unsigned int mask)
{
	t_ipv4			netmask;
	unsigned char	base;

	base = 255;
	if (mask >= 8)
		netmask.n1 = (unsigned char)base;
	else
		netmask.n1 = (unsigned char)(base << (8 - mask));
	if (mask >= 16)
		netmask.n2 = base;
	else if (mask < 8)
		netmask.n2 = 0;
	else
		netmask.n2 = (unsigned char)(base << (16 - mask));
	if (mask >= 24)
		netmask.n3 = base;
	else if (mask < 16)
		netmask.n3 = 0;
	else
		netmask.n3 = (unsigned char)(base << (24 - mask));
	if (mask >= 32)
		netmask.n4 = base;
	else if (mask < 24)
		netmask.n4 = 0;
	else
		netmask.n4 = (unsigned char)(base << (32 - mask));
	netmask.netmask = mask;
	return (netmask);
}

static int		check_mask_bits(t_ipv4 netmask)
{
	int	tmp;
	int	i;
	int	bit_count;
	int	check;

	tmp = netmask.n1 << 24;
	tmp += netmask.n2 << 16;
	tmp += netmask.n3 << 8;
	tmp += netmask.n4;
	bit_count = 0;
	check = 0;
	while (tmp != 0)
	{
		if (tmp >> 31 == 0)
		{
			check = 1;
		}
		else if (check == 0)
			bit_count++;
		else
			return (-1);
		tmp = tmp << 1;
	}
	return (bit_count);
}

static t_ipv4	mask_to_int(char *buffer)
{
	t_ipv4	ip;
	int		i;

	i = 0;
	ip.n1 = atoi(buffer);
	while (isdigit(buffer[i]) != 0)
		i++;
	i++;
	ip.n2 = atoi(buffer + i);
	while (isdigit(buffer[i]) != 0)
		i++;
	i++;
	ip.n3 = atoi(buffer + i);
	while (isdigit(buffer[i]) != 0)
		i++;
	i++;
	ip.n4 = atoi(buffer + i);
	ip.netmask = check_mask_bits(ip);
	return (ip);
}

t_ipv4	get_netmask(void)
{
	char	buffer[50];
	int		ret;
	int		mask;
	t_ipv4	netmask;

	bzero(buffer, 50);
	ft_printf("Please enter a netmask: (either in dotted decimal or CIDR notation)\n");
	ret = read(0, buffer, 50);
	if (ret == -1)
	{
		perror("read");
		netmask.n1 = 256;
		return (netmask);
	}
	if (check_format(buffer) == 0)
	{
		mask = atoi(buffer);
		if (netmask_error_checks(mask) == -1)
		{
			netmask.n1 = 256;
			return (netmask);
		}
		netmask = int_to_mask(atoi(buffer));
	}
	else
	{
		netmask = mask_to_int(buffer);
		if (mask_ip_error_check(netmask) == -1)
			netmask.n1 = 256;
	}
	return (netmask);
}
