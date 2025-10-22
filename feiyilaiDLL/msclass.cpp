#include "framework.h"
#include "msclass.h"
#include "msdk.h"
#include<iostream>

void __stdcall msclass::PrintHandle(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	std::cout << handle << std::endl;
}

int __stdcall msclass::Open(int Nbr)
{
	HANDLE handle = M_Open(Nbr);

	mHandleIndex += 1;

	mHandleMap[mHandleIndex] = handle;

	return mHandleIndex;
}

int __stdcall msclass::Open_VidPid(int Vid, int Pid)
{
	HANDLE handle = M_Open_VidPid(Vid, Pid);

	mHandleIndex += 1;

	mHandleMap[mHandleIndex] = handle;

	return mHandleIndex;
}

int __stdcall msclass::Close(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_Close(handle);
}

int __stdcall msclass::GetDevSn(int m_hdl, DWORD* dwp_LenResponse, unsigned char* ucp_Response)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_GetDevSn(handle, dwp_LenResponse, ucp_Response);
}

int __stdcall msclass::SetUserData(int m_hdl, DWORD dw_LenUserData, unsigned char* ucp_UserData)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_SetUserData(handle, dw_LenUserData, ucp_UserData);
}

int __stdcall msclass::VerifyUserData(int m_hdl, DWORD dw_LenUserData, unsigned char* ucp_UserData)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_VerifyUserData(handle, dw_LenUserData, ucp_UserData);
}

int __stdcall msclass::ChkSupportMdy(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_ChkSupportMdy(handle);
}

int __stdcall msclass::GetAbsCfg(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_GetAbsCfg(handle);
}

int __stdcall msclass::SetAbsCfg(int m_hdl, int e1d0)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_SetAbsCfg(handle, e1d0);
}

int __stdcall msclass::SetNewVidPid(int m_hdl, int mVid, int mPid, int sVid, int sPid)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_SetNewVidPid(handle, mVid, mPid, sVid, sPid);
}

int __stdcall msclass::ResetVidPid(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_ResetVidPid(handle);
}

int __stdcall msclass::GetVidPid(int m_hdl, int IdIndex)
{
	HANDLE handle = mHandleMap[m_hdl];

	return 0;
	//return M_GetVidPid(handle, IdIndex);
}

int __stdcall msclass::ChkSupportProdStrMdy(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_ChkSupportProdStrMdy(handle);
}

int __stdcall msclass::GetProdStr(int m_hdl, int m0s1, int* LenOfStr, unsigned char* ucp_Str)
{
	HANDLE handle = mHandleMap[m_hdl];

	return 0;
	//return M_GetProdStr(handle, m0s1, LenOfStr, ucp_Str);
}

int __stdcall msclass::SetProdStr(int m_hdl, int m0s1, int LenOfStr, unsigned char* ucp_Str)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_SetProdStr(handle, m0s1, LenOfStr, ucp_Str);
}

int __stdcall msclass::InitParam(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_InitParam(handle);
}

int __stdcall msclass::SetParam(int m_hdl, int ParamType, int Param1, int Param2)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_SetParam(handle, ParamType, Param1, Param2);
}

int __stdcall msclass::KeyPress(int m_hdl, int HidKeyCode, int Nbr)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_KeyPress(handle, HidKeyCode, Nbr);
}

int __stdcall msclass::KeyDown(int m_hdl, int HidKeyCode)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_KeyDown(handle, HidKeyCode);
}

int __stdcall msclass::KeyUp(int m_hdl, int HidKeyCode)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_KeyUp(handle, HidKeyCode);
}

int __stdcall msclass::KeyState(int m_hdl, int HidKeyCode)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_KeyState(handle, HidKeyCode);
}

int __stdcall msclass::KeyPress2(int m_hdl, int KeyCode, int Nbr)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_KeyPress2(handle, KeyCode, Nbr);
}

int __stdcall msclass::KeyDown2(int m_hdl, int KeyCode)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_KeyDown2(handle, KeyCode);
}

int __stdcall msclass::KeyUp2(int m_hdl, int KeyCode)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_KeyUp2(handle, KeyCode);
}

