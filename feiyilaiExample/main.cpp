#include "header/Win32Window.h"
#include "header/GL3Graphics.h"
#include "header/ImguiManager.h"
#include "example.h"

// 主代码
int main(int, char**)
{
	// 先创建窗口、OpenGL图形
    auto window = Win32Window(L"飞易来示例");
    auto gfx = GL3Graphics(window);

	// 显示窗口并更新
    window.Show();
    window.WindowUpdate();

	// 再创建Imgui管理器和示例
	auto imguiManager = ImguiManager(window, gfx);
    auto fylExample = FYLExample();

    // 主循环
    while (window.HandleMessage())
    {
		// 开始新帧
        imguiManager.NewFrame();

		// 显示示例窗口【主要示例代码都在这里面】
        fylExample.ShowExampleWindow();

		// 渲染
        imguiManager.Render();
    }

    return 0;
}
