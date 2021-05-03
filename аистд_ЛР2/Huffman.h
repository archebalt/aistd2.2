#pragma once
#include <iostream>
#include"Queue.h"
#include"Node.h"
#include"List.h"
#include <string>
using namespace std;

class huffman
{
	Node* head;
	string str2, str3;
public:
	huffman(string str)
	{
		int amountOfLetter[256] = { 0 };
		for (int i = 0; i < str.size(); i++) 
			amountOfLetter[str[i] + 128]++;
		int count = 0;
		queue q1;
		queue q2;
		for (int i = 0; i < 256; i++)
		{
			if (amountOfLetter[i] != 0)
			{
				count++;
				cout << (char)(i + 128) << " : " << amountOfLetter[i] << endl;
				Node *point = new Node;
				point->amount = amountOfLetter[i];
				point->letter = (char)(i + 128);
				q1.push(point);
				q2.push(point);
			}
		}
		head = nullptr;
		Node *node1 = q1.TailElement();
		Node* node2 = nullptr;
		int little1 = node1->amount;
		node1->num = "0";
		q1.pop_tail();
		for (int i = 0; (i < count) && (q1.isEmpty() == false); i++)
		{
			node2 = q1.TailElement();
			int little2 = node2->amount;
			node2->num = "1";
			q1.pop_tail();
			little1 += little2;
			Node* root = new Node;
			root->amount = little1;
			root->letter = '&';
			node1->parent = root;
			node2->parent = root;
			root->leftChild = node1;
			root->rightChild = node2;
			q1.push(root);
			head = root;
			node1 = q1.TailElement();
			little1 = node1->amount;
			if (q1.Size() > 1)
			{
				node1->num = "0";
			}
			else
			{
				node1->num = "&";
			}
			q1.pop_tail();
		}
		Node* node3 = nullptr;
		Node* node4 = nullptr;
		List letters;
		while(q2.Size() != 0)
		{
			node3 = q2.TailElement();
			node4 = q2.TailElement();
			string s1, s2;
			while (node3->parent != nullptr)
			{
				s1 += node3->num ;
				node3 = node3->parent;
			}
			int j = s1.size() - 1;
			for (int i = 0; i < s1.size(); i++)
			{
				char chh = s1[j];
				s2 += chh;
				j--;
			}
			node4->str = s2;
			cout << node4->letter << ' ' << node4->str; 
			letters.push(node4);
			
			cout << endl;
			q2.pop_tail();
		}
		
		for (int i = 0; i < str.size(); i++) // закодирование
		{
			ListNode* sup = letters.show_head();
			while (sup->data->letter != str[i])
				sup = sup->next;
			str2 = str2 + sup->data->str;
		}
		cout << endl;
		Node* Supp = head;
		for (int i = 0; i < str2.size(); i++) ///////// декодирование
		{
			if (str2[i] == '0' && Supp->letter == '&')
			{
				Supp = Supp->leftChild;
			}
			else if (str2[i] == '1' && Supp->letter == '&')
			{
				Supp = Supp->rightChild;
			}
			else
			{
				str3 += Supp->letter;
				Supp = head;
				i--;
			}
		}
		str3 += Supp->letter;
		//cout << str3;
	}
	string res()
	{
		return str2; // результат кодирования
	}
	string deCode()
	{
		return str3; // результат декодирования
	}
};