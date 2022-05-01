#ifndef CONFIG_H
#define CONFIG_H

//游戏
#define GAME_WIDTH  1648    //宽度
#define GAME_HEIGHT  1027    //高度
#define GAME_TITLE "Global War of Crafts 1.0"   //标题
#define GAME_ICON ":/scene/resources/restart_nanie.PNG" //图标加载路径
#define GAME_RATE 10 //定时器刷新时间间隔10ms

//bgm
#define SOUND_BACKGROUND ":/scene/resources/bgm2.wav"
#define SOUND_BOMB ":/scene/resources/bomb2.wav"

//地图
#define MAP_PATH ":/scene/resources/background2(1).jpg"   //背景
#define MAP_SCOLL_SPEED 2 //背景地图滚动速度


//飞行器
#define UFO_PATH ":/scene/resources/ren(1)(1)(1).png"

//子弹
#define BULLET_PATH ":/scene/resources/bullet(1)(1).png"
#define BULLET_SPEED 5
#define BULLET_NUM 50   //总数
#define BULLET_INTERVAL 20  //时间间隔

//英雄守护者1
#define GUARDIAN_PATH ":/scene/resources/guardian-1.png"
#define GUARDIAN_SPEED 3
#define GUARDIAN_NUM 5     //总数
#define GUARDIAN_INTERVAL 100    //时间间隔

//爆炸
#define BOMB_PATH ":/scene/resources/bomb-%1.png"
#define BOMB_NUM 20         //爆炸数量
#define BOMB_MAX 7
#define BOMB_INTERVAL 20    //时间间隔



#endif // CONFIG_H
