#include<ui_engine.h>
#include<interFace.h>
using namespace std;

vector<Person> member;

// 示例
// 第一个 界面 ( 欢迎界面 )
void Welcome() {

    INIT_NORMAL // 初始化 窗口  ( 不可省略 )
    SCENE_WITHOUT_BACK(// 初始化场景 
        auto title = new Label("大富翁银行系统", 23, 4);
        int bottom = 7;
        for(int i = 0; i < member.size(); i++) {
            auto new_member = new Label(member[i].getName(), 27, bottom, member[i].color);
            bottom += 2;
        }
        auto btn1 = new Button("添加成员", 26, bottom, [&](){
            // 请在这里编写按钮触发事件 (Enter 触发)
            if(member.size() == 6) {
                Error("已到达人数上限 !");
            }
            else {
                string input = get_user_name();
                if(input != "") {
                    member.push_back(Person{input});
                    // Error(input);
                }
            }
            

        });
        auto start = new Button("开始游戏", 48, 17, [&](){
            Game();
        });
        start->setColor(green_l, yellow_l + blue * 16);
        auto btn3 = new Button("退出", 50, 19, [](){
            exit(0);// 结束进程
        });
        btn3->setColor(gray, yellow_l + blue * 16);
        // 当前 场景 主循环 LOOP
        
        LOOP(
            // 按钮 监听 (如有按钮组件 则不可省略)
            
            // 调用组件方法
            LISTEN_BUTTON(btn1, btn3, start)
            
            
            
            title->randColorShow(500);
        )
    )
    return;
}