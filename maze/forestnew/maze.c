#include <ansi.h>
inherit "/adm/daemons/vrm_server2.c";
 
#define ENTER_ROOM_X  0
#define ENTER_ROOM_Y  0
#define ENTER_ROOM_Z  0

string *unique_rooms = ({
        "/maze/forestnew/unique_room/snakehole",
        "/maze/forestnew/unique_room/bearlair",
        "/maze/forestnew/unique_room/wolfcave",
        "/maze/forestnew/unique_room/tigerhill",
        "/maze/forestnew/unique_room/dragonland",
});

void create() 
{ 
        //迷宫房间所继承的物件的档案名称。 
        set_inherit_room( ROOM ); 
                        
        //唯一房间
        set_unique_room( unique_rooms ); 

        //迷宫房间里的怪物。 
        set_maze_npcs( ([
                /*
                "/maze/forestnew/npc/toad": !random(5), 
                ""/maze/forestnew/npc/rabbit": !random(5),  
                "/maze/forestnew/npc/wolf_baby": !random(5), 
                "/maze/forestnew/wolf_big": !random(5), 
                "/"/maze/forestnew/npc/snake_baby": !random(5), 
                "/maze/forestnew/npc/snake_big": !random(5), 
                "/maze/forestnew/npc/tiger_baby": !random(5), 
                "/maze/forestnew/npc/tiger_big": !random(5), 
                "/maze/forestnew/npc/bear_baby": !random(5), 
                "/maze/forestnew/npc/bear_big": !random(5), 
                "/maze/forestnew/npc/dragon_baby": !random(10), 
                */
                "/maze/forestnew/npc/tiger_king": !random(5), 
                "/maze/forestnew/npc/wolf_king": !random(5), 
                "/maze/forestnew/npc/bear_king": 1, 
                "/maze/forestnew/npc/snake_king": !random(5), 
        ]) );                   

        set_lonely_create(1);

        //迷宫的单边长 
        set_maze_long(8); 
        
        //不算死亡
        set_maze_nodeath(1);
                        
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
        set_maze_room_short(HIG"原始森林"NOR);
                        
        set_maze_room_desc(@LONG
原始森林树叶苍黑如盖，遮天蔽日，林中弥漫着枯叶腐烂
和树脂混合的味道，地上的苔鲜落叶踩上去软绵绵的，上面还
布满野兽的痕迹，四周浓密的山雾，让人难以分辨方向。
LONG); 

        //入口房间短描述 
        set_entry_short(HIR"原始森林入口"NOR); 
                        
        //入口房间描述 
        set_entry_desc(@LONG
原始森林树叶苍黑如盖，遮天蔽日，林中弥漫着枯叶腐烂
和树脂混合的味道，地上的苔鲜落叶踩上去软绵绵的，上面还
布满野兽的痕迹，四周浓密的山雾，让人难以分辨方向。
LONG);
                        
        //出口房间短描述 
        set_exit_short(HIY"原始森林出口"NOR); 
                        
        //出口房间描述 
        set_exit_desc(@LONG
原始森林树叶苍黑如盖，遮天蔽日，林中弥漫着枯叶腐烂
和树脂混合的味道，地上的苔鲜落叶踩上去软绵绵的，上面还
布满野兽的痕迹，四周浓密的山雾，让人难以分辨方向。
LONG);

        // 迷宫房间是否为户外房间？ 
        set_outdoors(1);                                                

        // 迷宫房间是否刷新且刷新时间设置
        //set_maze_refresh(180);
        
        // 迷宫限制最高进入等级
        set_remove_time(1800); 
} 


