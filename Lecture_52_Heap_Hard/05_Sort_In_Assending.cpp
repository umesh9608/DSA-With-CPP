// shorting in asending order
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool sortbysec(pair<int, int> a, pair<int, int> b)
{
  // return a.second < b.second;
  return a.second < b.second || (a.second==b.second&&a.first<b.first);

}

int main()
{
  vector<pair<int, int>> v;

  v.push_back(make_pair(10, 20));
  v.push_back(make_pair(7, 8));
  v.push_back(make_pair(4, 9));
  v.push_back(make_pair(4, 7));
  v.push_back(make_pair(9, 15));

  sort(v.begin(), v.end(), sortbysec);

  for (int i = 0; i < 5; i++)
    cout << v[i].first << " " << v[i].second << endl;

  return 0;
}