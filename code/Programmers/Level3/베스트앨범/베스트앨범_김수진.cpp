#include<bits/stdc++.h>

using namespace std;

bool sortValue(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}
bool sortPlay(pair<int,int>a, pair<int,int> b){
    return a.first> b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> album;
    vector<pair<string,int>> v;
    for(int i=0; i<genres.size();i++){
        if(album.count(genres[i])!=0){
            album[genres[i]]+=plays[i];
        }
        album.insert(make_pair(genres[i],plays[i]));
    }
    
    for (auto it = album.begin(); it!= album.end(); ++it){
        v.push_back(make_pair(it->first, it->second));
    }
		
    sort(v.begin(),v.end(),sortValue);

    for(auto i : v){
        vector<pair<int,int>> index;
        for(int idx=0; idx<genres.size(); idx++){
           if(i.first==genres[idx]){
            index.push_back(make_pair(plays[idx],idx));
            }  
        }
       sort(index.begin(),index.end(),sortPlay);   
       answer.push_back(index[0].second);
        if(index.size()>1){
            answer.push_back(index[1].second);
        }
    }
    
    return answer;
}