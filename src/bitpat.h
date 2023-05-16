/**
 * \file bitpat.h
 * \author Justin Hadella (justin.hadella@gmail.com)
 * \brief 
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
 * \brief Function to set whether or not a bit *n* in set in *u*
 * 
 * \param u  The number to test
 * \param n  The bit to test
 * \return 1 if the bit *n* is in *u* is set, otherwise 0
 */
int
bit_test(unsigned int u, unsigned int n);

/**
 * \brief Function to set bit *n* in *u*
 * 
 * \param u  The number to update
 * \param n  The bit to set
 */
void
bit_set(unsigned int *u, unsigned int n);

/**
 * \brief Function to clear bit *n* in *u*
 * 
 * \param u The number to update
 * \param n The bit to clear
 */
void
bit_clr(unsigned int *u, unsigned int n);

/**
 * \brief Function to toggle bit *n* in *u*
 * 
 * \param u  The number to update
 * \param n  The bit to toggle
 */
void
bit_toggle(unsigned int *u, unsigned int n);

/**
 * \brief 
 * 
 * \param source 
 * \param pattern 
 * \param n 
 * \return int 
 */
int
bitpat_search(unsigned int u, unsigned int pattern, unsigned int n);

/**
 * \brief 
 * 
 * \param u 
 * \param n 
 * \param count 
 * \return unsigned int 
 */
unsigned int
bitpat_get(unsigned int u, unsigned int n, unsigned int count);

/**
 * \brief 
 * 
 * \param u 
 * \param pattern 
 * \param n 
 * \param count 
 * \return int 
 */
int
bitpat_set(unsigned int *u,  unsigned int pattern, unsigned int n, unsigned int count);

#ifdef __cplusplus
} 
#endif
#endif // BITPAT_h
