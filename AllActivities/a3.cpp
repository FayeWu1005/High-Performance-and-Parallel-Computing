#include <cstdio>
#include <cstdlib>
#include <omp.h>
#include <iostream>

//#define N 1000000
#define N 2000

double A[N][N], B[N][N], A_Orig[N][N], GroundTruth[N][N];

void Populate(double x[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			x[i][j] = 100.0 * rand() / RAND_MAX;
		}
	}
}

void Copy(double src[N][N], double dest[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dest[i][j] = src[i][j];
		}
	}
}

void Check(double src[N][N], double dest[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dest[i][j] != src[i][j]) {
				printf("Error detected at (%d, %d)\n", i, j);
			}
		}
	}
}

#define OP A[i][j] = A[i][j-1] + B[i][j]
#define OUTER for(int i = 1; i < N; i++)
#define INNER for(int j = 0; j < N; j++)
#define OP A[i][j] = A[i-1][j] + B[i][j]

int main()
{
	srand(12);
	Populate(A);
	Copy(A, A_Orig);
	Populate(B);

	auto start_time = omp_get_wtime();

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			OP;
		}
	}
	
	auto end_time = omp_get_wtime();

	printf("Sequential time = %0.17f\n", (end_time - start_time));
	
	////////////////////////////////////////////////////////////////
	Copy(A_Orig, A);

	auto para_start_time = omp_get_wtime();
	for (int i = 1; i < N; i++)
	{
#pragma omp parallel for
		for (int j = 0; j < N; j++)
		{
			OP;
		}
	}
	auto para_end_time = omp_get_wtime();
	printf("Parallel inner loop time = %0.17f\n", (para_end_time - para_start_time));

}