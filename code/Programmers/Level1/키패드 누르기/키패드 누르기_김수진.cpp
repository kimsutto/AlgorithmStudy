#include <bits/stdc++.h>

//나중에 간결하게 수정하기... .... 

using namespace std;

vector<pair<int,int>> keypad;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    keypad.push_back(make_pair(3,1)); //0
    keypad.push_back(make_pair(0,0));
    keypad.push_back(make_pair(0,1));
    keypad.push_back(make_pair(0,2));
    keypad.push_back(make_pair(1,0));
    keypad.push_back(make_pair(1,1));
    keypad.push_back(make_pair(1,2));
    keypad.push_back(make_pair(2,0));
    keypad.push_back(make_pair(2,1));
    keypad.push_back(make_pair(2,2));
    
    pair<int,int> left = make_pair(3,0);
    pair<int,int> right = make_pair(3,2); 
    
    for(int i=0; i<numbers.size(); i++){
        int x = numbers[i];
        if(x%3==1){
            answer+="L";
            left = make_pair(keypad[x].first,keypad[x].second);
        }else if(x%3==0&&x!=0){
            answer+= "R";
            right = make_pair(keypad[x].first,keypad[x].second);
        }else{
            int leftDiff = abs(left.first-keypad[x].first) + abs(left.second-keypad[x].second);
            int rightDiff = abs(right.first-keypad[x].first) + abs(right.second-keypad[x].second);
        
            if(leftDiff>rightDiff){
                answer+= "R";
                right = make_pair(keypad[x].first,keypad[x].second);
            }else if(leftDiff<rightDiff){
                answer+= "L";
                left = make_pair(keypad[x].first,keypad[x].second);
            }else {
                if(hand=="right"){
                    answer+= "R";
                    right = make_pair(keypad[x].first,keypad[x].second); 
                }else{
                    answer+= "L";
                    left = make_pair(keypad[x].first,keypad[x].second); 
                }
            }
        }
        
    }
    return answer;
}
