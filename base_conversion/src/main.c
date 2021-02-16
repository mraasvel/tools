/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 18:21:24 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/16 13:25:20 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include "base.h"
#include "prototypes.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static ErrNum OutputNumber(unsigned long long number, int base)
{
	char *result;

	result = ft_ulltoa_base(number, base);
	if (result == NULL) {
		return (malloc_error);
	}
	// Set specific flags for specific bases
	PutBase(result, base);
	free(result);
	return (success);
}

void PrintBases(Data *data) {
	for (int i = 0; i < 15; i++) {
		if (data->flags[i]) {
			if (OutputNumber(data->num, i + 2) != success) {
				SetErrorData(data, malloc_error, NULL);
				ExitProgram(data);
			}
		}
	}
}

/*
** Idea: run program and give number + base it is in, and base to convert it to.
**
** ./convert [NUM] [FROM_BASE] [TO_BASE]
** Example:
** 	./convert 1234 10 16
** Output:
** 	0x4D2
** Idea: any number of TO_BASE's can be given (2 - 16)
** 15 valid bases
** No to_base argument: default = 2, 10 and 16
** Output function: Get string version of string first, then fix output using printf easily
**
** Binary: xxxx xxxx xxxx (space every 4 chars (leading zero's otherwise))
** Hex: 0xhhhh hhhh 0x prefix + space every 4 chars (leading zero's otherwise)
** Decimal: xx xxx xxx (space every 3 chars, no leading zero's)
*/	

int	main(int argc, char *argv[]) {
	Data data;

	bzero(&data, sizeof(Data));
	if (!ParseArguments(argc, argv, &data)) {
		ExitProgram(&data);
	}
	PrintBases(&data);
	return (0);
}
