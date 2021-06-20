#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>
#include <windows.h>
#include <ctime>


using namespace std;

int main(){
	
  LARGE_INTEGER li;
  
	__int64 CounterStart = 0;
	
	if (!QueryPerformanceFrequency(&li)) cout<<"QueryPerformanceFrequency failed\n";
	double PCFreq = (double) li.QuadPart;


 	// DEGISKENLERIN TANIMLANMASI
    int  i, j, k, ** A, ** B, ** C;

    // MATRISLER
    A = new int * [25];
    B = new int * [25];
    C = new int * [25];
    
    for (i = 0; i < 25; i++) A[i] = new int[25];
    for (i = 0; i < 25; i++) B[i] = new int[25];
    for (i = 0; i < 25; i++) C[i] = new int[25];
    
    // CARPMA KOSULUNUN KONTROLU

        // MATRISLERE RASTGELE DEGERLERIN ATANMASI
        for (i = 0; i < 25; i++)
            for (j = 0; j < 25; j++) {
                A[i][j]=rand()%10;
                B[i][j]=rand()%10;
            }
        cout << endl;

   // start time
	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
	
	//3408 3376 3303 - 
	
    CRITICAL_SECTION kritik;
    InitializeCriticalSection(&kritik);

    EnterCriticalSection(&kritik);
    //SONUC MATRISINE AKTARIM
    for (i = 0; i < 25; i++)
            for (j = 0; j < 25; j++)
                for (k = 0; k < 25; k++)
                    C[i][j] += A[i][k] * B[k][j];
        cout << "\nA*B=\n";
    LeaveCriticalSection(&kritik);
    
    QueryPerformanceCounter(&li);
    
	cout <<"Elapsed time:" <<((double) (li.QuadPart - CounterStart)) / PCFreq;

     // SONUC MATRISININ YAZDIRILMASI
        for (i = 0; i < 25; i++){
             cout<<endl;
            for (j = 0; j < 25; j++){
                cout << C[i][j] << " ";}
		}

    return 0;}
