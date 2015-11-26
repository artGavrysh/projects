/* Given an arrary of ints. Every element is a length of a step perpendicular to the previous.  
 * Find the area of the polygon. Can use no more then 1 extra int in memory. Should be O(n) or faster.  
 * I did not solve this on the actual interview ;) 
 */

#include <stdio.h>

int abs(int a)
{
    return (a >= 0) ? a : -a;
}

//this is adaptation of Darel Rex Finely: http://alienryderflex.com/polygon_area/
int solution(int* v, int len)
{
    int i, x_i = 0, y_i = 0, area = 0; 
    int x_j = 0, y_j = 0; 
    for (i = 0; i < len-1; ++i) 
    {
        if (i%2)
            y_i += v[i];
        else
            x_i += v[i];
        area += (x_j + x_i) * (y_i - y_j) / 2; 
        x_j = x_i;
        y_j = y_i; 
    }
    return abs(area);
}

//this is my attempt to sqeeze all that into only one additional variable
int solutionShort(int *v, int len)
{

    int area = 0;
    //area += *v * 0; // the first round
 /*   area += (*v + *v) * *(v+1); // the second round i = 1
    area += (*v + *v + *(v+2)) * 0;// third i = 2
    *v += *(v+2);
    area += (*v + *(v+2) + *v + *(v+2)) * (*(v+1)+*(v+3) - *(v+1)); // forth i = 3
    area += (*v + *(v+2) + *v + *(v+2) + *(v+4)) * 2; //fifth i = 4
    *v += *(v+4);
    area += (*v + *v) * *(v+5); //sixth i = 5
    so I hope you can see the pattern now
*/ 
    len--;
    while (len-- > 0)
    {
        if(len%2)
        {
            //area += (*v + *v + *(v+2)) * 0;
            //printf("Odd: (%d, %d) <-> (%d, %d) = %d\n", *v, *(v+1), (*v + *(v+2)), *(v+1), area);
            *(v+2) += *v;
            v += 2;
        }
        else
        {
            area += (*v + *v) * *(v+1);
            //printf("Even: (%d, %d) <-> (%d, %d) = %d\n", *v, *(v-1), *v, (*(v-1) + *(v+1)), area);
            *(v+1) += *(v-1);
        }
    } 
    return abs(area) / 2;
}

int main ()
{
    int N = 8;
    int path[8] = {6,-3,7,-4,-8,3,-5,4};
    int area = solutionShort(path, N);
    printf("%d\n", area);
    return 0;
}
