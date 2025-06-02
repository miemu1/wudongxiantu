// This program is a part of NT MudLIB

inherit  ROOM;

void create()
{
        set("short",  "�θ���Ժ");
        set("long",  @LONG
�������θ��ĺ�Ժ���������۴����ߣ�Ϊ��ε�Ӣ�����æµ�š�
��Ժһ�Ǿ�����һ����ؤ��������̸��ʲô���ԱߵĽ�����ʿ�ƺ���
������Ϊ��м������������ǰ��̸��
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "east"  :  __DIR__"neitang",
                "west"  :  __DIR__"chaifang",
                "south" :  __DIR__"xiangfang3",
                "north" :  __DIR__"xiangfang2",
        ]));
        /*
        set("objects",([
                __DIR__"npc/gangbang" : 1,
        ]));
        */
        setup();
        //replace_program(ROOM);
}

#include "/maze/juxianzhuang/zhuang.h"

int valid_leave(object me, string dir)
{
        object room, ob;

        if( dir == "west" )
        {
                if( me->query_temp("juxianzhuang_step") == 6
                ||  me->query_temp("juxianzhuang_step") == 10 )
                {
                        room = get_object(__DIR__"chaifang");
                        if( !present("xiao feng", room) )
                        {
                                ob = new(__DIR__"npc/xiaofeng");
                                ob->move(room);
                        }
                        return 1;
                }
        }

        return ::valid_leave(me, dir);
}