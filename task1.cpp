#include <iostream>

enum class Color {Red, Green, Blue};

struct Pixel {
	Color col;
	int shade;
};

void init(Pixel** arr, int m, int n);

void print (Pixel** arr, int m, int n);

int main()
{
	int m = 0;
	int n = 0;
	std::cout << "enter the number of rows and cols" << std::endl;
	std::cin >> m >> n;
	Pixel** arr = new Pixel*[m];
	for (int i = 0; i < m; ++i) {
		arr[i] = new Pixel[n];
	}
	init(arr, m, n);
	print(arr, m, n);

	for (int i = 0; i < m; ++i){
		delete [] arr[i];
	}
	delete [] arr;

}

void init(Pixel** arr, int m, int n)
{
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			int shade = 0;
			int colorChoice = 0;
			std::cout << "enter the shade for a pixel from 0 to 255" << std::endl;
			std::cin >> shade;
			if (shade < 0) {
				shade = 0;
			} else if (shade > 255) {
				shade = 255;
			}
			std::cout << "Enter the color for Pixel: 0 for Red, 1 for Green, 2 for Blue" << std::endl;
			std::cin >> colorChoice;
			if (colorChoice < 0 || colorChoice > 2) {
				colorChoice = 0;
			} 
			switch(colorChoice) {
				case 0:
					arr[i][j] = {Color::Red, shade};
					break;
				case 1:
					arr[i][j] = {Color::Green, shade};
					break;
				case 2:
					arr[i][j] = {Color::Blue, shade};
					break;
			}
		}
	}
}

void print (Pixel** arr, int m, int n)
{
	std::cout << "Here is your image" << std::endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			std::string colorName;
			switch(arr[i][j].col) {
				case Color::Red:
					colorName = "Red";
					break;
				case Color::Green:
					colorName = "Green";
					break;
				case Color::Blue:
					colorName = "Blue";
					break;
		}
		std::cout << "Pixel (" << i << ", " << j << "): Color: " << colorName << ", Shade: " << arr[i][j].shade << std::endl;
		}
	}
}


