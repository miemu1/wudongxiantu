#include <ansi.h>
inherit ROOM;

void home(object ob);

void create()
{
        set("short", "��̲");
        set("long", @LONG
�㱻һ��紵��ͷ��Ŀѣ���ƺ��ֻص��˺�̲��
LONG);

        set("exits", ([
                "out" : "/d/luoyang/wenmiao",
        ]));

        setup();
}

/*
void init()
{

	this_player()->move("/d/shenlong/haitan");
}
*/
int valid_leave(object me, string dir) 
{
        if (dir == "out") 
                FUBEN_D->clear_fuben("jiutoushe", query("id", me)); 
        return 1; 
}
