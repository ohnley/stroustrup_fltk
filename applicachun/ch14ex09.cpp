#include "dummycmake/Simple_window.h"
#include "dummycmake/Graph.h"

int main(){
    Simple_window win (Point{100,100}, 1200, 800, "hexagon example");
    win.wait_for_button();
    Graph_lib::Octagon oct = {Graph_lib::Point{300,300}, 50};
    win.attach(oct);
    win.wait_for_button();
    return EXIT_SUCCESS;
}