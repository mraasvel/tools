/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wrappers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 20:47:42 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/14 20:48:22 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void SetErrorData(Data *data, ErrNum type, char* message) {
	data->error.message = message;
	data->error.type = type;
}
