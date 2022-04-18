#include<ui_engine.h>
#include<interFace.h>
using namespace std;



void OP(int line) {

    INIT_NORMAL // 初始化 窗口  ( 不可省略 )
    SCENE_INSIDE(// 初始化场景 
        
        auto add = new Button("+", 36, line * 2 + 6, red, yellow_l + blue * 16, [&](){
            stringstream temp = message("增加金额 : ");
            double val = 0;
            temp >> val;
            if(val != -1)member[line].add(val);
            Back(1);
        });
        auto dec = new Button("-", 40, line * 2 + 6, blue, yellow_l + blue * 16, [&](){
            stringstream temp = message("减少金额 : ");
            double val = 0;
            temp >> val;
            if(val != -1)member[line].dec(val);
            Back(1);
        });
        auto transfer = new Button("转账", 44, line * 2 + 6, yellow, yellow_l + blue * 16, [&](){
            Transfer(line);
            Back(1);
        });
        auto b = new Button("取消", 50, line * 2 + 6, yellow, yellow_l + blue * 16, [&](){
            Back(1);
        });
        
        LOOP(
            LISTEN_BUTTON(add, dec, transfer, b);
        )
    )
    return;
}