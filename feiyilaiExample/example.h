#pragma once
#include <memory>
#include "header/ThreadPool.h"
#include "header/VKCode.h"

class FYLExample
{
public:
	FYLExample();
	~FYLExample();

	void ShowExampleWindow();

private:
	int m_FYLDevice = 0; // 飞易来设备句柄
	std::unique_ptr<ThreadPool> m_ThreadPool;	// 线程池

	float m_RelativeMousePos[2] = { 100.0f, 100.0f };	// 鼠标移动相对位置
	float m_AbsoluteMousePos[2] = { 100.0f, 100.0f };	// 鼠标移动绝对位置
	int m_CurrentMousePos[2] = { 0, 0 };	// 当前鼠标位置

	std::string m_PressKeyCode = "d";	// 按键代码
	int m_PressNbr = 10;	// 按键次数

	int LeftClickNbr = 5; // 鼠标左键点击次数

	VKCode m_VKCode; // 虚拟键码
};
