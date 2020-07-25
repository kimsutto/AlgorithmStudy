#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


int getParent(int parent[], int x){
  if(parent[x]==x) return x;
  return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b){
  a = getParent(parent, a);
  b = getParent(parent, b);
  if(a < b) parent[b]=a;
  else parent[a] = b;
}

int countGroups(vector<string> related) {
  int parent[301];
  int size = related.size();
  
  for(int i=0; i<size ; i++){
    parent[i] = i;
  }

  for(int i=0; i<size; i++){
    for(int j=0; j<size; j++){
      if(i!=j && (related[i][j]-'0'==1)){
        unionParent(parent, i, j);
      }
    }
  }

  set<int> s;
  for(int i=0; i<size; i++){
    s.insert(getParent(parent,i));
  }
  return s.size();
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string related_count_temp;
  getline(cin, related_count_temp);
  
  int related_count = stoi(ltrim(rtrim(related_count_temp)));
  
  vector<string> related(related_count);

  for (int i = 0; i < related_count; i++) {
    string related_item;
    getline(cin, related_item);
    related[i] = related_item;
  }

  int result = countGroups(related);
  
  fout << result << "\n";
  fout.close();

  return 0;
}

string ltrim(const string &str) {
  string s(str);
  s.erase(
    s.begin(),
    find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
  );
  return s;
}

string rtrim(const string &str) {
  string s(str);
  s.erase(
    find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
    s.end()
  );
  return s;
}

