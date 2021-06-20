#include <time.h>
#include <sys/time.h>
#include "stdio.h"
#include <immintrin.h>

int main(int argc, char* argv[])
{
 struct timeval t_before, t_after, t_diff;
 
int i,ii,j,jj;
int N = 1000;
int blok_boyu = 100;

float A[N][N], B[N][N];
gettimeofday(&t_before, NULL);
//Start
  for (i=0; i< N; i++)
    for (j=0; j< N; j++)
      A[i][j] = A[i][j] + B[j][i];

gettimeofday(&t_after, NULL);

timersub(&t_after, &t_before, &t_diff);
 printf("1. Sonuç: %ld.%09ld s\n",(long int)t_diff.tv_sec, (long int)t_diff.tv_usec);

gettimeofday(&t_before, NULL);
//Start
for (i=0; i< N; i+=blok_boyu)
  for (j=0; j< N; j+=blok_boyu)
    for (ii=i; ii<i+blok_boyu; ii++)
      for (jj=j; jj<j+blok_boyu; jj++)
        A[ii][jj] = A[ii][jj] + B[jj][ii];
gettimeofday(&t_after, NULL);

 timersub(&t_after, &t_before, &t_diff);
 printf("2. Sonuç: %ld.%09ld s\n",(long int)t_diff.tv_sec, (long int)t_diff.tv_usec);

}