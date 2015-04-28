#include "StrokeLabelTTF.h"
USING_NS_CC;

bool StrokeLabelTTF::initWithString(const std::string&string, const char *fontName,
									float fontSize, 
									float strokeSize,
									const cocos2d::ccColor3B& color3,
									const cocos2d::ccColor3B& colStroke)
{
	if(!Node::init()){
		return false;
	}

	/* 正文CCLabelTTF */
	center = CCLabelTTF::create(string, fontName, fontSize);  
	center->setColor(color3);  
	this->addChild(center);

	/* 描边CCLabelTTF 上 */
	up = CCLabelTTF::create(string, fontName, fontSize);  
	up->setColor(colStroke);  
	up->setPosition(ccp(center->getContentSize().width*0.5, center->getContentSize().height*0.5+strokeSize));  
	center->addChild(up,-1);  
	this->addChild(up);

	/* 描边CCLabelTTF 下 */
	down = CCLabelTTF::create(string, fontName, fontSize);  
	down->setColor(colStroke);  
	down->setPosition(ccp(center->getContentSize().width*0.5, center->getContentSize().height*0.5-strokeSize));  
	center->addChild(down,-1);  
	this->addChild(down);

	/* 描边CCLabelTTF 左 */ 
	left = CCLabelTTF::create(string, fontName, fontSize);  
	left->setPosition(ccp(center->getContentSize().width*0.5-strokeSize, center->getContentSize().height*0.5));  
	left->setColor(colStroke);  
	center->addChild(left,-1);  
	this->addChild(left);

	/* 描边CCLabelTTF 右 */
	right = CCLabelTTF::create(string, fontName, fontSize);  
	right->setColor(colStroke);  
	right->setPosition(ccp(center->getContentSize().width*0.5+strokeSize,center->getContentSize().height*0.5));  
	center->addChild(right,-1);  
	this->addChild(right);

	return true;
}
StrokeLabelTTF* StrokeLabelTTF::create(const std::string& string, const char *fontName, float fontSize, float fStrokeSize,const cocos2d::ccColor3B& color3,const cocos2d::ccColor3B& colStroke)
{
	StrokeLabelTTF *pRet = new StrokeLabelTTF();
	if(pRet && pRet->initWithString(string, fontName, fontSize, fStrokeSize,color3, colStroke))
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

StrokeLabelTTF * StrokeLabelTTF::create(const std::string& string, const char *fontName, float fontSize)
{
	StrokeLabelTTF *pRet = new StrokeLabelTTF();
	if(pRet && pRet->initWithString(string,fontName,fontSize,1.5,ccc3(255,255,255),ccc3(0,0,0)))
	{
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);
	return NULL;
}

void StrokeLabelTTF::setString(const std::string& text)
{
	center->setString(text);
	up->setString(text);
	down->setString(text);
	left->setString(text);
	right->setString(text);

	updateStroke();
}

void StrokeLabelTTF::setAnchorPoint(const cocos2d::CCPoint &anchorPoint)
{
	this->anchorPoint = anchorPoint;

	updateStroke(); 
}
void StrokeLabelTTF::updateStroke()
{
	center->setPosition(center->getContentSize().width * (0.5f - anchorPoint.x),center->getContentSize().height* (0.5f - anchorPoint.y));
}