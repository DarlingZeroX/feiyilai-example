#pragma once
#include "msdk.h"
#include <unordered_map>

class msclass
{
public:
	void WINAPI PrintHandle(int m_hdl);

	int WINAPI Open(int Nbr);

	int WINAPI Open_VidPid(int Vid, int Pid);

	int WINAPI Close(int m_hdl);

	int WINAPI GetDevSn(int m_hdl, DWORD* dwp_LenResponse, unsigned char* ucp_Response);

	int WINAPI SetUserData(int m_hdl, DWORD dw_LenUserData, unsigned char* ucp_UserData);
	//验证用户数据 //参数定义同上
	int WINAPI VerifyUserData(int m_hdl, DWORD dw_LenUserData, unsigned char* ucp_UserData);
	//检查盒子是否是可修改盒子; 返回: 0:是可修改； 其他:不可修改
	int WINAPI ChkSupportMdy(int m_hdl);
	//读取当前绝对移动功能的状态 返回: 1:打开; 0:关闭; 其他: 错误
	int WINAPI GetAbsCfg(int m_hdl);
	//设置绝对移动功能: e1d0=1 打开; =0;关闭
	int WINAPI SetAbsCfg(int m_hdl, int e1d0);

	int WINAPI SetNewVidPid(int m_hdl, int mVid, int mPid, int sVid, int sPid);
	int WINAPI ResetVidPid(int m_hdl);
	//读取VID/PID; IdIndex=1/2/3/4 分别对应 主控端Vid, 主控端Pid, 被控端Vid, 被控端Pid
	int WINAPI GetVidPid(int m_hdl, int IdIndex);
	//是否支持修改产品名称, 返回值1=支持，0=不支持；-1，失败
	int WINAPI ChkSupportProdStrMdy(int m_hdl);

	int WINAPI GetProdStr(int m_hdl, int m0s1, int* LenOfStr, unsigned char* ucp_Str);

	int WINAPI SetProdStr(int m_hdl, int m0s1, int LenOfStr, unsigned char* ucp_Str);
	//DLL内部参数恢复默认值
	int WINAPI InitParam(int m_hdl);

	int WINAPI SetParam(int m_hdl, int ParamType, int Param1, int Param2);

	int WINAPI KeyPress(int m_hdl, int HidKeyCode, int Nbr);
	//按下某个按键不弹起        //HidKeyCode: 键盘码
	int WINAPI KeyDown(int m_hdl, int HidKeyCode);
	//弹起某个按键              //HidKeyCode: 键盘码
	int WINAPI KeyUp(int m_hdl, int HidKeyCode);
	//读取按键状态              //HidKeyCode: 键盘码 //返回 0: 弹起状态；1:按下状态；-1: 失败(端口未打开)
	//使用该接口，不允许手工操作键盘，否则该接口返回值有可能不正确
	int WINAPI KeyState(int m_hdl, int HidKeyCode);

