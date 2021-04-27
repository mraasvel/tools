/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fake_malloc.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/04/27 08:54:35 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FAKE_MALLOC_H
# define FAKE_MALLOC_H

void	*fake_malloc(size_t size);

# define malloc(size) fake_malloc(size)

#endif
