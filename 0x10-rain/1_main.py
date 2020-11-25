#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [4, 3, 2, 1, 0, 1, 2]
    print(rain(walls))
