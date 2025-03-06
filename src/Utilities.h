#include<iostream>



#define DEBUG 1


#if DEBUG
#define LOG(x) std::cout << x << '\n'
#else
#define LOG(x)
#endif