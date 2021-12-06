#include "acllib.h"
#include "fruit.h"
#include "item.h"
#include "basket.h"
#include <time.h>
#include <stdio.h>

const int winWidth = 800, winHeight = 600;
const int maxNum = 30;
ACL_Image imgApple, imgBanana, imgBasket, imgLemon, imgBomb;
Basket* basket = NULL;
Item* items[maxNum] = { 0 };
int itemNum = 0;

void timerEvent(int id);
void keyEvent(int key, int event);
void createItem();
void Update();

int Setup()
{
	initWindow("Catch Fruits", DEFAULT, DEFAULT, winWidth, winHeight);
	
	srand((unsigned)time(NULL));

	loadImage("basket.jpg", &imgBasket);
	loadImage("apple.jpg", &imgApple);
	loadImage("banana.jpg", &imgBanana);
	loadImage("lemon.jpg", &imgLemon);
	loadImage("bomb.jpg", &imgBomb);
	basket = new Basket(winWidth/2-60, winHeight-110, 120, 100, 10, &imgBasket);

	registerTimerEvent(timerEvent);
	registerKeyboardEvent(keyEvent);

	startTimer(0, 40);
	startTimer(1, 1000);
	return 0;
}

void Update()
{
	bool flag = false;

	for (int i = 0; i < itemNum; ++i)
	{
		if (items[i] && basket)
		{
			if (items[i]->collision(basket))
			{
				items[i]->toggle(basket);
				delete items[i];
				items[i] = NULL;
			}
		}
	}
	beginPaint();
	clearDevice();
	if (basket)
	{
		basket->drawSprite();
		char txt[10];
		sprintf_s(txt, "%d", basket->getScore());
		setTextSize(40);
		setTextColor(WHITE);
		setTextBkColor(RGB(252, 70, 107));
		paintText(10, 10, txt);
	}
	for (int i = 0; i < itemNum; ++i)
	{
		if (items[i])
		{
			flag = true;
			items[i]->drawSprite();
			if (items[i]->getRect().y > winHeight)
			{
				delete items[i];
				items[i] = NULL;
			}
		}
	}
	if (itemNum >= maxNum && flag == false)
	{
		setTextSize(70);
		paintText(winWidth/2-160, winHeight/2-35, "Game Over");
	}
	endPaint();
}

void timerEvent(int id)
{
	switch (id)
	{
	case 0:
		for (int i = 0; i < itemNum; i++)
			if (items[i])
			{
				items[i]->move(winHeight);
			}
		break;
	case 1:
		if (itemNum < maxNum)
		{
			createItem();
		}
		break;
	case 2:
		basket->changeSpeed(10);
		cancelTimer(2);
		break;
	}
	Update();
}

void keyEvent(int key, int event)
{
	if (event != KEY_DOWN)return;
	if (basket)basket->move(key, winWidth);
	Update();
}

void createItem()
{
	int width = 60;
	int x = rand() % winWidth - width;
	if (x < 0)x = 0;
	int t = rand() % 10;
	switch (t)
	{
	case 0:
		items[itemNum++] = new Bomb(x, &imgBomb);
		break;
	case 1:
		items[itemNum++] = new Bomb(x, &imgBomb);
		break;
	case 2:
		items[itemNum++] = new Banana(x, &imgBanana);
		break;
	case 3:
		items[itemNum++] = new Banana(x, &imgBanana);
		break;
	case 4:
		items[itemNum++] = new Lemon(x, &imgLemon);
		break;
	default:
		items[itemNum++] = new Apple(x, &imgApple);
		break;
	}
}