#pragma once
#include "spriteBase.h"
#include "basket.h"
class Item:public SpriteBase
{
public:
	Item(int, int, ACL_Image*);
	void move(int);
	bool collision(Basket*);
	virtual void toggle(Basket*);
protected:
	int score;
};

