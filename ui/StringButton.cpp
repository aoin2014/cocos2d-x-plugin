#include "StringButton.h"

USING_NS_CC;

StringButton* StringButton::create(Node* node,const ccMenuCallback &callback){
	StringButton* ret = new StringButton();
	if(ret && ret->init(node, callback)){
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool StringButton::init(Node* node,const ccMenuCallback &callback){
	//////////////////////////////
	// 1. super init first
	if ( !cocos2d::Node::init() )
	{
		return false;
	}

	isEnable = true;

	auto dispatcher = Director::getInstance()->getEventDispatcher();  
	auto myListener = EventListenerTouchOneByOne::create();  

	//如果不加入此句消息依旧会向下传递  
	myListener->setSwallowTouches(true);  
	myListener->onTouchBegan = [=](Touch* touch,Event* event)  
	{  
		if(!isEnable) return false;

		//some check  
		if (isInSprite(touch))  
		{  
			setSelect();
			return true;  
		}  
		return false;  
	};  

	myListener->onTouchMoved = [=](Touch* touch,Event* event)  
	{  
		//do something  
	};  

	myListener->onTouchEnded = [=](Touch* touch,Event* event)  
	{  
		if(isEnable){

			//do something  
			if(m_select){
				if(isInSprite(touch)){
					if(callback){
						callback(this);
					}
				}
				unSelect();
			}
		}
	};
	dispatcher->addEventListenerWithSceneGraphPriority(myListener,this);

	return true;
}

bool StringButton::isInSprite(CCTouch *theTouch){
	if(m_sprite){
		//    返回当前触摸位置在OpenGL坐标 
		CCPoint touchPoint=theTouch->getLocation();
		//    将世界坐标转换为当前父View的本地坐标系
		CCPoint reallyPoint=m_sprite->getParent()->convertToNodeSpace(touchPoint);
		//    获取当前基于父view的坐标系
		CCRect rect=m_sprite->boundingBox();
		//    CCnode->convertToNodeSpace 或者  convertToWorldSpace 是基于当前Node的  与当前Node相关
		if(rect.containsPoint(reallyPoint)){
			return true;
		}
	}

	return false;
}

void StringButton::setSelect(){
	m_select = true;

	ScaleTo* scaleTo = ScaleTo::create(0.2f,1.2f);
	this->runAction(scaleTo);
}

void StringButton::unSelect(){
	m_select = false;

	ScaleTo* scaleTo = ScaleTo::create(0.2f,1.0f);
	this->runAction(scaleTo);
}

void StringButton::setImage(char* fileName,char* disenableFileName){
	this->fileName = fileName;
	this->disenableFileName = disenableFileName;

	m_sprite = Sprite::createWithSpriteFrameName(fileName);
	this->addChild(m_sprite);
}

void StringButton::setEnable(bool isEnable){
	this->isEnable = isEnable;

	if(isEnable){
		m_sprite->setSpriteFrame(fileName);

		m_label->setOpacity(255);
	}else{
		m_sprite->setSpriteFrame(disenableFileName);

		m_label->setOpacity(150);
	}
}

void StringButton::setString(char* text,char* fontName,int fontSize,cocos2d::Color3B color,cocos2d::Color3B strokeColor){

	m_label = LabelTTF::create();
	m_label->setString(text);
	m_label->setFontName(fontName);
	m_label->setFontSize(fontSize);
	m_label->setColor(color);
	m_label->enableStroke(strokeColor,50);
	this->addChild(m_label);

	m_label->setPosition(30,0);
}
