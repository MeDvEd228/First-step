#include <iostream>

int main()
{
	int const  WIDTH_SCREEN = 120; 	// ширина окна консоли
	int const  HEIGHT_SCREEN = 30; 	// высота окна консоли 
	float aspect = (float)WIDTH_SCREEN / HEIGHT_SCREEN; // аспект хранит в себе отношение ширины и высоты 
	float pixelAspect = 8.0f / 16.0f; 		// пиксельАспект хранит в себе размер одного символа на это влияет размер шрифта в консоли 

	char* screen = new char[WIDTH_SCREEN * HEIGHT_SCREEN + 1];  //выделение памяти для массив чаров формальна вся наша картинка +1 в конце это для нулевого символа
	screen[WIDTH_SCREEN * HEIGHT_SCREEN] = '\0';
	for (int k = 0; k < 10000; k++) { // анимация длится 10 сек
		for (int i = 0; i < WIDTH_SCREEN; i++){
			for (int j = 0; j < HEIGHT_SCREEN; j++){
				float x = (float)i / WIDTH_SCREEN * 2.0f - 1.0f;
				float y = (float)j / HEIGHT_SCREEN * 2.0f - 1.0f;
				x *= aspect * pixelAspect;
				x += sin(k * 0.001);
				char pixel = ' ';
				if (x*x + y*y< 1)
					pixel = '@';
				if (x * x + y * y < 0.8f) //если убрать эту строчку получится цельный круг 
					pixel = ' '; // и эту
				screen[i + j * WIDTH_SCREEN] = pixel;	
				
			}
		}
		printf(screen);
	}
	getchar();
}
