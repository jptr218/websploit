#pragma once

#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

string exec(string cmd);
bool inTags(string s, string val, string tag = "ns", string endTag = "ns");
bool contains(string c, string ss);
bool between(int v, int m, int mm);

bool testConnect(string url);
string request(string url, string param, string val);

struct exploit
{
	string name;
	string toPass;
	string expected;
	string unexpected;
	string s_tag;
	string e_tag;
	string n_s_tag;
	string n_e_tag;
	string desc;

	exploit(string n, string tp, string e, string ue, string st, string et, string nst, string net, string d);
};

exploit vec_find(vector<exploit> vec, string n);

vector<exploit> initExploits();

bool testExploit(exploit e, string url, string param);