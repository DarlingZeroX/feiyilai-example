#include "framework.h"
#include "msexport.h"

static msclass* gMSClass = new msclass();

void __stdcall C64_PrintHandle(int m_hdl)
{
	return gMSClass->PrintHandle(m_hdl);
}

int __stdcall C64_Open(int Nbr)
{
	return gMSClass->Open(Nbr);
}

int __stdcall C64_Open_VidPid(int Vid, int Pid)
{
	return gMSClass->Open_VidPid(Vid,Pid);
}

int __stdcall C64_Close(int m_hdl)
{
	return gMSClass->Close(m_hdl);
}

int __stdcall C64_GetDevSn(int m_hdl, DWORD* dwp_LenResponse, unsigned char* ucp_Response)
{
	return gMSClass->GetDevSn(m_hdl, dwp_LenResponse, ucp_Response);
}

int __stdcall C64_SetUserData(int m_hdl, DWORD dw_LenUserData, unsigned char* ucp_UserData)
{
	return gMSClass->SetUserData(m_hdl, dw_LenUserData, ucp_UserData);
}

int __stdcall C64_VerifyUserData(int m_hdl, DWORD dw_LenUserData, unsigned char* ucp_UserData)
{
	return gMSClass->VerifyUserData(m_hdl, dw_LenUserData, ucp_UserData);
}

int __stdcall C64_ChkSupportMdy(int m_hdl)
{
	return gMSClass->ChkSupportMdy(m_hdl);
}

int __stdcall C64_GetAbsCfg(int m_hdl)
{
	return gMSClass->GetAbsCfg(m_hdl);
}

int __stdcall C64_SetAbsCfg(int m_hdl, int e1d0)
{
	return gMSClass->SetAbsCfg(m_hdl, e1d0);
}

int __stdcall C64_SetNewVidPid(int m_hdl, int mVid, int mPid, int sVid, int sPid)
{
	return gMSClass->SetNewVidPid(m_hdl, mVid, mPid, sVid, sPid);
}

int __stdcall C64_ResetVidPid(int m_hdl)
{
	return gMSClass->ResetVidPid(m_hdl);
}

int __stdcall C64_GetVidPid(int m_hdl, int IdIndex)
{
	return gMSClass->GetVidPid(m_hdl, IdIndex);
}

int __stdcall C64_ChkSupportProdStrMdy(int m_hdl)
{
	return gMSClass->ChkSupportProdStrMdy(m_hdl);
}

int __stdcall C64_GetProdStr(int m_hdl, int m0s1, int* LenOfStr, unsigned char* ucp_Str)
{
	return gMSClass->GetProdStr(m_hdl, m0s1, LenOfStr, ucp_Str);
}

int __stdcall C64_SetProdStr(int m_hdl, int m0s1, int LenOfStr, unsigned char* ucp_Str)
{
	return gMSClass->SetProdStr(m_hdl, m0s1, LenOfStr, ucp_Str);
}

int __stdcall C64_InitParam(int m_hdl)
{
	return gMSClass->InitParam(m_hdl);
}

int __stdcall C64_SetParam(int m_hdl, int ParamType, int Param1, int Param2)
{
	return gMSClass->SetParam(m_hdl, ParamType, Param1, Param2);
}

int __stdcall C64_KeyPress(int m_hdl, int HidKeyCode, int Nbr)
{
	return gMSClass->KeyPress(m_hdl, HidKeyCode ,Nbr);
}

int __stdcall C64_KeyDown(int m_hdl, int HidKeyCode)
{
	return gMSClass->KeyDown(m_hdl, HidKeyCode);
}

int __stdcall C64_KeyUp(int m_hdl, int HidKeyCode)
{
	return gMSClass->KeyUp(m_hdl, HidKeyCode);
}

int __stdcall C64_KeyState(int m_hdl, int HidKeyCode)
{
	return gMSClass->KeyState(m_hdl, HidKeyCode);
}

int __stdcall C64_KeyPress2(int m_hdl, int KeyCode, int Nbr)
{
	return gMSClass->KeyPress2(m_hdl, KeyCode, Nbr);
}

int __stdcall C64_KeyDown2(int m_hdl, int KeyCode)
{
	return gMSClass->KeyDown2(m_hdl, KeyCode);
}

int __stdcall C64_KeyUp2(int m_hdl, int KeyCode)
{
	return gMSClass->KeyUp2(m_hdl, KeyCode);
}

int __stdcall C64_KeyState2(int m_hdl, int KeyCode)
{
	return gMSClass->KeyState2(m_hdl, KeyCode);
}

int __stdcall C64_ReleaseAllKey(int m_hdl)
{
	return gMSClass->ReleaseAllKey(m_hdl);
}

int __stdcall C64_NumLockLedState(int m_hdl)
{
	return gMSClass->NumLockLedState(m_hdl);
}

