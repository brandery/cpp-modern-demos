#include <tuple>
#include <list>
#include <iostream>
#include "main.h"
using namespace std;

auto get_students()
{
	std::list<std::tuple<double, char, const char*> > _list;
	// 返回类型被推断为 std::tuple<double, char, std::string>
	auto stu_0 = std::make_tuple(3.8, 'A', "张三");
	auto stu_1 = std::make_tuple(2.9, 'C', "李四");
	auto stu_2 = std::make_tuple(1.7, 'D', "王五");

	_list.push_back(std::move(stu_0));
	_list.push_back(std::move(stu_1));
	_list.push_back(std::move(stu_2));

	return _list;
}



int main() {
    auto stu_s = get_students();
	int stu_index = 0;
    for (auto& stu_i : stu_s) {
		cout << "stu_index: " << stu_index++ << endl;
		auto stu_i_len = tuple_len(stu_i);
        for (int i = 0; i < stu_i_len; ++i) {
            // 运行期索引
            std::cout <<tuple_index(stu_i, i) << std::endl;
        }
    }

	/*for (auto&& [num, score, name]: stu_s) {
		std::cout << num << score << name << std::endl;
	}*/
}