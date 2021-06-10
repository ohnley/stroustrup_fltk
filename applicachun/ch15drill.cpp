#include "dummycmake/Window.h"
#include "dummycmake/Graph.h"
#include "dummycmake/Simple_window.h"
#include <iostream>
#include <string>

double one (double x){return 1;}
double slope(double x){return x/2;}
double square(double x){return x*x;}

struct Person {
    public:
        Person() : name(""), age(0) {}
        Person(std::string n, int a) : name(n), age(a) {}
        std::string get_name() const {return name;}
        int get_age() const {return age;}
        void set_name(std::string n) {name = n;}
        void set_age(int a) {
            if(a > 150) error("age exceeds 150"); 
            age = a;
        }


    private:
        string name;
        int age;

    // friend ostream& operator<<(ostream os, const Person& p);
    // friend ostream& operator>>(ostream os, const Person& p);

};


void  contains_invalid(const std::string& input, const std::string& excl){
    for (char c : input){
        for (char e : excl){
            if (c == e) error("name contains invalid character in the following: " + excl);
        }
    }
}

std::ostream& operator<<(ostream& os, const Person& p){
    os << "Name: " << p.get_name() << " Age: " << p.get_age() << "\n";
    return os;
} 

std::istream& operator>>(istream& os, Person& p){
    int new_age;
    string new_name;
    
    cin >> new_name;
    cin >> new_age;
    if (new_age >= 150) error("Age above 150, error.");
    
    cout << "new_name: " << new_name << '\n';
    cout << "new_age: " << new_age << '\n';

    p.set_age(new_age);
    p.set_name(new_name);

    return os;

} 

int main(){

    Simple_window win {Graph_lib::Point{100,100}, 600, 600, "Function graphing"};
    const int axis_x = 100;
    const int axis_y = 300;
    const int axis_length = 400;
    const int notches = 20;
    const int x_scale = axis_length/notches;
    const int y_scale = axis_length/notches;
    Graph_lib::Axis x {Graph_lib::Axis::Orientation::x, Graph_lib::Point{axis_x, axis_y}, axis_length, notches, "x-axis"};
    Graph_lib::Axis y {Graph_lib::Axis::Orientation::y, Graph_lib::Point{axis_y, axis_y + (axis_length/2)}, axis_length, notches, "y-axis"};
    win.attach(x);
    win.attach(y);
    x.set_color(Graph_lib::Color::red);
    y.set_color(Graph_lib::Color::red);

    Graph_lib::Function onef = {one, -8, 6, Point{300,300}, 400, x_scale, y_scale};
    Graph_lib::Function halff = {slope, -8, 6, Point{300,300}, 400, x_scale, y_scale};
    onef.set_color(Color::blue);
    halff.set_color(Color::green);
    win.attach(onef);
    win.attach(halff);
    win.wait_for_button();


    Person iam = {"Todd", 69};
    std::cout << iam;
    
    std::cout << "Please Input A Name and an Age:";
    Person per = {};
    std::cin >> per;
    std::cout << per;
    // x = (x++) * (++x);
    return EXIT_SUCCESS;
}