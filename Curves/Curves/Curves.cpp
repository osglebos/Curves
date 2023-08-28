#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
#include "Curves.h"
using namespace std;

Circle::Circle(double radius = 1)
{
	if (radius <= 0)
	{
		cout << "It isnt able to create Circle\n";
		radius = 0; // отработать исключения
	}
	this->radius = radius;
}

void Circle::print(void)
{
	cout << "Circle   : " << to_string(radius) << endl;
}

DOT Circle::ReturnDot(double t = 0)
{
	return DOT(cos(t) * this->radius, sin(t) * this->radius, 0);
}

VECTOR3D Circle::ReturnDerivative(double t)
{
	return VECTOR3D(-sin(t) * this->radius, cos(t) * this->radius, 0);
}

Circle::~Circle()
{
		;
}

Ellipsis::Ellipsis(double a = 1, double b = 2)
{
	if (a <= 0 || b <= 0)
	{
		cout << "It isnt able to create Ellipse\n";
		a = b = 0; // отработать исключения
	}
	this->a = a;
	this->b = b;
}

void Ellipsis::print(void)
{
	cout << "Ellipsis : " << to_string(a) << " " << to_string(b) << endl;
}

DOT Ellipsis::ReturnDot(double t = 0)
{
	return DOT(cos(t) * this->a, sin(t) * this->b, 0);
}

VECTOR3D Ellipsis::ReturnDerivative(double t)
{
	return VECTOR3D(-sin(t) * this->a, cos(t) * this->b, 0);
}

Ellipsis::~Ellipsis()
{
	;
}

Helix::Helix(double radius = 1, double step = 1)
{
	if (radius <= 0 || step <= 0)
	{
		cout << "It isnt able to create Helix\n";
		radius = step = 0; // отработать исключения
	}
	this->radius = radius;
	this->step = step;
}

void Helix::print(void)
{
	cout << "Helix    : " << to_string(radius) << " " << to_string(step) << endl;
}

DOT Helix::ReturnDot(double t = 0)
{
	return DOT(cos(t) * this->radius, sin(t) * this->radius, t * step / (2 * M_PI));
}

VECTOR3D Helix::ReturnDerivative(double t)
{
	return VECTOR3D(-sin(t) * this->radius, cos(t) * this->radius, step / (2 * M_PI));
}

Helix::~Helix()
{
	;
}
