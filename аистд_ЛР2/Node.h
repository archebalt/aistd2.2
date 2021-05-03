#pragma once
#include <iostream>
#include <string>
using namespace std;
class Node
{
public:

	char letter;
	int amount;
	string str;
	string num;
	Node *leftChild;
	Node *rightChild;
	Node* parent;
	Node()
	{
		letter = '&';
		amount = 0;
		str = "";
		leftChild = nullptr;
		rightChild = nullptr;
		parent = nullptr;
	}
};

class nodeQueue
{
public:
	Node* data;
	nodeQueue *next;
	nodeQueue* before;
	nodeQueue()
	{
		data = nullptr;
		next = nullptr;
		before = nullptr;
	}
};

class ListNode
{
public:
	Node* data;
	ListNode* next;
	ListNode()
	{
		data = nullptr;
		next = nullptr;
	}
};
