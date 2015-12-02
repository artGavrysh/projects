/*
 * Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, 
 * write a method to rotate the image by 90 degrees. Can you do this in place?
 */

#include <stdio.h>

#define N 5 

//typedef struct pix {unsigned char x[4];} pix;

static char screen[N][N] = {{'a', 'b', 'c', 'd', 'e'},
                            {'f', 'g', 'h', 'i', 'j'},
                            {'k', 'l', 'm', 'n', 'o'},
                            {'p', 'q', 'r', 's', 't'},
                            {'u', 'v', 'w', 'x', 'y'}};

int main()
{
    int i, j;
    /*rotate the scree
     * first transpose then reverse the rows
    */ 
    char tmp;
    for( i = 0; i < N - 1; ++i)
        for (j = i + 1; j < N; ++j)
        {
            tmp = screen[i][j];
            screen[i][j] = screen[j][i];
            screen[j][i] = tmp;
        }
            
    for (i = N-1; i >= 0; --i)
    {
        for (j = 0; j < N; ++j)
            printf("%c, ", screen[i][j]);
        printf("\n");
    }
    
    return 0;
}
