#include "setting.h"
#include <string>
using namespace sf;

int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	//создание объектов игры

	//ракетки
	RectangleShape leftBat, rightBat;
	leftBat.setSize(batSize);
	rightBat.setSize(batSize);
	leftBat.setFillColor(leftBatColor);
	rightBat.setFillColor(rightBatColor);
	leftBat.setPosition(batOffset, (WINDOW_HEIGHT - batHeight) / 2);
	rightBat.setPosition(WINDOW_WIDTH - batOffset, (WINDOW_HEIGHT - batHeight) / 2);
	float leftBatSpeedY = 0.f;
	float rightBatSpeedY = 0.f;
	leftBat.setSize(BAT_SIZE);
	leftBat.setFillColor(LEFT_BAT_COLOR);
	leftBat.setPosition(BAT_OFFSET, (WINDOW_HEIGHT - BAT_SIZE.y) / 2);
	rightBat.setSize(BAT_SIZE);
	rightBat.setFillColor(RIGHT_BAT_COLOR);
	rightBat.setPosition(WINDOW_WIDTH - BAT_OFFSET - BAT_SIZE.x, (WINDOW_HEIGHT - BAT_SIZE.y) / 2);

	//шарик
	CircleShape ball(ballRadius);
	ball.setFillColor(ballColor);
	ball.setPosition((WINDOW_WIDTH - 2 * ballRadius) / 2,
		(WINDOW_HEIGHT - 2 * ballRadius) / 2);
	float ball_dx = 2.f;
	float ball_dy = 2.f;
	float arr_speed[]{ -5.f, -4.f, -3.f, -2.f, -1.f, 1.f, 3.f, 4.f, 5.f };
	int index = rand() % 10;
	float ball_speedx = arr_speed[index];
	index = rand() % 10;
	float ball_speedy = arr_speed[index];

	int leftPlayerScore = 0;
	int rightPlayerScore = 0;
	Font font;

	font.loadFromFile("DS-DIGI");
	
	Text  leftPlayerScoreText;
	leftPlayerScoreText.setString(std::to_string(leftPlayerScore));

	leftPlayerScoreText.setFont(font);
	leftPlayerScoreText.setCharacterSize(64);
	leftPlayerScoreText.setPosition(550.f, 10.f);

	Text  rightPlayerScoreText;
	rightPlayerScoreText.setString(std::to_string(leftPlayerScore));

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		//1 Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}

		//2 Обновление объектов
		ball.move(ball_speedx, ball_speedy);
		if (ball.getPosition().x <= 0)
		{
			ball_speedx = -ball_speedx;
			rightPlayerScore++;
		}
		if (ball.getPosition().x >= (WINDOW_WIDTH - 2 * ballRadius))
		{
			ball_speedx = -ball_speedx;
			rightPlayerScore++;
		}
		if (ball.getPosition().y <= 0 || ball.getPosition().y >=
			(WINDOW_WIDTH - 2 * ballRadius))
		{
			ball_speedy = -ball_speedy;
		}



			//Проверка нажатий клавиш
			//если клавиша W нажата - лева ракетка вниз
			//ËÅÂÀß ÐÀÊÅÒÊÀ
			if (Keyboard::isKeyPressed(Keyboard::W)) {
				leftBatSpeedY = -batSpeed;
				leftBat.move(0.f, -BAT_DY);
			}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			leftBatSpeedY = batSpeed;
			if (Keyboard::isKeyPressed(Keyboard::S)) {
				leftBat.move(0.f, BAT_DY);
			}
		}



		//3 Отрисовка окна
		//3.1 Очистка окна
		window.clear();
		//3.2 Отрисовка объектов (В ПАМЯТИ!)
		window.draw(leftBat);
		window.draw(rightBat);
		window.draw(ball);
		window.draw(leftPlayerScoreText);
		window.draw(rightPlayerScoreText);
		//3.3 вывод на экран
		window.display();
	}

	return 0;
}