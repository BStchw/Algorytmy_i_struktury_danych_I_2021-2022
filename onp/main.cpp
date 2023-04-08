#include <iostream>
#include <cassert>
#include "mystack.h"

using namespace std;


int main()
{

    std::vector<std::string> input { "-6", "2", "/" };
    int result = rpn(input); // result = -3
    cout << "Wynik: " << result << endl;



    return 0;
}