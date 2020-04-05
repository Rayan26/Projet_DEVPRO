#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <vector>
#include "Personne.h"


using namespace std;


int main()
{
    vector<string> comp;
    string* str = new string("C++");
    Personne rayan("Kallab","Rayan","kallabr@gmail.com",13011,str);

    rayan.printInfo();
    
    return 0;
}
