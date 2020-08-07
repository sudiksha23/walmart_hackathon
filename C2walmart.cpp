#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include<sstream>
using namespace std;
struct items{
	int itemId, basePrice, baseUnits, p1, u1, p2, u2, p3, u3, p4, u4;
};
int main(){
	ifstream item;
	item.open("dataset.csv");

	if(!item.is_open())
		cout<<"not opened"<<endl;
	string item_id, base_price, base_units, price1, unit1, price2, unit2, price3, unit3, price4, unit4;
	items arr[301];
	int i=1;
	getline(item, item_id, ',');
	getline(item, base_price, ',');
	getline(item, base_units, ',');
	getline(item, price1, ',');
	getline(item, unit1, ',');
	getline(item, price2, ',');
	getline(item, unit2, ',');
	getline(item, price3, ',');
	getline(item, unit3, ',');
	getline(item, price4, ',');
	getline(item, unit4, ',');
	while(item.good()){
		//getline(item, item_id, ',');
		getline(item, base_price, ',');
		getline(item, base_units, ',');
		getline(item, price1, ',');
		getline(item, unit1, ',');
		getline(item, price2, ',');
		getline(item, unit2, ',');
		getline(item, price3, ',');
		getline(item, unit3, ',');
		getline(item, price4, ',');
		getline(item, unit4, ',');

		// stringstream geek(item_id);
		// geek>>arr[i].itemId;

		stringstream geek1(base_price);
		geek1>>arr[i].basePrice;

		stringstream geek2(base_units);
		geek2>>arr[i].baseUnits;

		stringstream geek3(price1);
		geek3>>arr[i].p1;

		stringstream geek4(unit1);
		geek4>>arr[i].u1;
		
		stringstream geek5(price2);
		geek5>>arr[i].p2;
		
		stringstream geek6(unit2);
		geek6>>arr[i].u2;
		
		stringstream geek7(price3);
		geek7>>arr[i].p3;
		
		stringstream geek8(unit3);
		geek8>>arr[i].u3;
		
		stringstream geek9(price4);
		geek9>>arr[i].p4;
		
		stringstream geek10(unit4);
		geek10>>arr[i].u4;
		//cout<<arr[i].itemId<<endl;
		cout<<arr[i].basePrice<<" "<<arr[i].baseUnits<<" "<<arr[i].p1<<" "<<arr[i].u1<<" "<<arr[i].p2<<" "<<arr[i].u2<<" "<<arr[i].p3<<" "<<arr[i].u3<<" "<<arr[i].p4<<" "<<arr[i].u4<<endl;
		cout<<arr[i].basePrice*arr[i].baseUnits<<endl;
		i++;
		}
	item.close();
}