#include "Debug.h"
#include <string>

using std::string;
using std::cout;
using std::endl;

namespace DebugFrameWork
{
	/// <summary>
	/// 控制台输出颜色
	/// </summary>
	/// <param name="log"></param>
	/// <param name="colorType"></param>
	//template<class T>
	//void Log(T& log, int col)
	void Log(string log, int col)
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
}