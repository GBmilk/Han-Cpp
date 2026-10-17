#pragma once
#ifndef HAN_CMATH_H
#define HAN_CMATH_H

// ============================================
// Han++ - 数学模块
// 文件: han_cmath.h
// 说明: 数学函数与常量
// 编码: UTF-8
// 适用编译器：MSVC GCC Clang
// ============================================

#include "han_grammar.h"
#include <cmath>

namespace han {
    constexpr 浮点 圆周率 = 3.14159265358979323846;
    constexpr 浮点 自然常数 = 2.71828182845904523536;

    namespace 数学 {
        inline 浮点 绝对值(浮点 x) { return std::fabs(x); }
        inline 整数 绝对值(整数 x) { return std::abs(x); }
        inline 长整数 绝对值(长整数 x) { return std::llabs(x); }
        inline 浮点 平方根(浮点 x) { return std::sqrt(x); }
        inline 浮点 立方根(浮点 x) { return std::cbrt(x); }
        inline 浮点 幂(浮点 x, 浮点 y) { return std::pow(x, y); }
        inline 浮点 指数(浮点 x) { return std::exp(x); }
        inline 浮点 自然对数(浮点 x) { return std::log(x); }
        inline 浮点 常用对数(浮点 x) { return std::log10(x); }
        inline 浮点 正弦(浮点 x) { return std::sin(x); }
        inline 浮点 余弦(浮点 x) { return std::cos(x); }
        inline 浮点 正切(浮点 x) { return std::tan(x); }
        inline 浮点 向上取整(浮点 x) { return std::ceil(x); }
        inline 浮点 向下取整(浮点 x) { return std::floor(x); }
        inline 浮点 四舍五入(浮点 x) { return std::round(x); }
        inline 整数 最大(整数 a, 整数 b) { return a > b ? a : b; }
        inline 整数 最小(整数 a, 整数 b) { return a < b ? a : b; }
        inline 浮点 最大(浮点 a, 浮点 b) { return a > b ? a : b; }
        inline 浮点 最小(浮点 a, 浮点 b) { return a < b ? a : b; }
        inline 整数 模(整数 a, 整数 b) {
            整数 r = a % b;
            return r < 0 ? r + (b < 0 ? -b : b) : r;
        }
    } // namespace 数学
    using 数学::绝对值;
    using 数学::平方根;
    using 数学::立方根;
    using 数学::幂;
    using 数学::指数;
    using 数学::自然对数;
    using 数学::常用对数;
    using 数学::正弦;
    using 数学::余弦;
    using 数学::正切;
    using 数学::向上取整;
    using 数学::向下取整;
    using 数学::四舍五入;
    using 数学::最大;
    using 数学::最小;
    using 数学::模;
} // namespace han

#endif // HAN_CMATH_H