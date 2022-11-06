// Ex 1.7
// Structure (time)

#include <stdio.h>
#include <time.h>
#include <limits.h>

// c)
// Affiche le texte et la date
void PrintTime(char *text, struct tm *const val)
{
    printf(text,
           val->tm_mday, val->tm_mon + 1, val->tm_year + 1900,
           val->tm_hour, val->tm_min, val->tm_sec);
}

char *GetWeekDay(int dayNum)
{
    // tm_wday : Days since Sunday (0-6)

    // Une autre methode est avec un tableau mais cela utilise
    // de la memoire ram alors qu'ici uniquement de la memoire programme

    switch (dayNum)
    {
    case 0:
        return "Dimanche";
    case 1:
        return "Lundi";
    case 2:
        return "Mardi";
    case 3:
        return "Mercredi";
    case 4:
        return "Jeudi";
    case 5:
        return "Vendredi";
    case 6:
        return "Samedi";
    default:
        return "Undefined";
    }
}

int main(void)
{
    // a)
    // recuperer le temps
    time_t const cTimeSec = time(NULL);

    // convertir dans la structure tm
    struct tm *const pCurrTime = localtime(&cTimeSec);
    PrintTime("a) Current date and time is\t: %02d.%02d.%04d %02d:%02d:%02d\n", pCurrTime);

    // b)
    // Temps maximum
    time_t const cTimeMaxSec = _I32_MAX;
    // convertir dans la structure tm
    struct tm *const pMaXTime = localtime(&cTimeMaxSec);

    PrintTime("b) Overflow will occur 1s after\t: %02d.%02d.%04d %02d:%02d:%02d\n", pMaXTime);

    // c)
    // La fonction localTime utilise une unique structure. Donc l'ancien pointeur n'est plus a jour !!
    struct tm *pTime = localtime(&cTimeSec);
    PrintTime("c) Current date and time is\t: %02d.%02d.%04d %02d:%02d:%02d\n", pTime);
    pTime = localtime(&cTimeMaxSec);
    PrintTime("   Overflow will occur 1s after\t: %02d.%02d.%04d %02d:%02d:%02d\n", pTime);

    // d)
    pTime = localtime(&cTimeSec);
    printf("d) Current week day is\t\t: %s", GetWeekDay(pTime->tm_wday));

    return 0;
}