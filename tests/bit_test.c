/**
 * \file bit_test.c
 * \author Justin Hadella (justin.hadella@gmail.com)
 * \brief Units for `bitpat` functions
 * \version 0.1
 * \date 2023-05-15
 */
#include <criterion/criterion.h>

#include <stdio.h>
#include <limits.h>

#include "../src/bitpat.h"

void
suite_setup()
{
	// Do nothing
}

void
suite_teardown()
{
	// Do nothing
}

TestSuite(bitpat_tests, .init=suite_setup, .fini=suite_teardown);

Test(bitpat_tests, bit_test)
{
	size_t bit_sz = 8 * sizeof(unsigned int);
	
	// In this test, only the bit under test is set
	for (int i = 0; i < bit_sz; ++i) {
		unsigned int u = 1 << i;
		cr_expect(bit_test(u, i) != 0, "bit_test(%u, %u) should be non-zero if bit is set", u, i);
	}

	// In this test, every bit is set so all bits should be set
	for (int i = 0; i < bit_sz; ++i) {
		unsigned int u = UINT_MAX;
		cr_expect(bit_test(u, i) == 1, "bit_test(%u, %u) should be 1", u, i);
	}

	// In this test, non of the bits are set
	for (int i = 0; i < bit_sz; ++i) {
		cr_expect(bit_test(0, i) == 0, "bit_test(0, %u) should be 0 for bit %u", i);
	}

	// Edge tests
	cr_expect(bit_test(1, 0) == 1, "bit_test(1, 0) should be 1");
	cr_expect(bit_test(0, 0) == 0, "bit_test(0, 0) should be 0");
	cr_expect(bit_test(0, 1) == 0, "bit_test(0, 1) should be 0");

	// Some explicit tests already covered above
	cr_expect(bit_test(3, 0) == 1, "bit_test(3, 0) should be 1");
	cr_expect(bit_test(3, 1) == 1, "bit_test(3, 1) should be 1");
	cr_expect(bit_test(3, 2) == 0, "bit_test(3, 2) should be 0");
}

Test(bitpat_tests, bit_set_test)
{
	size_t bit_sz = 8 * sizeof(unsigned int);

	// In this test, we loop and set one bit per iteration and check to see it's set
	for (int i = 0; i < bit_sz; ++i) {
		unsigned int u = 0;

		bit_set(&u, i);
		cr_expect(bit_test(u, i) == 1, "bit_test(%u, %u) should be 1 if bit is set", u, i);
	}
}

Test(bitpat_test, bit_clr_test)
{
	size_t bit_sz = 8 * sizeof(unsigned int);

	// In this test, we loop and clear one bit per iteration and check to see it's cleared
	for (int i = 0; i < bit_sz; ++i) {
		unsigned int u = UINT_MAX;

		bit_clr(&u, i);
		cr_expect(bit_test(u, i) == 0, "bit_test(%u, %u) should be 0 if bit is clear", u, i);
	}
}

Test(bitpat_test, bit_toggle_test)
{
	size_t bit_sz = 8 * sizeof(unsigned int);

	// In this test, we loop and toggle each bit per iteration and check to see if set
	for (int i = 0; i < bit_sz; ++i) {
		unsigned int u = 0;

		bit_toggle(&u, i);

		cr_expect(bit_test(u, i) == 1, "bit_test(%u, %u) should be 1 if bit is set", u, i);
	}

	// In this test, we loop and toggle each bit per iteration and check to see if cleared
	for (int i = 0; i < bit_sz; ++i) {
		unsigned int u = UINT_MAX;

		bit_toggle(&u, i);
		
		cr_expect(bit_test(u, i) == 0, "bit_test(%u, %u) should be 0 if bit is clear", u, i);
	}	
}