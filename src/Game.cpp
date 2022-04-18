#include<ui_engine.h>
#include<interFace.h>
using namespace std;


// 示例
// 第一个 界面 ( 欢迎界面 )
void Game() {

    INIT_NORMAL // 初始化 窗口  ( 不可省略 )
    SCENE_WITHOUT_BACK(// 初始化场景 
        
        auto l1 = new Label("成员", 8, 2, gray);
        int bottom = 5;
        for(int i = 0; i < member.size(); i++) {
            auto new_member = new Label(member[i].getName(), 7, bottom, member[i].color);
            bottom += 2;
        }
        LOOP(
            // 按钮 监听 (如有按钮组件 则不可省略)
            
            // 调用组件方法
            LISTEN_BUTTON()
            
            
            
           
        )
    )
    return;
}