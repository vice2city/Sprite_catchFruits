#include "item.h"
Item::Item(int tx, int s, ACL_Image * i)
	:SpriteBase(tx, 20, 60, 60, s, i)
{
	score = 0;
}

void Item::move(int winHeight)
{
	y += speed;
}

void Item::toggle(Basket* basket)
{
	basket->addScore(score);
}

bool Item::collision(Basket* basket)
{
	rect b = basket->getRect();
	if (b.y > (y + height) || (b.y + b.height/4) < y) return false;
	if (b.x < x && (b.x + b.width) > (x + width)) return true;
	return false;
}