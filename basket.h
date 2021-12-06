#pragma once
#include "spriteBase.h"
class Basket:public SpriteBase
{
public:
	Basket(int, int, int, int, int, ACL_Image*);
	void addScore(int s);
	int getScore();
	void move(int ,int);
private:
	int score = 0;
};

