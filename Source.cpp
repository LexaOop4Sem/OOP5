#include "screen.h" 
#include "line.h" 
#include "square.h" 
#include "rhomb.h" 

#include <vector> 
#include <memory> 

int main()
{
	auto screen = std::make_unique<Screen>(100, 100);

	std::vector<std::shared_ptr<Shape>> shapes;


	shapes.emplace_back(std::make_shared<Rhomb>(Point(3, 23)));
	
	shapes.emplace_back(std::make_shared<Rhomb>(Point(15, 23)));
	shapes.emplace_back(std::make_shared<Rhomb>(Point(33, 23)));

	shapes.emplace_back(std::make_shared<Square>(Point(10, 1), Point(38, 16))); // ����� 


	Point p1 = shapes[shapes.size() - 1]->getLeftBottom();
	p1.setX(p1.getX() - 2);
	p1.setY(p1.getY() + 1);
	Point p2 = shapes[shapes.size() - 1]->getRightBottom();
	p2.setX(p2.getX() + 2);
	p2.setY(p2.getY() + 1);
	shapes.emplace_back(std::make_shared<Line>(p1, p2)); // ����� ��� ������ 

	p1 = shapes[shapes.size() - 1]->getLeftBottom();
	p1.setX(p1.getX() + 1);
	p1.setY(p1.getY() + 1);
	p2 = shapes[shapes.size() - 1]->getRightBottom();
	p2.setX(p2.getX() - 1); p2.setY(p2.getY() + 20);
	shapes.emplace_back(std::make_shared<Square>(p1, p2)); // ������ 

	Point eyeLeft = shapes[shapes.size() - 1]->getLeftTop();
	eyeLeft.setX(eyeLeft.getX() + 5);
	eyeLeft.setY(eyeLeft.getY() + 2);
	Point eyeRight = Point(eyeLeft.getX()+2, eyeLeft.getY());
	shapes.emplace_back(std::make_shared<Line>(eyeLeft, eyeRight)); // ����� ���� 
	//shapes.emplace_back(std::make_shared<Square>(eyeLeft, eyeRight)); // ������ 


	eyeRight = shapes[shapes.size() - 2]->getRightTop();
	eyeRight.setX(eyeRight.getX() - 5);
	eyeRight.setY(eyeRight.getY() + 2);
	eyeLeft = Point(eyeRight.getX() - 2, eyeRight.getY());
	shapes.emplace_back(std::make_shared<Line>(eyeLeft, eyeRight)); // ������ ���� 
	

	std::shared_ptr<Shape> leftEye = shapes[shapes.size() - 2];
	std::shared_ptr<Shape> rightEye = shapes[shapes.size() - 1];
	Point nose = Point(leftEye->getRightTop().getX() +
		(rightEye->getLeftTop().getX() - leftEye->getRightTop().getX()) / 2,
		leftEye->getRightTop().getY() + 9);
	shapes.emplace_back(std::make_shared<Line>(nose, nose)); // ��� 

	std::shared_ptr<Shape> head = shapes[shapes.size() - 4];
	p1 = head->getLeftBottom(); p1.setX(p1.getX() + 2);  p1.setY(p1.getY() - 2);
	p2 = head->getRightBottom(); p2.setX(p2.getX() - 2); p2.setY(p2.getY() - 2);
	shapes.emplace_back(std::make_shared<Line>(p1, p2)); // ��� 



	auto costume = std::make_shared<Line>(Point(p1.getX(), p1.getY() + 10),
		Point(p2.getX(), p2.getY() + 10));
	shapes.emplace_back(costume); //����� ������� 

	p1 = Point(costume->getLeftBottom().getX(), costume->getLeftBottom().getY() + 1);
	auto leftDot = std::make_shared<Line>(p1, p1);
	shapes.emplace_back(leftDot); //����� ����� 

	p1 = Point(costume->getRightBottom().getX(), costume->getRightBottom().getY() + 1);
	auto rightDot = std::make_shared<Line>(p1, p1);
	shapes.emplace_back(rightDot); //������ ����� 

	try {
		for (auto shape : shapes) {
			shape->draw(screen.get());
		}
	}
	catch (...) {
		cout <<" error"<< endl;
		
	}
	screen->draw();

	std::cin.get();
	system("pause");
	return 0;
}
