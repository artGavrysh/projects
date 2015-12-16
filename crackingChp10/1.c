/*
 *  You have a basketball hoop and someone says that you can play 1 of 2 games.
 *  Game #1: You get one shot to make the hoop.
 *  Game #2: You get three shots and you have to make 2 of 3 shots.
 *  If p is the probability of making a particular shot, for which values of p should you pick one game 
 *  or the other?
 *  p > 3*p^2 - 2*p^3;
 *  p < 0.5. P(1) > P(2); Game 1 is preferable. Otherwise is Game2 is preferable
 */

/*
 *  There are three ants on different vertices of a triangle. 
 *  What is the probability of collision (between any two or all of them) if they start walking 
 *  on the sides of the triangle?
 *  Similarly find the probability of collision with ‘n’ ants on an ‘n’ vertex polygon.
 *  There are only two ways to avoid the collision: all ants move clockwise and all ants move ctrclockwise.
 *  The total number of ways is 2^3. P(collision) = 1 - 2 / 2^3 = 1 - 1/4 = 3/4;
 */

/*
 * Given two lines on a Cartesian plane, determine whether the two lines would intersect.
 * Determine the slope as delta(y)/delta(x). If the slope is the same then no intersection.
 */

/*
 * Write a method to implement *, - , / operations. You should use only the + operator.
 * * is implemented by adding to itself
 */
#include <stdio.h>

unsigned int subtract(unsigned int n, unsigned int m)
{
    int i = 0;
    unsigned int tmp = 0xffffffff;
    while( i++ < m)
        n += tmp;
    return n;
}

unsigned int divide(unsigned int n, unsigned int m)
{
    int i, counter = 0;
    unsigned int tmp = 0xffffffff;
    while (n > m)
    {
        counter++;
        i = 0;
        while (i++ < m)
            n += tmp;
    }
    return counter;
}

int main()
{
    int i, j;
    scanf("%d %d", &i, &j);

    //printf("%d\n", subtract(i,j));
    printf("%d\n", divide(i, j));

    return 0;
}

/*
 * Given two squares on a two dimensional plane, find a line that would cut these two squares in half.
 * Any line that goes through the center of a rectangle must cut it in half.
 */

/*
 *  Given a two dimensional graph with points on it, find a line which passes the most number of points.
 *  Iterate through the pairs of points and count the frequency and count the most frequent. 
 */

