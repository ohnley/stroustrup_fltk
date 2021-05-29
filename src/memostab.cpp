#include "dummycmake/memostab.h"
#include <iostream>
// memo-ized fib

// int addingsd(int jk){
// 	return jk * 2;
// }


long tab_fib(const int n){
    if (n <= 0) return 0;
    if (n == 1) return 1;
    std::vector<long> v(n+1, 0);  
    v[1] = 1;
    for (int i = 2; i <= n; i++){
        v[i] = v[i-1] + v[i-2];
    }  
    return v[v.size()-1];
}

long dumb_fib(int n){
    if (n <= 0) return 0;
    else if(n == 1) return 1;
    else return (long)(dumb_fib(n-1) + dumb_fib(n-2));
}


long fib_memo(int n, std::unordered_map<int, long> &fibmap){
    if (fibmap.find(n) != fibmap.end()) return fibmap[n];
    
    long ret_val;
    
    if (n == 0) ret_val = 0;
    else if (n == 1) ret_val = 1;
    else ret_val = (fib_memo(n-1, fibmap) + fib_memo(n-2, fibmap));

    fibmap[n] = ret_val;
    return ret_val;
}

