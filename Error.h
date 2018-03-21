#pragma once
#include<string>
using namespace std;
class MyError {
public:
	MyError(const string &text, const string &ShapeType) {
		message = text;
		TypeOfShape = ShapeType;

	
	}

	string message;
	string TypeOfShape;
};