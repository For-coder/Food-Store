#include "Shop.h"




void Shop::menu() {

	m:
	int pick;
	string email;
	string password;

	cout << "***************WELCOME TO STORE MENU***************" << endl << endl;
	cout << "1) Administrator" << endl << endl;
	cout << "2) Buyer" << endl << endl;
	cout << "3) Exit" << endl << endl;
	cout << "Please select.";
	cin >> pick;


	switch (pick) {
	case 1:
		cout << "****PLEASE LOGIN****" << endl;
		cout << "Enter your email: ";
		cin >> email;
		cout << endl;
		cout << "Enter you password: ";
		cin >> password;
		cout << endl;

		if (email == "admin@email.com" && password == "admin123") {
			admin();
		}
		else
		{
			cout << "Invalid email and password!" << endl;
		}
		break;


	case 2:
		buyer();

		break;


	case 3:
		exit(0);

		break;

	default:
		cout << "*PLEASE SELECT*" << endl; 
		cout << "1) Administrator" << endl;
		cout << "2) Buyer" << endl; 
		cout << "3) Exit" << endl;
		break;
	}

	goto m;
}

void Shop::admin() {

	m:
	int pick;

	cout << "***************ADMINISTRATOR MENU***************" << endl;
	cout << "1) Add the product" << endl;
	cout << "2) Change the product" << endl;
	cout << "3) Delete the product" << endl;
	cout << "4) Back to main menu" << endl;
	cout << "Enter your choice.";
	cin >> pick;
	cout << endl;

	switch (pick)
	{
	case 1:
		add();
		break;

	case 2:
		edit();
		break;

	case 3:
		rem();
		break;

	case 4:
		menu();
		break;

	default:
		cout << "*PLEASE SELECT*" << endl;
		cout << "1) Add the product" << endl;
		cout << "2) Change the product" << endl;
		cout << "3) Delete the product" << endl;
		cout << "4) Back to main menu" << endl;
		break;
	}
	goto m;
}

void Shop::buyer() {

	m:
	int pick;
	cout << "***************BUYER***************" << endl;
	cout << "1) Buy product" << endl;
	cout << "2) Go back" << endl;
	cout << " Enter your choice." << endl;
	cin >> pick;
	cout << endl; 

	switch (pick)
	{
	case 1:
		receipt();
		break;

	case 2:
		menu();
		break;
	default:
		cout << "*PLEASE SELECT*" << endl;
		cout << "1) Buy product" << endl;
		cout << "2) Go back" << endl;
		break;
	}
	goto m;
}

void Shop::add() {

	m:
	fstream data;
	int c;
	int token = 0;
	float p;
	float d;
	string n;


	cout << "***************ADD NEW PRODUCT***************" << endl;
	cout << "Product code: ";
	cin >> proCode;
	cout << endl;

	cout << "Name of product: ";
	cin >> proName;
	cout << endl;

	cout << "Price of product: ";
	cin >> price;
	cout << endl;

	cout << "Discount of product(You may enter 0): ";
	cin >> dis;
	cout << endl;


	data.open("database.txt", ios::in);

	if (!data) {
		data.open("database.txt", ios::app | ios::out);
		data << " " << proCode << " " << proName << " " << price << " " << dis << endl;
		data.close();
	}
	else
	{
		data >> c >> n >> p >> d;

		while (!data.eof()) {
			if (c == proCode) {
				token++;
			}
			data >> c >> n >> p >> d;
		}
		data.close();
	
	if (token == 1) {
		goto m;
	}
	else
	{
		data.open("database.txt", ios::app | ios::out);
		data << " " << proCode << " " << proName << " " << price << " " << dis << endl;
		data.close();
	}
	}
	cout << "INSERTED" << endl;
}

