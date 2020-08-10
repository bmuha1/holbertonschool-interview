#!/usr/bin/python3
'''
In a text file, there is a single character H. Your text editor can execute
only two operations in this file: Copy All and Paste. Given a number n, write
a method that calculates the fewest number of operations needed to result in
exactly n H characters in the file.
'''


def minOperations(n):
    '''
    minOperations - Return the fewest number of operations needed
    @n: The number of H characters needed

    Return: The fewest number of operations needed, or 0
    '''
    if n < 2:
        return 0
    divisor, sum = 2, 0
    while divisor <= n / 2:
        if n % divisor == 0:
            n //= divisor
            sum += divisor
        else:
            divisor += 1
    return sum + n
