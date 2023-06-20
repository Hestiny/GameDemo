#include "CommonTool.h"
#include "../DebugTool/Debug.h"

using namespace DebugFrameWork;

namespace CommonTool
{
	template<class T>
	int Length(T& arr)
	{
		if (arr == nullptr)
		{
			Log("数组获取长度失败 地址为空", Red);
			return 0;
		}
		return sizeof(arr) / sizeof(arr[0]);
	}
}