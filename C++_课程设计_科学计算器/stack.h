#pragma once
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstdlib>
using namespace std;

const int kmax_length = 100;
template <class Datatype>
class Stack
{
public:
	Stack();
	void pushStack(Datatype);  //��ջ
	Datatype popStack();  //��ջ
	Datatype getStackTop(); //��ȡջ��Ԫ��
	int getTopLocation();  //��ȡջ����λ��
	bool isEmpty();  //�ж�ջ�Ƿ�Ϊ��
	bool isFull();  //�ж�ջ�Ƿ�����
private:
	int top_;
	Datatype stack_[kmax_length];
};

#endif // !STACK_H

template<class Datatype>
inline Stack<Datatype>::Stack()
{
	top_ = -1;  //��ʼ��ջ��
}

template<class Datatype>
inline void Stack<Datatype>::pushStack(Datatype data)
{
	if (!isFull())
	{
		stack_[++top_] = data;
	}
	else
	{
		cout << "Error! Stack full!" << endl;
	}
}

template<class Datatype>
inline Datatype Stack<Datatype>::popStack()
{
	if (!isEmpty())
	{
		return stack_[top_--];
	}
	else
	{
		cout << "Error! Stack is already empty!" << endl;
		exit(-1);
	}
}

template<class Datatype>
inline Datatype Stack<Datatype>::getStackTop()
{
	if (!isEmpty())
	{
		return stack_[top_];
	}
	else
	{
		cout << "Error! Stack is already empty!" << endl;
		exit(-2);
	}

}

template<class Datatype>
inline int Stack<Datatype>::getTopLocation()
{
	return top_;
}

template<class Datatype>
inline bool Stack<Datatype>::isEmpty()
{
	if (top_ == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class Datatype>
inline bool Stack<Datatype>::isFull()
{
	if (top_ == kmax_length - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

