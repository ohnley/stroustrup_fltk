//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef GRAPH_GUARD
#define GRAPH_GUARD 1

#include <FL/fl_draw.H>
#include <FL/Fl_Image.H>
#include "Point.h"
#include "std_lib_facilities.h"
#include <functional>

namespace Graph_lib {

// defense against ill-behaved Linux macros:
#undef major
#undef minor

//------------------------------------------------------------------------------

// Color is the type we use to represent color. We can use Color like this:
//    grid.set_color(Color::red);
struct Color {
    enum Color_type {
        red=FL_RED,
        blue=FL_BLUE,
        green=FL_GREEN,
        yellow=FL_YELLOW,
        white=FL_WHITE,
        black=FL_BLACK,
        magenta=FL_MAGENTA,
        cyan=FL_CYAN,
        dark_red=FL_DARK_RED,
        dark_green=FL_DARK_GREEN,
        dark_yellow=FL_DARK_YELLOW,
        dark_blue=FL_DARK_BLUE,
        dark_magenta=FL_DARK_MAGENTA,
        dark_cyan=FL_DARK_CYAN
    };

    enum Transparency { invisible = 0, visible=255 };

    Color(Color_type cc) :c(Fl_Color(cc)), v(visible) { }
    Color(Color_type cc, Transparency vv) :c(Fl_Color(cc)), v(vv) { }
    Color(int cc) :c(Fl_Color(cc)), v(visible) { }
    Color(Transparency vv) :c(Fl_Color{}), v(vv) { }    // default color

    int as_int() const { return c; }

    char visibility() const { return v; } 
    void set_visibility(Transparency vv) { v=vv; }
private:
    char v;    // invisible and visible for now
    Fl_Color c;
};

//------------------------------------------------------------------------------

struct Line_style {
    enum Line_style_type {
        solid=FL_SOLID,            // -------
        dash=FL_DASH,              // - - - -
        dot=FL_DOT,                // ....... 
        dashdot=FL_DASHDOT,        // - . - . 
        dashdotdot=FL_DASHDOTDOT,  // -..-..
    };

    Line_style(Line_style_type ss) :s(ss), w(0) { }
    Line_style(Line_style_type lst, int ww) :s(lst), w(ww) { }
    Line_style(int ss) :s(ss), w(0) { }

    int width() const { return w; }
    int style() const { return s; }
private:
    int s;
    int w;
};

//------------------------------------------------------------------------------

class Font {
public:
    enum Font_type {
        helvetica=FL_HELVETICA,
        helvetica_bold=FL_HELVETICA_BOLD,
        helvetica_italic=FL_HELVETICA_ITALIC,
        helvetica_bold_italic=FL_HELVETICA_BOLD_ITALIC,
        courier=FL_COURIER,
        courier_bold=FL_COURIER_BOLD,
        courier_italic=FL_COURIER_ITALIC,
        courier_bold_italic=FL_COURIER_BOLD_ITALIC,
        times=FL_TIMES,
        times_bold=FL_TIMES_BOLD,
        times_italic=FL_TIMES_ITALIC,
        times_bold_italic=FL_TIMES_BOLD_ITALIC,
        symbol=FL_SYMBOL,
        screen=FL_SCREEN,
        screen_bold=FL_SCREEN_BOLD,
        zapf_dingbats=FL_ZAPF_DINGBATS
    };

    Font(Font_type ff) :f{ff} { }
    Font(int ff) :f{ff} { }

    int as_int() const { return f; }
private:
    int f;
};

//------------------------------------------------------------------------------

template<class T> class Vector_ref {
    vector<T*> v;
    vector<T*> owned;
public:
    Vector_ref() {}

    ~Vector_ref() { for (int i=0; i<owned.size(); ++i) delete owned[i]; }

    void push_back(T& s) { v.push_back(&s); }
    void push_back(T* p) { v.push_back(p); owned.push_back(p); }

    T& operator[](int i) { return *v[i]; }
    const T& operator[](int i) const { return *v[i]; }

    int size() const { return v.size(); }
};

//------------------------------------------------------------------------------

typedef std::function<double (double)> Fct;

class Shape  {        // deals with color and style, and holds sequence of lines 
public:
    void draw() const;                 	// deal with color and draw lines
    virtual void move(int dx, int dy); 	// move the shape +=dx and +=dy

    void set_color(Color col); 
    Color color() const;

    void set_style(Line_style sty);
    Line_style style() const; 

    void set_fill_color(Color col); 
    Color fill_color() const; 

    Point point(int i) const;  		// read only access to points
    int number_of_points() const; 

