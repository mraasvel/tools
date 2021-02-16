/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 18:34:56 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/15 21:08:19 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "base.h"
#include "prototypes.h"

static Bool StringTest(const char* str, int (*Test)(int)) {
	for (size_t i = 0; str[i] != '\0'; i++) {
		if (!Test(str[i])) {
			return (false);
		}
	}
	return (true);
}

static Bool IsInBase(int num, const char* base, int base_from) {
	for (int i = 0; i < base_from; i++) {
		if (num == base[i]) {
			return (true);
		}
	}
	return (false);
}

static Bool IsValidNumber(char* str, int base_from) {
	const char* base = "0123456789ABCDEF";
	ft_strupcase(str);
	for (int i = 0; str[i] != '\0'; i++) {
		if (!IsInBase(str[i], base, base_from)) {
			return (false);
		}
	}
	return (true);
}

static Bool IsValidBase(const char* str, int base) {
	if (!StringTest(str, ft_isdigit)) {
		return (false);
	} else if (!ft_inrange(base, 2, 16)) {
		return (false);
	}
	return (true);
}

/*
** Type of argument error: invalid base, invalid number of arguments etc...
** Base range = 2-16
*/

Bool ParseArguments(int argc, char *argv[], Data *data) {

	if (argc < 3) {
		SetErrorData(data, invalid_argc, NULL);
		return (false);
	} else if (argc == 3) {
		//! Default conversions are base 2, 10 and 16
		data->flags[0] = true;
		data->flags[8] = true;
		data->flags[14] = true;
	}

	for (int i = 2; i < argc; i++) {
		int base = ft_atoi(argv[i]);
		if (!IsValidBase(argv[i], base)) {
			SetErrorData(data, invalid_arg, argv[i]);
			return (false);
		} else if (i != 2) {
			data->flags[base - 2] = true;
		} else {
			data->base_from = base;
		}
	}

	if (!IsValidNumber(argv[1], data->base_from)) {
		SetErrorData(data, not_in_base, argv[1]);
		return (false);
	} else {
		data->num = ft_atoull_base(argv[1], data->base_from);
	}
	return (true);
}
