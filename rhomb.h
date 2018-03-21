#pragma once
#pragma once
//Τΰιλ square.h 


#ifndef RHOMB_H 
#define RHOMB_H 

#include "line.h" 

class Rhomb : public virtual Shape
{
public:

	/*Rhomb(const Point& left, const Point& top,const Point& right, const Point& bottom)*/
	Rhomb(const Point& dot)
	{
		_leftRight = new Line(Point(dot.getX() -4, dot.getY()), Point(dot.getX()+4, dot.getY()));
		_leftTop = new Line(Point(dot.getX() - 4, dot.getY()), Point(dot.getX() , dot.getY()-4));
		_topRight = new Line(Point(dot.getX(), dot.getY()-4), Point(dot.getX() + 4, dot.getY()));
		_leftBot = new Line(Point(dot.getX() - 4, dot.getY()), Point(dot.getX(), dot.getY()+4));
		_rightBot = new Line(Point(dot.getX() + 4, dot.getY()), Point(dot.getX(), dot.getY()+4));
		_topBot = new Line(Point(dot.getX(), dot.getY()-4), Point(dot.getX(), dot.getY()+4));
		//_right = new Line(right,bottom);
		//_bottom = new Line(bottom,left);

	}


	virtual void draw(Screen* screen) const
	{
		_leftRight->draw(screen);
		_leftTop->draw(screen);
		_topRight->draw(screen);
		_leftBot->draw(screen);
		_rightBot->draw(screen);
		_topBot->draw(screen);

		//_bottom->draw(screen);
	}

	virtual void move(Point p)
	{
		_leftRight->move(p);
		//_top->move(p);
		//_right->move(p);
		//_bottom->move(p);
	}

	Point getLeftTop() const
	{
		return _leftRight->getLeftTop();
	}

	Point getRightTop() const
	{

		return _leftRight->getLeftTop();
		//return _right->getRightTop();
	}

	Point getLeftBottom() const

	{
		return _leftRight->getLeftTop();
		//return _left->getLeftBottom();
	}

	Point getRightBottom() const
	{
	
		return _leftRight->getLeftTop();//return _right->getRightBottom();
	}

	virtual ~Rhomb()
	{
		delete _leftRight;
		/*delete _top;
		delete _right;
		delete _bottom;*/
	}




protected:
	Line * _leftRight, *_leftTop,*_topRight, *_leftBot, *_rightBot,*_topBot;
};
#endif //RHOMB_H 
