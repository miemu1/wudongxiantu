// ximenroad.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long",
"�Ƽ���������֣���֦ͦ�Σ���ľ��б���ּ�С����������Զ����\n"
"�в������֣�������ת��ʹ���ʱ���⾡��������ǰ�͵������������ˡ�\n"
);
        set("exits", ([
                "northup" : __DIR__"ximenroad2",
                "southeast" : __DIR__"ximen",
        ]));
        set("outdoors", "����");
        setup();
        replace_program(ROOM);
}
