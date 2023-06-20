#pragma once
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

namespace DebugFrameWork
{
#define RESET_STR "\033[0m";
#define BLACK_STR "\033[30m" ; /* Black */
#define RED_STR "\033[31m"   ; /* Red */
#define GREEN_STR "\033[32m"  ;/* Green */
#define YELLOW_STR "\033[33m"; /* Yellow */
#define BLUE_STR "\033[34m"  ; /* Blue */
#define PURPLE_STR "\033[35m" ;/* Purple */
#define CYAN_STR "\033[36m"  ; /* Cyan */
#define WHITE_STR "\033[37m" ; /* White */

	enum DebugColorEnum
	{
		NONE = 0,
		Black,
		Red,
		Green,
		Yellow,
		Blue,
		Purple,
		Cyan,
		White,
	};

	template<class T>
	void Log(T& log, int col)
	{
		DebugFrameWork::DebugColorEnum colorType = static_cast<DebugFrameWork::DebugColorEnum>(col);
		string start = "";
		string end = RESET_STR;
		switch (colorType)
		{
		case DebugFrameWork::DebugColorEnum::NONE:
			end = "";
			break;
		case DebugFrameWork::DebugColorEnum::Black:
			start = BLACK_STR;
			break;
		case DebugFrameWork::DebugColorEnum::Red:
			start = RED_STR;
			break;
		case DebugFrameWork::DebugColorEnum::Green:
			start = GREEN_STR;
			break;
		case DebugFrameWork::DebugColorEnum::Yellow:
			start = YELLOW_STR;
			break;
		case DebugFrameWork::DebugColorEnum::Blue:
			start = BLUE_STR;
			break;
		case DebugFrameWork::DebugColorEnum::Purple:
			start = PURPLE_STR;
			break;
		case DebugFrameWork::DebugColorEnum::Cyan:
			start = CYAN_STR;
			break;
		case DebugFrameWork::DebugColorEnum::White:
			start = WHITE_STR;
			break;
		default:
			end = "";
			break;
		}

		cout << start << log << end << endl;
		/*SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);*/
	}
	//void Log(std::string, int);
}
