#include "basket.h"
Basket::Basket(int tx, int ty, int w, int h, int s, ACL_Image* i)
	:SpriteBase(tx, ty, w, h, s, i)
{
	score = 0;
}

void Basket::addScore(int s)
{
	score += s;
}

int Basket::getScore()
{
	return score;
}

void Basket::move(int key, int winWidth)
{
	switch (key)
	{
	case VK_LEFT:
		x -= speed;
		if (x < 0) x = 0;
		break;
	case VK_RIGHT:
		x += speed;
		if (x > (winWidth - width)) x = (winWidth - width);
		break;
	}
}

void Basket::changeSpeed(int s)
{
	speed = s;
}