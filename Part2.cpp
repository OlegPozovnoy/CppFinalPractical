// Part2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

class Point{
public:
	int X=0;
	int Y=0;
};

// required by set
bool operator<(const Point& lh, const Point& rh) {
	return lh.X < rh.X ? true : lh.Y<rh.Y;
}

void importer(set<Point>& values);

int main() {

	int pick;
	set<Point> data;

	cout << "\nWelcome, \n\nPlease select from: ";

	do {
		cout << "\n\n(1). Load Points Data";
		cout << "\n(2). Display unique points";
		cout << "\n(3). Exit";
		cout << "\n\nYour choice:";

		cin >> pick;

		switch (pick) {
		case 1:
			importer(data);
			cout<<"\nData loaded";
			break;
		case 2: {
			int counter = 1;
			for (auto i = data.begin(); i != data.end(); i++) {
				cout << "\nPoint " << counter++ << ": " << (*i).X << "," << (*i).Y;
			}
		}
			break;
		case 3:
			return 0;
		default:
			cout << "\nWrong input, please try again";
		}
	} while (true);

}


//import the data
void importer(set<Point>& values) {

	//string path;
	//cout << "Please enter the file path: ";
	//cin >> path;

	//ifstream in(path);
	ifstream in(string("data.txt"));//hardcoded filename
	if (in.fail())
	{
		cout << "File open error";
		return;
	}

	Point next;
	while (!in.eof()) {
		int stringnum;
		in >> stringnum; // gettign stringnum - not used
		
		if (!in.good()) {
			cout << "Wrong data format at the line, labeled as " << stringnum << ", the rest of the import will be skipped.";
			return;
		}
		if (in.peek() != ',')//checking file format
		{
			cout << "\nExpected ',', found " << in.peek();
		}

		in.ignore(1);
		in >> next.X;
		if (!in.good()) {
			cout << "Wrong data format at the line, labeled as " << stringnum << ", the rest of the import will be skipped.";
			return;
		}
		if (in.peek() != ',')//checking file format
		{
			cout << "\nExpected ',', found " << in.peek();
		}
		in.ignore(1);
		in >> next.Y;
		if (!in.good()) {
			cout << "Wrong data format at the line, labeled as "<< stringnum<<", the rest of the import will be skipped.";
			return;
		}
		values.insert(next);
	}
	in.close();
}
