#pragma once

#ifndef SCENE
#include<ui_engine.h>
#define SCENE(TEXT) \
powerprint("Powered by cmd-UI-Engine", 90, 50, gray, -1);\
while(1) {\
    temp.clear();\
    system("CLS");\
	pointer = 0;\
    make_boundary(1, 1, 59,22,LINE);\
    auto btn_back = new Button("返回", 50, 20, BACK);\
    temp.push_back(btn_back);btn_back->show();\
    TEXT\
    if(back) {\
        back = 0;\
        break;\
    }\
}\

#define SCENE_WITHOUT_BACK(TEXT) \
while(1) {\
    temp.clear();\
    system("CLS");\
    powerprint("Powered by cmd-UI-Engine", 18, 23, gray, -1);\
	pointer = 0;\
    make_boundary(1, 1, 59,22,LINE);\
    TEXT\
    if(back) {\
        back--;\
        break;\
    }\
}\

#define SCENE_INSIDE(TEXT) \
while(1) {\
    temp.clear();\
	pointer = 0;\
    make_boundary(1, 1, 59,22,LINE);\
    TEXT\
    if(back) {\
        back--;\
        break;\
    }\
}\

void Error(string text);


#endif