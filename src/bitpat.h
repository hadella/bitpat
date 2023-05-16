/**
 * \file bitpat.h
 * \author Justin Hadella (justin.hadella@gmail.com)
 * \brief Definitions for utility functions for bit manipulation of integer numbers
 * \version 0.1
 * \date 2023-05-15
 * 
 * @copyright Copyright (c) 2023 Justin Hadella
 * 
 */
#ifndef BITPAT_h
#define BITPAT_h

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Predicate function indicates whether or not bit *n* in *u* is set
 * 
 * *n* == 0 represents the least significant bit
 * 
 * \param u  The number to test
 * \param n  The bit to test
 * \return 1 if bit *n* is in *u* is set, otherwise 0
 */
int
bit_test(unsigned int u, unsigned int n);

/**
 * \brief Function to set bit *n* in *u*
 * 
 * *n* == 0 represents the least significant bit
 * 
 * \param u  The number to update
 * \param n  The bit to set
 */
void
bit_set(unsigned int *u, unsigned int n);

/**
 * \brief Function to clear bit *n* in *u*
 * 
 * *n* == 0 represents the least significant bit
 * 
 * \param u The number to update
 * \param n The bit to clear
 */
void
bit_clr(unsigned int *u, unsigned int n);

/**
 * \brief Function to toggle bit *n* in *u*
 * 
 * *n* == 0 represents the least significant bit
 * 
 * \param u  The number to update
 * \param n  The bit to toggle
 */
void
bit_toggle(unsigned int *u, unsigned int n);

/**
 * \brief Function to search *u* for the *pattern* at an offset *n*
 * 
 * *n* == 0 represents the least significant bit
 * 
 * \param source  the number to examine
 * \param pattern the pattern to search for
 * \param n       the index to start searching at
 * 
 * \return the index where the pattern is found, otherwise -1 if the pattern was not found
 */
int
bitpat_search(unsigned int u, unsigned int pattern, unsigned int n);

/**
 * \brief Function gets the pattern of *count* bits from position *n* in *u*
 * 
 * *n* == 0 represents the least significant bit
 * 
 * \param u     the number to extract the pattern from
 * \param n     the bit position the pattern should start at
 * \param count the number of bits in the pattern
 * 
 * \return the bit pattern found
 */
unsigned int
bitpat_get(unsigned int u, unsigned int n, unsigned int count);

/**
 * \brief Function sets a specific set of bits in *u* with a *pattern*
 * 
 * *n* == 0 represents the least significant bit
 * 
 * \param u        the number to modify
 * \param pattern  the pattern to set
 * \param n        the bit position the pattern should start at
 * \param count    the number of bits in the pattern
 */
void
bitpat_set(unsigned int *u, unsigned int pattern, unsigned int n, unsigned int count);

#ifdef __cplusplus
} 
#endif
#endif // BITPAT_h
