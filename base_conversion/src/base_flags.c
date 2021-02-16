/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   base_flags.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/16 13:13:53 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/16 13:26:51 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "prototypes.h"

typedef void (*t_base)(const char*);

static void	Base2(const char* number) {
	FormattedOutput(number, true, 4, ' ');
}
static void	Base3(const char* number) {
	FormattedOutput(number, false, 0, ' ');
}
static void	Base4(const char* number) {
	FormattedOutput(number, false, 0, ' ');
}
static void	Base5(const char* number) {
	FormattedOutput(number, false, 0, ' ');
}
static void	Base6(const char* number) {
	FormattedOutput(number, false, 0, ' ');
}
static void	Base7(const char* number) {
	FormattedOutput(number, false, 0, ' ');
}
static void	Base8(const char* number) {
	printf("0o");
	FormattedOutput(number, false, 0, ' ');
}
static void	Base9(const char* number) {
	FormattedOutput(number, false, 0, ' ');
}
static void	Base10(const char* number) {
	FormattedOutput(number, false, 3, ',');
}
static void	Base11(const char* number) {
	FormattedOutput(number, false, 0, ' ');
}
static void	Base12(const char* number) {
	FormattedOutput(number, false, 0, ' ');
}
static void	Base13(const char* number) {
	FormattedOutput(number, false, 0, ' ');
}
static void	Base14(const char* number) {
	FormattedOutput(number, false, 0, ' ');
}
static void	Base15(const char* number) {
	FormattedOutput(number, false, 0, ' ');
}
static void	Base16(const char* number) {
	printf("0x");
	FormattedOutput(number, false, 0, ' ');
}

void PutBase(const char* number, int base) {
	static const t_base bases[] = {
		Base2,
		Base3,
		Base4,
		Base5,
		Base6,
		Base7,
		Base8,
		Base9,
		Base10,
		Base11,
		Base12,
		Base13,
		Base14,
		Base15,
		Base16
	};

	bases[base - 2](number);
}
