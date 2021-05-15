#pragma once
#include <vector>

template <class Type>						//(����������� �����������) ������ ������-���������� ��� �������� ��������� ��������
class iContainer							//(������������ �����������) ��������� ��� �������� �������-�����������
{
protected:
	std::vector<Type> data;
public:
	virtual int howManyInside() = 0;		//���������� ���������� �������� ��������
};