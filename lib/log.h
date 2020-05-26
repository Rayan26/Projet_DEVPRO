#ifndef _LOG
#define _LOG
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;
class Log
{
public:
	Log(std::string msg);
	void msg(std::string msg);
};




#endif