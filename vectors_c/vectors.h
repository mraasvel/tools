/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vectors.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 13:29:17 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/18 16:43:08 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <stddef.h>

struct	s_int32vect
{
	int		*table;
	size_t	nmemb;
	size_t	size;
};

struct	s_uint32vect
{
	unsigned int		*table;
	size_t	nmemb;
	size_t	size;
};

struct	s_int64vect
{
	long long	*table;
	size_t		nmemb;
	size_t		size;
};

struct	s_uint64vect
{
	unsigned long long	*table;
	size_t				nmemb;
	size_t				size;
};

struct	s_charvect
{
	char	*str;
	size_t	nmemb;
	size_t	size;
};

struct	s_strvect
{
	char	**str;
	size_t	nmemb;
	size_t	size;
};

struct	s_fltvect
{
	float	*table;
	size_t	nmemb;
	size_t	size;
};

struct	s_dblvect
{
	double	*table;
	size_t	nmemb;
	size_t	size;
};

typedef struct s_int32vect t_int32vect;
typedef struct s_uint32vect t_uint32vect;
typedef struct s_int64vect t_int64vect;
typedef struct s_uint64vect t_uint64vect;
typedef struct s_charvect t_charvect;
typedef struct s_strvect t_strvect;
typedef struct s_fltvect t_fltvect;
typedef struct s_dblvect t_dblvect;

t_int32vect		*int32vect_init(size_t initial_size);
int				int32vect_pushback(int value, t_int32vect *vector);
void			int32vect_free(t_int32vect *vector);

t_uint32vect	*uint32vect_init(size_t initial_size);
int				uint32vect_pushback(unsigned int value, t_uint32vect *vector);
void			uint32vect_free(t_uint32vect *vector);

t_int64vect		*int64vect_init(size_t initial_size);
int				int64vect_pushback(long long value, t_int64vect *vector);
void			int64vect_free(t_int64vect *vector);

t_uint64vect	*uint64vect_init(size_t initial_size);
int				uint64vect_pushback(unsigned long long value, t_uint64vect *vector);
void			uint64vect_free(t_uint64vect *vector);

#endif
