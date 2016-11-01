#ifndef _BOARD__
#define _BOARD__
#include "cocos2d.h"
USING_NS_CC;
class Board :public Sprite
{
public:
	Board();
	~Board();
	CREATE_FUNC(Board);
	virtual bool init()
	{
		if (!Sprite::init()) return false;

		int type[] = { 0, 0, 0, 0, 1, 1, 2, 3, 0 };
		//_type = type[(int)(CCRANDOM_0_1() * 8)];
		_type = 0;
		_file[5] = _type + 48;

		_has_item = CCRANDOM_0_1() < 0.9 ? false : true;
		_moveable = CCRANDOM_0_1() < 0.7 ? false : true;

		this->createWithSpriteFrameName(_file);
		this->setPosition(CCRANDOM_0_1()*Director::getInstance()->getVisibleSize().height, \
			CCRANDOM_0_1()*Director::getInstance()->getVisibleSize().width);


	}

	Board* create(int posX)
	{
		Board* board = create();
		
	}
private:
	bool _has_item;
	bool _moveable;
	bool _is_fragile;
	int _type;
	char _file[] = "board0.png";
};
#endif
