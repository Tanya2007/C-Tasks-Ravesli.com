#include <iostream>
#include <conio.h>
#include <ctime>
#include <string>

#if defined (_WIN32)
#include <windows.h>
void sleep()
{
	Sleep(1000);
}
//for other operating systems, 
//you need to write your own function "sleep()"
#endif

int main()
{
	int count(0);
	std::string h, m, s;
	
	while((!_kbhit()) && (count < 3000))
	{	
		std::time_t end_time = time(nullptr);
		
		tm local_tm;
		localtime_s(&local_tm, &end_time);
		
		h = local_tm.tm_hour < 10 ? "0" + std::to_string(local_tm.tm_hour) : std::to_string(local_tm.tm_hour);
		m = local_tm.tm_min < 10 ? "0" + std::to_string(local_tm.tm_min) : std::to_string(local_tm.tm_min);
		s = local_tm.tm_sec < 10 ? "0" + std::to_string(local_tm.tm_sec) : std::to_string(local_tm.tm_sec);
		
		std::cout << "\r" << h << ":" << m << ":" << s;
		
		++count;
		sleep();
	}

	return 0;
}