/*
 *  There are one hundred closed lockers in a hallway. 
 *  A man begins by opening all one hundred lockers. 
 *  Next, he closes every second locker. 
 *  Then he goes to every third locker and closes it if it is open or opens it if it is closed 
 *  (e.g., he toggles every third locker). 
 *  After his one hundredth pass in the hallway, in which he toggles only locker number one hundred, how many lockers are open?
 */
#include <stdio.h>

#define N_LOCKERS 100

static char v[N_LOCKERS+1];

int main()
{
    int i, j, res = 0;

    for (i = 0; i <= N_LOCKERS; ++i)
        v[i] = 1;

    for (i = 2; i <= N_LOCKERS; ++i)
    {
        if (i * i < N_LOCKERS)
        {
            for ( j = i*i; j <= N_LOCKERS; j +=i)
            {
                if ((j/i) % 2 ) //odd multiple
                    v[j] = 0;
                else
                    v[j] = 1;
            }
        }
    }

    for (i = 0; i <= N_LOCKERS; ++i)
        res += v[i];

    printf("%d\n", res);

    return 0;
}
