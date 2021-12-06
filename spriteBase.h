#pragma once
#include"acllib.h"

class SpriteBase
{
protected:
	int x, y;
	int speed;
	int width, height;
	ACL_Image* img;
public:
	SpriteBase(int, int, int, int, int, ACL_Image*);
	void drawSprite();
	void move(int, int);
	rect getRect();
};