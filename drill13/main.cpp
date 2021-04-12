#include "Simple_window.h"
#include "Graph.h"

int main()
{
	Point p{ 100,100 };
	constexpr int xmax = 800;
	constexpr int ymax = 1000;
	Simple_window win{ p,xmax,ymax,"Drill 13 Oláh Tamás" };

	constexpr int gridsize = 100;
	constexpr int gridmax = 800;

	Lines grid;
	for (int i = 0; i <= 8; ++i)
	{
		grid.add(Point{ 0,i * 100 }, Point{ gridmax,i * 100 });
	}
	for (int i = 0; i <= 8; ++i)
	{
		grid.add(Point{ i * 100,0 }, Point{ i * 100,gridmax });
	}

	grid.set_color(Color::dark_blue);

	win.attach(grid);

	win.wait_for_button();

	Vector_ref <Graph_lib::Rectangle> vr;

	for (int i = 0; i < 8; ++i)
	{
		vr.push_back(new Graph_lib::Rectangle(Point{ i * 100, i * 100 }, 100, 100));
		vr[i].set_fill_color(Color::dark_red);
		win.attach(vr[i]);
	}

	win.set_label("Rectangles");

	win.wait_for_button();

	Image i1{Point{300,0},"shrek.gif" };
	Image i2{ Point{0,300},"shrek.gif" };
	Image i3{ Point{600,300},"shrek.gif" };

	win.attach(i1);
	win.attach(i2);
	win.attach(i3);

	win.wait_for_button();

	Image car{ Point{0,0},"car.gif" };
	win.attach(car);
	win.wait_for_button();
	bool move = true;
	int szamlalo = 1;
	while (move)
	{
		if (szamlalo % 4 == 1)
			car.move(0, 700);
		else if (szamlalo % 4 == 2)
			car.move(700, 0);
		else if (szamlalo % 4 == 3)
			car.move(0, -700);
		else
			car.move(-700, 0);
		szamlalo++;
		win.wait_for_button();
	}
	


}
