/*
 *  Given a sorted array of n integers that has been rotated an unknown number of times, give an O(log n) 
 *  algorithm that finds an element in the array. You may assume that the array was originally sorted in increasing order.
 *  EXAMPLE:
 *  Input: find 5 in array (15 16 19 20 25 1 3 4 5 7 10 14)
 *  Output: 8 (the index of 5 in the array)
 */
#include <stdio.h>

static int v[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};

int binarySearch(int v[], int low, int high, int key);

int main()
{
    int i, size = sizeof(v) / sizeof(v[0]);
    int key = 5;

    for (i = 0; i < size-1; ++i)
        if (v[i] > v[i+1])
            break;

    if (key == v[i])
        printf("%d\n", i);
    else if (key < v[i])
        printf("%d\n", binarySearch(v, i+1, size-1, key));
    else
        printf("%d\n", binarySearch(v, 0, i-1, key));

    return 0;
}

int binarySearch(int v[], int low, int high, int key)
{
    int mid;
    while (low != high)
    {
        mid = high - (high - low)/2;
        if (key < v[mid])
            high = mid - 1;
        else
            low = mid;
    }
    if ( key == v[high])
        return high;
    else
        return -1;
}
