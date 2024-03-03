#include<iostream>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin >> n;
		int max_num=0;
		int pre_data=-1;
		int temp_total=0;
		while(n--){

			int temp;
			cin>>temp;
			if(temp>pre_data){
				temp_total++;
				//cout<< temp_total;
			}
			
			else{
				
				if(temp_total>max_num){
					max_num=temp_total;
				}
				temp_total=1;
			}
			pre_data=temp;
		}
		if(temp_total>max_num){
					max_num=temp_total;
				}
		cout<<max_num<<'\n';
	}
} 
