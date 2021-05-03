#pragma once
#include"Node.h"
class List
{
private:
	ListNode* head;
	ListNode* tail;
	int size;
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	void push(Node* param)
	{
		ListNode* cur = new ListNode;
		cur->data = param;
		if (size == 0)
		{
			tail = head = cur;
			head->next = nullptr;
		}
		else
		{
			cur->next = nullptr;
			tail->next = cur;
			tail = cur;
		}
		size++;
	}
	ListNode *show_head()
	{
		return head;
	}
	~List()
	{
		ListNode* cur = head;
		while (cur != tail)
		{
			ListNode* sup = cur->next;
			delete cur;
			cur = sup;
		}
		delete tail;
	}
};
