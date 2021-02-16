/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prototypes.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/16 13:25:00 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "base.h"

Bool ParseArguments(int argc, char *argv[], Data *data);

void PutBase(const char* number, int base);
void FormattedOutput(const char* num, Bool lz, int groupsize, char sep);
char *ft_ulltoa_base(unsigned long long num, int base);

void SetErrorData(Data *data, ErrNum type, char* message);
void FtPerror(ErrNum type, const char* message);

void ExitProgram(Data *data);

#endif
