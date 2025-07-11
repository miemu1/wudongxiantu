#include <ansi.h>
inherit VRM_SERVER;

#define ENTER_ROOM_X  0
#define ENTER_ROOM_Y  0
#define ENTER_ROOM_Z  0

string *unique_rooms = ({
});

void create()
{
        //迷宫房间所继承的物件的档案名称。
        set_inherit_room( ROOM );

        //唯一房间
        set_unique_room( unique_rooms ); 

        //迷宫房间里的怪物。
        set_maze_npcs( ([
                "/d/maze/qnmj/npc/1": 5,
        ]) );

        //不算死亡
        //set_true_death_room(1);

        //迷宫的单边长
        set_maze_long(4);

        //入口方向(出口在对面)
        set_entry_dir("east");

        //入口与区域的连接方向
        set_link_entry_dir("east");

        //入口与区域的连接档案名
        set_link_entry_room(__DIR__"enter");

        //出口与区域的连接方向
        set_link_exit_dir("west");

        //出口与区域的连接档案名
        set_link_exit_room(__DIR__"out");

        //以下是入口坐标
        set_link_entry_room_x(ENTER_ROOM_X);
        set_link_entry_room_y(ENTER_ROOM_Y);
        set_link_entry_room_z(ENTER_ROOM_Z);

        //普通房间描述
        set_maze_room_short(HIG"初级潜能"NOR);

        set_maze_room_desc(@LONG
这里是初级潜能。
LONG);

        //入口房间短描述
        set_entry_short(HIR"初级潜能"NOR);

        //入口房间描述
        set_entry_desc(@LONG
这里是葵花仙宗。
LONG);

        //出口房间短描述
        set_exit_short(HIY"原始森林出口"NOR);

        //出口房间描述
        set_exit_desc(@LONG
这里是绝望之塔第一层空间.。
LONG);

        // 迷宫房间是否为户外房间？
        set_outdoors(1);

        // 迷宫房间是否刷新且刷新时间设置
        set_maze_refresh(3600);
}

string query_my_map(){  return read_file(__DIR__"maze.map");}

