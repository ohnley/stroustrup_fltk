#include "dummycmake/Simple_window.h"
#include "dummycmake/Graph.h"
// #include <vector>
// #include <iostream>

void ex04(Simple_window& win){
    Graph_lib::Rectangle rect1{Point{100, 100},100,100};
    rect1.set_fill_color(Color::white);
    win.attach(rect1);

   Graph_lib::Rectangle rect2{Point{200, 100},100,100};
    rect2.set_fill_color(Color::red);
    win.attach(rect2);

    Graph_lib::Rectangle rect3{Point{300, 100},100,100};
    rect3.set_fill_color(Color::white);
    win.attach(rect3);

    Graph_lib::Rectangle rect4{Point{100, 200},100,100};
    rect4.set_fill_color(Color::red);
    win.attach(rect4);

    Graph_lib::Rectangle rect5{Point{200, 200},100,100};
    rect5.set_fill_color(Color::white);
    win.attach(rect5);

    Graph_lib::Rectangle rect6{Point{300, 200},100,100};
    rect6.set_fill_color(Color::red);
    win.attach(rect6);

    Graph_lib::Rectangle rect7{Point{100, 300},100,100};
    rect7.set_fill_color(Color::white);
    win.attach(rect7);

    Graph_lib::Rectangle rect8{Point{200, 300},100,100};
    rect8.set_fill_color(Color::red);
    win.attach(rect8);


    Graph_lib::Rectangle rect9{Point{300, 300},100,100};
    rect9.set_fill_color(Color::white);
    win.attach(rect9);

    win.wait_for_button();
}

void ex06(Simple_window& win){
    Closed_polyline poly;
    poly.add(Point{300,300});
    poly.add(Point{700,300});
    poly.add(Point{300,700});
    poly.add(Point{700,700});
    poly.add(Point{800,550});

    win.attach(poly);
    win.wait_for_button();

}

void ex09(Simple_window& win){
  Image simple_gif {Point{10,10}, "F:\\my_dev\\dummy_cmake\\applicachun\\tenor.gif"};
  simple_gif.set_mask(Point{0,0}, 500,500);
  win.attach(simple_gif);
  win.wait_for_button();


}

void ch13_grid(Simple_window& win){
    Graph_lib::Lines grid;
    int boxes_per = 10;
    int x_size = win.x_max();
    int y_size = win.y_max();
    for (int x = 0; x <= x_size; x += (x_size/boxes_per) ){
        grid.add(Point{x, 0}, Point{x, y_size});
    }
    for (int y = 0; y <= y_size; y += (y_size/boxes_per) ){
        grid.add(Point{0, y}, Point{x_size, y});
    }
    grid.set_style(Line_style{Line_style::dash, 3});
    win.attach(grid);
    win.wait_for_button();
    
}

void ch_13drill(){
    Simple_window drill_win {Point{100, 100}, 1100, 900, "header"};
    
    // create gridlines
    Lines grid {};
    for (int i = 0; i < 9; i++){
        grid.add(Point{200, i*100}, Point{1000, i*100});
        grid.add(Point{200 + (100*i), 0}, Point{ 200 + (100*i), 800});
    }
    drill_win.attach(grid);
    
    // create rectangles
    Vector_ref<Graph_lib::Rectangle> rects;
    for (int i = 0; i < 8; i++){
        rects.push_back(new Graph_lib::Rectangle {Point{200 + (i* 100), (i*100)}, 101, 101});
        rects[rects.size()-1].set_fill_color(Color::dark_red);
        drill_win.attach(rects[rects.size()-1]);
    }

    // add 200x200 image
    Image simple_gif1 {Point{200, 200}, "F:\\my_dev\\dummy_cmake\\applicachun\\homer.gif"};
    Image simple_gif2 {Point{200, 400}, "F:\\my_dev\\dummy_cmake\\applicachun\\homer.gif"};
    Image simple_gif3 {Point{400, 400}, "F:\\my_dev\\dummy_cmake\\applicachun\\homer.gif"};
    drill_win.attach(simple_gif1);
    drill_win.attach(simple_gif2);
    drill_win.attach(simple_gif3);

    // jumping 100x100 image
    for (int i = 0; i<5; i++){
        int x;
        if (i%2 == 0) x = i;
        else x = i*2;
        int y = 2;
        Image simple_im {Point{200+ x*100, 400},"F:\\my_dev\\dummy_cmake\\applicachun\\char.gif" };
        drill_win.attach(simple_im);
        drill_win.wait_for_button();

    }
    
    drill_win.wait_for_button();
}

