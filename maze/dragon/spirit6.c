inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "��̶���");
        set("long",
"[1;32mǰ��������̶����ȥǰ����˼���������ֹ���������ü���\n"
"��Ҫ��ͷ�������back�������棬��һ�����µ�ͨ���������ƺ��൱�\n"
);

        set("exits", ([ 
              "north" : __DIR__"dragoncave", 
              "westdown" : __DIR__"spirit7", 
           ]));

        set("no_magic", 1);
	setup();
}

void init()
{
        add_action("do_back", "back");
}

int do_back(object me)
{
        me=this_player();
        message_vision(HIC"$N����Ӱ��ʧ��һ���â�С�\n"NOR,me); 
        me->set_temp("mark/diary", 0);
        me->set_temp("m_success/����",0);  
        me->set_temp("m_success/��Ӱ",0);  
        me->set_temp("m_success/����",0);  
        me->move("/d/city/wumiao");
        return 1;
}