    Shape(const Shape&) = delete;      	// prevent copying
    Shape& operator=(const Shape&) = delete;

    virtual ~Shape() { }
protected:
    Shape() {};    
    Shape(initializer_list<Point> lst);

    virtual void draw_lines() const;   // draw the appropriate lines
    void add(Point p);                 // add p to points
    void set_point(int i,Point p);     // points[i]=p;
private:
    vector<Point> points;              // not used by all shapes
    Color lcolor {static_cast<int>(fl_color())};// color for lines and characters (with default)
    Line_style ls {0}; 
    Color fcolor {Color::invisible};   // fill color
};

//------------------------------------------------------------------------------

struct Function : Shape {
    // the function parameters are not stored
    Function(Fct f, double r1, double r2, Point orig,
        int count = 100, double xscale = 25, double yscale = 25, double filler = 20);    
    Function(double (*f)(double), double r1, double r2, Point orig,
	int count = 100, double xscale = 25, double yscale = 25);
};

//------------------------------------------------------------------------------

struct Line : Shape {            // a Line is a Shape defined by two Points
    Line(Point p1, Point p2);    // construct a line from two points
};

//------------------------------------------------------------------------------

struct Rectangle : Shape {
    Rectangle(Point xy, int ww, int hh);
    Rectangle(Point x, Point y);
    void draw_lines() const;

    int height() const { return h; }
    int width() const { return w; }
private:
    int h;    // height
    int w;    // width
};

//------------------------------------------------------------------------------

struct Open_polyline : Shape {         // open sequence of lines
    Open_polyline() {}
    Open_polyline(initializer_list<Point> lst): Shape{lst} {}
    
    void add(Point p) { Shape::add(p); }
};

//------------------------------------------------------------------------------

struct Closed_polyline : Open_polyline { // closed sequence of lines
    using Open_polyline::Open_polyline;	 // use Open_polyline's 
					 // constructors (A.16)
    void draw_lines() const;		
};

//------------------------------------------------------------------------------

struct Polygon : Closed_polyline {    // closed sequence of non-intersecting lines
    Polygon() {};
    Polygon(initializer_list<Point> lst);

    void add(Point p);
};

//------------------------------------------------------------------------------

struct Lines : Shape {                 // related lines
    Lines() {}			       // empty
    Lines(initializer_list<pair<Point,Point>> lst); // initialize from a list

    void draw_lines() const;
    void add(Point p1, Point p2);      // add a line defined by two points
};

//------------------------------------------------------------------------------

struct Text : Shape {
    // the point is the bottom left of the first letter
    Text(Point x, const string& s) 
	: lab{s} 
	{ add(x); }

    void draw_lines() const;

    void set_label(const string& s) { lab = s; }
    string label() const { return lab; }

    void set_font(Font f) { fnt = f; }
    Font font() const { return fnt; }

    void set_font_size(int s) { fnt_sz = s; }
    int font_size() const { return fnt_sz; }
private:
    string lab;    // label
    Font fnt{fl_font()};
    int fnt_sz{fl_size()<14?14:fl_size()};
};

//------------------------------------------------------------------------------

struct Axis : Shape {
    enum Orientation { x, y, z };
    Axis(Orientation d, Point xy, int length,
        int number_of_notches=0, string label = "");

    void draw_lines() const override;
    void move(int dx, int dy) override;
    void set_color(Color c);

    Text label;
    Lines notches;
};

//------------------------------------------------------------------------------

struct Circle : Shape {
    Circle(Point p, int rr);    // center and radius

    void draw_lines() const;

    Point center() const ; 
    int radius() const { return r; }
    void set_radius(int rr) 
    { 
	set_point(0,Point{center().x-rr, center().y-rr}); // maintain
							  // the center
	r=rr; 
    }
private:
    int r;
};

//------------------------------------------------------------------------------

struct Ellipse : Shape {
    Ellipse(Point p, int w, int h);    // center, min, and max distance from center

    void draw_lines() const;

    Point center() const;
    Point focus1() const;
    Point focus2() const;

    void set_major(int ww) 
    { 	
	set_point(0,Point{center().x-ww,center().y-h});	// maintain
							// the center
	w=ww; 
    }
    int major() const { return w; }

