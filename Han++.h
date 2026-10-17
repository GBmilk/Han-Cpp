#ifndef HAN_H
#define HAN_H

// ============================================
// Han++ - 总入口
// 文件: Han++.h
// 说明: 包含所有模块，提供启动画面与控制台 UTF-8 初始化
// 编码: UTF-8
// 适用编译器：MSVC GCC Clang
// ============================================

#if defined(_WIN32)
#include <windows.h>
#endif

#include "han_grammar.h"
#include "han_cmath.h"
#include "han_string.h"

// 3. 程序入口宏
#define 主函数 main

namespace han {
    inline void 打印启动画面() {
        打印行("-------------------------------");
        打印行("Han++ Beta 1.10版本 作者：GB牛奶");
        打印行("-------------------------------");
        换行();
    }
    struct 全局初始化器 {
        全局初始化器() {
#if defined(_WIN32)
            SetConsoleOutputCP(65001);
            SetConsoleCP(65001);
#endif
            打印启动画面();
        }
    };

    inline 全局初始化器 _全局初始化;
    inline void 显示启动画面() {
        打印启动画面();
    }

} // namespace han

#endif // HAN_H