int __stdcall msclass::KeyState2(int m_hdl, int KeyCode)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_KeyState2(handle, KeyCode);
}

int __stdcall msclass::ReleaseAllKey(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_ReleaseAllKey(handle);
}

int __stdcall msclass::NumLockLedState(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_NumLockLedState(handle);
}

int __stdcall msclass::CapsLockLedState(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_CapsLockLedState(handle);
}

int __stdcall msclass::ScrollLockLedState(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_ScrollLockLedState(handle);
}

int __stdcall msclass::KeyInputString(int m_hdl, char* InputStr, int InputLen)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_KeyInputString(handle, InputStr, InputLen);
}

int __stdcall msclass::KeyInputStringGBK(int m_hdl, char* InputStr, int InputLen)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_KeyInputStringGBK(handle, InputStr, InputLen);
}

int __stdcall msclass::KeyInputStringUnicode(int m_hdl, char* InputStr, int InputLen)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_KeyInputStringUnicode(handle, InputStr, InputLen);
}

int __stdcall msclass::LeftClick(int m_hdl, int Nbr)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_LeftClick(handle, Nbr);
}

int __stdcall msclass::LeftDoubleClick(int m_hdl, int Nbr)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_LeftDoubleClick(handle, Nbr);
}

int __stdcall msclass::LeftDown(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_LeftDown(handle);
}

int __stdcall msclass::LeftUp(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_LeftUp(handle);
}

int __stdcall msclass::RightClick(int m_hdl, int Nbr)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_RightClick(handle, Nbr);
}

int __stdcall msclass::RightDown(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_RightDown(handle);
}

int __stdcall msclass::RightUp(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_RightUp(handle);
}

int __stdcall msclass::MiddleClick(int m_hdl, int Nbr)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_MiddleClick(handle, Nbr);
}

int __stdcall msclass::MiddleDown(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_MiddleDown(handle);
}

int __stdcall msclass::MiddleUp(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_MiddleUp(handle);
}

int __stdcall msclass::ReleaseAllMouse(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_ReleaseAllMouse(handle);
}

int __stdcall msclass::MouseKeyState(int m_hdl, int MouseKeyCode)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_MouseKeyState(handle, MouseKeyCode);
}

int __stdcall msclass::MouseWheel(int m_hdl, int Nbr)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_MouseWheel(handle, Nbr);
}

int __stdcall msclass::ResetMousePos(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_ResetMousePos(handle);
}

int __stdcall msclass::MoveR(int m_hdl, int x, int y)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_MoveR(handle, x, y);
}

int __stdcall msclass::MoveTo(int m_hdl, int x, int y)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_MoveTo(handle, x, y);
}

int __stdcall msclass::GetCurrMousePos(int m_hdl, int* x, int* y)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_GetCurrMousePos(handle, x, y);
}

int __stdcall msclass::GetCurrMousePosX(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_GetCurrMousePosX(handle);
}

int __stdcall msclass::GetCurrMousePosY(int m_hdl)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_GetCurrMousePosY(handle);
}

int __stdcall msclass::MoveR2(int m_hdl, int x, int y)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_MoveR2(handle, x, y);
}

int __stdcall msclass::MoveTo2(int m_hdl, int x, int y)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_MoveTo2(handle, x, y);
}

int __stdcall msclass::GetCurrMousePos2(int* x, int* y)
{
	return M_GetCurrMousePos2(x, y);
}

int __stdcall msclass::ResolutionUsed(int m_hdl, int x, int y)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_ResolutionUsed(handle, x, y);
}

int __stdcall msclass::MoveTo3(int m_hdl, int x, int y)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_MoveTo3(handle, x, y);
}

int __stdcall msclass::MoveTo3_D(int m_hdl, int x, int y)
{
	HANDLE handle = mHandleMap[m_hdl];

	return M_MoveTo3_D(handle, x, y);
}

int __stdcall msclass::Delay(int time)
{
	return M_Delay(time);
}

int __stdcall msclass::DelayRandom(int Min_time, int Max_time)
{
	return M_DelayRandom(Min_time, Max_time);
}

int __stdcall msclass::RandDomNbr(int Min_V, int Max_V)
{
	return M_RandDomNbr(Min_V, Max_V);
}

