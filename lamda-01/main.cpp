#include <iostream>
#include <utility>
#include "main.h"
#include <vector>
#include <string>
using namespace std;


int main()
{
    std::string lv1 = "string,"; // lv1 ��һ����ֵ
    //std::string&& r1 = lv1; // �Ƿ�, ��ֵ���ò���������ֵ
    std::string&& rv1 = std::move(lv1); // �Ϸ�, std::move���Խ���ֵת��Ϊ��ֵ
    std::cout << rv1 << std::endl; // string,

    const std::string& lv2 = rv1 + rv1; // �Ϸ�, ������ֵ�����ܹ��ӳ���ʱ��������������
    // lv2 += "Test"; // �Ƿ�, ���������޷����޸�
    std::cout << lv2 << std::endl; // string,string

    std::string&& rv2 = lv1 + lv2; // �Ϸ�, ��ֵ�����ӳ���ʱ������������
    rv2 += "Test"; // �Ϸ�, �ǳ��������ܹ��޸���ʱ����
    std::cout << rv2 << std::endl; // string,string,string,Test

    pass(lv1); // �����ֵ
    pass(rv1); // �����ֵ
    pass(rv2); // �����ֵ
    pass(to_string(1)); // �����ֵ

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