#include <iostream>
#include <cstddef>
#include <utility>
#include "string.h"

int main() {
 String s1; // ""
 String s2("Hello"); // "Hello"
 String s3(s2); // "Hello" (копия)
 s3.print(std::cout);
 String s4(std::move(s3)); // "Hello" (перемещение, s3 теперь пуст)
 s1 = s2; // копирующее присваивание
 s1.append(", World!");
 s1.print(std::cout); // "Hello, World!"
 size_t pos = s1.find("World");
 std::cout << pos << std::endl; // 7
 s2.print(std::cout);
 s3.print(std::cout);
 s4.print(std::cout);

 return 0;
}