void ch13ex01(){
    
    Simple_window win (Point{100,100}, 1200, 800, "header");
    Graph_lib::Arc arc1(Point{150,100}, 100, 50, 45,175);
    win.attach(arc1);
    //win.wait_for_button();
    arc1.set_color(Color::red);
    arc1.set_color(Color::dark_cyan);
    
    // win.attach(arc1);
    // arc1.set_color(Color::dark_cyan);
    // arc1.draw_lines();
    win.wait_for_button();
}

void ch13ex02(){
     Simple_window win (Point{100,100}, 1200, 800, "header");
     Graph_lib::Box b{200, 200, 300, 200, 10};
     win.attach(b);
     b.set_color(Color::red);
     b.set_color(Color::cyan);
     win.wait_for_button();

     b.move(100,300);

     Graph_lib::Arrow ar{Point{300,100}, Point{100,50}};
     win.attach(ar);
     win.wait_for_button();
}

void ch13ex04(){
    Simple_window win (Point{100,100}, 1200, 800, "header");

    Graph_lib::Rectangle rec {Point{200,300}, Point{250,350}};
    rec.set_color(Color::red);
    win.attach(rec);
    
    // center of rectangle
    Graph_lib::Point center = Graph_lib::center(rec);
    Graph_lib::Mark centmark {center, 'c'};
    // std::cout << center.x << " y: " << center.y << '\n';
    win.attach(centmark);
    
    
    
    win.wait_for_button();
}

int main(){

    using namespace Graph_lib; //our graphics facilities are in Graph_lib (defined in Graph.h)

    // Point top_left{600, 300};    //will be top left corner of window

    // Simple_window win {top_left, 600, 600, "Canvas"};
    // ch13ex02();
    ch13ex04();
    ch_13drill();
    // ex04(win);
    // ex06(win);
    // ex09(win);
    // ch13_grid(win);
    // win.wait_for_button();


    // Axis xa {Axis::x, Point{20,350},280,10,"x-axeees"};
    // xa.set_color(Color::dark_magenta);
    // win.attach(xa);
    // Axis ya {Axis::y, Point{20,350}, 280, 10, "y axiiss"};
    // win.attach(ya);
    // win.set_label("20,000 LBS OF BANANAS");
    // Function sine {sin, 0, 100, Point{20,150}, 1000, 50, 50};
    // sine.set_color(Color::blue);
    // win.attach(sine);

    // poly.add(Point{300,200}); // three points make a triangle
    // poly.add(Point{350,100});
    // poly.add(Point{400,200});
    // poly.set_color(Color::red);
    // poly.set_style(Line_style::dash);
    // win.attach(poly);

    // Graph_lib::Rectangle r {Point{200,200}, 300, 30}; // top left corner, width, height
    // win.attach(r);

    // Closed_polyline poly_rect;
    // poly_rect.add(Point{100,50});
    // poly_rect.add(Point{200,50});
    // poly_rect.add(Point{200,100});
    // poly_rect.add(Point{100,100});
    // poly_rect.add(Point{50,75});
    // win.attach(poly_rect);

    // r.set_fill_color(Color::yellow); // color the inside of the rectangle
    // poly.set_style(Line_style(Line_style::dash,4));
    // poly_rect.set_style(Line_style(Line_style::dash,2));
    // poly_rect.set_fill_color(Color::green);


    // Text t {Point{150,150}, "Hello, graphical world!"};
    // win.attach(t);
    // win.set_label("Canvas #8");

    // win.wait_for_button();  //give control to the display engine
    return 0;
}

// void printer(const vector<int> list){
//     for (int i : list){
//         std::cout << i << " ";
//     }
    
//     std::cout << '\n';
// }