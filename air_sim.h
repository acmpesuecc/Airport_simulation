#include <conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define MAX 15
#define ARRIVE 0
#define DEPART 1
#define RAND_MAX 

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

void initqueue(struct queue*);
void addqueue(struct queue*, struct plane);
struct plane* delqueue(struct queue*);
int size(struct queue q);
int empty(struct queue q);
int full(struct queue* q);
void initairport(struct airport* ap);
void start(int* endtime, double* expectarrive, double* expectdepart);
void newplane(struct airport* ap, int curtime, int action);
void refuse(struct airport* ap, int action);
void land(struct airport* ap, struct plane* pl, int curtime);
void fly(struct airport* ap, struct plane* pl, int curtime);
void idle(struct airport* ap, int curtime);
void conclude(struct airport* ap, int endtime);
int randomnumber(double expectedvalue);
void apaddqueue(struct airport*ap, char type);
struct plane apdelqueue(struct airport*ap, char type);
int apsize(struct airport* ap, char type);
int apfull(struct airport* ap, char type);
int apempty(struct airport* ap, char type);
void myrandomize();
