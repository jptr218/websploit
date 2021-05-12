#include "websploit.h"

bool testConnect(string url) {
    return (exec("curl -s " + url) != "");
}

string request(string url, string param, string val) {
    return exec("curl -s -d " + param + "=\"" + val + "\" -X POST " + url);
}