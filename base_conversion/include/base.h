/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   base.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 18:32:57 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/15 21:15:31 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

typedef enum Bool Bool;
typedef enum ErrNum ErrNum;
typedef struct Data Data;
typedef struct ErrorData ErrorData;

enum Bool {
	false,
	true
};

enum ErrNum {
	success,
	invalid_argc,
	invalid_arg,
	not_in_base,
	malloc_error
};

struct ErrorData {
	ErrNum type;
	const char* message;
};

struct Data {
	ErrorData error;
	Bool flags[15];
	int base_from;
	unsigned long long num;
};

#endif
