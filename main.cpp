#include<iostream>
#include<vector>
#include<fstream>
#include<queue>

#define INF 1000000

using namespace std;

vector <int> distance_count(vector <vector<int>> &edges, int start){
  vector<int> dist(edges.size(), INF);
  dist[start] = 0;
  queue <int> q;
  q.push(start);
  while(q.size()){
    int current = q.front();
    q.pop();
    for(long unsigned int i=0;i<edges[current].size();i++){
      if(dist[edges[current][i]] > dist[current] + 1){
        q.push(edges[current][i]);
        dist[edges[current][i]] = dist[current] + 1;
      }
    }
  }
  return dist;
}

int main()
{
  ifstream in("test1.txt"); //файл с графом
  int n;
  in>>n;
  int k;
  in>>k;
  vector <vector<int>> ed(n);
  for(int i=0;i<k;i++){
    int a, b;
    in>>a>>b;
    ed[a].push_back(b);
    ed[b].push_back(a);
  }
  int start;
  in>>start;
  ofstream out;
  out.open("result.txt"); //файл с резульататом
  vector<int> ans = distance_count(ed, start);
  for(auto i:ans)out<<i<<endl;
  in.close();
  out.close();
}
