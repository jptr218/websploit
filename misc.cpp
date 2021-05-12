#include "websploit.h"

string exec(string cmd) {
    FILE* pipe = _popen(cmd.c_str(), "r");
    if (!pipe) {
        return "";
    }
    string result;
    char buff[128];
    while (!feof(pipe)) {
        while (fgets(buff, 128, pipe) != NULL) {
            result += buff;
        }
    }
    return result;
}

bool inTags(string s, string val, string tag, string endTag) {
    if (val == "ns") {
        return false;
    }else if(endTag == "ns") {
        return contains(s, val);
    }

    int s_tag_pos = 0;
    int e_tag_pos = 0;

    string tmp = "";
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        tmp += c;
        if ((c == '>' || c == '<') && tmp.length() > 1) {
            if (tmp == tag) {
                s_tag_pos = i;
            }
            else if (tmp == endTag) {
                e_tag_pos = i;
            }
            tmp = "";
            i--;
        }
    }
    
    if (s_tag_pos == 0) {
        return 0;
    }
    else if (e_tag_pos == 0 && contains(s, val)) {
        return between(s.find(val), s_tag_pos, s.find(val));
    }
    else if (contains(s, val)) {
        return between(s.find(val), s_tag_pos, e_tag_pos);
    }

    return false;
}

exploit vec_find(vector<exploit> vec, string n) {
    for (exploit e : vec) {
        if (e.name == n) {
            return e;
        }
    }
    return exploit("ns", "ns", "ns", "ns", "ns", "ns", "ns", "ns", "ns");
}

bool contains(string c, string ss) {
	return (c.find(ss) != string::npos);
}

bool between(int v, int mm, int m) {
    return (v <= m && v >= mm);
}