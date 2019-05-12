#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include "11021.h"
#include <stdio.h>

void RleCodec::encode()
{
    std::stringstream os;
    char str1;
    char str2;
    char num;
    int cnt=0;
    for(auto c:code_str){
        if(cnt==0){
            str1=c;
            cnt=1;
        }
        else if(c==str1){
            cnt++;
        }
        else{
            while(cnt>=26){
                os << 'Q'<<'Z'<< str1;
                cnt-=26;
            }
            if(cnt>0){
                num=65+cnt-1;
                os <<'Q'<< num <<str1;
            }
            cnt=1;
            str1=c;
        }
    }
    while(cnt>=26){
        os << 'Q'<<'Z'<< str1;
        cnt-=26;
    }
    if(cnt>0){
        num=65+cnt-1;
        os <<'Q'<<num << str1;
    }
    code_str = os.str();
    encoded=true;
}

void RleCodec::decode()
{
	std::stringstream os;
	std::string int_str;
	char q = 'A';
	char number = ' ';
	int cnt = 0;
	for (auto c : code_str) {
        if (q=='A') {
            q = c;
		}else if(number == ' '){
            number = c;
		}
        else {
            int_str.push_back(c);
			int cnt = 0;
            cnt = number - 'A' +1;
            for (int i=0; i<cnt; ++i)
					os << c;
			int_str.clear();
			number = ' ';
			q = 'A';
		}
	}

	code_str = os.str();
	encoded = false;
}
