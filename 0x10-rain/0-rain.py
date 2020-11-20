#!/usr/bin/python3
"""
Calculate how much water will be retained after it rains
"""


def rain(walls):
    """
    Calculate how much water will be retained after it rains
    """
    if not walls:
        return 0
    retained = 0
    for i in range(1, len(walls) - 1):
        if walls[i - 1] > walls[i] < walls[i + 1]:
            retained += min(walls[i - 1], walls[i + 1]) - walls[i]
    return retained
