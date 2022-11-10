// Introduction aux structures

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
    point_t coord[4];
    uint32_t area;
} rect_t;

void CalculateArea(rect_t rectangle)
{
    rectangle.area = 0;
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

void printCoord(rect_t *pRect)
{
    for (int j = 0; j < 4; j++)
    {
        printf("[%3d, %3d]", pRect->coord[j].x, pRect->coord[j].y);
    }
    printf("\n");
}

int main(void)
{
    // 3 methodes de definir des structures. celle a savoir pour TE la 1e avec les {}
    rect_t TabRect[cNB_RECT] = {
        {{{5, 2}, {25, 2}, {25, 24}, {5, 24}}, 0},                                                     // area = 640
        createRect((point_t){-5, -2}, (point_t){5, -2}, (point_t){5, 8}, (point_t){-5, 8}),            // area = 100
        createRect(createPoint(10, 0), createPoint(20, 0), createPoint(20, 20), createPoint(10, 20))}; // area = 200

    for (int i = 0; i < cNB_RECT; i++)
    {
        printf("Rectangle %d point values are\t: ", i + 1);
        printCoord(&TabRect[i]);
    }

    return 0;
}