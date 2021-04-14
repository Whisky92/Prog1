#include "Graph.h"
#include "Simple_window.h"

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
int main()
{
    Simple_window win{ Point{100,100},600,600,"Function graphs." };

    constexpr int notchdist = 20;
    constexpr int axislength = 400;
    constexpr int notchnumber = (axislength / notchdist);

    Point orig{ 300,300 };

    constexpr int origpoint = 300;

    constexpr int xstart = 300 - 200;
    constexpr int ystart = 300 + 200;


    Axis x{ Axis::x, Point{xstart, origpoint}, axislength, notchnumber, "1 == 20 pixels" };
    Axis y{ Axis::y, Point{origpoint, ystart}, axislength, notchnumber, "1 == 20 pixels" };

    x.set_color(Color::red);
    y.set_color(Color::red);

    constexpr int f_rangemin = -10;
    constexpr int f_rangemax = 11;
    constexpr int f_nop = 400;
    constexpr int f_scale = 20;
    Function f{ one,f_rangemin,f_rangemax,orig,f_nop,f_scale,f_scale};
    Function f2{slope,f_rangemin,f_rangemax,orig,f_nop,f_scale,f_scale };
    Function f3{ square,f_rangemin,f_rangemax,orig,f_nop,f_scale,f_scale };
    Function f4{ [](double x) {return cos(x); } , f_rangemin, f_rangemax, orig, f_nop, f_scale, f_scale};
    Function sloping_cos{ [](double x) {return cos(x) + slope(x); },f_rangemin,f_rangemax,orig,f_nop,f_scale,f_scale };

    f.set_color(Color::black); //a feladat nem kérte
    f2.set_color(Color::black); // a feladat nem kérte
    f3.set_color(Color::black); // a feladat nem kérte
    f4.set_color(Color::blue);
    sloping_cos.set_color(Color::black);
    Text t{Point{xstart,ystart-120},"x/2"};
    t.set_color(Color::black); // a feladat nem kérte
    win.attach(x);
    win.attach(y);

    
    win.wait_for_button();
    win.set_label("f");
    win.attach(f);
    win.wait_for_button();
    win.set_label("f2+t");
    win.attach(f2);
    win.attach(t);
    win.wait_for_button();
    win.attach(f3);
    win.wait_for_button();
    win.attach(f4);
    win.wait_for_button();
    win.attach(sloping_cos);
    win.wait_for_button();


}