#pragma once

#ifndef LISTEN_BUTTON

#define LISTEN_BUTTON(...) vector<Button* > list = {__VA_ARGS__};\
for(int i = 0; i < temp.size(); i++) {\
    list.push_back(temp[i]);\
}\
temp.clear();\
if(!list.empty()) {\
    int list_cnt = list.size();\
    if(Key[1] || Key[3]) {list[pointer]->release();pointer += list_cnt; pointer--; pointer %= list_cnt;}\
    if(Key[2] || Key[4]) {list[pointer]->release();pointer += list_cnt; pointer++; pointer %= list_cnt;}\
    memset(Key, 0, sizeof(Key));\
    list[pointer]->click();\
    for(int i = 0; i < list_cnt; i++) {\
        list[i]->show();\
    }\
    if(ENTER) {\
        list[pointer]->Func();\
        exit(0);\
    }\
}\




#endif