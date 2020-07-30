#include <iostream>
#include <utility>
#include "main.h"
#include <vector>
#include <string>
using namespace std;


int main()
{
    std::string lv1 = "string,"; // lv1 是一个左值
    //std::string&& r1 = lv1; // 非法, 右值引用不能引用左值
    std::string&& rv1 = std::move(lv1); // 合法, std::move可以将左值转移为右值
    std::cout << rv1 << std::endl; // string,

    const std::string& lv2 = rv1 + rv1; // 合法, 常量左值引用能够延长临时变量的生命周期
    // lv2 += "Test"; // 非法, 常量引用无法被修改
    std::cout << lv2 << std::endl; // string,string

    std::string&& rv2 = lv1 + lv2; // 合法, 右值引用延长临时对象生命周期
    rv2 += "Test"; // 合法, 非常量引用能够修改临时变量
    std::cout << rv2 << std::endl; // string,string,string,Test

    pass(lv1); // 输出左值
    pass(rv1); // 输出左值
    pass(rv2); // 输出左值
    pass(to_string(1)); // 输出左值

    return 0;
}

//int main() {
//    auto important = std::make_unique<int>(1);
//    auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int {
//        return x + y + v1 + (*v2);
//    };
//    std::cout << add(3, 4) << std::endl;
//    return 0;
//}