/*
 * Assume you have a method isSubstring which checks if one word
 * is a substring of another. Given two strings, s1 and s2, write code to check
 * if s2 is a rotation of s1 using only one call to isSubstring
 * (i.e., “waterbottle” is a rotation of “erbottlewat”).
 */
#include <stdio.h>
#include <string.h>

#define MAX_N 32

int main()
{
    int i, len = 0;
    char sent[2*MAX_N], word[MAX_N];
    scanf("%s %s", sent, word);

    for (i = 0; sent[i] != '\0'; ++i)
       ;
    len = i;
    for (i = 0; i < len; ++i)
       sent[len + i] = sent[i];

    if (strstr(sent, word) != NULL)
        printf("yes\n");
    else
        printf("no\n");

    return 0;
}
