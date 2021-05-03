#pragma once
#include <iostream>
#include"Node.h"
class queue
{
private:
	nodeQueue *head;
	nodeQueue* tail;
	int size;
public:
	queue()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	void push(Node* data)
	{
		nodeQueue* add = new nodeQueue();
		add->data = data;
		if (size == 0)
		{
			tail = head = add;
		}
		else
		{
			nodeQueue *cur = head;
			while (add->data->amount < cur->data->amount && cur->next != nullptr)
			{
				cur = cur->next;
			}
			if (cur->next == nullptr && add->data->amount <= cur->data->amount)
			{
				cur->next = add;
				add->before = cur;
				add->next = nullptr;
				tail = add;
			}
			else if (add->data->amount >= cur->data->amount && cur->before == nullptr)
			{
				add->before = nullptr;
				add->next = cur;
				cur->before = add;
				head = add;
			}
			else
			{
				add->next = cur;
				add->before = cur->before;
				cur->before->next = add;
				cur->before = add;
			}
		}
		size++;
	}
	int Size()
	{
		return size;
	}
	void pop_tail()
	{
		if (size == 1)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			size--;
		} 
		else if (size > 1)
		{
			tail = tail->before;
			delete tail->next;
			tail->next = nullptr;
			size--;
		}
	}
	Node *TailElement()
	{
		return tail->data;
	}
	bool isEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		return false;
	}
};