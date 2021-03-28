#include "Simple_window.h"
#include "Graph.h"

double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) {return cos(x) + slope(x);}

int main()
{
	using namespace Graph_lib;
	Simple_window win {Point{100,100},600,600, "Function Graphs"};

	//drawing the axes
	Axis xa {Axis::x, Point{100,300}, 400, 20, "x axis"};
	xa.set_color(Color::red);
	win.attach(xa);
	Axis ya {Axis::y, Point{300, 500}, 400, 20, "y axis"};
	ya.set_color(Color::red);
	win.attach(ya);

	constexpr int intervallum_min = -10;
	constexpr int intervallum_max = 11;
	constexpr int num_points = 400;
	constexpr int x_scale = 20;
	constexpr int y_scale = 20;
	const Point orig {300,300};

	Function fct_one {one, intervallum_min, intervallum_max, orig, num_points, x_scale, y_scale};
	win.attach(fct_one);

	Function fct_slope {slope, intervallum_min, intervallum_max, orig, num_points, x_scale, y_scale};
	win.attach(fct_slope);
	Text slope_label {Point{100,385}, "x/2"};
	win.attach(slope_label);

	Function fct_square {square, intervallum_min, intervallum_max, orig, num_points, x_scale, y_scale};
	win.attach(fct_square);

	Function fct_cos {cos, intervallum_min, intervallum_max, orig, num_points, x_scale, y_scale};
	fct_cos.set_color(Color::blue);
	win.attach(fct_cos);

	Function fct_sloping_cos {sloping_cos, intervallum_min, intervallum_max, orig, num_points, x_scale, y_scale};
	win.attach(fct_sloping_cos);
	win.wait_for_button();
}