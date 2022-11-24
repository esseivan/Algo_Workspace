#include <stdio.h>

int main(void)
{
    int x = 0;
    char *arr2;
    char arr[] = {1, 2, 3, 4};
    char arr3[] = {5, 6, 7, 8};
    char *arr4;

    // En mémoire : 4 emplacements pour les 4 nombres
    // et un emplacement pour le pointeur vers le tableau
    arr2 = arr;
    arr4 = arr3;

    printf("%p\n", arr);
    printf("%p\n", &arr);

    return 0;
}