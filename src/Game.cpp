#include<ui_engine.h>
#include<interFace.h>
using namespace std;


// 示例
// 第一个 界面 ( 欢迎界面 )
void Game() {

    INIT_NORMAL // 初始化 窗口  ( 不可省略 )
    SCENE_WITHOUT_BACK(// 初始化场景 
        
        auto l1 = new Label("成员", 8, 3, gray);
        auto l2 = new Label("当前资产", 20, 3, gray);
        int bottom = 6;
        
        for(int i = 0; i < member.size(); i++) {
            auto new_member = new Button(member[i].getName(), 7, bottom, member[i].color, yellow_l + blue * 16, [&](){
                // Error(to_string(pointer));
                OP(pointer - 1);
            });
            auto l = new Label(to_string(member[i].getMoney()), 20, bottom, aqua);
            temp.push_back(new_member);
            bottom += 2;
        }
        auto btn1 = new Button("返回", 50, 19, [](){
            Back(1);// 结束进程
        });
        LOOP(
            LISTEN_BUTTON(btn1)
        )
        delete l1; delete l2;
    )
    return;
}