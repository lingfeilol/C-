#include<iostream>
using namespace std;

#include<string>


int main()
{
    string s;
    getline(cin,s);
    size_t pos=s.rfind(' '); //找到最后一个单词的前一个空格索引
    cout<<s.size()-pos-1<<endl; //总长度减去 这个索引加一的长度
}