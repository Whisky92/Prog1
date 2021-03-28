#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

int main()
{
	using namespace Graph_lib;

	constexpr int x_max = 1000;
	constexpr int y_max = 800;

	Simple_window win {Point{100, 100}, x_max, y_max, "CH13_Drill"};

	//making the grid
	constexpr int grid_size = 100;
	constexpr int grid_max = 800;
	Lines grid;
	for (int x = grid_size; x <= grid_max; x+=grid_size)
	{
		grid.add(Point{x,0}, Point{x, grid_max});
		grid.add(Point{0,x}, Point{grid_max, x});
	}
	win.attach(grid);

	//making the red squares
	Vector_ref<Rectangle> red_squares;
	for (int i = 0; i < 8; ++i)
	{
		red_squares.push_back(new Rectangle(Point{i * grid_size, i * grid_size}, grid_size, grid_size));
		red_squares[red_squares.size()-1].set_fill_color(Color::red);
		win.attach(red_squares[red_squares.size()-1]);
	}

	//placing images
	Vector_ref<Image> vi;
	vi.push_back(new Image(Point{200,000}, "image.jpg"));
	vi.push_back(new Image(Point{400,200}, "image.jpg"));
	vi.push_back(new Image(Point{600,400}, "image.jpg"));
	for (int i = 0; i < vi.size(); ++i)
	{
		win.attach(vi[i]);
	}

	//moving an image around
	Image pic{Point{0,0}, "car.jpg"};
	pic.set_mask(Point{30, 50}, 100, 100);
	win.attach(pic);
	int num_of_squares = 64; // 8*8
	int move_counter = 1;
	int move_x = 100;
	int move_y = 0;
	for (int i = 0; i < num_of_squares; ++i)
	{
		if (move_counter == 8){
			move_y += 100;
			move_counter = 0;
			move_x = -700;
		}
		win.wait_for_button();
		pic.move(move_x, move_y);
		move_counter++;
		move_y = 0;
		move_x = 100;