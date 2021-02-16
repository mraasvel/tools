/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_program.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 20:15:15 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/14 20:40:17 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "prototypes.h"
#include "base.h"

void ExitProgram(Data *data) {
	if (data->error.type != success) {
		FtPerror(data->error.type, data->error.message);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
