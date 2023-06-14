//Muhammad Shayaan Nofil | i21-0450
#include "cstack.h"

struct tabs {
	string tab[12] = { "|start|","|head|", "|priorty|", "|paragraph|", "|chk|", "|post_exp|", "|pre_exp|", "|sol_exp|", "|src|", "|tab|","|Function|", "|In_exp|" };
	string etab[12] = { "|\\start|","|\\head|", "|\\priorty|", "|\\paragraph|", "|\\chk|", "|\\post_exp|", "|\\pre_exp|", "|\\sol_exp|", "|\\src|", "|\\tab|","|\\Function|","|\\In_exp|"};

	int tind(string str) {
		for (int i = 0; i < 12; i++) {
			if (str == tab[i]) {
				return i;
			}
		}
		return -1;
	}
	int etind(string str) {
		for (int i = 0; i < 12; i++) {
			if (str == etab[i]) {
				return i;
			}
		}
		return -1;
	}
};
int intsize(string str) {
	int s = 0;
	for (int i = 0; i < str.length(); i++) {
		s += str[i];
	}
	return s;
}
int getpriorty(string stri) {
	ifstream file(stri);
	string str; int size;
	stack<string> s1;
	tabs t1; bool check = false;

	while (getline(file, str)) {
		string temp = "";
		if (check == true) {
			return stoi(str);
		}
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '|') {
				int x = i + 1, ind = -1;
				temp += str[i];
				while (str[x] != '|') {
					temp += str[x];
					x++;
				}
				temp += str[x];
				i = x;
				ind = t1.tind(temp);

				if (ind == 2) {
					check = true;
					continue;
				}
			}
		}
	}
}
bool parse(string stri) {
	ifstream file(stri);
	string str; int size;
	stack<string> s1;
	tabs t1;

	while (getline(file, str)) {
		size = str.length();
		string temp = "\0";
		bool check = false;
		bool end = false;
		for (int i = 0; i < size; i++) {
			if (str[i] == '|') {//|\\head|
				int x = i + 1;
				int ind = -1, ind2 = -1;
				temp = str[i];
				while (str[x] != '|') {//|\\head|
					temp += str[x];
					x++;
				}
				temp += str[x];
				i = x;

				ind = t1.tind(temp);
				ind2 = t1.etind(temp);			
				if (ind2 != -1) {
					int stind = t1.tind(s1.Peek());
					if (ind2 == stind) {
						s1.pop();
					}
				}
				else if (s1.isEmpty() == false && intsize(temp) == intsize(s1.Peek()) + 92) {
					s1.pop();
				}
				else {		
					s1.push(temp);				
				}
			}			
		}
	}
	if (s1.isEmpty()) {
		return true;
	}
	else {
		cout << s1.Peek() << endl;
		return false;
	}
}
void validate(string stri) {
	ifstream file(stri);
	string str; int size;
	stack<string> s1; tabs t1;
	bool end = false;

	if (parse(stri)) {
		while (getline(file, str)) {
			size = str.length();
			string temp = "";
			bool check = false;
			for (int i = 0; i < size; i++) {
				if (str[i] == '|') {
					int x = i + 1;
					int ind = -1, ind2 = -1;
					temp = str[i];
					while (str[x] != '|') {
						temp += str[x];
						x++;
					}
					temp += str[x];
					i = x;

					ind = t1.tind(temp);
					ind2 = t1.etind(temp);
					if (ind != -1) {
						s1.push(temp);
						if (ind == 5 || ind == 6 || ind == 7 || ind == 11|| ind == 8) {
							string exp = "";
							for (int y = i+1; y < size; y++) {
								if (str[y] == '|') {
									y = size;
								}
								else if (y == i+1 && str[y] != 32) {
									exp = str[y];
								}
								else if (str[y] != 32) {
									exp += str[y];
								}
							}
							switch (ind) {
							case 5:
								postfix(exp);
								break;
							case 6:
								prefix(exp);
								break;
							case 7:
								solfix(exp);
								break;
							case 11:
								postfix(exp);
								break;
							case 8:
								isoimage(exp);
								break;
							}
						}

					}
					if (ind2 != -1) {
						int stind = t1.tind(s1.Peek());
						if (ind2 == stind) {
							s1.pop();
							if (ind2 == 9) {//checking for \t
								ofstream mfile("Output_files/Output.txt", ios::app);
								cout << "\t";
								mfile << "\t";
								mfile.close();
							}
						}	
					}
					if (temp == "|\\start|") {
						end = true;
					}

				}		
				if (end == false) {
					int ind = t1.tind(s1.Peek());
					if ((ind == 3 || ind == 1) || ind == 4) {
						if (str[i] != 9 && str[i] != '|') {
							ofstream mfile("Output_files/Output.txt", ios::app);
							cout << str[i];
							mfile << str[i];
							mfile.close();
						}
						check = true;
					}
										
				}
			}	
			if (check == true) {
				ofstream mfile("Output_files/Output.txt", ios::app);
				cout << endl;
				mfile << endl;
				mfile.close();
			}
		}
	}
	else {
		while (getline(file, str)) {
			size = str.length();
			string temp = "";
			bool check = false;
			for (int i = 0; i < size; i++) {
				if (str[i] == '|') {
					int x = i + 1;
					int ind = -1, ind2 = -1;
					temp = str[i];
					while (str[x] != '|') {
						temp += str[x];
						x++;
					}
					temp += str[x];
					i = x;

					ind = t1.tind(temp);
					ind2 = t1.etind(temp);
					if (ind != -1) {
						s1.push(temp);
					}
					if (ind2 != -1) {
						int stind = t1.tind(s1.Peek());
						if (ind2 == stind) {
							s1.pop();
							if (ind2 == 9) {//checking for \t
								ofstream mfile("Output_files/Output.txt", ios::app);
								cout << "\t";
								mfile.close();
							}
							if (ind2 == 1) {
								ofstream mfile("Output_files/Output.txt", ios::app);
								cout << "\nSyntax error";
								mfile << "\nSyntax error";
								mfile.close();
								return;
							}
						}
					}
				}
				if (end == false) {
					int ind = t1.tind(s1.Peek());
					if ((ind == 3 || ind == 1) || ind == 4) {
						if (str[i] != 9 && str[i] != '|') {
							ofstream mfile("Output_files/Output.txt", ios::app);
							cout << str[i];
							mfile << str[i];
							mfile.close();
						}
						check = true;
					}

				}
			}
		}
	}
}
void startit() {
	ofstream myfile("Output_files/Output.txt");
	myfile.close();
	queue<int> q1; int hit = 0, fault = 0;
	for (int i = 1; i <= 7; i++) {
		string str = "Test_files/Test-";
		str += i + 48;
		str += ".txt";
		int temp = getpriorty(str);
		if (q1.find(temp)) {
			hit++;
		}
		else {
			fault++;
			q1.enqueue(temp);
		}
		validate(str);
	}
	ofstream mfile("Output_files/Output.txt", ios::app);
	cout << "\nLRU Results: hits = " << hit << ", faults = " << fault;
	mfile << "\nLRU Results: hits = " << hit << ", faults = " << fault;
	mfile.close();
}