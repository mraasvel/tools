/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 23:35:27 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/27 09:23:08 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

/*
** The enums make it easy to communicate using function returns
*/

typedef enum	e_ret
{
	error = -1,
	eof_read,
	line_read,
	cont_read
}				t_ret;

/*
** Position = last newline position
** It being zero means that the buffer has been cleared
*/

typedef struct	s_buffer
{
	char	buffer[BUFFER_SIZE + 1];
	int		position;
}				t_buffer;

int				get_next_line(int fd, char **line);

#endif
