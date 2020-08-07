#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include<sstream>
using namespace std;
struct items{
	int itemId, basePrice, baseUnits, p1, u1, p2, u2, p3, u3, p4, u4, baseRevenuePerItem;
	int revenuePrice1,revenuePrice2,revenuePrice3,revenuePrice4;
	int hitPrice1,hitPrice2,hitPrice3,hitPrice4;
	int finalHit;
	int finalHitPrice;
	int k;
	string result;
};

bool comparetwoks(items a,items b)
{
	return a.k>b.k;
}

bool comparebyid(items a,items b)
{
	return a.itemId<b.itemId;
}

int smallest(int p1,int p2, int p3, int p4)
{
	int t1=min(p1,p2);
	int t2=min(p3,p4);
	if(t1<t2)
		return t1;
	else return t2;
}
int main(){
	ifstream item;
	item.open("dataset.csv");
	int baseUnitsSum=0,baseRevenuesum=0;
	float revenueGainAsk=10,quantityGainAsk=25;

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
	arr[0].k=0;
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
		arr[i].itemId=i;
		arr[i].k=arr[i].u4-arr[i].baseUnits;
		arr[i].result="Base_Price";
		arr[i].baseRevenuePerItem = arr[i].basePrice * arr[i].baseUnits;
		arr[i].revenuePrice1 = arr[i].p1 * arr[i].u1;
		arr[i].revenuePrice2 = arr[i].p2 * arr[i].u2;
		arr[i].revenuePrice3 = arr[i].p3 * arr[i].u3;
		arr[i].revenuePrice4 = arr[i].p4 * arr[i].u4;

		baseUnitsSum = baseUnitsSum + arr[i].baseUnits; 
		
		baseRevenuesum = baseRevenuesum + arr[i].baseRevenuePerItem;
		//cout<<arr[i].itemId<<" "<<arr[i].basePrice<<" "<<arr[i].baseUnits<<" "<<arr[i].p1<<" "<<arr[i].u1<<" "<<arr[i].p2<<" "<<arr[i].u2<<" "<<arr[i].p3<<" "<<arr[i].u3<<" "<<arr[i].p4<<" "<<arr[i].u4<<" "<<arr[i].u4-arr[i].baseUnits<<endl;
		//cout<<arr[i].basePrice*arr[i].baseUnits<<endl;
		i++;
		}
		revenueGainAsk=((float)revenueGainAsk/100)*baseRevenuesum;
		quantityGainAsk=((float)quantityGainAsk/100)*baseUnitsSum;
		sort(arr, arr+301, comparetwoks);
	//	cout<<baseUnitsSum<<" "<<baseRevenuesum<<" ";
		//for(i=0;i<301;i++)
		//cout<<arr[i].itemId<<" "<<arr[i].basePrice<<" "<<arr[i].baseUnits<<" "<<arr[i].p1<<" "<<arr[i].u1<<" "<<arr[i].p2<<" "<<arr[i].u2<<" "<<arr[i].p3<<" "<<arr[i].u3<<" "<<arr[i].p4<<" "<<arr[i].u4<<" "<<arr[i].k<<endl;
		//cout<<endl;
		i=1;
		while(i<301 && (revenueGainAsk>0 || quantityGainAsk>0))
		{
			int p1=arr[i].u1-arr[i].baseUnits;
			int p2=arr[i].u2-arr[i].u1;
			int p3=arr[i].u3-arr[i].u2;
			int p4=arr[i].u4-arr[i].u3;
			int d=smallest(p1,p2,p3,p4);
			int q;
			if(p1==d)
				{
					arr[i].result="Price1";
					revenueGainAsk=revenueGainAsk-(arr[i].revenuePrice1-arr[i].baseRevenuePerItem);
					quantityGainAsk=quantityGainAsk-(arr[i].u1-arr[i].baseUnits);
				}
			else if(p2==d)
				{
					arr[i].result="Price2";
					revenueGainAsk=revenueGainAsk-(arr[i].revenuePrice2-arr[i].baseRevenuePerItem);
					quantityGainAsk=quantityGainAsk-(arr[i].u2-arr[i].baseUnits);
				}
			else if(p3==d)
				{
					arr[i].result="Price3";
					revenueGainAsk=revenueGainAsk-(arr[i].revenuePrice3-arr[i].baseRevenuePerItem);
					quantityGainAsk=quantityGainAsk-(arr[i].u3-arr[i].baseUnits);
				}
			else if(p4==d)
				{
					arr[i].result="Price4";
					revenueGainAsk=revenueGainAsk-(arr[i].revenuePrice4-arr[i].baseRevenuePerItem);
					quantityGainAsk=quantityGainAsk-(arr[i].u4-arr[i].baseUnits);
				}
			i++;
		}
		sort(arr,arr+301,comparebyid);
		ofstream myresult;
		myresult.open("scenario1.csv");
		myresult<<"Item Id"<<","<<"Price"<<endl;
		for(i=1;i<301;i++)
		{
			myresult<<arr[i].itemId<<","<<arr[i].result<<endl;
			//cout<<arr[i].result<<" ";
		}
		//cout<<arr[i].itemId<<" "<<arr[i].basePrice<<" "<<arr[i].baseUnits<<" "<<arr[i].p1<<" "<<arr[i].u1<<" "<<arr[i].p2<<" "<<arr[i].u2<<" "<<arr[i].p3<<" "<<arr[i].u3<<" "<<arr[i].p4<<" "<<arr[i].u4<<" "<<arr[i].k<<endl;
		cout<<revenueGainAsk<<" "<<quantityGainAsk;
	//	cout<<revenueGainAsk;
	item.close();
}