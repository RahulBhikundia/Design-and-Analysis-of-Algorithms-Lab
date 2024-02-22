#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int a;

    for (int i=0;i<10;i++)
    {
        v.push_back(rand()%10);
    }

    cout<<"The random Numbers are:";
    for(int i=0; i<10;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    cout<<"Enter Number to find:";
    cin>>a;

    int flag = 0,i;
    for(i=0;i<10;i++){
        if(a==v[i]){
            flag = 1;
            break;
        }
    }

    if(flag) cout<<a<<" Found at position "<<i+1;
    else cout<<a<<" not found in the given list";
}