void Shop::edit() {
	fstream data, data1;

	int pkey, c;
	int token = 0;
	float p, d;
	string n;

	cout << "***************CHANGE RECORD***************" << endl;
	cout << "Product code: ";
	cin >> pkey;
	cout << endl;

	data.open("database.txt", ios::in);

	if (!data) {
		cout << "No such file." << endl;
	}
	else {
		data1.open("database1.txt", ios::app | ios::out);

		data << " " << proCode << " " << proName << " " << price << " " << dis << endl;
		while (!data.eof()) {
			if (pkey == proCode) {
				cout << "Enter new product code: ";
				cin >> c;
				cout << endl;
				cout << "Enter name of the product: ";
				cin >> n;
				cout << endl;
				cout << "Enter the price: ";
				cin >> p;
				cout << endl;
				cout << "Enter the discount: ";
				cin >> d;
				cout << endl;
				data1 << " " << c << " " << n << " " << p << " " << d << endl;
				cout << "CHANGE RECORD" << endl;
				token++;
			}
			else {
				data1 << " " << proCode << " " << proName << " " << price << " " << dis << endl;
			}
			data >> proCode >> proName  >> price >> dis;
		}
		data.close();
		data1.close();

		remove("database.txt");
		rename("database1.txt", "database.txt");

		if (token == 0) {
			cout << "No such record." << endl;
		}
	}


}

void Shop::rem() {
	fstream data, data1;
	int pkey;
	int token = 0;
	cout << "***************DELETE PRODUCT****************" << endl;
	cout << "Enter product code: " << endl;
	cin >> pkey;
	cout << endl;

	data.open("database.txt", ios::in);
	if (!data) {
		cout << "No such file." << endl;

	}
	else
	{
		data1.open("database1.txt", ios::app | ios::out);
		data << " " << proCode << " " << proName << " " << price << " " << dis << endl;

		while (!data.eof()) {
			if (proCode == pkey) {
				cout << "Product deleted." << endl;
				token++;
			}
			else {
				data1<< " " << proCode << " " << proName << " " << price << " " << dis << endl;
			}
			data >> proCode >> proName >> price >> dis;
		}
		data.close();
		data1.close();

		remove("database.txt");
		rename("database1.txt", "database.txt");

		if(token == 0){
			cout << "No such record." << endl;
		}
	}
}

void Shop::list() {

	ifstream data;
	data.open("database.txt", ios::in);
	cout << "*****************************" << endl;
	cout << "ProNo******Name******Price" << endl;

	data >> proCode >> proName >> price >> dis;

	while (!data.eof()) {
		cout << proCode << "*****" << proName << "*****" << price << endl;
		data >> proCode >> proName >> price >> dis;
	}

	data.close();
}

void Shop::receipt() {
	m:
	fstream data;
	int arrc[100];
	int arrq[100];
	char pick;
	int c = 0;
	float amount = 0;
	float dis = 0;
	float total = 0;

	cout << "RECEIPT" << endl;
	data.open("database.txt", ios::in);
	if (!data) {
		cout << "Empty database." << endl;
	}
	else
	{
		data.close();
		list();
		cout << "******************************" << endl;
		cout << "*PLACE YOUR ORDER*" << endl;
		do {
			cout << "Enter product code: " << endl;
			cin >> arrc[c];
			cout << "Enter product quantity" << endl;
			cin >> arrq[c];

			for (int i = 0; i < c; i++) {
				if (arrc[c] == arrc[i]) {
					cout << "Duplicate product code> Try agin." << endl;
					goto m;
				}
			}
			c++;
			cout << "Buy another product? y/n.";
			cin >> pick;
			cout << endl;
		}

		while (pick == 'y'); {
			cout << "***************RECEIPT***************" << endl;
			cout << "ProductNo******Product Name******Product Quantity" << endl;
			cout << "tPrice******tAmount******tAmount eith discount" << endl;

			for (int i = 0; i < c; i++) {
				data.open("database.txt", ios::in);
				data >> proCode >> proName >> price >> dis;
				while (!data.eof())
				{
					if (proCode == arrc[i]) {
						amount = price * arrq[i];
						dis = amount - (amount * dis / 100);
						total = total + dis;
						cout << proCode << proName << arrq[i] << price << amount << dis <<endl;
					}
					data >> proCode >> proName >> price >> dis;
				}
			}
			data.close();
		}
		cout << "******************************" << endl;
		cout << "Total Amount: " << total << endl;
	}
}




