#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <vector>
#include "Personne.h"


using namespace std;


int main()
{
    //TEST FONCTION AFFICHAGE INFORMATION
    vector<string> competence(4,"C++");
    Personne rayan("Kallab","Rayan","kallabr@gmail.com",13011,competence);
    rayan.printInfo();
    
    return 0;
}
