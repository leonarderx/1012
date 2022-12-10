#pragma once
#include <SFML/Graphics.hpp>
#include <string>

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "SFML Lesson2";
const float FPS = 60.f;

const float WINDOW_WIDTH{ 800.f };
const float WINDOW_HEIGHT{ 600.f };
const std::string WINDOW_TITLE{ "SFML Lesson3" };
const unsigned int FPS{ 60 };

const float batWidth = 20.f;
const float batHeight = 80.f;
const float batOffset = 50.f;
const sf::Vector2f batSize(20.f, 80.f);
const sf::Color leftBatColor{ 158,20,37 };
const sf::Color rightBatColor{ 20,158,49 };
const float batSpeed = 5.f;
const sf::Vector2f BAT_SIZE{ 25.f, 100.f };
const float BAT_OFFSET{ 50.f };
const sf::Color LEFT_BAT_COLOR{ 178, 38, 38 };
const sf::Color RIGHT_BAT_COLOR{ 255, 205, 50 };
const float BAT_DY = 5.f;

const float ballRadius = 25.f;
const sf::Color ballColor{ sf::Color::Yellow };
const float BALL_RADIUS = 15.f;
const sf::Color BALL_COLOR{ 250, 208, 0 };