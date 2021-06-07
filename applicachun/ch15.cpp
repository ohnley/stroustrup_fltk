// #include "dummycmake/Simple_window.h"
// #include "dummycmake/Graph.h"
// #include <string>

// double one(double) {return 1;}
// double half_slope(double x) {return x/2;}
// double square(double x) {return x*x;}
// double slope_cos(double x) {return cos(x) + half_slope(x);}

// double fac(int n ){
//     if (n <= 1) return 1;
//     return (double) n * fac(n-1);
// }
// double term(double x, int n){return pow(x,n)/fac(n);}

// double expe(double x, int n){
//     double sum = 0;
//     for (int i = 0; i < n; i++) sum += term(x,i);
//     return sum;
// }

// int main(){
//     constexpr int xmax = 1000;
//     constexpr int ymax = 800;
//     constexpr int x_orig = xmax/2; // position of (0,0) is center of window
//     constexpr int y_orig = ymax/2;
//     constexpr Point orig {x_orig,y_orig};
//     constexpr int r_min = -10; // range [–10:11)
//     constexpr int r_max = 11;
//     constexpr int n_points = 400; // number of points used in range
//     constexpr int x_scale = 30; // scaling factors
//     constexpr int y_scale = 30;
//     Simple_window win {Point{100,100},xmax,ymax,"Function graphing"};

//     // Function s {one, r_min, r_max, orig, n_points, x_scale, y_scale };
//     // Function sq {square, r_min, r_max, orig, n_points, x_scale, y_scale };
//     Function sc {slope_cos, 
//                  r_min, r_max, orig, n_points, x_scale, y_scale};

//     // use a lambda expression rather than a function
//     // can add an explicit return return type with "-> <type>" after the argument list
//     Function ss {[](double x) -> double { return cos(x) + half_slope(x);}, 
//                  r_min, r_max, orig, n_points, x_scale, y_scale, 100};
//     win.attach(ss);
//     win.wait_for_button();  
//     ss.set_color(Color::black);
//     ostringstream strstrm;
//     for (int n = 0; n<10; n++){
//         strstrm << "exp approx: n==" << n;
//         win.set_label(strstrm.str());
//         Function e {[n](double x) {return (expe(x,n));}, r_min, r_max, orig,
//             200, x_scale, y_scale};
//         win.attach(e);
//         win.wait_for_button();
//         win.detach(e);
//     }



//     // std::string file_name = "japanese-age-data.txt";

//     // ifstream ifs {file_name};
//     // Graph_lib::Lines young = {};
//     // Graph_lib::Lines middle = {};
//     // Graph_lib::Lines old = {};

    
//     // if (!ifs) error("file not found or cannot open file", file_name);
//     // int base_year = 1900;
//     // int end_year = 2050;
//     // for (Distribution d; ifs >> d;){
//     //     if (d.year < base_year || end_year < d.year){
//     //         error("year out of range");
//     //     }
//     //     if (d.young + d.old + d.middle != 100){
//     //         error("data does not add to 100 for year: " + d.year);
//     //     }
        
//     //     Graph_lib::Point py_start = young.point(young.number_of_points() - 1);
//     //     Graph_lib::Point pm_start = middle.point(middle.number_of_points() - 1);
//     //     Graph_lib::Point oy_start = old.point(old.number_of_points() - 1);

        
//     // }


//     return EXIT_SUCCESS;
// }