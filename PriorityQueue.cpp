#include "PriorityQueue.h"

Node* KhoiTaoNode(char letter, int priority) {
	Node* p = new Node;
	if (p == NULL) {
		cout << "\nKhong du vung nho de cap phat";
		return NULL;
	}
	else {
		p->letter = letter;
		p->priority = priority;
		return p;
	}
}


void enqueue(priorityQueue &hang, Node* p) {
	hang.danhsach.push_back(p);
	int size = hang.danhsach.size();
	cout << "\nCurrent size = " << size << endl;
	if (size > 1) {
		bubbleUp(hang);
	}
	system("pause");
}

void bubbleUp(priorityQueue& hang) {
	int idx = hang.danhsach.size() - 1;
	Node* element = hang.danhsach[idx];
	while (idx > 0) {
		int parentIdx = floor((idx - 1) / 2);
		cout << "\nParent" << parentIdx << endl;
		Node* parent = hang.danhsach[parentIdx];
		if (element->priority >= parent->priority) break;
		hang.danhsach[parentIdx] = element;
		hang.danhsach[idx] = parent;
		idx = parentIdx;
	}
	system("pause");
}

void XuatDuLieu(priorityQueue hang) {
	int size = hang.danhsach.size();
	if (size == 0) {
		cout << "\nDanh sach khong co phan tu";
	}
	else {
		for (int i = 0; i < size; i++) {
			cout << hang.danhsach[i]->letter << " : " << hang.danhsach[i]->priority << endl;
		}
	}
}

Node* dequeue(priorityQueue & hang) {
	int size = hang.danhsach.size();
	if (size == 0) {
		cout << "\nKhong the dequeue, danh sach trong";
		return NULL;
	}
	else {
		Node* min = hang.danhsach[0];
		Node* end = hang.danhsach[size - 1];
		hang.danhsach.pop_back();
		if (size > 0) {
			hang.danhsach[0] = end;
			sinkDown(hang);
		}
		return min;
	}
}

void sinkDown(priorityQueue &hang) {
	int idx = 0;
	int size = hang.danhsach.size();
	Node* element = hang.danhsach[0];
	while (true) {
		int leftChildIdx = 2 * idx + 1;
		int rightChildIdx = 2 * idx + 2;
		Node* leftChild = NULL;
		Node* rightChild = NULL;
		int swap = NULL;
		if (leftChildIdx < size) {
			leftChild = hang.danhsach[leftChildIdx];
			if (leftChild->priority < element->priority) {
				swap = leftChildIdx;
			}
		}
		
		if (rightChildIdx < size) {
			rightChild = hang.danhsach[rightChildIdx];
			if ((swap == NULL && rightChild->priority < element->priority) ||
				(swap != NULL && rightChild->priority < leftChild->priority)) {
				swap = rightChildIdx;
			}
		}

		if (swap == NULL) break;
		hang.danhsach[idx] = hang.danhsach[swap];
		hang.danhsach[swap] = element;
		idx = swap;
	}
}

void Menu(priorityQueue &hang) {
	int luachon;
	do {
		system("CLS");
		cout << "\n=======Menu=======";
		cout << "\n1. Nhap phan tu vao hang doi uu tien: ";
		cout << "\n2. Xuat du lieu";
		cout << "\n3. Dequeue All";
		cout << "\n0. Thoat";
		do {
			cout << "\nNhap vao lua chon: ";
			cin >> luachon;
			if (luachon < 0 || luachon > 10) {
				cout << "\nLua chon khong hop le. nhap lai";
			}
		} while (luachon < 0 || luachon > 10);
		if (luachon == 1) {
			char kyTu;
			int thuTu;
			cin.ignore();
			cout << "\nNhap ky tu: ";
			cin >> kyTu;
			cout << "\nNhap thu tu uu tien: ";
			cin >> thuTu;
			Node* p = KhoiTaoNode(kyTu, thuTu);
			enqueue(hang, p);
		}
		else if (luachon == 2) {
			XuatDuLieu(hang);
			system("pause");
		}

		else if (luachon == 3) {
			int size = hang.danhsach.size();
			vector<int> duLieu;
			for (int i = 0; i < size; i++) {
				Node* remove = dequeue(hang);
				duLieu.push_back(remove->priority);
			}
			for (int i = 0; i < size; i++) {
				cout << duLieu[i] << " ";
			}
			system("pause");
		}
	} while (luachon != 0);
}