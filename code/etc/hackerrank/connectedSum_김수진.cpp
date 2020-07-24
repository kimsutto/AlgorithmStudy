#include <bits/stdc++.h>

using namespace std;


string ltrim(const string &);
string rtrim(const string &);


vector<int> node[100001];
bool visited[100001];
bool check[100001];


int bfs(int start){
  queue<int> q;
  q.push(start);
  int m = 1;
  while(!q.empty()){
     int x = q.front();
     visited[x] = true;
     check[x] = true;
     q.pop();
     for (int i = 0; i < node[x].size(); i++) {
        int y = node[x][i];
        if (visited[y] == false) {
          q.push(y);
          m++;
          visited[y] = true;
          check[y] = true;
        }
      }
  } 
  return m;
}

int connectedSum(int n, vector<string> edges) {
  int sum = 0;
  for(int i = 0; i<edges.size(); i++){
    stringstream ss(edges[i]);
    string num[2];
    string str;
    int j = 0;
    while(ss>>str){
      num[j++] = str;
    }
    j=0;
    node[stoi(num[0])].push_back(stoi(num[1]));
    node[stoi(num[1])].push_back(stoi(num[0]));
  }

  for(int i=1; i<=n; i++){
    if(!(check[i])){
      int h = bfs(i);
      cout << h;
      sum += ceil(sqrt(h));
    }
  }
  return sum; 
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));
  string n_temp;
  getline(cin, n_temp);
  
  int n = stoi(ltrim(rtrim(n_temp)));

  string edges_count_temp;
  getline(cin, edges_count_temp);
  int edges_count = stoi(ltrim(rtrim(edges_count_temp)));
  vector<string> edges(edges_count);

  for (int i = 0; i < edges_count; i++) {
     string edges_item;
     getline(cin, edges_item);
     edges[i] = edges_item;
  }
  int result = connectedSum(n, edges);

  fout << result << "\n";

  fout.close();

  return 0;

}



string ltrim(const string &str) {
  string s(str);
  s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
  return s;
}



string rtrim(const string &str) {
  string s(str);
  s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),s.end());
  return s;
}
