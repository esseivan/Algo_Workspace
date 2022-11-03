// Ex 1.5
// Bubble sort

#include <stdio.h>
#include <stdint.h>

int BubbleSort(uint16_t *A, int n);
void BubbleSort2(uint16_t *Tab, int n, int* permut);
int BubbleSort_Arrays(uint16_t Tab[], int n);
void PrintTableau(uint16_t *Tab, int n);
void PrintTableau_Tab(uint16_t Tab[], int n); // Meme chose que l'autre fonction mais sous forme tableau
void swap(uint16_t *a, uint16_t *b);

int main(void)
{
    uint16_t Tab[] = {28, 3, 45, 1, 5, 17, 33, 32, 42, 2};
    int const n = sizeof(Tab) / sizeof(Tab[0]);

    // Afficher tableau
    printf("Tableau non trie : ");
    PrintTableau(Tab, n);
    printf("\n");

    // int permutations = BubbleSort_Arrays(Tab, n);
    int permutations = BubbleSort(Tab, n);
    // int permutations;
    // BubbleSort2(Tab, n, &permutations);

    printf("Tableau trie : ");
    PrintTableau(Tab, n);
    printf("\n");

    printf("Le nombre de permutations requises pour trier le tableau est : %d", permutations);

    return 0;
}

void PrintTableau(uint16_t *Tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d; ", *(Tab + i));
    }
}

void PrintTableau_Tab(uint16_t Tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d; ", Tab[i]);
    }
}

void swap(uint16_t *a, uint16_t *b)
{
    uint16_t temp = *a;
    *a = *b;
    *b = temp;
}

int BubbleSort(uint16_t *Tab, int n)
{
    int permutations = 0;
    int s = 0;
    do
    {
        s = 0;
        for (int i = 1; i < n; i++)
        {
            if (*(Tab + i) < *(Tab + i - 1)) // Dereferenciation
            {
                swap((Tab + i), (Tab + i - 1)); // Envoi des adresses
                permutations++;
                s++;
            }
        }

    } while (s != 0);

    return permutations;
}

void BubbleSort2(uint16_t *Tab, int n, int* permut)
{
    int permutations = 0;
    int s = 0;
    do
    {
        s = 0;
        for (int i = 1; i < n; i++)
        {
            if (*(Tab + i) < *(Tab + i - 1)) // Dereferenciation
            {
                swap((Tab + i), (Tab + i - 1)); // Envoi des adresses
                permutations++;
                s++;
            }
        }

    } while (s != 0);

    *permut = permutations;
}

int BubbleSort_Arrays(uint16_t Tab[], int n)
{
    int permutations = 0;
    int s = 0;
    do
    {
        s = 0;
        for (int i = 1; i < n; i++)
        {
            if (Tab[i] < Tab[i-1]) // Dereferenciation
            {
                swap(&Tab[i], &Tab[i-1]); // Envoi des adresses
                permutations++;
                s++;
            }
        }

    } while (s != 0);

    return permutations;
}
