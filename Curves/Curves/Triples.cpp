#pragma once
#include "Triples.h"
#include <string>
#include <iostream>
using namespace std;

string TRIPLE::do_string(void)
{
	return to_string(first_field) + " " + to_string(second_field) + " " + to_string(third_field);
}


void TRIPLE::print(void)
{
	cout << "TRIPLE : " + do_string() << endl;
}

void DOT::print(void)
{
	cout << "DOT : " + this->do_string() << endl;
}

void VECTOR3D::print(void)
{
	cout << "3D VECTOR : " + this->do_string() << endl;
}
