// Room: /tangmen/xdajie1.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�����");
        set("long",
"һ����֪��������Ƽ����������ˣ������͵��������ˡ����ǵ���\n"
"�����ŵı���֮·����ֵı��߾������������ž�¥�ˣ��������˵Ļ���\n"
"���������ٰ죬�ϰ�����ǽ�����������һ�仨�Ʒʡ�\n"
);
        set("outdoors", "����");
        set("no_clean_up", 0);
        set("exits", ([ 
                "west"  : __DIR__"ximen",
                "north" : __DIR__"jiulou",
                "east"  : __DIR__"zhongxin",
        ]));

        setup();
        replace_program(ROOM);
}

