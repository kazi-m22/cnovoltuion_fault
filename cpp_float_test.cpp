#include <iostream>
#include "cpp_float.h"
#include <cstdlib>


int main() {
    // Example usage
    float x[1024];
    float y[1024];
    int size = 4;

    //populating input
    for(int i = 0; i<1024; i++) {
    	x[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    cpp_float(x, y);

    for(int i = 0; i<1024; i++){
    	cout << y[i] << endl;
    }
    //std::cout << "Result: " << result << std::endl;

    return 0;
}
//    // Test case 1
//    float result1 = cpp_float(1.5, 2.5, 3.5, 4.5);
//    std::cout << "Test Case 1 Result: " << result1 << std::endl;
//
//    // Test case 2
//    float result2 = cpp_float(0.0, 0.0, 0.0, 0.0);
//    std::cout << "Test Case 2 Result: " << result2 << std::endl;
//
//    // Test case 3
//    float result3 = cpp_float(-1.0, 1.0, -1.0, 1.0);
//    std::cout << "Test Case 3 Result: " << result3 << std::endl;
//
//    // Add more test cases as needed...

//    return 0;

