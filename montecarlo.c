/**
 * This program calculates an estimation of Pi using the Monte Carlo
 * technique and utilizes PThreads
 * 
 * @author Alaina Finley
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

double totalDots;
double circleDots;
double piEstimation;

void *runner();

//parent thread will calculate pi which is 4 x (circleDots)/(totalDots) 
//and then output estimation of pi
int main(void) {

    //pthread identifier
    pthread_t tid;
    
    //create the child thread
    pthread_create(&tid, NULL, runner, NULL);
    
    //uncomment for two threads to be created
    //pthread_create(&tid, NULL, runner, NULL);

    //join the parent and child threads
    pthread_join(tid, NULL);

    piEstimation = 4 * (circleDots/totalDots);
    printf("The number of points in the circle are: %f\n", circleDots);
    printf("The total number of points are: %f\n", totalDots);
    printf("The estimation of pi is: %f\n", piEstimation);

    return 0;
}

//thread for random number of points
//this thread will count total number of points and number of points
//within circle
void *runner(){

    // seed the random number generator
    srandom((unsigned)time(NULL));
    double randNumber = random();
    // printf("%f\n", randNumber);
    int i;
    double x, y;
    for (i = 0; i < randNumber; i++) {
        // generate a random number between -1.0 and +1.0
        x = random()/ ((double)RAND_MAX + 1) * 2.0 - 1.0;
        y = random()/ ((double)RAND_MAX + 1) * 2.0 - 1.0;
        // printf("%f\n",x);
        if(sqrt((x*x)+(y*y)) <= 1.0){
            circleDots++;
        }
        totalDots++;
    }
    
    pthread_exit(0);
}