#pragma once
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Node {
	char letter;
	int priority;
};
typedef struct Node Node;


struct priorityQueue {
	vector<Node *> danhsach;
};
typedef struct priorityQueue priorityQueue;


Node* KhoiTaoNode(char , int);
void enqueue(priorityQueue &, Node* );
void bubbleUp(priorityQueue &);
void XuatDuLieu(priorityQueue);
Node* dequeue(priorityQueue &);
void sinkDown(priorityQueue &);
void Menu(priorityQueue &);