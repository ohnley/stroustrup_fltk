
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include "dummycmake/Gui.h"
#include <string>

namespace Graph_lib {

//------------------------------------------------------------------------------

void Button::attach(Window& win)
{
    pw = new Fl_Button(loc.x, loc.y, width, height, label.c_str());
    pw->callback(reinterpret_cast<Fl_Callback*>(do_it), &win); // pass the window
    own = &win;
}

//------------------------------------------------------------------------------

int In_box::get_int()
{
    Fl_Input& pi = reference_to<Fl_Input>(pw);
    // return atoi(pi.value());
    const char* p = pi.value();
    if (!isdigit(p[0])) return -999999;
    return atoi(p);
}

//------------------------------------------------------------------------------

string In_box::get_string()
{
	Fl_Input *p = static_cast<Fl_Input *>(pw);

	return string{p->value()};
}

//------------------------------------------------------------------------------

void In_box::attach(Window& win)
{
    pw = new Fl_Input(loc.x, loc.y, width, height, label.c_str());
    own = &win;
}

//------------------------------------------------------------------------------

void Out_box::put(const string& s)
{
    reference_to<Fl_Output>(pw).value(s.c_str());
}

//------------------------------------------------------------------------------

void Out_box::attach(Window& win)
{
    pw = new Fl_Output(loc.x, loc.y, width, height, label.c_str());
    own = &win;
}

//------------------------------------------------------------------------------

Menu::Menu(Point xy, int w, int h, Kind kk, const string& label)
            : Widget(xy,w,h,label,0), k(kk), offset(0)
        {}

//------------------------------------------------------------------------------

void Menu::hide()                 // hide all buttons
{
    for (unsigned int i = 0; i<selection.size(); ++i) 
	selection[i].hide(); 
}

//------------------------------------------------------------------------------

void Menu::move(int dx, int dy)   // move all buttons
{
    for (unsigned int i = 0; i<selection.size(); ++i) 
	selection[i].move(dx,dy);
}

//------------------------------------------------------------------------------

void Menu::attach(Window& win)    // attach all buttons
{
    for (int i=0; i<selection.size(); ++i) win.attach(selection[i]);
    own = &win;
}
	  
//------------------------------------------------------------------------------

int Menu::attach(Button& b)
{
    b.width = width;
    b.height = height;

    switch(k) {
    case horizontal:
        b.loc = Point{loc.x+offset,loc.y};
        offset+=b.width;
        break;
    case vertical:
        b.loc = Point{loc.x,loc.y+offset};
        offset+=b.height;
        break;
    }
    selection.push_back(b); // b is NOT OWNED: pass by reference
    return int(selection.size()-1);
}

//------------------------------------------------------------------------------

int Menu::attach(Button* p)
{
    Button& b = *p;
    b.width = width;
    b.height = height;

    switch(k) {
    case horizontal:
        b.loc = Point{loc.x+offset,loc.y};
        offset+=b.width;
        break;
    case vertical:
        b.loc = Point{loc.x,loc.y+offset};
        offset+=b.height;
        break;
    }
    selection.push_back(&b); // b is OWNED: pass by pointer
    return int(selection.size()-1);
}

//------------------------------------------------------------------------------

Lines_window::Lines_window(Point xy, int w, int h, const string& title) :
    Window{xy, w, h, title},
    next_but{Point{x_max() - 150, 0}, 70, 20, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},    
    quit_but{Point{x_max() - 70, 0}, 70, 20, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},

    next_x{Point{x_max() - 310,0}, 50, 20, "next x:"},
    next_y{Point{x_max() - 210,0}, 50, 20, "next y:"},
    xy_out{Point{100,0}, 100, 20, "current (x,y):"}
    {
    attach(next_but);
    attach(quit_but);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);
    }


void Lines_window::quit(){
    hide();
}

void Lines_window::next(){
    int x = next_x.get_int();
    int y = next_y.get_int();
    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << ')';
    xy_out.put(ss.str());

}

}; // of namespace Graph_lib
