#pragma once
#include "Triples.h"

class Curve
{
public:
	virtual void print(void) = 0;
	virtual DOT ReturnDot(double t) = 0;
	virtual VECTOR3D ReturnDerivative(double t) = 0;
};

class Circle : public Curve
{
public:
	double radius;
	Circle(double);
	void print(void) override;
	DOT ReturnDot(double) override;
	VECTOR3D ReturnDerivative(double) override;
	~Circle();
};

class Ellipsis : public Curve
{
public:
	double a, b;
	Ellipsis(double, double);
	void print(void) override;
	DOT ReturnDot(double) override;
	VECTOR3D ReturnDerivative(double) override;
	~Ellipsis();
};

class Helix : public Curve
{
public:
	double radius, step;
	Helix(double, double);
	void print(void) override;
	DOT ReturnDot(double);
	VECTOR3D ReturnDerivative(double) override;
	~Helix();
};


