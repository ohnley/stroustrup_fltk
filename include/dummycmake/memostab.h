#include <unordered_map>

long tab_fib(int n);
long fib_memo(int n, std::unordered_map<int, long> &fibmap);
long dumb_fib(int n);
