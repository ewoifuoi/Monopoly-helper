#include<ui_engine.h>
#include<interFace.h>
using namespace std;



void Transfer(int line) {

    INIT_NORMAL // 初始化 窗口  ( 不可省略 )
    SCENE_INSIDE(// 初始化场景 
        int bottom = line * 2 + 6 + 1;
        for(int i = 0; i < member.size(); i++) {
            if(i == line) continue;

            auto new_btn = new Button(member[i].getName(), 44, bottom, member[i].color, yellow_l + blue * 16, [&](){
                stringstream ss = message("转账金额 : ");
                double val = 0;
                ss >> val;
                if(member[line].giveTo(member[pointer], val) == -1) {
                    Error("余额不足, 转账失败 !");
                }
                
                Back(1);
            });
            temp.push_back(new_btn);
            bottom++;
        }
        
        auto b = new Button("取消", 44, bottom, gray, yellow_l + blue * 16, [&](){
            Back(1);
        });
        
        LOOP(
            LISTEN_BUTTON(b);
        )
    )
    return;
}