int __stdcall C64_CapsLockLedState(int m_hdl)
{
	return gMSClass->CapsLockLedState(m_hdl);
}

int __stdcall C64_ScrollLockLedState(int m_hdl)
{
	return gMSClass->ScrollLockLedState(m_hdl);
}

int __stdcall C64_KeyInputString(int m_hdl, char* InputStr, int InputLen)
{
	return gMSClass->KeyInputString(m_hdl, InputStr, InputLen);
}

int __stdcall C64_KeyInputStringGBK(int m_hdl, char* InputStr, int InputLen)
{
	return gMSClass->KeyInputStringGBK(m_hdl, InputStr, InputLen);
}

int __stdcall C64_KeyInputStringUnicode(int m_hdl, char* InputStr, int InputLen)
{
	return gMSClass->KeyInputStringUnicode(m_hdl, InputStr, InputLen);
}

int __stdcall C64_LeftClick(int m_hdl, int Nbr)
{
	return gMSClass->LeftClick(m_hdl,Nbr);
}

int __stdcall C64_LeftDoubleClick(int m_hdl, int Nbr)
{
	return gMSClass->LeftDoubleClick(m_hdl, Nbr);
}

int __stdcall C64_LeftDown(int m_hdl)
{
	return gMSClass->LeftDown(m_hdl);
}

int __stdcall C64_LeftUp(int m_hdl)
{
	return gMSClass->LeftUp(m_hdl);
}

int __stdcall C64_RightClick(int m_hdl, int Nbr)
{
	return gMSClass->RightClick(m_hdl, Nbr);
}

int __stdcall C64_RightDown(int m_hdl)
{
	return gMSClass->RightDown(m_hdl);
}

int __stdcall C64_RightUp(int m_hdl)
{
	return gMSClass->RightUp(m_hdl);
}

int __stdcall C64_MiddleClick(int m_hdl, int Nbr)
{
	return gMSClass->MiddleClick(m_hdl, Nbr);
}

int __stdcall C64_MiddleDown(int m_hdl)
{
	return gMSClass->MiddleDown(m_hdl);
}

int __stdcall C64_MiddleUp(int m_hdl)
{
	return gMSClass->MiddleUp(m_hdl);
}

int __stdcall C64_ReleaseAllMouse(int m_hdl)
{
	return gMSClass->ReleaseAllMouse(m_hdl);
}

int __stdcall C64_MouseKeyState(int m_hdl, int MouseKeyCode)
{
	return gMSClass->MouseKeyState(m_hdl, MouseKeyCode);
}

int __stdcall C64_MouseWheel(int m_hdl, int Nbr)
{
	return gMSClass->MouseWheel(m_hdl, Nbr);
}

int __stdcall C64_ResetMousePos(int m_hdl)
{
	return gMSClass->ResetMousePos(m_hdl);
}

int __stdcall C64_MoveR(int m_hdl, int x, int y)
{
	return gMSClass->MoveR(m_hdl, x, y);
}

int __stdcall C64_MoveTo(int m_hdl, int x, int y)
{
	return gMSClass->MoveTo(m_hdl, x, y);
}

int __stdcall C64_GetCurrMousePos(int m_hdl, int* x, int* y)
{
	return gMSClass->GetCurrMousePos(m_hdl, x, y);
}

int __stdcall C64_GetCurrMousePosX(int m_hdl)
{
	return gMSClass->GetCurrMousePosX(m_hdl);
}

int __stdcall C64_GetCurrMousePosY(int m_hdl)
{
	return gMSClass->GetCurrMousePosY(m_hdl);
}

int __stdcall C64_MoveR2(int m_hdl, int x, int y)
{
	return gMSClass->MoveR2(m_hdl, x ,y);
}

int __stdcall C64_MoveTo2(int m_hdl, int x, int y)
{
	return gMSClass->MoveTo2(m_hdl, x, y);
}

int __stdcall C64_GetCurrMousePos2(int* x, int* y)
{
	return gMSClass->GetCurrMousePos2( x, y);
}

int __stdcall C64_ResolutionUsed(int m_hdl, int x, int y)
{
	return gMSClass->ResolutionUsed(m_hdl, x, y);
}

int __stdcall C64_MoveTo3(int m_hdl, int x, int y)
{
	return gMSClass->MoveTo3(m_hdl, x, y);
}

int __stdcall C64_MoveTo3_D(int m_hdl, int x, int y)
{
	return gMSClass->MoveTo3_D(m_hdl, x, y);
}

int __stdcall C64_Delay(int time)
{
	return gMSClass->Delay(time);
}

int __stdcall C64_DelayRandom(int Min_time, int Max_time)
{
	return gMSClass->DelayRandom(Min_time, Max_time);
}

int __stdcall C64_RandDomNbr(int Min_V, int Max_V)
{
	return gMSClass->RandDomNbr(Min_V, Max_V);
}
