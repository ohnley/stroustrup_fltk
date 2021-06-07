#include "dummycmake/Window.h"
#include "dummycmake/Graph.h"
#include "dummycmake/Simple_window.h"


int main(){

    Simple_window win {Graph_lib::Point{100,100}, 600, 600, "Function graphing"};
    int axis_x = 100;
    int axis_y = 100;
    Graph_lib::Axis x {Graph_lib::Axis::Orientation::x, Graph_lib::Point{axis_x, axis_y}, 300, 20, "x-axis"};
    win.attach(x);
    x.set_color(Graph_lib::Color::black);
    
    win.wait_for_button();
    
    // x = (x++) * (++x);
    return EXIT_SUCCESS;
}