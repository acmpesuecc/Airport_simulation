#define MAX 15
#define ARRIVE 0
#define DEPART 1
//fill up
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#include "air_sim.h"

void initqueue(struct queue* pq)
{
    struct queue* pq = (struct queue*)malloc(sizeof(struct queue*));
    pq->count = 0;
    pq->front = 0;
    pq->rear = -1;
}

void addqueue(struct queue* pq, struct plane item)
{
  //fill up
  if (pq->count >= MAX)
    {
        printf("\nTHE QUEUE IS FULL.\n");
        return;
    }
    (pq->count)++;

    pq->rear = (pq->rear + 1) % MAX;
    pq->p[pq->rear] = item;
  

}
struct plane delqueue(struct queue* pq)
{
    struct plane p1;
    if (pq->count <= 0)
    {
        printf("\nQueue is empty.\n");
        p1.id = 0;
        p1.tm = 0;
    }
    else
    {
        (pq->count)--;
        p1 = pq->p[pq->front];
        pq->front = (pq->front + 1) % MAX;
    }
    return p1;
}

int size(struct queue* q)
{
    return q->count;
}

int empty(struct queue* q)
{
    return (q->count <= 0);
}
int full(struct queue* q)
{
    return (q->count >= MAX);
}


void initairport(struct airport* ap)
{
   //fill up
}

void start(int* endtime, double* expectarrive, double* expectdepart)
{
    int flag = 0;
    char wish;

    printf("Program that simulates an airport with only one runway.\n");
    printf("One plane can land or depart in each unit of time.\n");
    printf("Up to %d planes can be waiting to land or take off at any time.\n", MAX);
    printf("How many units of time will the simulation run?\n");
    scanf("%d", endtime);
    myrandomize();
    do
    {
        printf("Expected number of arrivals per unit time? \n");
        scanf("%lf", expectarrive);
        printf("Expected number of departures per unit time? \n");
        scanf("%lf", expectdepart);

        if (*expectarrive < 0.0 || *expectdepart < 0.0)
        {
            printf("These numbers must be nonnegative.\n");
            flag = 0;
        }
        else
        {
            if (*expectarrive + *expectdepart > 1.0)
            {
                printf("The airport will become saturated. Read new numbers? \n");
                scanf(" %c", &wish);
                if (tolower(wish) == 'y')
                    flag = 0;
                else
                    flag = 1;
            }
            else
                flag = 1;
        }
    } while (flag == 0);
}
void newplane(struct airport* ap, int curtime, int action)
{
    (ap->nplanes)++;
    ap->pln.id = ap->nplanes;
    ap->pln.tm = curtime;

    switch (action)
    {
    case ARRIVE:
        printf("\n");
        printf("Plane %d ready to land.\n", ap->nplanes);
        break;

    case DEPART:
        printf("Plane %d ready to take off.\n", ap->nplanes);
        break;
    }
}

void refuse(struct airport* ap, int action)
{
    switch (action)
    {
    case ARRIVE:

        printf("plane  %d directed to another airport.\n", ap->pln.id);
        break;
    case DEPART:

        printf("plane %d told to try later.\n\n", ap->pln.id);
        break;
    }
    (ap->nrefuse)++;//fillup
}

void land(struct airport* ap, struct plane pl, int curtime)
{
    int wait;

    wait = curtime - pl.tm;
    printf("%d: Plane %d landed \n", curtime, pl.id);
    printf("in queue %d units \n\n", wait);
    (ap->nland)++;
    (ap->landwait) += wait;
}

void fly(struct airport* ap, struct plane pl, int curtime)
{
    int wait;

    wait = curtime - pl.tm;
    printf("%d: Plane %d took off \n", curtime, pl.id);
    printf("in queue %d units \n\n", wait);
    (ap->ntakeoff)++;
    (ap->takeoffwait) += wait;
}

void idle(struct airport* ap, int curtime)
{
    printf("%d: Runway is idle.\n", curtime);
    ap->idletime++;
}

void conclude(struct airport* ap, int endtime)
{
    printf("\tSimulation has concluded after %d units.\n" );
    printf("\tTotal number of planes processed: %d\n" );
    printf("\tNumber of planes landed: %d\n");
    printf("\tNumber of planes taken off: %d\n");
    printf("\tNumber of planes refused use: %d\n");
    printf("\tNumber left ready to land: %d\n");
    printf("\tNumber left ready to take off: %d\n");

    if (endtime > 0)
        printf("\tPercentage of time runway idle: %lf \n", ((double)ap->idletime / endtime) * 100.0);

    if (ap->nland > 0)
        printf("\tAverage wait time to land: %lf \n", ((double)ap->landwait / ap->nland));

    if (ap->ntakeoff > 0)
        printf("\tAverage wait time to take off: %lf\n ", ((double)ap->takeoffwait / ap->ntakeoff));
}

int randomnumber(double expectedvalue)
{
    int n = 0; //counter of iteration
    double limit;
    double x;  //pseudo random number
    limit = exp(-expectedvalue);
    x = rand() / (double) RAND_MAX;
    while (x > limit) {
        n++;
        x *= rand() / (double) RAND_MAX;
    }
    return n;//fill up
}

void apaddqueue(struct airport* ap, char type)
{
    switch (tolower(type))
    {
    case'l':
        addqueue(ap->pl, ap->pln);
        break;

    case't':
        addqueue(ap->pt, ap->pln);
        break;
    }
}

struct plane apdelqueue(struct airport* ap, char type)
{
    struct plane p1;

    switch (tolower(type))
    {
    case'l':
        p1 = delqueue(ap->pl);
        break;

    case't':
        p1 = delqueue(ap->pl);
        break;
    }

    return p1;
}

int apsize(struct airport* ap, char type)
{
    switch (tolower(type))
    {
    case'l':
        return (size((ap->pl)));

    case't':
        return (size((ap->pt)));
    }

    return 0;
}

int apfull(struct airport* ap, char type)
{
    switch (tolower(type))
    {
    case'l':
        return (full((ap->pl)));

    case't':
        return (full((ap->pt)));
    }

    return 0;
}

int apempty(struct airport* ap, char type)
{
    switch (tolower(type))
    {
    case'l':
        return (empty((ap->pl)));

    case't':
        return (empty((ap->pt)));
    }

    return 0;
}

void myrandomize()
{
    srand((unsigned int)(time(NULL) % 10000));
}
