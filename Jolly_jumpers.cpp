//使用Java的考生請注意，最外層的類別(class)需命名為 main 。
//如果遇到超乎想像的狀況，請更改編譯器試看看!! 各編譯器特性不同!!
//預設測資、隨機測資、固定測資是用來幫助除錯用的。批改時，只看暗中測資是否通過!!

#include <iostream>
using namespace std;
int main(void){
	int n;
	int* inputArray;
	bool* first;
	int diff;
	bool result=true;
	while(cin >> n){
		// cout << n << endl;
		inputArray =new int[n];
		first =new bool [n];
	
		for (int i=0;i<n;i++){
			first[i]=false;
			cin >> inputArray[i]; 
		}
	
		for (int i=1;i<n;i++){
			 diff = inputArray[i] - inputArray[i-1];
			 if(diff < 0)diff *= -1;
			 if(diff==0 | diff > n-1 )result=false;
			 else if(first[diff]==false){
			 	first[diff]=true;
			 }
			 else{
			 	result=false;
			 }
		}
		
		delete [] inputArray;
		delete [] first;
			if(result==true)cout << "Jolly" << endl;
	else{
		cout << "Not jolly" << endl;
	}
	result = true;
	}

}	
			 	
