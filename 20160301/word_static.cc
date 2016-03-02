 ///
 /// @file    word_static.cc
 /// @author  JinXin(xinge1231@qq.com)
 /// @date    2016-03-01 23:03:35
 ///
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class WordStatic
{
	public:
		int ReadFile(string filename);
		int WriteFile(string filename);
	private:
		vector<string> _words;//存储单词
		vector<int> _word_count;//存储词频
};

int WordStatic::ReadFile(string filename)//读取文件并统计词频
{
	ifstream ifs(filename);
	if(!ifs.good())
	{
		cout<<"open error."<<endl;
		return -1;
	}
	string s;
	int idx;
	while(ifs>>s)
	{
		for(idx=0;idx!=_words.size();++idx)
		{
			if(_words[idx]==s)
			{
				_word_count[idx]++;
				break;
			}
		}
		if(idx==_words.size())
		{
			_words.push_back(s);//添加新单词
			_word_count.push_back(1);//新单词次数置1
		}
	}
	return 0;
}

int WordStatic::WriteFile(string filename)//输出单词和词频
{
	ofstream ofs(filename);
	int idx;
	for(idx=0;idx!=_words.size();++idx)
	{
		ofs<<_words[idx]<<" "<<_word_count[idx]<<endl;
	}
	return 0;
}

int main()
{
	WordStatic word_static;
	string filename="The_Holy_Bible.txt";
	string dictionary="dictionary.txt";
	word_static.ReadFile(filename);
	word_static.WriteFile(dictionary);
	return 0;
}

