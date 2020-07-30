#include <iostream>
#include <string>

template <typename ... T>
auto average(T ... a) {
	return (a + ...)/(float)sizeof ...(a);
}

enum class MyEnum: unsigned char
{
	TRACE,
	DEBUG,
	INFO,
	WARN,
	ERROR,
	FATAL
};

int main() {
	auto avg = average(0, 1, 2, 3, 4, 5);

	std::cout << avg << ", " << (int)MyEnum::ERROR <<std::endl;
}