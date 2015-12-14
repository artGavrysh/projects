/*
 *  A circus is designing a tower routine consisting of people standing atop one another’s shoulders. 
 *  For practical and aesthetic reasons, each person must be both shorter and lighter than the person below him or her. 
 *  Given the heights and weights of each person in the circus, write a method to compute the largest possible 
 *  number of people in such a tower.
 *  EXAMPLE:
 *  Input (ht, wt): (65, 100) (70, 150) (56, 90) (75, 190) (60, 95) (68, 110)
 *  Output: The longest tower is length 6 and includes from top to bottom: (56, 90) (60,95) (65,100) (68,110) (70,150) (75,190)
 */
#include <stdio.h>

typedef struct Person
{
    int height;
    int weight;
} Person;

static Person people[] = {
    {70, 100},
    {70, 150},
    {56, 90},
    {75, 190},
    {60, 95},
    {68, 110}
};

int main()
{
    int i,j,k;
    Person tmp;
    int size = sizeof(people)/sizeof(Person);

    for (i = 0; i < size-1; ++i)
        for (j = i+1; j < size; ++j)
        {
            if (people[i].height > people[j].height)
            {
                tmp = people[i];
                people[i] = people[j];
                people[j] = tmp;
            }
        }
                
    for (i = 0; i < size-1; ++i)
        for (j = i+1; j < size; ++j)
        {
            if (people[i].weight > people[j].weight)
            {
                if (people[i].weight < people[j+1].weight)
                {
                    k = j;
                    while (k < size-1)
                    {
                        people[k] = people[k+1];
                        k++;
                    }
                    size--;
                }
                else
                {
                    k = i;
                    while (k < size-1)
                    {
                        people[k] = people[k+1];
                        k++;
                    }
                    size--;
                }
            }
        }

    for (i = 0; i < size; ++i)
        printf("%d, %d\n", people[i].height, people[i].weight);

    return 0;
}
