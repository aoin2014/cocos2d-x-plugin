#pragma once

#include "cocos2d.h"
using namespace cocos2d;

class StrokeLabelTTF : public cocos2d::Node
{
public:
	static StrokeLabelTTF* create(const std::string&string, const char *fontName, float fontSize, float strokeSize,const cocos2d::ccColor3B& color3 = cocos2d::ccc3(255, 255, 255),const cocos2d::ccColor3B& colStroke = cocos2d::ccc3(0, 0, 0));
	bool initWithString(const std::string&label, const char *fontName, float fontSize, float fStrokeSize, const cocos2d::ccColor3B& color3,const cocos2d::ccColor3B& colStroke);
	static StrokeLabelTTF * create(const std::string&string, const char *fontName, float fontSize);
public:
	void setString(const std::string& text);
	void setAnchorPoint(const cocos2d::CCPoint &anchorPoint);
protected:
	void updateStroke();
private:
	cocos2d::CCPoint anchorPoint;

	CCLabelTTF* center;
	CCLabelTTF* up;
	CCLabelTTF* down;
	CCLabelTTF* left;
	CCLabelTTF* right;
};
