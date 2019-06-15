#ifndef FIGURA_H
#define FIGURA_H
#include <iostream>
#include <fstream>
#include <locale.h>
#include <string>
#include <iomanip>
#include <vector>
#include <math.h>

using namespace std;
double Triangl_area(double &x,double &y,double &z);

//базовый класс
class Figura 
{
	public:
		virtual string name()=0;
		virtual double area()=0;
		virtual double perimetr()=0;
	
};


//класс окружность
class Circle:public Figura	
{
	private:
		double R;
	public:
		Circle()  {R=0.0;}
		Circle(double R) {this->R=R;}
		string name() {return "Circle";}
		double area() {return 3.1415*R*R;}
		double perimetr(){return 2.0*3.14*R;}
		
};

 
//класс треугольник
class Triangle: public Figura
{
	private:
		double x,y,z;
	public:
		Triangle()  {x=0.0; y=0.0; z=0.0;}
		Triangle(double _x,double _y,double _z) {x=_x; y=_y; z=_z;}

		string name() {return "Triangle";}
		double perimetr(){return x+y+z;}
		double area() {return Triangl_area(x,y,z);}//вызываем функци для счета площади
		
};



// Класс  прямоугольник
class Rectangle: public Figura
{
	double x, y; // ширина, длина
	public:
		Rectangle() {x=0;  y=0;};
		Rectangle(double _x, double _y){x=_x; y=_y;};

		string name() {return "Rectangle";}
		double perimetr(){return (x+y)*2;}
		double area() {return x*y;}

};


//класс ромб
class Rhombus: public Figura
{
	double a,h; // длина стороны и высота
	public:
		Rhombus() {a=0;  h=0;};
		Rhombus(double _a, double _h){a=_a; h=_h;};

		string name() {return "Rhombus";}
		double perimetr(){return a*4;}
		double area() {return a*h;}
};


//класс трапеция
class Trapezium: public Figura
{
	double a,b,c,d,h; // a,b-основания c,d-ребро h-высота
	public:
		Trapezium() {a=0; b=0; c=0; d=0; h=0;};
		Trapezium(double _a, double _b, double _с,double _d, double _h){a=_a; b=_b; c=_с; d=_d; h=_h;};

		string name() {return "Trapezium";}
		double perimetr(){return a+b+c+d;}
		double area() {return (a+b)*h/2;}
};



//для полигона
template <class P> struct Point
{
	P x, y;
};
//класс полигона
template <class P> class Poligon : public Figura
{

	public:

		Poligon(){}
		void creatvertex(P _x,P _y)
		{
			Point<P> polig;
			polig.x=_x;
			polig.y=_y;
			vertex.push_back(polig);
		}
		vector<Point<P>>vertex;	//вектор вершин с координатами x,y
		string name() { return "Poligon"; }


		double area()		
		{ 
			int max=0,index=0;
			for(int n=0;n<vertex.size() - 2;n++)
			{
				if(max<vertex[n].x)
				{
					max=vertex[n].x; //перепресваиваем ,пока не найдем выпуклую вершину
					index=n;//запоминаем индекс выпуклой вершины в массиве
				}
			}

			double area = 0;
			for (int i = index; i < vertex.size() - 2; i++) 
			{
					area += ((vertex[i + 1].x - vertex[0].x) * (vertex[i + 2].y - vertex[0].y)) - ((vertex[i + 1].y - vertex[0].y) *
						(vertex[i + 2].x - vertex[0].x));
			}

			return (double)abs((area)/2);
		}	
		double perimetr()
		{
			double perimetr = 0;
			for (int i = 0; i < vertex.size() - 1; i++) 
			{
				perimetr  += sqrt((vertex[i + 1].x - vertex[i].x) * (vertex[i + 1].x - vertex[i].x) + (vertex[i + 1].y - vertex[i].y) * 
							(vertex[i + 1].y - vertex[i].y));
			}
			perimetr  += sqrt((vertex[vertex.size() - 1].x - vertex[0].x) * (vertex[vertex.size() - 1].x - vertex[0].x) +
						(vertex[vertex.size() - 1].y - vertex[0].y) * (vertex[vertex.size() - 1].y - vertex[0].y));

			return perimetr ;
		}	

};


//Функции

double Triangl_area(double &x,double &y,double &z)
{
	double p=(x+y+z)/2.0;
	double result = sqrt(p*(p-x)*(p-y)*(p-z));
	return result;
}

double Fig_area(Figura &fig)
{
	return fig.area();
}

#endif 
