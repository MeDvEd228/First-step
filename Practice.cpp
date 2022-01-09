#include <iostream>


void Delenie() //деление числа на разряды 
{
	int NUM = 10819;
	int arr[5];
	int i = 0;
	while (NUM != 0)
	{
		arr[i] = NUM % 10;
		NUM /= 10;
		i++;
	}
	for (int j = 5; j != 0; j--)
	{
		std::cout << arr[j - 1] << std::endl;
	}
}


int main()
{
	int const  WIDTH_SCREEN = 120;
	int const  HEIGHT_SCREEN = 30;
	float aspect = (float)WIDTH_SCREEN / HEIGHT_SCREEN;
	float pixelAspect = 8.0f / 16.0f;

	char* screen = new char[WIDTH_SCREEN * HEIGHT_SCREEN + 1];
	screen[WIDTH_SCREEN * HEIGHT_SCREEN] = '\0';
	int tmp;
	for (int k = 0; k < 10000; k++) {
		for (int i = 0; i < WIDTH_SCREEN; i++){
			for (int j = 0; j < HEIGHT_SCREEN; j++){
				tmp = j;
				float x = (float)i / WIDTH_SCREEN * 2.0f - 1.0f;
				float y = (float)j / HEIGHT_SCREEN * 2.0f - 1.0f;
				x *= aspect * pixelAspect;
				x += sin(k * 0.001);
				char pixel = ' ';
				if (x*x + y*y< 1)
					pixel = '@';
				if (x * x + y * y < 0.8f)
					pixel = ' ';
				screen[i + j * WIDTH_SCREEN] = pixel;	
				
			}
		}
		printf(screen);
		
	}
	

	
	getchar();
}
