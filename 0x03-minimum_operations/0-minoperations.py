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
    if n < 2 or not isinstance(n, int):
        return 0
    if n < 6:
        return n
    min = {}
    for i in range(2, 6):
        min[i] = i
    for i in range(n - 1, 1, -1):
        if n % i == 0:
            if not min.get(i):
                min[i] = minOperations(i)
            return min[i] + n // i
    return n
