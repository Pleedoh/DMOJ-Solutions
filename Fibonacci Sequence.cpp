#include <iostream>
#include <vector>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef std::vector < std::vector<long long > > matrix;

void printMat(matrix A);
void initMatrix(matrix &A, int r);
matrix multMat(matrix A, matrix B);
matrix matPow(matrix A, unsigned long long p);

int main() {

	unsigned long long N;
	scan(N);

	matrix T;
	initMatrix(T, 2);

	T[0][0] = 0;
	T[0][1] = 1;
	T[1][0] = 1;
	T[1][1] = 1;

	matrix F1;
	initMatrix(F1, 2);
	F1[1][0] = 1;
	F1[1][1] = 1;

	//printMat(A);

	std::cout << multMat(matPow(T, N-1), F1)[1][1] % 1000000007;
}

matrix multMat(matrix A, matrix B) {
	int r = A.size();
	matrix AB;
	initMatrix(AB, 2);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			AB[i][j] = 0;
			for (int k = 0; k < r; k++) {
				AB[i][j] += A[i][k] * B[k][j];
				AB[i][j] %= 1000000007; //Mod the individual entries - see why this works
			}
		}
	}

	return AB;
}

void printMat(matrix A) {
	int r = A.size();
	for (int i = 0; i < r; i++) {
		std::cout << "|";
		for (int j = 0; j < r; j++) {
			std::cout << A[i][j] << " ";
		}
		std::cout << "|\n";
	}
}

void initMatrix(matrix &A,int r) {

	for(int i = 0; i < r; i++) {
		A.push_back(std::vector<long long>(r));
	}
}

matrix matPow(matrix A, unsigned long long p) {
	if (p == 1) return A;
	if (p % 2 != 0) return multMat(A, matPow(A, p - 1));

	matrix B = matPow(A, p / 2);

	return multMat(B, B);

}