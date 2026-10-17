#pragma once
#ifndef HAN_STRING_H
#define HAN_STRING_H

// ============================================
// Han++ - 字符串
// 文件: han_string.h
// 说明: 字符串操作
// 编码: UTF-8
// 适用编译器：MSVC GCC Clang
// ============================================

#include "han_grammar.h"
#include <string>
#include <algorithm>
#include <sstream>

namespace han {
    namespace 字符串操作 {

        inline 整数 字符串_长度(const 字符串& s) {
            return static_cast<整数>(s.size());
        }
        inline 布尔 字符串_为空(const 字符串& s) {
            return s.empty();
        }
        inline 字符串 字符串_转大写(字符串 s) {
            std::transform(s.begin(), s.end(), s.begin(),
                [](unsigned char c) { return static_cast<char>(std::toupper(c)); });
            return s;
        }
        inline 字符串 字符串_转小写(字符串 s) {
            std::transform(s.begin(), s.end(), s.begin(),
                [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
            return s;
        }
        inline 字符串 字符串_子串(const 字符串& s, 整数 起始, 整数 长度) {
            return s.substr(起始, 长度);
        }
        inline 字符串 字符串_替换(字符串 s, const 字符串& 旧, const 字符串& 新) {
            整数 位置 = 0;
            while ((位置 = static_cast<整数>(s.find(旧, 位置))) != (整数)字符串::npos) {
                s.replace(位置, 旧.size(), 新);
                位置 += static_cast<整数>(新.size());
            }
            return s;
        }
        inline 布尔 字符串_包含(const 字符串& s, const 字符串& 子) {
            return s.find(子) != 字符串::npos;
        }
        inline 字符串 字符串_反转(字符串 s) {
            std::reverse(s.begin(), s.end());
            return s;
        }
        inline 字符串 字符串_去空格(const 字符串& s) {
            整数 起始 = 0, 结束 = static_cast<整数>(s.size());
            while (起始 < 结束 && std::isspace(static_cast<unsigned char>(s[起始]))) 起始++;
            while (结束 > 起始 && std::isspace(static_cast<unsigned char>(s[结束 - 1]))) 结束--;
            return s.substr(起始, 结束 - 起始);
        }
        inline 字符串 字符串_拼接(const 字符串& a, const 字符串& b) {
            return a + b;
        }
        inline 整数 字符串_转整数(const 字符串& s) { return std::stoi(s); }
        inline 长整数 字符串_转长整数(const 字符串& s) { return std::stoll(s); }
        inline 浮点 字符串_转浮点(const 字符串& s) { return std::stod(s); }
        template <typename T>
        inline 字符串 值_转字符串(const T& 值) {
            std::ostringstream oss;
            oss << 值;
            return oss.str();
        }
    } // namespace 字符串操作
    using 字符串操作::字符串_长度;
    using 字符串操作::字符串_为空;
    using 字符串操作::字符串_转大写;
    using 字符串操作::字符串_转小写;
    using 字符串操作::字符串_子串;
    using 字符串操作::字符串_替换;
    using 字符串操作::字符串_包含;
    using 字符串操作::字符串_反转;
    using 字符串操作::字符串_去空格;
    using 字符串操作::字符串_拼接;
    using 字符串操作::字符串_转整数;
    using 字符串操作::字符串_转长整数;
    using 字符串操作::字符串_转浮点;
    using 字符串操作::值_转字符串;
} // namespace han

#endif // HAN_STRING_H