#ifndef __STRING_BUTTON_H__
#define __STRING_BUTTON_H__

#include "cocos2d.h"
#include "StrokeLabelTTF.h"

USING_NS_CC;

//单个元素精灵
class StringButton : public cocos2d::Node
{

public:
	// 初始化
	virtual bool init(Node* node,const ccMenuCallback &callback);
	//产生
	static StringButton* create(Node* node,const ccMenuCallback &callback);
	//设置背景
	void setImage(char* fileName,char* disenableFileName);
	//设置文字
	void setString(char* text,char* fontName,int fontSize,cocos2d::Color3B color,cocos2d::Color3B strokeColor);
	//触控是否在精灵中
	bool isInSprite(CCTouch *theTouch);
	void setEnable(bool isEnable);
private:
	//设置为选中状态
	void setSelect();
	//取消选中
	void unSelect();
private:
	//是否被选中
	bool m_select;
	//背景精灵
	Sprite* m_sprite;
	//文字
	cocos2d::LabelTTF * m_label;

	bool isEnable;

	char* fileName;
	char* disenableFileName;
};

#endif // __STRING_BUTTON_H__