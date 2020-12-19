/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vectors.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 13:29:17 by mraasvel      #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2020/12/19 21:17:04 by mraasvel      ########   odam.nl         */
=======
/*   Updated: 2020/12/18 16:43:08 by mraasvel      ########   odam.nl         */
>>>>>>> 9261496d9f2f38b5b41c790f3cb1e2e4cc4dfcee
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <stddef.h>

/*
** Integer vectors
** Can use t_vector instead if you don't mind typecasting
*/

typedef struct	s_int32vect
{
	int		*table;
	size_t	nmemb;
	size_t	size;
}		t_int32vect;

int			int32vect_pushback(int value, t_int32vect *vector);
void		int32vect_free(t_int32vect *vector);
t_int32vect	*int32vect_init(size_t initial_size);

typedef struct	s_uint32vect
{
	unsigned int		*table;
	size_t	nmemb;
	size_t	size;
}		t_uint32vect;

int				uint32vect_pushback(unsigned int value, t_uint32vect *vector);
void			uint32vect_free(t_uint32vect *vector);
t_uint32vect	*uint32vect_init(size_t initial_size);

typedef struct	s_int64vect
{
	long long	*table;
	size_t		nmemb;
	size_t		size;
}		t_int64vect;

int			int64vect_pushback(long long value, t_int64vect *vector);
void		int64vect_free(t_int64vect *vector);
t_int64vect	*int64vect_init(size_t initial_size);

typedef struct	s_uint64vect
{
	unsigned long long	*table;
	size_t				nmemb;
	size_t				size;
}		t_uint64vect;

int				uint64vect_pushback(unsigned long long value, t_uint64vect *vector);
void			uint64vect_free(t_uint64vect *vector);
t_uint64vect	*uint64vect_init(size_t initial_size);

/*
** Floating point vectors
*/

typedef struct	s_fltvect
{
	float	*table;
	size_t	nmemb;
	size_t	size;
}		t_fltvect;

int			fltvect_pushback(t_fltvect *vector, float data);
void		fltvect_free(t_fltvect *vector);
t_fltvect	*fltvect_init(size_t initial_size);

typedef struct	s_dblvect
{
	double	*table;
	size_t	nmemb;
	size_t	size;
}		t_dblvect;

int			dblvect_pushback(t_dblvect *vector, double data);
void		dblvect_free(t_dblvect *vector);
t_dblvect	*dblvect_init(size_t initial_size);

typedef struct	s_ldblvect
{
	long double	*table;
	size_t		nmemb;
	size_t		size;
}				t_ldblvect;

int			ldblvect_pushback(t_ldblvect *vector, long double data);
void		ldblvect_free(t_ldblvect *vector);
t_ldblvect	*ldblvect_init(size_t initial_size);

/*
** Vector that can take any data type
** except floats and doubles.
** 
** Pushback non_ptr: vector_pushback(vector, (void*)'a');
** Pushback string should be done like: vector_pushback(vector, ft_strdup("abcd"));
** since it will copy the ptr itself, not the contents.
**
** Send own delete function for freeing contents of void* (like free for strings/pointers)
*/

typedef struct	s_vector
{
	void	*table;
	size_t	data_size;
	size_t	nmemb;
	size_t	size;
<<<<<<< HEAD
}				t_vector;

t_vector	*vector_init(size_t initial_size, unsigned int data_type);
int			vector_pushback(t_vector *vector, void *data);
void		vector_free(t_vector *vector, void (*del)(void*));
void		*vector_add(t_vector *vector);
=======
};

typedef struct s_int32vect t_int32vect;
typedef struct s_uint32vect t_uint32vect;
typedef struct s_int64vect t_int64vect;
typedef struct s_uint64vect t_uint64vect;
typedef struct s_charvect t_charvect;
typedef struct s_strvect t_strvect;
typedef struct s_fltvect t_fltvect;
typedef struct s_dblvect t_dblvect;
>>>>>>> 9261496d9f2f38b5b41c790f3cb1e2e4cc4dfcee

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
