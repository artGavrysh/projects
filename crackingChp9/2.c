/*
 *  Write a method to sort an array of strings so that all the anagrams are next to each other.
 */
#include <stdio.h>
#include <stdlib.h>

void swap(void **v, int i, int j);
int compare (char *a, char *b);
void q_sort(void **v, int left, int right, int (*comp)(void*, void*));

static char vA[] = "alert";
static char vB[] = "mean";
static char vC[] = "gallery";
static char vD[] = "race";
static char vE[] = "offten";
static char vF[] = "allergy";
static char vG[] = "later";
static char vH[] = "name";
static char vI[] = "care";
static char vJ[] = "info";

int main()
{
    char *array[] = {vA, vB, vC, vD, vE, vF, vG, vH, vI, vJ};
    int i;
    
    q_sort((void**)array, 0, 8, (int (*)(void*, void*))compare);

    for (i = 0; i < 10; ++i)
        printf("%s\n", array[i]);

    return 0;
}

void q_sort(void *v[], int left, int right, int (*comp)(void*, void*))
{
    int i, pivot;

    if (left >= right)
        return;
    swap(v, left, (left+right)/2);
    pivot = left;
    for(i = left+1; i <= right; ++i)
        if ((*comp)(v[i], v[left]) < 0)
                swap(v, i, ++pivot);

    swap(v, left, pivot);
    q_sort(v, pivot+1, right, comp);
    q_sort(v, left, pivot-1, comp);
}

void swap(void** v, int i, int j)
{
    void* tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

int compare(char *a, char *b)
{
    int n = 0, m = 0;
    while (*a != '\0')
        n += *a++; 
    
    while (*b != '\0')
        m += *b++;
    if (n < m)
        return -1;
    else if ( n > m)
        return 1;
    else
        return 0;
}