	int WINAPI KeyPress2(int m_hdl, int KeyCode, int Nbr);
	//按下某个按键不弹起        //KeyCode: 键盘码
	int WINAPI KeyDown2(int m_hdl, int KeyCode);
	//弹起某个按键              //KeyCode: 键盘码
	int WINAPI KeyUp2(int m_hdl, int KeyCode);
	//读取按键状态              //KeyCode: 键盘码 //返回 0: 弹起状态；1:按下状态；-1: 失败(端口未打开)
	//使用该接口，不允许手工操作键盘，否则该接口返回值有可能不正确
	int WINAPI KeyState2(int m_hdl, int KeyCode);
	///////////以上接口采用的KeyCode是windows的KeyCode，新开发程序建议再使用
	//弹起所有按键
	int WINAPI ReleaseAllKey(int m_hdl);
	//读取小键盘NumLock灯的状态 //返回 0:灭；1:亮；-1: 失败
	int WINAPI NumLockLedState(int m_hdl);
	//读取CapsLock灯的状态 //返回 0:灭；1:亮；-1: 失败
	int WINAPI CapsLockLedState(int m_hdl);
	//读取ScrollLock灯的状态 //返回 0:灭；1:亮；-1: 失败
	int WINAPI ScrollLockLedState(int m_hdl);
	//输入一串ASCII字符串，如"ABCdef012,.<>"，在InputLen个字节内将忽略非ASCII字符，  //InputStr: 输入缓冲区首地址; 注意：不支持解析\n\r等转义字符！ InputLen:输出的长度
	int WINAPI KeyInputString(int m_hdl, char* InputStr, int InputLen);
	//输入一串字符串，支持中文(GBK编码)英文混合，如"啊啊啊ABCdef012,.<>"，在InputLen个字节内将忽略非ASCII和中文字符，  //InputStr: 输入缓冲区首地址; 注意：不支持解析\n\r等转义字符！ InputLen:输出的长度
	int WINAPI KeyInputStringGBK(int m_hdl, char* InputStr, int InputLen);
	//输入一串字符串，支持中文(Unicode编码)英文混合，如"啊啊啊ABCdef012,.<>"，在InputLen个字节内将忽略非ASCII和中文字符，  //InputStr: 输入缓冲区首地址; 注意：不支持解析\n\r等转义字符！ InputLen:输出的长度
	int WINAPI KeyInputStringUnicode(int m_hdl, char* InputStr, int InputLen);
	/***********鼠标操作函数;以下函数中的m_hdl是指M_Open返回的句柄*******/
	/***********以下所有命令返回 0: 成功；-1: 失败*******/
	//左键单击   //Nbr: 左键在当前位置单击次数 
	int WINAPI LeftClick(int m_hdl, int Nbr);
	//左键双击   //Nbr: 左键在当前位置双击次数
	int WINAPI LeftDoubleClick(int m_hdl, int Nbr);
	//按下左键不弹起
	int WINAPI LeftDown(int m_hdl);
	//弹起左键
	int WINAPI LeftUp(int m_hdl);
	//右键单击   //Nbr: 左键在当前位置单击次数
	int WINAPI RightClick(int m_hdl, int Nbr);
	//按下右键不弹起
	int WINAPI RightDown(int m_hdl);
	//弹起右键
	int WINAPI RightUp(int m_hdl);
	//中键单击   //Nbr: 左键在当前位置单击次数
	int WINAPI MiddleClick(int m_hdl, int Nbr);
	//按下中键不弹起
	int WINAPI MiddleDown(int m_hdl);
	//弹起中键
	int WINAPI MiddleUp(int m_hdl);
	//弹起鼠标的所有按键
	int WINAPI ReleaseAllMouse(int m_hdl);
	//读取鼠标左中右键状态   //MouseKeyCode: 1=左键 2=右键 3=中键  //返回 0: 弹起状态；1:按下状态；-1: 失败
	//只能读取盒子中鼠标的状态，读取不到实体鼠标的状态
	int WINAPI MouseKeyState(int m_hdl, int MouseKeyCode);
	//滚动鼠标滚轮;  Nbr: 滚动量,  为正,向上滚动；为负, 向下滚动;
	int WINAPI MouseWheel(int m_hdl, int Nbr);
	//将鼠标移动到原点(0,0)  在出现移动出现异常时，可以用该函数将鼠标复位
	int WINAPI ResetMousePos(int m_hdl);
	//从当前位置移动鼠标    x: x方向（横轴）的距离（正:向右; 负值:向左）; y: y方向（纵轴）的距离（正:向下; 负值:向上）
	int WINAPI MoveR(int m_hdl, int x, int y);
	//移动鼠标到指定坐标    x: x方向（横轴）的坐标; y: y方向（纵轴）的坐标。坐标原点(0, 0)在屏幕左上角
	//注意：如果出现过将鼠标移动的距离超过屏幕大小，再次MoveTo可能会出现无法正确移动到指定坐标的问题，如果出现该问题，需调用ResetMousePos复位
	int WINAPI MoveTo(int m_hdl, int x, int y);

	int WINAPI GetCurrMousePos(int m_hdl, int* x, int* y);
	//返回当前鼠标坐标X值
	int WINAPI GetCurrMousePosX(int m_hdl); //由于某些语言不支持指针，增加此接口
	//返回当前鼠标坐标Y值
	int WINAPI GetCurrMousePosY(int m_hdl); //由于某些语言不支持指针，增加此接口


	int WINAPI MoveR2(int m_hdl, int x, int y);
	//移动鼠标到指定坐标    x: x方向（横轴）的坐标; y: y方向（纵轴）的坐标。坐标原点(0, 0)在屏幕左上角
	int WINAPI MoveTo2(int m_hdl, int x, int y);
	//读取当前鼠标所在坐标  返回坐标在x、y中。
	int WINAPI GetCurrMousePos2(int* x, int* y);

	int WINAPI ResolutionUsed(int m_hdl, int x, int y);

	int WINAPI MoveTo3(int m_hdl, int x, int y);

	int WINAPI MoveTo3_D(int m_hdl, int x, int y);
	/*******************通用操作函数****************************/
	//延时指定时间  time:单位ms
	int WINAPI Delay(int time);
	//在指定的最小最大值之间延时随机时间  Min_time:最小延时时间; Max_time: 最大延时时间 （单位：ms）
	int WINAPI DelayRandom(int Min_time, int Max_time);
	//在最小最大值之间取随机数
	int WINAPI RandDomNbr(int Min_V, int Max_V);
private:
	std::unordered_map<int, HANDLE> mHandleMap;

	int mHandleIndex = 0;
};