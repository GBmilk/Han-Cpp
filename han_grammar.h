#pragma once
#ifndef HAN_GRAMMAR_H
#define HAN_GRAMMAR_H

// ============================================
// Han++ - 语法基础
// 文件: han_grammar.h
// 说明: 基础类型、容器别名、输入输出、数组操作、语法宏
// 编码: UTF-8
// 适用编译器：MSVC GCC Clang
// ============================================

#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <optional>
#include <algorithm>

namespace han {
    using 整数 = int;
    using 长整数 = long long;
    using 短整数 = short;
    using 无符号整数 = unsigned int;
    using 字节 = unsigned char;

    using 单精度 = float;
    using 浮点 = double;
    using 长浮点 = long double;

    using 布尔 = bool;
    using 字符 = char;
    using 宽字符 = wchar_t;
    using 字符串 = std::string;
    using 宽字符串 = std::wstring;

    using 空 = void;
    using 空指针 = std::nullptr_t;

    constexpr 布尔 真 = true;
    constexpr 布尔 假 = false;

    template <typename T> using 数组 = std::vector<T>;
    template <typename T> using 列表 = std::vector<T>;
    template <typename K, typename V> using 字典 = std::map<K, V>;
    template <typename K, typename V> using 映射 = std::map<K, V>;
    template <typename K> using 集合 = std::set<K>;
    template <typename T> using 智能指针 = std::shared_ptr<T>;
    template <typename T> using 独占指针 = std::unique_ptr<T>;
    template <typename T> using 可选 = std::optional<T>;

    using 整数数组 = 数组<整数>;
    using 浮点数组 = 数组<浮点>;
    using 字符串数组 = 数组<字符串>;

    template <typename T>
    inline void 打印(const T& 值) {
        std::cout << 值;
    }
    template <typename T, typename... 其他>
    inline void 打印(const T& 第一个, const 其他&... 剩余) {
        std::cout << 第一个;
        打印(剩余...);
    }
    template <typename... 参数>
    inline void 打印行(const 参数&... 值) {
        (std::cout << ... << 值);
        std::cout << std::endl;
    }
    inline void 换行() {
        std::cout << std::endl;
    }
    template <typename T>
    inline void 读取(T& 值) {
        std::cin >> 值;
    }
    inline 字符串 读取行() {
        字符串 行;
        std::getline(std::cin, 行);
        return 行;
    }
    namespace 数组操作 {

        template <typename T>
        inline 整数 数组_长度(const 数组<T>& v) {
            return static_cast<整数>(v.size());
        }
        template <typename T>
        inline 布尔 数组_为空(const 数组<T>& v) {
            return v.empty();
        }
        template <typename T>
        inline void 数组_添加(数组<T>& v, const T& 值) {
            v.push_back(值);
        }
        template <typename T>
        inline void 数组_删除末尾(数组<T>& v) {
            if (!v.empty()) v.pop_back();
        }
        template <typename T>
        inline void 数组_排序(数组<T>& v) {
            std::sort(v.begin(), v.end());
        }
        template <typename T>
        inline void 数组_反转(数组<T>& v) {
            std::reverse(v.begin(), v.end());
        }
        template <typename T>
        inline void 数组_清空(数组<T>& v) {
            v.clear();
        }
        template <typename T>
        inline 整数 数组_查找(const 数组<T>& v, const T& 值) {
            auto it = std::find(v.begin(), v.end(), 值);
            if (it == v.end()) return -1;
            return static_cast<整数>(it - v.begin());
        }
        template <typename T>
        inline 布尔 数组_包含(const 数组<T>& v, const T& 值) {
            return std::find(v.begin(), v.end(), 值) != v.end();
        }
        template <typename T>
        inline T 数组_最大值(const 数组<T>& v) {
            return *std::max_element(v.begin(), v.end());
        }
        template <typename T>
        inline T 数组_最小值(const 数组<T>& v) {
            return *std::min_element(v.begin(), v.end());
        }
        template <typename T>
        inline T 数组_求和(const 数组<T>& v) {
            T 总 = T{};
            for (const auto& x : v) 总 += x;
            return 总;
        }
        template <typename T>
        inline 浮点 数组_平均值(const 数组<T>& v) {
            if (v.empty()) return 0.0;
            return static_cast<浮点>(数组_求和(v)) / v.size();
        }
    } // namespace 数组操作
    using 数组操作::数组_长度;
    using 数组操作::数组_为空;
    using 数组操作::数组_添加;
    using 数组操作::数组_删除末尾;
    using 数组操作::数组_排序;
    using 数组操作::数组_反转;
    using 数组操作::数组_清空;
    using 数组操作::数组_查找;
    using 数组操作::数组_包含;
    using 数组操作::数组_最大值;
    using 数组操作::数组_最小值;
    using 数组操作::数组_求和;
    using 数组操作::数组_平均值;
} // namespace han

#define 如果          if
#define 否则          else
#define 否则如果      else if
#define 当            while
#define 循环          for
#define 做            do
#define 切换          switch
#define 情况          case
#define 默认          default
#define 跳出          break
#define 继续          continue
#define 返回          return

#define 类            class
#define 结构          struct
#define 枚举          enum
#define 命名空间      namespace
#define 模板          template
#define 类型名        typename
#define 常量表达式    constexpr
#define 常量          const
#define 自动          auto

#define 公开          public
#define 私有          private
#define 保护          protected

#define 静态          static
#define 内联          inline
#define 虚            virtual
#define 重写          override
#define 最终          final
#define 外部          extern

#define 尝试          try
#define 捕获          catch
#define 抛出          throw

#define 空类型        void

#endif // HAN_GRAMMAR_H