    void set_minor(int hh) 
    { 
	set_point(0,Point{center().x-w,center().y-hh});	// maintain
							// the center
	h=hh; 
    }
    int minor() const { return h; }
private:
    int w;
    int h;
};

//------------------------------------------------------------------------------

struct Marked_polyline : Open_polyline {
    Marked_polyline(const string& m) :mark{m} { if(m=="") mark="*"; }
    Marked_polyline(const string& m, initializer_list<Point> lst);
    void draw_lines() const;
private:
    string mark;
};

//------------------------------------------------------------------------------

struct Marks : Marked_polyline {
    Marks(const string& m) :Marked_polyline(m)
    {
        set_color(Color{Color::invisible});
    }
    Marks(const string& m, initializer_list<Point> lst)
	: Marked_polyline{m,lst}
    {
	set_color(Color{Color::invisible});
    }
};

//------------------------------------------------------------------------------

struct Mark : Marks {
    Mark(Point xy, char c) : Marks(string(1,c))
    {
        add(xy);
    }
};

//------------------------------------------------------------------------------

enum class Suffix {
    none, jpg, gif 
};

//------------------------------------------------------------------------------

struct Image : Shape {
    Image(Point xy, string file_name, Suffix e = Suffix::none);
    ~Image() { delete p; }
    void draw_lines() const;
    void set_mask(Point xy, int ww, int hh) { w=ww; h=hh; cx=xy.x; cy=xy.y; }
private:
    int w,h;  // define "masking box" within image relative to position (cx,cy)
    int cx,cy; 
    Fl_Image* p;
    Text fn;
};

//------------------------------------------------------------------------------

struct Bad_image : Fl_Image {
    Bad_image(int h, int w) : Fl_Image(h,w,0) { }
    void draw(int x,int y, int, int, int, int) { draw_empty(x,y); }
};

//------------------------------------------------------------------------------

struct Arc : Shape {
    Arc(Point p, int ww, int hh, double aa1, double aa2);

    void draw_lines() const;
    Point center() const { return Point{point(0).x + w, point(0).y+h}; }
    void set_major(int ww) { set_point(0,Point{center().x-ww,center().y-h}); w=ww; }
	int major() const { return w; }
	void set_minor(int hh) { set_point(0,Point{center().x-w,center().y-hh}); h=hh; }
	int minor() const { return h; }

    void set_angle1(double d)
    {
        if (d >= a2) error("first arc angle cannot be bigger than second angle");
        a1 = d;
    }

    void set_angle2(double d)
    {
        if (d <= a1) error("second arc angle cannot be smaller than first angle");
        a2 = d;
    }

    void set_angles(double d1, double d2)
    {
        if (d2<=d1) error("second arc angle must be bigger than first angle");
        a1 = d1;
        a2 = d2;
    }
private:
    int w;
    int h;
    double a1;
    double a2;
};


struct Box : Shape {
    Box(int x, int y, int w, int h, int round);
    void draw_lines() const ;
    int get_rad() {return r;}
    void set_rad(int rd) {r = rd;}
    

    private:
        Lines lines;
        int r;
        int x;
        int y;
        int w;
        int h;
};

struct Arrow : Line {
    Arrow(Graph_lib::Point a, Graph_lib::Point b) : Line(a,b) {}
    void draw_lines() const;
};

Graph_lib::Point center(Graph_lib::Rectangle& r);
Graph_lib::Point n(Graph_lib::Rectangle& r);

struct Regular_hexagon : Lines {
    Regular_hexagon(Graph_lib::Point center, int side_size);
};

class Immobile_Circle : public Circle {
    public:
        Immobile_Circle(Point p, int rr) : Circle(p, rr){}
    
    // disable the function of Circle by limiting its scope to within the class
    private:
        Circle::move;
};

// abstract class have protected constructors
class Abstract_Class {
    public:
        int some_public;
    protected:
        Abstract_Class(int x, double mult){some_public = mult*x;};

};

class Octagon : public Shape{
    public:
        Octagon(Point p, int size);
    protected:
        void move(int dx, int dy);
        void set_size(int r);
        void draw_lines() const;
    private:
        int size;
    
};


// when you attach a group to a window
// it gets narrowed down to a Shape
// so it loses its list of shapes
// so we need to modify the window class to handle groups
class Group : public Shape {
    public:
        void add_shape(Shape& s) {shapes.push_back(s);}
        void move(int index, int dx, int dy);
        void move(int dx, int dy);
        void set_style(Line_style sty);
        void set_color(Color col);
        void set_fill_color(Color col);
        void draw();
        int number_shapes() {return shapes.size();}
        Shape* get_shape(int i) {return &shapes[i];}
    private:
        Vector_ref<Shape> shapes;

        // prevent the child class Group from accessing these functions 
        Shape::number_of_points;        
        Shape::point;
        Shape::add;
        Shape::set_point;

};



} // of namespace Graph_lib

#endif
