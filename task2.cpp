#include <iostream>

const int size = 5;

void reverse (int arr[size][size]);

void negate (int arr[size][size]);

void print (int arr[size][size]);

int main()
{
	int arr[size][size];
	srand(time(0));
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			arr[i][j] = rand() % 2;
		}
	}
	std::cout << "Your initial matrix: " << std::endl;
	print(arr);
	reverse(arr);
	negate(arr);
	std::cout << "The matrix you created: " << std::endl;
	print(arr);

}

void reverse (int arr[size][size])
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size / 2; ++j) {
			std::swap(arr[i][j], arr[i][size - 1 - j]);
		}
	}
}

void negate (int arr[size][size])
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (arr[i][j] == 1) {
				arr[i][j] = 0;
			} else {
				arr[i][j] = 1;
			}
		}
	}
}

void print (int arr[size][size])
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


