#include<stdio.h>
#define MAX 3
#define ARRIVE 0
#define DEPART 1


void main()
{
    srand(time(NULL));
    struct airport a;
    int i, pri, curtime, endtime;
    double expectarrive, expectdepart;
    struct plane temp;
    int test;
    test = randomnumber(0.47);
    printf("%d", test);
    initairport(&a);

    start(&endtime, &expectarrive, &expectdepart);

    for (curtime = 1; curtime <= endtime; curtime++)
    {
        pri = randomnumber(expectarrive);

        for (i = 1; i <= pri; i++)
        {
            newplane(&a, curtime, ARRIVE);
            if (apfull(a, 'l'))
                refuse(&a, ARRIVE);
            else
                apaddqueue(&a, 'l');
        }

        pri = randomnumber(expectdepart);
        for (i = 1; i <= pri; i++)
        {
            newplane(&a, curtime, DEPART);
            if (apfull(a, 't'))
                refuse(&a, DEPART);
            else
                apaddqueue(&a, 't');
        }

        if (!(apempty(a, 'l')))
        {
            temp = apdelqueue(&a, 'l');
            land(&a, temp, curtime);
        }
        else
        {
            if (!(apempty(a, 't')))
            {
                temp = apdelqueue(&a, 't');
                fly(&a, temp, curtime);
            }
            else
                idle(&a, curtime);
        }
    }

    conclude(&a, endtime);

}