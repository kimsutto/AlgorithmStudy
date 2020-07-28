#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int Li=3, Lj=0;
    int Ri=3, Rj=2;
    int Ld =0;
    int Rd = 0;
    
    for(int i=0; i<numbers.size(); i++){
        if(numbers[i]%3==1){
            answer += 'L';
            Li = numbers[i]/3;
            Lj = 0;
        } else if(numbers[i]%3==0 && numbers[i]!=0){
            answer += 'R';
            Ri = numbers[i]/3-1;
            Rj = 2;
        } else if(numbers[i]%3==2){
            Ld = abs(Li-numbers[i]/3) + abs(Lj-1);
            Rd = abs(Ri-numbers[i]/3) + abs(Rj-1);
            
            if(Ld<Rd){
                answer+='L';
                Li = numbers[i]/3;
                Lj = 1;
            } else if(Rd<Ld){
                answer+='R';
                Ri = numbers[i]/3;
                Rj = 1;
            } else{
                if(hand == "left"){
                    answer+='L';
                    Li = numbers[i]/3;
                    Lj = 1;
                } else{
                    answer+='R';
                    Ri = numbers[i]/3;
                    Rj = 1;
                }
            }
        }else {
            Ld = abs(Li-3) + abs(Lj-1);
            Rd = abs(Ri-3) + abs(Rj-1);
            if(Ld<Rd){
                answer+='L';
                Li = 3;
                Lj = 1;
            } else if(Rd<Ld){
                answer+='R';
                Ri = 3;
                Rj = 1;
            } else{
                if(hand == "left"){
                    answer+='L';
                    Li = 3;
                    Lj = 1;
                }
                else{
                    answer+='R';
                    Ri = 3;
                    Rj = 1;
                }
            }
            
        }
    }
    
    
    return answer;
}
