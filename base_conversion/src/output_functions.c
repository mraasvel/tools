/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output_functions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/15 21:21:02 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/16 13:19:00 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "base.h"
#include "libft.h"

/*
** Flags:
**	lz = leading zero's
**
** groupsize:
**	if 0, all numbers are put together
**	otherwise the number is divided into multiple groups, each being groupsize size.
**	if the LZ flag is active; the first group will get leading zero's to fit the groupsize
*/

void FormattedOutput(const char* num, Bool lz, int groupsize, char sep)
{
	if (groupsize == 0) {
		printf("%s\n", num);
		return ;
	}
	int len = ft_strlen(num);
	int groups = len / groupsize;
	int rem = len % groupsize;
	if (lz == true && rem != 0) {
		//! Print leading zero's
		for (int i = 0; i < groupsize - rem; i++) {
			printf("0");
		}
	}
	//! Print initial part (if number is not a perfect multiple of groupsize)
	printf("%.*s", rem, num);
	num += rem;
	for (int i = 0; i < groups; i++) {
		//! Print seperator between each set
		if (i != 0 || rem != 0)
			printf("%c", sep);
		//! Use precision to print correct length
		printf("%.*s", groupsize, num + groupsize * i);
	}
	printf("\n");
}
