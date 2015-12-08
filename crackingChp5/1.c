/*
 *  You are given two 32-bit numbers, N and M, and two bit positions, i and j. 
 *  Write a method to set all bits between i and j in N equal to M 
 *  (e.g., M becomes a substring of N located at i and starting at j).
 *  EXAMPLE:
 *  Input: N = 10000000000, M = 10101, i = 2, j = 6
 *  Output: N = 10001010100
 */
#include <stdio.h>

#define MAX_N 64

static int N = 0x0400; //0000 0100 0000 0000;
static int M = 0x0015; //1 0101;

int main()
{
    int i = 2, j = 6;
    
    int mask = 0xffff >> (16-j+1);
    mask = mask << i;
    M = M << i;
    M = M & mask;
    N =  N & (mask ^ 0xffff);
    N = N ^ M;
    
    printf("0x%04x\n", N); //0x0454       0000 0100 0101 0100

    return 0;
}

