#include "fruit.h"
Apple::Apple(int dx, ACL_Image*i)
	:Item(dx, 5, i)
{
	score = 1;
}

Banana::Banana(int dx, ACL_Image* i)
	: Item(dx, 8, i)
{
	score = 2;
}

Lemon::Lemon(int dx, ACL_Image* i)
	: Item(dx, 12, i)
{
	score = 5;
}

Bomb::Bomb(int dx, ACL_Image* i)
	: Item(dx, 12, i)
{
	score = -5;
}

void Bomb::toggle(Basket* basket)
{
	basket->addScore(score);
	basket->changeSpeed(5);
	startTimer(2, 5000);
}