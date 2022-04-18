#include<ui_engine.h>
#include<interFace.h>
using namespace std;



int del() {

    INIT_NORMAL // 初始化 窗口  ( 不可省略 )
    SCENE_INSIDE(// 初始化场景 
        for(int i = 0; i < member.size(); i++) {
            auto b = new Button ("[删除]", 40, i * 2 + 7, green, white_b + red_l * 16, [&](){
                member.erase(member.begin() + pointer - 1);
                Back(1);
            });
            temp.push_back(b);
        }
        auto b = new Button("[返回]",40, member.size() * 2 + 7, gray, white_b + aqua_l * 16, [](){
            Back(1);
        });
        
        LOOP(
            LISTEN_BUTTON(b);
        )
    )
    return 0;
}