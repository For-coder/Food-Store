#include <iostream>
#include <fstream>
#include <string>


using namespace std;


#ifndef Shop_H
#define Shop_H

class Shop {

public:
	void menu();
	void admin();
	void buyer();
	void add();
	void edit();
	void rem();
	void list();
	void receipt();
	

private:
	int proCode;
	float price;
	float dis;
	string proName;


};


#endif
