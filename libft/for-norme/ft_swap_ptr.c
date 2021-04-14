/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swap_ptr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 16:09:28 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/04/14 16:26:55 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_ptr(void *a, void *b)
{
	void	*tmp;

	tmp = *(void **)a;
	*(void **)a = *(void **)b;
	*(void **)b = tmp;
}
