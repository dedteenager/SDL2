#include <SDL.h>
#include <cstdio>

//Некоторые константы нашего окна
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	//Какое окно будет рендерится
	SDL_Window* window = NULL;

	//Поверхность окна
	SDL_Surface* screenSurface = NULL;

	//Включим SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL не смог запуститься! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Создаем окно
		window = SDL_CreateWindow("Lesson 1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Окно не может быть создано! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Получаем поверхность
			screenSurface = SDL_GetWindowSurface(window);

			//Заполняем ее белым цветом
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xC0, 0xFF));

			//Обновляем поверхность
			SDL_UpdateWindowSurface(window);

			//Ждем две секунды
			SDL_Delay(5000);
		}
	}
	//И удаляем из памяти окно
	SDL_DestroyWindow(window);

	//Выход из SDL
	SDL_Quit();

	return 0;
}