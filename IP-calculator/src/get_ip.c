/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_ip.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 18:30:32 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/25 21:56:12 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ft_netmask.h"

static int		ip_error_checks(t_ipv4 ip)
{
	int	ret;

	ret = 0;
	if (ip.n1 > 255 || ip.n2 > 255 || ip.n3 > 255 || ip.n4 > 255)
	{
		fprintf(stderr, "Illegal value for ADDRESS (");
		print_ip(ip, stderr);
		fprintf(stderr, ")\n");
		ret = -1;
	}
	return (ret);
}

t_ipv4	convert_ip(const char *buffer)
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
	return (ip);
}

t_ipv4	get_ip(void)
{
	char	buffer[50];
	int		ret;
	t_ipv4	ip;

	bzero(buffer, 50);
	fprintf(stdout, "Please enter an IP address:\n");
	ret = read(0, buffer, 50);
	if (ret == -1)
	{
		perror("read error");
		ip.n1 = 256;
		return (ip);
	}
	ip = convert_ip(buffer);
	if (ip_error_checks(ip) == -1)
		ip.n1 = 256;
	return (ip);
}
