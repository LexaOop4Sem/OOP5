#pragma once
#pragma once
//Τΰιλ square.h 


#ifndef RHOMB_H 
#define RHOMB_H 

#include "line.h" 
#include "Error.h" 
using namespace std;

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
		
	//	cout<<((_leftRight->getFirstPoint()).getX());
	//	Point p = _leftRight->getFirstPoint();
	//	cout<<p.getX();
	}

	void DrawExeptions(Screen* screen)const {

			_leftRight->draw(screen);
			_leftTop->draw(screen);
			_topRight->draw(screen);
			_leftBot->draw(screen);
			_rightBot->draw(screen);
			_topBot->draw(screen);
	
		//////err with exeption from out of range vector
		////try {
		////	_leftRight->draw(screen);
		////	_leftTop->draw(screen);
		////	_topRight->draw(screen);
		////	_leftBot->draw(screen);
		////	_rightBot->draw(screen);
		////	_topBot->draw(screen);
		////}
		////catch (...) {
		////	std::cout << "catch error from drawing rhomb, rhomb was deleted" << endl;
		////}
	}


	virtual void draw(Screen* screen) const
	{

		try {
			if (((_leftRight->getFirstPoint().getX()) < 0) || (_leftRight->getFirstPoint().getX()) >100) {
				cout << ((_leftRight->getFirstPoint()).getX());
				Point p = _leftRight->getFirstPoint();
				cout << p.getX();
				std::cout << "err" << endl;
				throw  MyError("out of screen range", "rhomb");
			}
			DrawExeptions(screen);
		}
		catch (MyError err) {
			int newX, newY;
			cout << err.message << endl;
			cout << err.TypeOfShape << endl;
			do{
			cout << "enter new dot coordinates " << endl;
			cout << "X: " << endl;
			cin >> newX;
			cout << "Y: " << endl;
			cin >> newY;
			} 
			while (((newX - 4) < 0) || ((newX + 4) > 100) || ((newY - 4) < 0) || ((newY + 4) > 100));
			Point newdot(newX, newY);
			
			{_leftRight->EditLine(Point(newdot.getX() - 4, newdot.getY()), Point(newdot.getX() + 4, newdot.getY()));
			_leftRight->EditLine(Point(newdot.getX() - 4, newdot.getY()), Point(newdot.getX() + 4, newdot.getY()));
			_leftTop->EditLine(Point(newdot.getX() - 4, newdot.getY()), Point(newdot.getX(), newdot.getY() - 4));
			_topRight->EditLine(Point(newdot.getX(), newdot.getY() - 4), Point(newdot.getX() + 4, newdot.getY()));
			_leftBot->EditLine(Point(newdot.getX() - 4, newdot.getY()), Point(newdot.getX(), newdot.getY() + 4));
			_rightBot->EditLine(Point(newdot.getX() + 4, newdot.getY()), Point(newdot.getX(), newdot.getY() + 4));
			_topBot->EditLine(Point(newdot.getX(), newdot.getY() - 4), Point(newdot.getX(), newdot.getY() + 4));
			}
				DrawExeptions(screen);
			//	throw MyError("out of screen range", "rhomb");
			
		}
	}

	virtual void move(Point p)
	{
		_leftRight->move(p);
	}

	Point getLeftTop() const
	{
		return _leftRight->getLeftTop();
	}

	Point getRightTop() const
	{

		return _leftRight->getLeftTop();
		
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
