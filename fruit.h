#pragma once
#include "item.h"
class Apple :public Item
{
public:
	Apple(int, ACL_Image*);
};

class Banana :public Item
{
public:
	Banana(int, ACL_Image*);
};

class Lemon :public Item
{
public:
	Lemon(int, ACL_Image*);
};

class Bomb :public Item
{
public:
	Bomb(int, ACL_Image*);
	void toggle(Basket*);
};