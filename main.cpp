#include <iostream>
#include <fstream>
#include <locale.h>
#include <string.h>
#include <iomanip>
#include <vector>
#include "figura.h"

using namespace std;


int main()
{
	setlocale(LC_ALL,"Russian");
	vector<Figura*> myfig;

	Circle cir (3.0);
	Triangle tr(2.0,2.0,1.5);
	Rectangle rec(4.0,7.0);
	Trapezium trap(2.0,4.0,3.0,4.0,2.4);
	Rhombus romb(5.0,3.0);
	Poligon<double>* plgn = new Poligon<double>();
	plgn->creatvertex(1, 1);
	plgn->creatvertex(3, 4);
	plgn->creatvertex(4, 5);
	plgn->creatvertex(5, 7);
	plgn->creatvertex(9, 10);

	//заполняем вектор фигурами
	myfig.push_back(&cir);
	myfig.push_back(&tr);
	myfig.push_back(&rec);
	myfig.push_back(&trap);
	myfig.push_back(&romb);
	myfig.push_back(plgn);
	double area = 0, perimetr = 0;
	for (int i = 0; i < myfig.size(); i++)
	{
			cout << myfig[i]->name() <<":"<<endl<<" Area = " << myfig[i]->area() <<
											"; Perimetr = " << myfig[i]->perimetr() << endl<<endl;
			area += myfig[i]->area();
			perimetr += myfig[i]->perimetr();
	}
	
	cout << "Sum all area: " << area <<"; Sum all perimetr: " << perimetr << endl;

	system("pause");
	return 0;
}


