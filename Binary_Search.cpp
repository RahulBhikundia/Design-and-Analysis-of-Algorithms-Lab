#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int binarySearch(vector<int>& v, int first, int last, int ele)
{
    if(first>last) return -1;

    int mid = (first + last)/ 2;
    if(ele == v[mid]) return mid;
    else if(ele < v[mid]) return binarySearch(v,first,mid-1,ele);
    else return binarySearch(v,mid+1,last,ele);
}

int main()
{
    vector<int> v;
    string line;
    ifstream fin;

    fin.open("D:\\Before Code Forces\\Design-and-Analysis-of-Algorithms-Lab\\digit.txt");

    while (getline(fin, line))
    {
        if (!line.empty())
        {
            v.push_back(stoi(line));
        }
    }

    // Close the file
    fin.close();

    sort(v.begin(), v.end());

    cout << "The Numbers in file are:";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    int num,index;
    cout<<"Enter the number to be searched for:";
    cin>>num;
    index = binarySearch(v,0,9,num);
    if(index == -1) cout<<"Number not found";
    else cout<<num<<" found at position "<<index+1;
    return 0;
}