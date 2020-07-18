#!/usr/bin/python3
'''
You have n number of locked boxes in front of you. Each box is numbered
sequentially from 0 to n - 1 and each box may contain keys to the other boxes.

Write a method that determines if all the boxes can be opened.
Box 0 is unlocked.
'''


def canUnlockAll(boxes):
    '''
    canUnlockAll - Determine if all the boxes can be opened
    @boxes: List of lists containing the keys

    Return: True if all the boxes can be opened, False otherwise
    '''
    open = {0}
    for i, box in enumerate(boxes):
        for key in box:
            if key != i:
                open.add(key)
    for i in range(len(boxes)):
        if i not in open:
            return False
    return True
