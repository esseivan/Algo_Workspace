// Introduction aux structures
// Calcul des aires d'un rectangle défini par 4 points

#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define cNB_RECT 3

typedef struct point // Ici, point est optionnel
{
    int16_t x;
    int16_t y;

} point_t;

typedef struct
{
    int16_t x;
    int16_t y;
} vect_t;

typedef struct
{
    point_t coord[4];
    uint32_t area;
} rect_t;

vect_t *calculateVect(point_t *A, point_t *B)
{
    return &(vect_t){B->x - A->x, B->y - A->y};
}

uint32_t calculateNorm(vect_t *vecteur)
{
    return sqrt(pow(vecteur->x, 2) + pow(vecteur->y, 2));
}

point_t createPoint(int16_t x, int16_t y)
{
    point_t output = {x, y};
    return output;
}

rect_t createRect(point_t A, point_t B, point_t C, point_t D)
{
    rect_t output = {
        {A, B, C, D}, 0};
    return output;
}

uint32_t CalculateArea_vect(rect_t *rectangle)
{
    vect_t AB = *calculateVect(&rectangle->coord[0], &rectangle->coord[1]);
    vect_t BC = *calculateVect(&rectangle->coord[1], &rectangle->coord[2]);

    uint32_t area = calculateNorm(&AB) * calculateNorm(&BC);
    return area;
}

uint32_t CalculateArea(rect_t *rectangle)
{
    // abs retourne un int (soit int32_t)
    int32_t d1 = abs((int)rectangle->coord[1].x - (int)rectangle->coord[0].x);
    int32_t d2 = abs((int)rectangle->coord[3].y - (int)rectangle->coord[0].y);
    uint32_t area = ((uint32_t)d1) * ((uint32_t)d2);
    rectangle->area = area;
    return area;
}

void printCoord(rect_t *pRect)
{
    for (int j = 0; j < 4; j++)
    {
        printf("[%3d, %3d]", pRect->coord[j].x, pRect->coord[j].y);
    }
    printf("\n");
}

void printAddresses(rect_t *pRect)
{
    for (int j = 0; j < 4; j++)
    {
        printf("[%p, %p]", &pRect->coord[j].x, &pRect->coord[j].y);
    }
    printf("\n");
}

void swap(rect_t *var1, rect_t *var2)
{
    rect_t temp = *var1; // Clonage de var1
    *var1 = *var2;
    *var2 = temp;
}

void sortRectangles(rect_t *pRect, uint16_t n)
{
    for (uint16_t i = 1; i < n; i++)
    {
        rect_t *r1 = pRect + i;
        uint32_t a1 = CalculateArea(r1);

        rect_t *r2 = pRect + (i - 1);
        uint32_t a2 = CalculateArea(r2);

        // Tri croissant => swap si r2 > r1
        if (a2 > a1)
        {
            swap(r1, r2);
        }
    }
}

int main(void)
{
    // 3 methodes de definir des structures. celle a savoir pour TE la 1e avec les {}
    rect_t TabRect[cNB_RECT] = {
        {{{5, 2}, {25, 2}, {25, 34}, {5, 34}}, 0},                                                     // area = 640
        createRect((point_t){-5, -2}, (point_t){5, -2}, (point_t){5, 8}, (point_t){-5, 8}),            // area = 100
        createRect(createPoint(10, 0), createPoint(20, 0), createPoint(20, 20), createPoint(10, 20))}; // area = 200

    printf("b)\n");
    for (int i = 0; i < cNB_RECT; i++)
    {
        printf("Rectangle %d point values are\t: ", i + 1);
        printCoord(&TabRect[i]);
    }

    printf("c)\n");
    for (int i = 0; i < cNB_RECT; i++)
    {
        printf("Rectangle %d point addresses are\t: ", i + 1);
        printAddresses(&TabRect[i]);
    }

    printf("d)\n");
    for (int i = 0; i < cNB_RECT; i++)
    {
        printf("Rectangle %d computed area is\t: ", i + 1);
        printf("%d\n", CalculateArea(&TabRect[i]));
    }

    sortRectangles(TabRect, cNB_RECT);

    printf("e)\n");
    for (int i = 0; i < cNB_RECT; i++)
    {
        printf("Rectangle %d point values are\t: ", i + 1);
        printCoord(&TabRect[i]);
    }
    for (int i = 0; i < cNB_RECT; i++)
    {
        printf("Rectangle %d computed area is\t: ", i + 1);
        printf("%d\n", CalculateArea(&TabRect[i]));
    }

    return 0;
}