#pragma once
class Game
{
public:
	Game();
	bool init();
	bool loop();

private:
	unsigned framePerSecond;
	unsigned screenWidth;
	unsigned screenHeight;
};

