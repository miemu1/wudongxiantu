// This program is a part of NITAN MudLIB 
// redl 2013/8
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 

int clean_up() { return 1;}

void create()
{
        set("short", "ѧ�ý���");
        set("long", 
"����һ��ո������Ľ��ң�����������Ӳ�������͸�������������\n"
"ǰ��ǽ�����ǿ�ߴ��ʵ�ĺڰ壬�ڰ���д��һ�Ŵ��֡���������������\n"
"�����ε�������ҡ��������м�����ڷ��ż��������͵��ӣ�������ɢ��\n"
"�Ÿ��ֱ�īֽ�⡣\n"
);
                //set("outdoors", "yangzhou");
                set("exits",([ /* sizeof() == 1 */
                        "south" : __DIR__"caochang",
                ]));
                set("objects", ([ 
                        __DIR__"npc/xue" : 1,
        ])); 

        set("no_dazuo",1);
        set("no_kill",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);         
                set("no_rideto", 1);
                set("no_flyto", 1);
                set("no_magic", 1); 
        set("no_sleep_room", 1); 
        
        setup();
}

void init()
{
        object ob = this_player();
        if (base_name(ob)=="/clone/user/baby") {
                ob->command("halt");
                message_vision(CYN + "$N" + CYN + "���ŵ�����������һ�����˸�������λ���¡�\n" + NOR, ob);
        }
}

  
