#ifndef __STRING_BUTTON_H__
#define __STRING_BUTTON_H__

#include "cocos2d.h"
#include "StrokeLabelTTF.h"

USING_NS_CC;

//����Ԫ�ؾ���
class StringButton : public cocos2d::Node
{

public:
	// ��ʼ��
	virtual bool init(Node* node,const ccMenuCallback &callback);
	//����
	static StringButton* create(Node* node,const ccMenuCallback &callback);
	//���ñ���
	void setImage(char* fileName,char* disenableFileName);
	//��������
	void setString(char* text,char* fontName,int fontSize,cocos2d::Color3B color,cocos2d::Color3B strokeColor);
	//�����Ƿ��ھ�����
	bool isInSprite(CCTouch *theTouch);
	void setEnable(bool isEnable);
private:
	//����Ϊѡ��״̬
	void setSelect();
	//ȡ��ѡ��
	void unSelect();
private:
	//�Ƿ�ѡ��
	bool m_select;
	//��������
	Sprite* m_sprite;
	//����
	cocos2d::LabelTTF * m_label;

	bool isEnable;

	char* fileName;
	char* disenableFileName;
};

#endif // __STRING_BUTTON_H__