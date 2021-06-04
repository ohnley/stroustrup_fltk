#include "dummycmake/Simple_window.h"
#include "dummycmake/Graph.h"
#include <iostream>

int main(){
    Simple_window win (Point{100,100}, 1200, 800, "hexagon example");
    std::cout << 100;
    Group g;
    g.add_shape(Graph_lib::Rectangle{Point{100,200}, Point{150,400}});
    g.add_shape(Graph_lib::Rectangle{Point{100,100}, Point{150,400}});
    g.add_shape(Graph_lib::Rectangle{Point{500,200}, Point{550,400}});
    g.add_shape(Graph_lib::Regular_hexagon{Point{300,300},50});
    g.add_shape(Graph_lib::Arrow{Point{300,300},Point{50,50}});
    g.set_color(Color::black);
    win.attach(g);
    win.wait_for_button();

    g.move(10,10);
    win.wait_for_button();
    g.move(10,10);
    win.wait_for_button();
    g.move(10,10);
    g.set_color(Color::blue);
    win.wait_for_button();
    std::cout << 100;
    g.move(10,10);
    win.wait_for_button();

    return EXIT_SUCCESS;
}