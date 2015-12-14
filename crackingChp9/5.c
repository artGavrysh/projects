/*
 *  Given a sorted array of strings which is interspersed with empty strings, write a method to find 
 *  the location of a given string.
 *  Example: find “ball” in [“at”, “”, “”, “”, “ball”, “”, “”, “car”, “”, “”, “dad”, “”, “”] will return 4
 *  Example: find “ballcar” in [“at”, “”, “”, “”, “”, “ball”, “car”, “”, “”, “dad”, “”, “”] will return -1
 */
#include <stdio.h>
#include <string.h>

static char *v[] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};

int m_binarySearch(char **v, int low, int high, char *key, int(*comp)(char*, char*));

int main()
{
    char *key = "ballcar";

    int size = sizeof(v) / sizeof(v[0]);

    printf("%d\n", m_binarySearch(v, 0, size-1, key, (int (*)(char*, char*))strcmp));

    return 0;
}

int m_binarySearch(char *v[], int low, int high, char *key, int(*comp)(char*, char*))
{
    int mid, tmp;
    int res;
    while (low <= high)
    {
        mid = high - (high - low)/2;
        tmp = mid;
        while(*v[tmp] == '\0')
            tmp--;
        int res = (*comp)(key, v[tmp]); 
        if (res < 0)
            high = mid - 1;
        else if(res > 0)
            low = mid+1;
        else
            return tmp;
    }
    return -1;
}

