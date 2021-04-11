#include "Graph.h"
#include "Simple_window.h"

int main()
try {
	using namespace Graph_lib;

	Point tl(50, 50);
	//a labelt nem akarja valamiért átirni

	Simple_window win{ tl, 600, 400, "Oláh Tamás Drill Chapter 12" };
	win.wait_for_button();

	Axis xa{ Axis::x, Point{50, 200}, 140, 10, "x axis" };
	xa.set_color(Color::blue);
	xa.label.set_color(Color::black);
	win.attach(xa);
	win.set_label("x axis");
	win.wait_for_button();

	Axis ya{ Axis::y, Point{50,200}, 140, 10, "y axis" };
	ya.set_color(Color::blue);
	ya.label.set_color(Color::black);
	win.attach(ya);
	win.set_label("y axis");
	win.wait_for_button();

	Function sine{ sin,0,100,Point{40,200},700,50,50 };
	win.attach(sine);
	win.set_label("Sin graph");
	win.wait_for_button();

	sine.set_color(Color::blue);
	Graph_lib::Polygon poly;
	poly.add(Point{ 250,100 });
	poly.add(Point{ 350,100 });
	poly.add(Point{ 350,200 });
	poly.add(Point{ 250,200 });

	poly.set_color(Color::dark_blue);
	poly.set_style(Line_style::dot);
	win.attach(poly);
	win.set_label("Poly");
	win.wait_for_button();

	Graph_lib::Rectangle r{ Point{400,400}, 200, 100 };
	win.attach(r);
	win.set_label("Rectangle");
	win.wait_for_button();

	Closed_polyline poly_rect;
	poly_rect.add(Point{ 70,50 });
	poly_rect.add(Point{ 140,50 });
	poly_rect.add(Point{ 140,100 });
	poly_rect.add(Point{ 70,100 });
	win.attach(poly_rect);

	r.set_fill_color(Color::dark_magenta);
	poly.set_style(Line_style(Line_style::dash, 4));
	poly_rect.set_style(Line_style(Line_style::dot, 2));
	poly_rect.set_fill_color(Color::blue);
	win.set_label("Closed polyline");
	win.wait_for_button();

	Text t{ Point{50,300}, "My first graphical program" };
	win.attach(t);
	win.set_label("Text");
	win.wait_for_button();

	t.set_font(Font::times_bold);
	t.set_font_size(30);
	win.set_label("Font setting");
	win.wait_for_button();

	Image ii{ Point{100,50},"dog.jpg" };
	win.attach(ii);
	win.set_label("Image");
	win.wait_for_button();

	ii.move(170, 100);
	win.set_label("Move");
	win.wait_for_button();

	Circle c{ Point{300,200},50 };
	/*Ellipse e{ Point{100,200}, 75,25 };
	e.set_color(Color::dark_red);*/				// ellipszis valamiért nem akar mûködni
	Mark m{ Point{100,200},'d' };

	ostringstream oss;
	oss << "screen size: " << x_max() << "" << y_max()
		<< "; window size: " << win.x_max() << "" << win.y_max();
	Text sizes{ Point{80,15},oss.str() };

	Image cal{ Point{50,210},"cat.jpg" };
	cal.set_mask(Point{ 70,70 }, 300, 250);
	win.attach(c);
	win.attach(m);
	//win.attach(e);

	win.attach(sizes);
	win.attach(cal);
	win.set_label("Img cat");
	win.wait_for_button();

	return 0;
}
catch (exception& e) {
	return 1;
}
catch (...) {
	return 2;
}