//Muhammad Shayaan Nofil | i21-0450
#include "Queue.h"

template <class T>
struct node {
	T val;
	node* next;

	node() {
		next = NULL;
	}

	void setdata(T x) {
		val = x;
	}
	void setnext(node* x) {
		next = x;
	}
	T getdata() { return val; }
	node* getnext() { return next; }
};

template <class T>
struct stack {
	node<T>* head;
	int Size;

	stack() {
		head = NULL;
		Size = 0;
	}

	node<T>* gethead() { return head; }
	void sethead(node<T>* x) { head = x; }
	int sizeofstack() { return Size; }

	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	void push(T val) {
		node<T>* temp = new node<T>;
		temp->val = val;
		temp->next = NULL;

		if (head != NULL) {
			temp->next = head;
			head = temp;
			Size++;
		}
		else {
			head = temp;
			Size++;
		}

	}

	T pop() {
		T temp2;
		if (!isEmpty()) {
			if (head->next == NULL) {
				temp2 = head->val;
				delete head;
				head = NULL;
				Size--;
				return temp2;
			}
			else {
				node<T>* temp = head->next;
				temp2 = head->val;
				delete head;
				head = temp;
				Size--;
				return temp2;
			}
		}

	}

	T Peek() { 
		if (!isEmpty()) {
			return head->val;
		}		
	}

	void clear() {
		node<T>* temp = head;
		node<T>* temp2 = head->next;

		if (isEmpty() == false) {
			if (temp2 != NULL) {
				temp = NULL;
				temp = temp2;
				temp2 = temp2->next;
			}
		}
	}
};

bool checker(string str) {
	int a = str[str.length() - 1];
	if ((a > 64 && a < 91) || (a > 96 && a < 123) || (a >= 48 && a <= 57)) {
		a = str[0];
		if ((a > 64 && a < 91) || (a > 96 && a < 123) || (a >= 48 && a <= 57)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void postfix(string exp) {
	stack<char> opStack;
	string Output = "";

	if (checker(exp)) {
		for (int i = 0; i < exp.length(); i++)
		{
			int a = exp[i];
			if ((a > 64 && a < 91) || (a > 96 && a < 123))
			{
				Output += exp[i];
			}
			else if (a == 40)
			{
				opStack.push(exp[i]);
			}
			else if (a == 41)
			{

				while (opStack.isEmpty() != true)
				{
					char op = opStack.pop();
					int a = op;
					if (a == 40)
					{
						break;
					}
					else
					{
						Output += op;
					}

				}

			}
			else if (exp[i] == '^') {
				opStack.push(exp[i]);
			}
			else if (exp[i] == '*' || exp[i] == '/')
			{
				char op = opStack.Peek();
				if (op == '^') {
					Output += opStack.pop();
					opStack.push(exp[i]);
				}
				else {
					opStack.push(exp[i]);
				}
			}
			else if (exp[i] == '-' || exp[i] == '+')
			{
				char op = opStack.Peek();

				if (op == '*' || op == '/' || op == '+' || op == '-')
				{
					Output += opStack.pop();
					opStack.push(exp[i]);

				}
				else
				{
					opStack.push(exp[i]);
				}
			}
		}
		while (opStack.isEmpty() != true)
		{
			Output += opStack.pop();
		}
		ofstream mfile("Output_files/Output.txt", ios::app);
		cout << Output;
		mfile << Output;
		mfile.close();
	}
	else {
		ofstream mfile("Output_files/Output.txt", ios::app);
		cout << "Invalid Expression";
		mfile << "Invalid Expression";
		mfile.close();
	}
}

void prefix(string str) {
	stack<char> opStack;
	string Output = "", exp = "";

	if (checker(str)) {
		for (int i = str.length() - 1; i >= 0; i--) {
			exp += str[i];
		}
		for (int i = 0; i < exp.length(); i++) {
			if (exp[i] == ')') {
				exp[i] = '(';
			}
			else if (exp[i] == '(') {
				exp[i] = ')';
			}
		}

		for (int i = 0; i < exp.length(); i++)
		{
			int a = exp[i];
			if ((a > 64 && a < 91) || (a > 96 && a < 123))
			{
				Output += exp[i];
			}
			else if (a == 40)
			{
				opStack.push(exp[i]);
			}
			else if (a == 41)
			{
				while (opStack.isEmpty() != true)
				{
					char op = opStack.pop();
					int a = op;
					if (a == 40)
					{
						break;
					}
					else
					{
						Output += op;
					}
				}
			}
			else if (exp[i] == '^') {
				opStack.push(exp[i]);
			}
			else if (exp[i] == '*' || exp[i] == '/')
			{
				char op = opStack.Peek();
				if (op == '^') {
					Output += opStack.pop();
					opStack.push(exp[i]);
				}
				else {
					opStack.push(exp[i]);
				}
			}
			else if (exp[i] == '-' || exp[i] == '+')
			{
				char op = opStack.Peek();

				if (op == '*' || op == '/' || op == '+' || op == '-')
				{
					Output += opStack.pop();
					opStack.push(exp[i]);

				}
				else
				{
					opStack.push(exp[i]);
				}
			}
		}
		while (opStack.isEmpty() != true)
		{
			Output += opStack.pop();
		}
		string ans = "";

		for (int i = Output.length() - 1; i >= 0; i--) {
			ans += Output[i];
		}
		cout << ans;
		ofstream mfile("Output_files/Output.txt", ios::app);
		mfile << ans;
		mfile.close();
	}
	else {
		cout << "Invalid Expression";
		ofstream mfile("Output_files/Output.txt", ios::app);
		mfile << "Invalid Expression";
		mfile.close();
	}
}

void solfix(string exp) {
	stack<string> s1;

	char temp = exp[exp.length() - 1];
	if (temp < 'a' || temp > 'z' && temp < 'A' || temp > 'Z') {
		for (int i = 0; i < exp.length(); i++)
		{
			int a = exp[i];
			if ((a > 64 && a < 91) || (a > 96 && a < 123) || (a >= 48 && a <= 57))
			{
				string op = "";
				op = exp[i];
				s1.push(op);
			}
			else
			{
				string op1 = s1.Peek();
				s1.pop();
				string op2 = s1.Peek();
				s1.pop();
				s1.push(op2 + exp[i] + op1);
			}
		}
		cout << s1.Peek();
		ofstream mfile("Output_files/Output.txt", ios::app);
		mfile << s1.Peek();
		mfile.close();
	}
	else {
		cout << "Invalid Expression";
		ofstream mfile("Output_files/Output.txt", ios::app);
		mfile << "Invalid Expression";
		mfile.close();
	}
}