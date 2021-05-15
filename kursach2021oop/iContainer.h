#pragma once
#include <vector>

template <class Type>						//(статический полиморфизм) шаблон класса-контейнера для хранения различных обьектов
class iContainer							//(динамический полиморфизм) интерфейс для создания классов-контейнеров
{
protected:
	std::vector<Type> data;
public:
	virtual int howManyInside() = 0;		//возвращает количество хранимых обьектов
};