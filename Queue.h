//Muhammad Shayaan Nofil | i21-0450
#include <iostream>
#include <string>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;

template <class T>
struct Qnode {
	T data;
	Qnode* next;

	Qnode() {
		next = NULL;
	}

	void setdata(T x) {
		data = x;
	}
	void setnext(Qnode* x) {
		next = x;
	}
	T getdata() { return data; }
	Qnode* getnext() { return next; }
};

template <class T>
struct queue {
	Qnode<T>* tail;
	Qnode<T>* head;
	int size;

	queue() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	Qnode<T>* gettail() { return tail; }
	Qnode<T>* gethead() { return head; }
	void settail(Qnode<T>* x) { tail = x; }
	void sethead(Qnode<T>* x) { head = x; }

	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	void enqueue(T dat) {
		if (head == NULL && size <= 4)
		{
			Qnode<T>* temp = new Qnode<T>;
			temp->data = dat;
			temp->next - NULL;
			head = temp;
			tail = temp;
			size++;
		}
		else if (size <= 4) {
			Qnode<T>* temp = new Qnode<T>;
			temp->data = dat;
			Qnode<T>* templ = tail;
			templ->next = temp;
			temp->next - NULL;
			tail = temp;
			size++;
		}
		else {
			dequeue();
			enqueue(dat);
		}
	}

	void dequeue() {
		if (!isEmpty()) {
			Qnode<T>* temp = head->next;
			delete head;
			head = temp;
			size--;
		}
	}

	T front() { return head->getdata(); }
	bool find(int n) {
		Qnode<T>* temp = head;
		if (!isEmpty()) {
			for (int i = 0; i < size; i++) {
				if (temp->data == n) {
					return true;
				}
				temp = temp->next;
			}			
		}
		return false;
	}
};

void isoimage(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '\\') {
			str[i] = '/';
		}
		if (i == 0) {
			str[i] = ' ';
		}
		if (str[i] == 'i') {
			str[i] = 'I';
		}
	}
	str += ".png";
	string temp = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ') {
			temp += str[i];
		}
	}
	Mat gt = imread(temp, IMREAD_GRAYSCALE);
	imwrite("Output_files/iso.png", gt);

	cout << "1-5 xD";
	ofstream mfile("Output_files/Output.txt", ios::app);
	mfile << "1-5 xD";
	mfile.close();

}