#include "dummycmake/Gui.h"
#include "dummycmake/Simple_window.h"


struct My_window : Simple_window {
    My_window(Point xy, int w, int h, const string& ti) :
        Simple_window(xy, w, h, ti),
        quit_button{Point{x_max() - 150, 0}, 70, 20, "quit",
            [](Address, Address pw) {reference_to<My_window>(pw).quit();}}
    {
        attach(quit_button);
    }
    
    private:
        void quit() {hide();}
        Button quit_button;
};



int main(){
    try
    {
        My_window win{Graph_lib::Point{100, 100}, 600, 400, "mywin"};
        return Graph_lib::gui_main();
    }
    catch (exception &e)
    {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "Some exception\n";
        return 2;
    }
}