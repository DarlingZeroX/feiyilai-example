#include "example.h"
#include "feiyilaiDLL/msexport.h"
#include "imgui/imgui.h"
#include "imgui/imgui_stdlib.h"

FYLExample::FYLExample()
{
	m_FYLDevice = C64_Open(1);

	m_ThreadPool = std::make_unique<ThreadPool>(4);
}

FYLExample::~FYLExample()
{
	//C64_Close(m_FYLDevice);
}

void FYLExample::ShowExampleWindow()
{
    bool show_demo_window = true;
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
    //if (show_demo_window)
    //     ImGui::ShowDemoWindow(&show_demo_window);

    // 飞易来示例【详细说明请看feiyilaiDLL的msexport.h，更加具体的接口请看msdk.h】
    {
		ImGui::Begin("飞易来示例", nullptr, ImGuiWindowFlags_AlwaysAutoResize);                          // 创建ImGui窗口并设置标题

        // 鼠标移动岛相对位置
        ImGui::Text("鼠标移动到相对位置");
        ImGui::InputFloat2("##鼠标移动到相对位置", m_RelativeMousePos);
        ImGui::SameLine();
        if (ImGui::Button("移动##鼠标移动到相对位置"))
        {
            C64_MoveR2(m_FYLDevice, m_RelativeMousePos[0], m_RelativeMousePos[1]);
        }

        // 鼠标移动到绝对位置
        ImGui::Text("鼠标移动到绝对位置");
        ImGui::InputFloat2("##鼠标移动到绝对位置", m_AbsoluteMousePos);
        ImGui::SameLine();
        if (ImGui::Button("移动##鼠标移动相对位置"))
        {
            C64_MoveTo2(m_FYLDevice, m_AbsoluteMousePos[0], m_AbsoluteMousePos[1]);
        }

		// 获取当前鼠标位置
        ImGui::Text("获取鼠标当前位置");
        ImGui::InputInt2("##获取鼠标当前位置", m_CurrentMousePos,ImGuiInputTextFlags_ReadOnly);
        ImGui::SameLine();
        if (ImGui::Button("获取##获取鼠标当前位置"))
        {
        	C64_GetCurrMousePos2(&m_CurrentMousePos[0], &m_CurrentMousePos[1]);
        }

        // 鼠标左键循环点击
        ImGui::Text("鼠标左键点击");
        ImGui::InputInt("点击次数", &LeftClickNbr);
        ImGui::SameLine();
        if (ImGui::Button("点击##鼠标左键点击"))
        {
			// 用线程池执行，避免阻塞UI线程
            m_ThreadPool->enqueue([this]()
                {
                    C64_LeftClick(m_FYLDevice, LeftClickNbr);
                });
        }

		// 键盘循环按下某个按键
        ImGui::Text("键盘循环按下按键");
        ImGui::InputInt("按下次数", &m_PressNbr);
        ImGui::InputText("按键", &m_PressKeyCode);
        ImGui::SameLine();
        if (ImGui::Button("按下##键盘循环按下按键"))
        {
            // 用线程池执行，避免阻塞UI线程
            m_ThreadPool->enqueue([this]()
                {
                    C64_KeyPress2(m_FYLDevice, m_VKCode.GetVKCode(m_PressKeyCode), m_PressNbr);
                });
        }

        // 键盘指示灯情况【存在卡死Bug】
        //int NumLockLed = C64_NumLockLedState(m_FYLDevice);
		//ImGui::Text("NumLockLed键盘指示灯状态: %d", NumLockLed);
        //
        //int CapsLockLed = C64_CapsLockLedState(m_FYLDevice);
        //ImGui::Text("CapsLockLed键盘指示灯状态: %d", CapsLockLed);
        //
        //int ScrollLockLed = C64_ScrollLockLedState(m_FYLDevice);
        //ImGui::Text("ScrollLockLed键盘指示灯状态: %d", ScrollLockLed);

        ImGui::End();
    }
}

