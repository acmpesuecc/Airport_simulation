#include <conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define MAX 3
#define ARRIVE 0
#define DEPART 1

struct plane
{
    int id;
    int tm;
};

struct queue
{
    int count;
    int front;
    int rear;
    struct plane p[MAX];
};

struct airport
{
    struct queue landing;
    struct queue takeoff;
    struct queue* pl;
    struct queue* pt;
    int idletime;
    int landwait, takeoffwait;
    int nland, nplanes, nrefuse, ntakeoff;
    struct plane pln;
};