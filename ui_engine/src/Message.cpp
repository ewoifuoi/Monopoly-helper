#include<ui_engine.h>
#include<interFace.h>

using namespace std;

// 表单窗口 ( 获取信息 )
stringstream message(string text) {
    stringstream input;
    vector<Button*> temp;
	int pointer = 0;
    temp.clear();
	pointer = 0;
    make_boundary(13,5, 50, 18,  LINE);
    for(int i = 14; i <= 49; i++) {
        for(int j = 6; j <= 17; j++) {
            powerprint(" ", i, j, white, -1);
        }
    }
    auto txt = new Label(text, 18, 10, yellow_l);
    auto btn = new Button("确定", 27, 14, [&](){
        Back(1);
    });
    auto btn2 = new Button("取消", 35, 14, [&](){
        input << "";
        Back(1);
    });
    set_console_color(aqua);
    show_cursor();
    goto_xy(32, 10);
    string tem;
    cin >> tem;
    input << tem;
    HideCursor();
    LOOP(
        LISTEN_BUTTON(btn, btn2)
    )
    delete txt;delete btn;delete btn2;
    if(back) back = 0;
    return input;
}