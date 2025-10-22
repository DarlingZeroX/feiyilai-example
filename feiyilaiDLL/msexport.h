#pragma once
#include "config.h"
#include "msclass.h"

extern "C" {

	FYL_API void WINAPI C64_PrintHandle(int m_hdl);

	FYL_API int WINAPI C64_Open(int Nbr);

	FYL_API int WINAPI C64_Open_VidPid(int Vid, int Pid);

	FYL_API int WINAPI C64_Close(int m_hdl);

	
	FYL_API int WINAPI C64_GetDevSn(int m_hdl, DWORD* dwp_LenResponse, unsigned char* ucp_Response);

	FYL_API int WINAPI C64_SetUserData(int m_hdl, DWORD dw_LenUserData, unsigned char* ucp_UserData);
	//验证用户数据 //参数定义同上
	FYL_API int WINAPI C64_VerifyUserData(int m_hdl, DWORD dw_LenUserData, unsigned char* ucp_UserData);
	//检查盒子是否是可修改盒子; 返回: 0:是可修改； 其他:不可修改
	FYL_API int WINAPI C64_ChkSupportMdy(int m_hdl);
	//读取当前绝对移动功能的状态 返回: 1:打开; 0:关闭; 其他: 错误
	FYL_API int WINAPI C64_GetAbsCfg(int m_hdl);
	//设置绝对移动功能: e1d0=1 打开; =0;关闭
	FYL_API int WINAPI C64_SetAbsCfg(int m_hdl, int e1d0);


	FYL_API int WINAPI C64_SetNewVidPid(int m_hdl, int mVid, int mPid, int sVid, int sPid);
	FYL_API int WINAPI C64_ResetVidPid(int m_hdl);
	//读取VID/PID; IdIndex=1/2/3/4 分别对应 主控端Vid, 主控端Pid, 被控端Vid, 被控端Pid
	FYL_API int WINAPI C64_GetVidPid(int m_hdl, int IdIndex);
	//是否支持修改产品名称, 返回值1=支持，0=不支持；-1，失败
	FYL_API int WINAPI C64_ChkSupportProdStrMdy(int m_hdl);

	FYL_API int WINAPI C64_GetProdStr(int m_hdl, int m0s1, int* LenOfStr, unsigned char* ucp_Str);

	FYL_API int WINAPI C64_SetProdStr(int m_hdl, int m0s1, int LenOfStr, unsigned char* ucp_Str);
	//DLL内部参数恢复默认值
	FYL_API int WINAPI C64_InitParam(int m_hdl);

	FYL_API int WINAPI C64_SetParam(int m_hdl, int ParamType, int Param1, int Param2);
	

	FYL_API int WINAPI C64_KeyPress(int m_hdl, int HidKeyCode, int Nbr);
	//按下某个按键不弹起        //HidKeyCode: 键盘码
	FYL_API int WINAPI C64_KeyDown(int m_hdl, int HidKeyCode);
	//弹起某个按键              //HidKeyCode: 键盘码
	FYL_API int WINAPI C64_KeyUp(int m_hdl, int HidKeyCode);
	//读取按键状态              //HidKeyCode: 键盘码 //返回 0: 弹起状态；1:按下状态；-1: 失败(端口未打开)
	//使用该接口，不允许手工操作键盘，否则该接口返回值有可能不正确
	FYL_API int WINAPI C64_KeyState(int m_hdl, int HidKeyCode);

	FYL_API int WINAPI C64_KeyPress2(int m_hdl, int KeyCode, int Nbr);
	//按下某个按键不弹起        //KeyCode: 键盘码
	FYL_API int WINAPI C64_KeyDown2(int m_hdl, int KeyCode);
	//弹起某个按键              //KeyCode: 键盘码
	FYL_API int WINAPI C64_KeyUp2(int m_hdl, int KeyCode);

	FYL_API int WINAPI C64_KeyState2(int m_hdl, int KeyCode);
	///////////以上接口采用的KeyCode是windows的KeyCode，新开发程序建议再使用
	//弹起所有按键
	FYL_API int WINAPI C64_ReleaseAllKey(int m_hdl);
	//读取小键盘NumLock灯的状态 //返回 0:灭；1:亮；-1: 失败
	FYL_API int WINAPI C64_NumLockLedState(int m_hdl);
	//读取CapsLock灯的状态 //返回 0:灭；1:亮；-1: 失败
	FYL_API int WINAPI C64_CapsLockLedState(int m_hdl);
	//读取ScrollLock灯的状态 //返回 0:灭；1:亮；-1: 失败
	FYL_API int WINAPI C64_ScrollLockLedState(int m_hdl);
	//输入一串ASCII字符串，如"ABCdef012,.<>"，在InputLen个字节内将忽略非ASCII字符，  //InputStr: 输入缓冲区首地址; 注意：不支持解析\n\r等转义字符！ InputLen:输出的长度
	FYL_API int WINAPI C64_KeyInputString(int m_hdl, char* InputStr, int InputLen);
	//输入一串字符串，支持中文(GBK编码)英文混合，如"啊啊啊ABCdef012,.<>"，在InputLen个字节内将忽略非ASCII和中文字符，  //InputStr: 输入缓冲区首地址; 注意：不支持解析\n\r等转义字符！ InputLen:输出的长度
	FYL_API int WINAPI C64_KeyInputStringGBK(int m_hdl, char* InputStr, int InputLen);
	//输入一串字符串，支持中文(Unicode编码)英文混合，如"啊啊啊ABCdef012,.<>"，在InputLen个字节内将忽略非ASCII和中文字符，  //InputStr: 输入缓冲区首地址; 注意：不支持解析\n\r等转义字符！ InputLen:输出的长度
	FYL_API int WINAPI C64_KeyInputStringUnicode(int m_hdl, char* InputStr, int InputLen);

	FYL_API int WINAPI C64_LeftClick(int m_hdl, int Nbr);
	//左键双击   //Nbr: 左键在当前位置双击次数
	FYL_API int WINAPI C64_LeftDoubleClick(int m_hdl, int Nbr);
	//按下左键不弹起
	FYL_API int WINAPI C64_LeftDown(int m_hdl);
	//弹起左键
	FYL_API int WINAPI C64_LeftUp(int m_hdl);
	//右键单击   //Nbr: 左键在当前位置单击次数
	FYL_API int WINAPI C64_RightClick(int m_hdl, int Nbr);
	//按下右键不弹起
	FYL_API int WINAPI C64_RightDown(int m_hdl);
	//弹起右键
	FYL_API int WINAPI C64_RightUp(int m_hdl);
	//中键单击   //Nbr: 左键在当前位置单击次数
	FYL_API int WINAPI C64_MiddleClick(int m_hdl, int Nbr);
	//按下中键不弹起
	FYL_API int WINAPI C64_MiddleDown(int m_hdl);
	//弹起中键
	int WINAPI C64_MiddleUp(int m_hdl);
	//弹起鼠标的所有按键
	FYL_API int WINAPI C64_ReleaseAllMouse(int m_hdl);


	FYL_API int WINAPI C64_MouseKeyState(int m_hdl, int MouseKeyCode);
	//滚动鼠标滚轮;  Nbr: 滚动量,  为正,向上滚动；为负, 向下滚动;
	FYL_API int WINAPI C64_MouseWheel(int m_hdl, int Nbr);
	//将鼠标移动到原点(0,0)  在出现移动出现异常时，可以用该函数将鼠标复位
	FYL_API int WINAPI C64_ResetMousePos(int m_hdl);
	//从当前位置移动鼠标    x: x方向（横轴）的距离（正:向右; 负值:向左）; y: y方向（纵轴）的距离（正:向下; 负值:向上）
	FYL_API int WINAPI C64_MoveR(int m_hdl, int x, int y);
	//移动鼠标到指定坐标    x: x方向（横轴）的坐标; y: y方向（纵轴）的坐标。坐标原点(0, 0)在屏幕左上角
	//注意：如果出现过将鼠标移动的距离超过屏幕大小，再次MoveTo可能会出现无法正确移动到指定坐标的问题，如果出现该问题，需调用ResetMousePos复位
	FYL_API int WINAPI C64_MoveTo(int m_hdl, int x, int y);

	FYL_API int WINAPI C64_GetCurrMousePos(int m_hdl, int* x, int* y);
	//返回当前鼠标坐标X值
	FYL_API int WINAPI C64_GetCurrMousePosX(int m_hdl); //由于某些语言不支持指针，增加此接口
	//返回当前鼠标坐标Y值
	FYL_API int WINAPI C64_GetCurrMousePosY(int m_hdl); //由于某些语言不支持指针，增加此接口

	FYL_API int WINAPI C64_MoveR2(int m_hdl, int x, int y);
	//移动鼠标到指定坐标    x: x方向（横轴）的坐标; y: y方向（纵轴）的坐标。坐标原点(0, 0)在屏幕左上角
	FYL_API int WINAPI C64_MoveTo2(int m_hdl, int x, int y);
	//读取当前鼠标所在坐标  返回坐标在x、y中。
	FYL_API int WINAPI C64_GetCurrMousePos2(int* x, int* y);

	FYL_API int WINAPI C64_ResolutionUsed(int m_hdl, int x, int y);

	FYL_API int WINAPI C64_MoveTo3(int m_hdl, int x, int y);

	FYL_API int WINAPI C64_MoveTo3_D(int m_hdl, int x, int y);

	FYL_API int WINAPI C64_Delay(int time);
	//在指定的最小最大值之间延时随机时间  Min_time:最小延时时间; Max_time: 最大延时时间 （单位：ms）
	FYL_API int WINAPI C64_DelayRandom(int Min_time, int Max_time);
	//在最小最大值之间取随机数
	FYL_API int WINAPI C64_RandDomNbr(int Min_V, int Max_V);
}
