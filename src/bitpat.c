/**
 * \file bitpat.c
 * \author Justin Hadella (justin.hadella@gmail.com)
 * \brief 
 * \version 0.1
 * \date 2023-05-15
 * 
 * @copyright Copyright (c) 2023 Justin Hadella
 */
#include "bitpat.h"

int
bit_test(unsigned int u, unsigned int n)
{	
	return (u >> n) & 1;
}

void
bit_set(unsigned int *u, unsigned int n)
{
	*u |= 1 << n;
}

void
bit_clr(unsigned int *u, unsigned int n)
{
	*u &= ~(1 << n);
}

void
bit_toggle(unsigned int *u, unsigned int n)
{
	*u ^= 1 << n;
}

int
bitpat_search(unsigned int u, unsigned int pattern, unsigned int n)
{
	// TODO
	return 0;
}

unsigned int
bitpat_get(unsigned int u, unsigned int n, unsigned int count)
{
	// TODO
	return 0;
}

int
bitpat_set(unsigned int *u,  unsigned int pattern, unsigned int n, unsigned int count)
{
	// TODO
	return 0;
}
