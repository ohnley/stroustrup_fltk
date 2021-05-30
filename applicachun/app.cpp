#include "dummycmake/Simple_window.h"
#include "dummycmake/Graph.h"
// #include <vector>
// #include <iostream>
#define MY_PI_CONST  3.14159265358979323846

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
    win.attach(centmark);
    win.wait_for_button();

    center = Graph_lib::n(rec);
    Graph_lib::Mark north {center, 'n'};

    win.attach(north);

    // don't need to re-attach, it already knows to move it
    centmark.move(100, 100); 
   
    win.wait_for_button();

}

void ch13ex08(){
    Simple_window win (Point{100,100}, 1200, 800, "hexagon example");

    Graph_lib::Regular_hexagon rhex {Point{400, 400}, 100};
    Graph_lib::Regular_hexagon ehex {Point{400, 572}, 100};
    Graph_lib::Regular_hexagon ehex {Point{700, 572}, 100};
    Graph_lib::Regular_hexagon qhex {Point{700, 400}, 100};
    Graph_lib::Regular_hexagon shex {Point{100, 400}, 100};
    
    win.attach(rhex);
    win.attach(ehex);
    win.attach(qhex);
    win.attach(shex);
    win.wait_for_button();

    while (true){
        rhex.move(2,3);
        win.wait_for_button();
    }

}

int main(){
    using namespace Graph_lib; 
    ch13ex08();
    

    
    return 0;
}

