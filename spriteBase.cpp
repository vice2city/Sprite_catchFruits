#include "spriteBase.h"

SpriteBase::SpriteBase(int tx, int ty, int w, int h, int s, ACL_Image* i)
{
	x = tx;
	y = ty;
	speed = s;
	width = w;
	height = h;
	img = i;
}

void SpriteBase::drawSprite()
{
	putImageScale(img, x, y, width, height);
}

void SpriteBase::move(int dx, int dy)
{
	x += dx;
	y += dy;
}

rect SpriteBase::getRect()
{
	return { x, y, width, height };
}