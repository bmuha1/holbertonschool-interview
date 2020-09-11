#include "palindrome.h"

/**
 * is_palindrome - Check whether or not an unsigned integer is a palindrome
 *
 * @n: The unsigned integer to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reverse = 0, copy = n;

	while (copy > 0)
	{
		reverse = reverse * 10 + copy % 10;
		copy /= 10;
	}

	return (n == reverse);
}
