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

void initqueue(struct queue* );
void addqueue(struct queue* , struct plane );
struct plane delqueue(struct queue* );
int size(struct queue );
int empty(struct queue );
int full(struct queue );
void initairport(struct airport* );
void start(int* , double* , double* );
void newplane(struct airport* , int , int );
void refuse(struct airport* , int );
void land(struct airport* , struct plane , int );
void fly(struct airport* , struct plane , int );
void idle(struct airport* , int );
void conclude(struct airport* , int );
int randomnumber(double );
void apaddqueue(struct airport* , char) ;
struct plane apdelqueue(struct airport* , char );
int apsize(struct airport , char );
int apfull(struct airport , char );
int apempty(struct airport , char );
void myrandomize();

