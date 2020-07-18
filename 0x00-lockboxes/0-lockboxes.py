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
    open = openBox(boxes, 0, {0})
    for i in range(len(boxes)):
        if i not in open:
            return False
    return True


def openBox(boxes, box, open):
    '''
    openBox - Open the specified box
    @boxes: List of lists containing the keys
    @box: The current box to open
    @open: Set containing the boxes that are currently open

    Return: Set containing all the boxes that can be opened
    '''
    if box >= len(boxes):
        return
    for key in boxes[box]:
        if key not in open:
            open.add(key)
            openBox(boxes, key, open)
    return open
