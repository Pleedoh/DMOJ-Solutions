#include <bits/stdc++.h>
#define s(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
using namespace std;
void add(string num1,string num2,bool makeNegative){
	string sum = "";
	//deal with two negatives
	if(makeNegative){
	 num1 = num1.substr(1,num1.length()-1);
	 num2 = num2.substr(1,num2.length()-1);
	}
	if (num1.length() > num2.length()) swap(num1, num2);

	int len1 = num1.length(),len2 = num2.length();//num 2 is longer
	int diff = len2- len1;//to make sure digits are alligned when adding
	short carry = 0;
	short tempSum = 0;
	//descend because ones place is farthest back in the string
    for (int i=len1-1; i>=0; i--){//hand addition
    	tempSum = num1[i] + num2[i+diff] + carry - 96;
        sum.push_back(tempSum%10 + 48);
        carry = tempSum/10;
    }
    for (int i=diff-1; i>=0; i--){//carry thru
           	tempSum = (num2[i]-48+carry);
            sum.push_back(tempSum%10 + 48);
            carry = tempSum/10;
    }
    if(carry) sum.push_back(carry + 48);//add final carry
    reverse(sum.begin(),sum.end());
    if(makeNegative) cout<<'-';
    cout<<sum<<"\n";
}
/*SUBTRACTION FUNCTION NEEDS WORK*/
void subtract(string num1,string num2){
	string sum = "";
	bool makeNegative = false;
	short neg;

	if(num1[0] == '-'){
		num1 = num1.substr(1,num1.length()-1);
		neg = 1;
	}
	else{
		num2 = num2.substr(1,num2.length()-1);
		neg = 2;
	}

	if(num1.length() > num2.length()){
		swap(num1,num2);//big on top
		if(neg == 1) neg = 2;
		else neg = 1;
	}
	//equal length
	if(num1.length() == num2.length()){//find the bigger number
		for(int i =0; i < num1.length();i++){
			if(num1[i] > num2[i]){//1 is bigger
				swap(num1,num2);//2 will always be bigger,bigger on top
				if(neg == 1) makeNegative = true;
				break;
			}
			if(num1[i] < num2[i]){//2 is bigger
				if(neg == 2) makeNegative = true;
				break;
			}
		}
	}
	//'0' = 48, add to turn into char, sub to use int
	else if(neg == 2) makeNegative = true;
	int len1 = num1.length(),len2 = num2.length();//num2 is longer
		int diff = len2-len1;//to make sure digits are alligned
		short tempSum = 0;
	    for (int i=len1-1; i>=0; i--){//hand subtraction
	    	tempSum = num2[i+diff] - num1[i];
	    	if(tempSum >= 0) sum.push_back(tempSum + 48);
	    	else{
	    		for(int j = i-1; j+diff >= 0; j--){
	    			if(num2[j+diff] > 48){
	    				num2[j+diff]--;
	    				break;
	    			}
	    			else num2[j+diff] = 57;
	    		}
	    		tempSum += 10;
	    		sum.push_back(tempSum + 48);
	    	}
	    }
	    for (int i=diff-1; i>=0; i--){//carry thru
	           if(num2[i] > 48) sum.push_back(num2[i]);
	    }
	    reverse(sum.begin(),sum.end());
	    if(sum.length() > 1){
			int cut = 0;
			for(int i = 0; i < sum.length();i++){
				if(sum[i] <= 48) cut++;
				else break;
			}
			sum = sum.substr(cut);
	    }

	    if(makeNegative) cout<<'-';
	    cout<<sum<<"\n";
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	string num1,num2;//num 2 being greater
	while(n--){
		cin>>num1>>num2;
		if(num1[0] =='-' || num2[0] == '-'){
			if(num1[0] == '-' && num2[0] == '-') add(num1,num2,true);
			else subtract(num1,num2);
		}
		else{
			add(num1,num2,false);
		}
	}
    return 0;
}