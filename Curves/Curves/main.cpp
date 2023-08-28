#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <conio.h>
#include "Curves.h"
#include "Triples.h"

using namespace std;

vector<Curve *> CreateListOfCurves(int len = 100)
{
	srand((unsigned int)time(nullptr));
	vector<Curve *> res(len);
	for (int i = 0; i < len; i++)
	{
		switch (rand() % 3)
		{
		case 0:
			res[i] = new Circle(rand() % 100);
			break;
		case 1:
			res[i] = new Ellipsis(rand() % 100, rand() % 100);
			break;
		case 2:
			res[i] = new Helix(rand() % 100, rand() % 100);
			break;
		default:
			break;
		}
	}
	return res;
}

void PrintList(vector<Curve *> arr)
{
	for (int i = 0; i < (int) arr.size(); i++)
	{
		arr[i]->print();
	}
	cout << endl;
}

void PrintList(vector<Circle *> arr)
{
	for (int i = 0; i < (int)arr.size(); i++)
	{
		arr[i]->print();
	}
	cout << endl;
}

void PrintDotList(vector<Curve *> arr, double angle)
{
	for (int i = 0; i < (int)arr.size(); i++)
	{
		arr[i]->print();
		arr[i]->ReturnDot(angle).print();
		cout << endl;
	}
	cout << endl;
}

void PrintDerivativeList(vector<Curve *> arr, double angle)
{
	for (int i = 0; i < (int)arr.size(); i++)
	{
		arr[i]->print();
		arr[i]->ReturnDerivative(angle).print();
		cout << endl;
	}
	cout << endl;
}

int main(void)
{
	vector<Curve *> Curves;
	vector<Circle *> Circles;

	int exit = 0;
	char key;
	printf("------------------------------\n");
	printf("ecs exit\n");
	printf("c   Create vector of curves\n");
	printf("s   Print all curves\n");
	printf("p   Coordinates of points\n");
	printf("d   Coordinates of derivatives\n");
	printf("1   Copy circles to another vector\n");
	printf("2   Print all circles\n");
	printf("3   Check that second container shares (i.e. not clones) circles\n");
	printf("4   Sort circles\n");
	printf("5   Summ all radius of circles\n");
	printf("------------------------------\n");

	while (exit == 0)
	{
		key = _getch();
		system("cls");
		printf("------------------------------\n");
		printf("ecs exit\n");
		printf("c   Create vector of curves\n");
		printf("s   Print all curves\n");
		printf("p   Coordinates of points\n");
		printf("d   Coordinates of derivatives\n");
		printf("1   Copy circles to another vector\n");
		printf("2   Print all circles\n");
		printf("3   Check that second container shares (i.e. not clones) circles\n");
		printf("4   Sort circles\n");
		printf("5   Summ all radius of circles\n");
		printf("------------------------------\n");
		switch (key)
		{

		case 'c':
		{
			for (auto p : Curves)
				delete p;
			Curves.clear();
			Circles.clear();
			// в задании было указано что не должно быть явного освобождения памяти, 
			//но не знаю как тут обойтись без этого и использовать виртуальные методы и не клонировать во второй контейнер
			int n = 0;
			cout << "input number of curves" << endl;
			cin >> n;
			Curves = CreateListOfCurves(n);
		}

		case 's':
			PrintList(Curves);
			break;
		
		case 'd':
			PrintDerivativeList(Curves, M_PI / 4);
			break;

		case 'p':
			PrintDotList(Curves, M_PI / 4);
			break;

		case '1':
			for (int i = 0; i < (int)Curves.size(); i++)
			{
				if (typeid(*Curves[i]).hash_code() == typeid(Circle(2)).hash_code())
				{
					Circles.push_back((Circle *)Curves[i]);
				}
			}

		case '2':
			PrintList(Circles);
			break;

		case '3':
			Circles[0]->print();
			for (int i = 0; i < (int)Curves.size(); i++)
			{
				if (typeid(*Curves[i]).hash_code() == typeid(Circle(2)).hash_code())
				{
					Circle *t = (Circle *)Curves[i];
					cout << "Changing 1st Circle in curves array radius form " << t->radius;
					t->radius = rand() % 100 + 1;
					cout << " to " << t->radius << endl;
					break;
				}
			}
			Circles[0]->print();
			break;

		case '4':
			cout << "Before sorting:" << endl;
			PrintList(Circles);
			sort(Circles.begin(), Circles.end(), [](Circle* a, Circle* b) { return a->radius < b->radius; });
			cout << "After sorting:" << endl;
			PrintList(Circles);
			break;

		case '5':
		{
			double sum = 0;
			for (int i = 0; i < (int)Circles.size(); i++)	sum += Circles[i]->radius;
			cout << sum << endl;
			break;

		}
			
		case 27:
			exit = 1;
			break;

		default:
			printf("Not relevant key\n");
		}
	}
	for (auto p : Curves)
		delete p;
	Curves.clear();
	Circles.clear();
	return 0;
}