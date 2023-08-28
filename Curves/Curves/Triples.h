#pragma once
#include <string>

struct TRIPLE
{
public:
	double first_field, second_field, third_field;
	TRIPLE(double a = 0, double b = 0, double c = 0) : first_field(a), second_field(b), third_field(c) {};
	virtual void print(void);
protected:
	std::string do_string(void);
};

struct DOT : public TRIPLE
{
	DOT(double a, double b, double c) : TRIPLE(a, b, c) {}
	void print(void) override;
};

struct VECTOR3D : public TRIPLE
{
	VECTOR3D(double a, double b, double c) : TRIPLE(a, b, c) {}
	void print(void) override;
};