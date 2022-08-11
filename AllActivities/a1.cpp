//#include <cstdio>
//#include <cstdlib>
//#include <omp.h>
//
////#define N 1000000
//#define N 2000
//
//double A[N][N], B[N][N], A_Orig[N][N], GroundTruth[N][N];
//
//void Populate(double x[N][N])
//{
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			x[i][j] = 100.0 * rand() / RAND_MAX;
//		}
//	}
//}
//
//void Copy(double src[N][N], double dest[N][N])
//{
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			dest[i][j] = src[i][j];
//		}
//	}
//}
//
//void Check(double src[N][N], double dest[N][N])
//{
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (dest[i][j] != src[i][j]) {
//				printf("Error detected at (%d, %d)\n", i, j);
//			}
//		}
//	}
//}
//
//int main()
//{
//	long long total = 0;
//
//	printf("sizeof(total) = %zu\n", sizeof(total));
//	printf("sizeof(long) = %zu\n", sizeof(long));
//	printf("sizeof(int) = %zu\n", sizeof(int));
//	printf("\n");
//	printf("============Originall sequential time test=============\n");
//	auto start_time = omp_get_wtime();
//	for (int i = 0; i <= N; i++) { 
//		total += i;
//	}
//	auto end_time = omp_get_wtime();
//
//	printf("total = %lld\n", total);
//	printf("Sequential time = %0.17f\n", (end_time - start_time));
//	printf("\n");
//
//	printf("============Parallel time test================\n");
//	long long par_total = 0;
//	auto par_start_time = omp_get_wtime();
//#pragma omp parallel for 
//	for (int i = 0; i <= N; i++) {
//		auto reg = par_total;
//		reg = reg + i;
//		par_total = reg;
//		// par_total += i;
//	}
//
//	auto par_end_time = omp_get_wtime();
//	printf("Parallel total = %lld\n", par_total);
//	printf("Parallel time = %0.17f\n", (par_end_time - par_start_time));
//	printf("\n");
//
//	printf("============Updated =============\n");
//	srand(12);
//	Populate(A);
//	Copy(A, A_Orig);
//	Populate(B);
//
//	auto new_start_time = omp_get_wtime();
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			A[i][j] = A[i][j] + B[i][j];
//		}
//	}
//
//	auto new_end_time = omp_get_wtime();
//
//	Copy(A, GroundTruth);
//	printf("Total = %lld\n", total);
//	printf("Sequential time = %0.17f\n", (new_end_time - new_start_time));
//	printf("\n");
//
//	Copy(A_Orig, A);
//	auto outer_start_time = omp_get_wtime();
//#pragma omp parallel for
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			A[i][j] = A[i][j] + B[i][j];
//		}
//	}
//	auto outer_end_time = omp_get_wtime();
//	printf("Parallel outer time = %0.17f\n", (outer_end_time - outer_start_time));
//	Check(A, GroundTruth);
//	printf("\n");
//	Copy(A_Orig, A);
//
//	auto inner_start_time = omp_get_wtime();
//
//	for (int i = 0; i < N; i++) {
//#pragma omp parallel for
//		for (int j = 0; j < N; j++) {
//			A[i][j] = A[i][j] + B[i][j];
//		}
//	}
//
//	auto inner_end_time = omp_get_wtime();
//	printf("Parallel inner time = %0.17f\n", (inner_end_time - inner_start_time));
//	Check(A, GroundTruth);
//
//	
//
//}