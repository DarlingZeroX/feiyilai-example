# 子目录首行：强制初始化C环境
enable_language(C)

# 设置C标准（Lua源码需ANSI C）
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MP")

# 将源代码添加到此项目的可执行文件。
file(GLOB SRC_FILES
	"${CMAKE_CURRENT_SOURCE_DIR}/msclass.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/msexport.cpp"
)

# 收集头文件（假设头文件在 Include 目录下）
file(GLOB HEADER_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/framework.h"  
	"${CMAKE_CURRENT_SOURCE_DIR}/msclass.h" 
	"${CMAKE_CURRENT_SOURCE_DIR}/msdk.h" 
	"${CMAKE_CURRENT_SOURCE_DIR}/msexport.h" 
)

# 缺失关键配置 ↓
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)  # 强制导出所有符号[1,3,4](@ref)
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")  # 确保.lib生成在lib目录

# 定义动态库编译宏（关键！）
add_definitions(-DFYL_EXPORT)

# 创建动态库并添加源文件和头文件（头文件仅用于 IDE 显示）
add_library(feiyilaiDLL SHARED
    ${SRC_FILES}
    ${HEADER_FILES}  # 重要：将头文件添加到目标中
)

target_link_libraries(feiyilaiDLL PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/msdk.lib)

target_include_directories(feiyilaiDLL PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
set_target_properties(feiyilaiDLL PROPERTIES LINKER_LANGUAGE C)


#拷贝目标依赖的所有DLL
set(DLL_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/msdk.dll"
)

foreach(dll ${DLL_FILES})
    add_custom_command(TARGET feiyilaiDLL POST_BUILD  # 这里要指定具体的目标名称
        COMMAND ${CMAKE_COMMAND} -E copy
            "${dll}"
            "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"  # 直接使用变量
        COMMENT "Copying ${dll} to output directory"
    )
endforeach()



