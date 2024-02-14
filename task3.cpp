#include <iostream>

void visited (int** arr, int m, int n, int i, int j);

int Icelands(int** arr, int m, int n);

void print(int** arr, int m, int n);

int main()
{
	int m = 0;
	int n = 0;
	std::cout << "enter the number of rows and cols" << std::endl;
	std::cin >> m >> n;
	int** arr = new int*[m];
	for (int i = 0; i < m; ++i) {
		arr[i] = new int[n];
	}
	srand(time(0));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			arr[i][j] = rand() % 2;
		}
	}
	
	std::cout << "here is a matrix" << std::endl;
	print(arr, m, n);
	std::cout << "the objects number is" << std::endl;
	std::cout << Icelands(arr, m, n);
	for (int i = 0; i < m; ++i) {
		delete [] arr[i];
	}
		delete [] arr;
}

void visited (int** arr, int m, int n, int i, int j) {
	if (i < 0 || i >= m || j < 0 || j >= n || arr[i][j] == 0) {
		return;
	}

		arr[i][j] = 0;
		visited (arr, m, n, i, j + 1);
		visited (arr, m, n, i, j - 1);
		visited (arr, m, n, i + 1, j);
		visited (arr, m, n, i - 1, j);
}

int Icelands(int** arr, int m, int n)
{
	int count = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] == 1) {
				visited (arr, m, n, i, j);
				++count;
			}
		}
	}
	return count;
}

void print(int** arr, int m, int n)
{
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


