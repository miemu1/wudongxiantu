//qianyuan.c

#include <room.h>;
inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "����ǰԺ");
        set("long",
"����ǰԺ��һ�ɻ����˱Ƕ������㲻�ɵ����������һ���������㰡\n"
"�����ܶ���һЩ������֪���ģ��в���ʶ�ģ�����һ�仨����ͻ���ģ���\n"
"��������ȥժ�������Ա���һ��Сľ��(sign)��\n"
);
        set("exits", ([
                "out"   : __DIR__"tmdamen",
                "north" : __DIR__"shuige1",
        ]));
        set("item_desc", ([
                "sign" : (HIG"·�ߵ�Ұ����Ҫ�ɣ����ﻨ��Ҳ��Ҫժ\n"NOR),
        ]));        
        set("outdoors", "����");
        setup();
}

void init()
{
        add_action("do_zhai","zhai");
}

int do_zhai(string arg)
{
        object me;
      
        me = this_player();
      
        tell_object(me,HIR"�����ˣ�\n"NOR);    
      
        return 1;
}      
