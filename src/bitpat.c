/**
 * \file bitpat.c
 * \author Justin Hadella (justin.hadella@gmail.com)
 * \brief Implementation for utility functions for bit manipulation of integer numbers
 * \version 0.1
 * \date 2023-05-15
 * 
 * @copyright Copyright (c) 2023 Justin Hadella
 */
#include "bitpat.h"

#include <stdio.h>

static unsigned int calc_mask(unsigned int bits, unsigned int n, unsigned int count);
static unsigned int calc_pattern_mask(unsigned int pattern);

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
	int bits = 8 * sizeof(int);

	unsigned int mask = calc_pattern_mask(pattern);

	for (int i = n; i < bits; ++i) {
		unsigned int tmp = (u >> i) & mask;

		if (tmp == pattern) {
			return i;
		}
	}

	return -1;
}

unsigned int
bitpat_get(unsigned int u, unsigned int n, unsigned int count)
{
	unsigned int mask = calc_mask(8 * sizeof(int), n, count);

	return (u >> n) & mask;
}

void
bitpat_set(unsigned int *u,  unsigned int pattern, unsigned int n, unsigned int count)
{
	unsigned int mask = calc_mask(8 * sizeof(int), n, count);

	// Clear bits within the mask
	*u &= ~(mask << n);

	// Set the pattern
	*u |= (pattern & mask) << n;
}

static unsigned int
calc_mask(unsigned int bits, unsigned int n, unsigned int count)
{
	unsigned bits_mask = (2 << ((bits - 1) - 1)) >> n;
	unsigned count_mask = (2 << count) - 1;

	return bits_mask & count_mask;
}

static unsigned int
calc_pattern_mask(unsigned int pattern)
{
	unsigned int mask = 0;

	for (int i = 0; mask < pattern; ++i) {
		mask |= 1 << i;
	}

	return mask;
}