/*
 * Tower Of Hanoi
 * Description : Exercice de tour d'Hanoi, deplacement d'anneaux
 * Author : Esseiva Nicolas
 * Date : 20.10.22
 */

#include <stdio.h>
#include <string.h>

int toh(int disk, char src, char dest, char aux);

int main(void)
{

    int n = 0;

    char next = 'Y';
    while (next == 'y' || next == 'Y')
    {

        printf("Enter value :");
        scanf("%d", &n);

        printf("Value is %d\r\n", n);

        char src = 'A', dest = 'B', aux = 'C';
        int c = toh(n, src, dest, aux);

        printf("For n=%d, %d moves were necessary\r\n", n, c);

        printf("Continue ? Y to continue, N to exit :\r\n");
        scanf(" %c", &next);
    }

    return 0;
}

int toh(int disk, char src, char dest, char aux)
{
    int c = 0;
    if (disk == 1)
    {
        printf("Move disk %d from %c to %c\r\n", disk, src, dest);
        c++;
    }
    else
    {
        c += toh(disk - 1, src, aux, dest);

        printf("Move disk %d from %c to %c\r\n", disk, src, dest);
        c++;

        c += toh(disk - 1, aux, dest, src);
    }
    return c;
}