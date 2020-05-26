#include "log.h"
using namespace std;

const std::string currentDateTime()
{
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
	// for more information about date/time format
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}

Log::Log(std::string msg)
{
	this->msg(msg);
}



void Log::msg(std::string msg)
{
	std::fstream journal("log/log.txt", ios::app);
	journal << currentDateTime() << " : " << msg << endl;
}