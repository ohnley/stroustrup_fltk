#include "dummycmake/Simple_window.h"
#include "dummycmake/Graph.h"


double one(double) {return 1;}
double half_slope(double x) {return x/2;}
double square(double x) {return x*x;}
double slope_cos(double x) {return cos(x) + half_slope(x);}

int main(){
    constexpr int xmax = 1000;
    constexpr int ymax = 800;
    constexpr int x_orig = xmax/2; // position of (0,0) is center of window
    constexpr int y_orig = ymax/2;
    constexpr Point orig {x_orig,y_orig};
    constexpr int r_min = -10; // range [–10:11)
    constexpr int r_max = 11;
    constexpr int n_points = 400; // number of points used in range
    constexpr int x_scale = 30; // scaling factors
    constexpr int y_scale = 30;
    Simple_window win {Point{100,100},xmax,ymax,"Function graphing"};

    // Function s {one, r_min, r_max, orig, n_points, x_scale, y_scale };
    // Function sq {square, r_min, r_max, orig, n_points, x_scale, y_scale };
    Function sc {slope_cos, 
                 r_min, r_max, orig, n_points, x_scale, y_scale};

    // use a lambda expression rather than a function
    // can add an explicit return return type with "-> <type>" after the argument list
    Function ss {
                [](double x) -> double { return cos(x) + half_slope(x);}, 
                 r_min, r_max, orig, n_points, x_scale, y_scale, 100};
    win.attach(ss);
    
    //[](double x) { return cos(x) + half_slope(x); }
    // win.attach(sq);
    // win.attach(sc);
    // sq.set_color(Color::black);
    // sc.set_color(Color::black);
    win.wait_for_button();
    ss.set_color(Color::black);
    win.wait_for_button();

    return EXIT_SUCCESS;
}