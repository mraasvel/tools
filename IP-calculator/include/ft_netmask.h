/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_netmask.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 11:44:56 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/27 19:53:00 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NETMASK_H
# define FT_NETMASK_H

typedef struct	s_ipv4
{
	unsigned int	n1;
	unsigned int	n2;
	unsigned int	n3;
	unsigned int	n4;
	unsigned int	netmask;
}				t_ipv4;

int				print_ip(t_ipv4 ip, FILE *stream);
t_ipv4			get_ip(void);
t_ipv4			get_netmask(void);
int				calculate_ip(void);

#endif
