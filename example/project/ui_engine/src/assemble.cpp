#include<ui_engine.h>
#include<assemble.h>
using namespace std;




Label::Label(string Tex, int x, int y) {
    text = Tex; loc.first = x; loc.second = y; color = white;
    this->show();
}
void Label::randColorShow(int p) {// 随机颜色 (霓虹灯效果)
    if(loop_cnt % p == 0) {
        color = rand() % 14 + 1;
        powerprint(text, loc.first, loc.second, color, -1);
    }
}
void Label::show() {// 简单输出
    powerprint(text, loc.first, loc.second, color, -1);
}
void Label::removeTo(int x, int y) {// 改变位置并输出
    for(int i = 0; i < text.size(); i++) powerprint(" ", loc.first + i, loc.second, white, -1);
    loc.first = x;
    loc.second = y;
    powerprint(text, loc.first, loc.second, color, -1);
}

Button::Button(string Tex, int x, int y) {
    text = Tex;
    loc.first = x; loc.second = y;
    color = white;
    on_color = yellow_l + blue * 16;
    this->show();
}

Button::Button(string Tex, int x, int y, void(*func)()) {
    text = Tex;
    loc.first = x; loc.second = y;
    color = white;
    on_color = yellow_l + blue * 16;
    Func = func;
    this->show();
}

Button::Button(string Tex, int x, int y, int xxl) {
    if(xxl == BACK) {
        Func = [](){Back();};
        if_back = 1;
    }
    text = Tex;
    loc.first = x; loc.second = y;
    color = white;
    on_color = yellow_l + blue * 16;
    this->show();
}

void Button::show() {
    if(if_on) {
        powerprint(text, loc.first, loc.second, on_color, -1);
    }
    else {
        powerprint(text, loc.first, loc.second, color, -1);
    }
    
}

void Button::click() {
    if_on = 1;
    if(if_back) {signal_will_stop = 1;}// 返回按钮回调优化 (当光标选中"返回"按钮时激活, 用于被触发时在快速停止监听线程)
}

void Button::release() {
    if_on = 0;
    if(if_back) {signal_will_stop = 0;}// 预告信号 重置
}

int Button::onClick() {
    return if_on;
}



