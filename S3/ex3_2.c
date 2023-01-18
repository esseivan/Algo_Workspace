/*
 * Fichier : ex3_2.c
 * Auteur : Esseiva Nicolas
 * Date : 12.01.23
 * Description : FIFO basique avec référencement du prochain élément
 *  Deux méthodes d'implémentation : Ajouter au début de la liste
 *  Puis retirer celui ci.
 *  Autrement il faut parcourir toute la liste pour ajouter et enlever, plus long
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct Data_s
{
    int sensorNumber;
    double sensorValue;
    long time;
    struct Data_s *pNext;
} Data_t;

/// @brief  With this function a new list is created
/// @param  -
/// @return pointer to the first element of the list
Data_t *createLIFO(void);

/// @brief  Add a new element to list
/// @param  ppList is the pointer to the list pointer
/// @param  newElement is element to be added to the list
/// @return true for success, false if the new element could not be added to the list
bool put(Data_t **ppList, Data_t newElement);

/// @brief  Add a new element to list
/// @param  ppList is the pointer to the list pointer
/// @param  newElement is the pointer to the element to be added to the list
/// @return true for success, false if the new element could not be added to the list
bool put_p(Data_t **ppList, Data_t *newElement);

/// @brief  Retrieve an element from the list
/// @param  ppList is the pointer to the list pointer
/// @param  pElement is the pointer to store the retrieved element
/// @return true for success, false if there was no element in the list.
bool get(Data_t **ppList, Data_t *pElement);

/// @brief  Shows the stored elements of the list
/// @param  -
/// @return -
void showList(Data_t *pList);

/// @brief Ecriture des donnees dans un fichier
/// @param pList is the pointer to the list pointer
void writeInFile(Data_t *pList);

void printSensor(Data_t *sensor, char *text)
{
    printf("%s sensor=%d, value=%f, time=%ld\n", text, sensor->sensorNumber, sensor->sensorValue, sensor->time);
}

int main(void)
{
    Data_t *pList = createLIFO();

    for (int i = 0; i < 5; i++)
    {
        Data_t element;
        element.sensorNumber = i; // just add some test values
        element.sensorValue = 0.1 * i * i;
        element.time = time(NULL) + i;
        printSensor(&element, "Added sensor :");
        if (!put(&pList, element))
        {
            printf("No more memory\n");
            exit(-1);
        }
    }

    printf("\nList :\n");
    showList(pList);
    writeInFile(pList);

    printf("\nGet all :\n");
    for (int i = 0; i < 5; i++)
    {
        Data_t element2;
        if (!get(&pList, &element2))
        {
            printf("Error in getting element...\n");
        }
        else
        {
            printSensor(&element2, "get:");
        }
    }

    printf("\nList :\n");
    showList(pList);

    return 0;
}

Data_t *createLIFO(void)
{
    return NULL;
}

bool put(Data_t **ppList, Data_t newElement)
{
    // LIFO : On va ajouter au début de la liste

    // Allocation de la memoire pour le nouvel element
    Data_t *pNew = (Data_t *)malloc(sizeof(Data_t));

    if (NULL == pNew) // Allocation impossible
        return false;

    *pNew = newElement; // Copie du nouvel element
    pNew->pNext = NULL; // Notre nouvel element sera le dernier

    // pNew est le nouveau premier élément, le prochain est l'actuel (ou NULL)
    pNew->pNext = *ppList;
    // Mise a jour de ppList, le début de la liste
    *ppList = pNew;

    return true;
}

bool put_p(Data_t **ppList, Data_t *newElement)
{
    // LIFO : On va ajouter au début de la liste

    newElement->pNext = NULL; // Notre nouvel element sera le dernier

    // pNew est le nouveau premier élément, le prochain est l'actuel (ou NULL)
    newElement->pNext = *ppList;
    // Mise a jour de ppList, le début de la liste
    *ppList = newElement;

    return true;
}

bool get(Data_t **ppList, Data_t *pElement)
{
    // LIFO : On retourne le dernier élément ajouté. Donc le premier de la liste

    if (NULL == *ppList) // Pointeur vers la liste null
        return false;

    Data_t *pFlow = *ppList; // Premier element de la liste
    if (NULL == pFlow)       // Liste vide. On retourne false
        return false;

    // LIFO -> on retourne le premier element
    *pElement = *pFlow;
    // Et on l'enleve, on adapte le debut de liste
    *ppList = pFlow->pNext;

    // Ne pas oublier de libérer la mémoire utilisée
    free(pFlow);

    return true;
}

void showList(Data_t *pList)
{
    if (NULL == pList)
    {
        printf("No element in list !");
        return;
    }

    while (NULL != pList) // Stop quand plus d'element
    {
        printf("sensor=%d, value=%f, time=%ld\n",
               pList->sensorNumber,
               pList->sensorValue,
               pList->time);
        pList = pList->pNext; // Prochain element
    }

    printf("\n");
}

void writeInFile(Data_t *pList)
{
    char const cFileName[] = "ex3_2.csv";
    FILE *const pFile = fopen(cFileName, "w");
    if (NULL == pFile)
    {
        printf("File not found!");
        return;
    }

    Data_t *pFlow = pList;
    while (NULL != pFlow) // Stop quand plus d'element
    {
        fprintf(pFile, "sensor=%d, value=%f, time=%ld\n",
                pFlow->sensorNumber,
                pFlow->sensorValue,
                pFlow->time);
        pFlow = pFlow->pNext; // Prochain element
    }

    fclose(pFile);
}