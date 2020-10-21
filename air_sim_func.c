#define MAX 3
#define ARRIVE 0
#define DEPART 1



void initqueue(struct queue* pq)
{
    pq->count = 0;
    pq->front = 0;
    pq->rear = -1;
}

void addqueue(struct queue* pq, struct plane item)
{
    
}
struct plane delqueue(struct queue* pq)
{
    struct plane p1;

}

int size(struct queue q)
{
    return q.count;
}

int empty(struct queue q)
{
    return (q.count <= 0);
}
int full(struct queue q)
{
    return (q.count >= MAX);
}


void initairport(struct airport* ap)
{
   
}

void start(int* endtime, double* expectarrive, double* expectdepart)
{
    int flag = 0;
    char wish;

    printf("Program that simulates an airport with only one runway.");
    printf("One plane can land or depart in each unit of time.");
    printf("Up to %d planes can be waiting to land or take off at any time.", MAX);
    printf("How many units of time will the simulation run?");
    scanf("%d", endtime);
    myrandomize();
    do
    {
        printf("Expected number of arrivals per unit time? ");
        scanf("%lf", expectarrive);
        printf("Expected number of departures per unit time? ");
        scanf("%lf", expectdepart);

        if (*expectarrive < 0.0 || *expectdepart < 0.0)
        {
            printf("These numbers must be nonnegative.");
            flag = 0;
        }
        else
        {
            if (*expectarrive + *expectdepart > 1.0)
            {
                printf("The airport will become saturated. Read new numbers? ");
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
        printf("Plane %d ready to land.", ap->nplanes);
        break;

    case DEPART:
        printf("Plane %d ready to take off.", ap->nplanes);
        break;
    }
}

void refuse(struct airport* ap, int action)
{
    switch (action)
    {
    case ARRIVE:

        printf("plane  %d directed to another airport.", ap->pln.id);
        break;
    case DEPART:

        printf("plane %d told to try later.", ap->pln.id);
        break;
    }
    ()++;
}

void land(struct airport* ap, struct plane pl, int curtime)
{
    int wait;

    wait = curtime - pl.tm;
    printf("%d: Plane %d landed ", curtime, pl.id);
    printf("in queue %d units ", wait);
    (ap->nland)++;
    (ap->landwait) += wait;
}

void fly(struct airport* ap, struct plane pl, int curtime)
{
    int wait;

    wait = curtime - pl.tm;
    printf("%d: Plane %d took off ", curtime, pl.id);
    printf("in queue %d units ", wait);
    (ap->ntakeoff)++;
    (ap->takeoffwait) += wait;
}

void idle(struct airport* ap, int curtime)
{
    printf("%d: Runway is idle.", curtime);
    ap->idletime++;
}

void conclude(struct airport* ap, int endtime)
{
    printf("\tSimulation has concluded after %d units." );
    printf("\tTotal number of planes processed: %d" );
    printf("\tNumber of planes landed: %d");
    printf("\tNumber of planes taken off: %d");
    printf("\tNumber of planes refused use: %d");
    printf("\tNumber left ready to land: %d");
    printf("\tNumber left ready to take off: %d");

    if (endtime > 0)
        printf("\tPercentage of time runway idle: %lf ", ((double)ap->idletime / endtime) * 100.0);

    if (ap->nland > 0)
        printf("\tAverage wait time to land: %lf ", ((double)ap->landwait / ap->nland));

    if (ap->ntakeoff > 0)
        printf("\tAverage wait time to take off: %lf ", ((double)ap->takeoffwait / ap->ntakeoff));
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
    return;
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

int apsize(struct airport ap, char type)
{
    switch (tolower(type))
    {
    case'l':
        return (size(*(ap.pl)));

    case't':
        return (size(*(ap.pt)));
    }

    return 0;
}

int apfull(struct airport ap, char type)
{
    switch (tolower(type))
    {
    case'l':
        return (full(*(ap.pl)));

    case't':
        return (full(*(ap.pt)));
    }

    return 0;
}

int apempty(struct airport ap, char type)
{
    switch (tolower(type))
    {
    case'l':
        return (empty(*(ap.pl)));

    case't':
        return (empty(*(ap.pt)));
    }

    return 0;
}

void myrandomize()
{
    srand((unsigned int)(time(NULL) % 10000));
}