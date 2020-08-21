#include <bits/stdc++.h>

using namespace std;

long long calculation(long long a, long long b, char op) { 
        if (op == '+') { 
            return a + b; 
        } else if (op == '-') { 
            return a - b; 
        } else{ 
            return a * b; 
        }
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> num;
    vector<char> op;
    string n;
    int nn=0;
    
    for(int i=0; i<expression.size(); i++){
        if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*'){
            op.push_back(expression[i]);
            num.push_back(stoi(n));
            nn++;
            n = "";
        }else{
            n += expression[i];
        }
    }
    num.push_back(stoi(n));
    
    
    vector<char> op_ = {'+', '-', '*'};
    sort(op_.begin(),op_.end());
    
    do{
            vector<char> op2;
            op2.assign(op.begin(), op.end());
            vector<long long> num2;
            num2.assign(num.begin(), num.end());
        
        for(int j=0; j<3; j++){
            int i = 0;
            while(i<op2.size()){
                if(op2[i]==op_[j]){
                    long long j = calculation(num2[i],num2[i+1],op2[i]);
                    num2[i]=j; 
                    num2.erase(num2.begin()+i+1);
                    op2.erase(op2.begin()+i);
                }else{
                    i++;
                }
            }
        }    
        if(abs(num2[0]) > answer){
                answer = abs(num2[0]);
        }
    }while(next_permutation(op_.begin(), op_.end()));
    
    return answer;
}
