// 猫狗队列.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdint>
#include <string>
#include <queue>

class Dog
{
public:
	std::string name;
	uint16_t count;//时间戳
};

class Cat
{
public:
	std::string name;
	uint16_t count;
};

class Pet
{
	
};
class DogCatQueue
{
private:
	std::queue<Dog> dogs;
	std::queue<Cat> cats;
	uint16_t count=0;

public:
	void Add(Dog dog)
	{
		dogs.push(dog);

	}
};
int main()
{
	
    return 0;
}

