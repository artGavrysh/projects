/*
 *  Imagine a robot sitting on the upper left hand corner of an NxN grid. 
 *  The robot can only move in two directions: right and down. How many possible paths are there for the robot?
 *  FOLLOW UP
 *  Imagine certain squares are “off limits”, such that the robot can not step on them. 
 *  Design an algorithm to get all possible paths for the robot.
 */
#include <stdio.h>

int getPossiblePath(int N);

int main()
{
    int N;

    scanf("%d", &N);

    printf("%d\n", getPossiblePath(N));

    return 0;
}

int getPossiblePath(int N)
{
    if (N <= 0)
        return 0;
    else if (N < 3)
        return N;
    else
        return getPossiblePath(N-1) + 2;
}
