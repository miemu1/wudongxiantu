inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "�ʹ����");
        set("long", @LONG
�����ǻʹ��ڵĴ��������Ŀ�ƽ������ʱ��һЩ��Ů��̫��
�������㲻�Ҷ࿴�����ǿ�㳯ǰ�߰ɣ�ʡ�������������̲顣
LONG );
        set("outdoors", "city2");
        set("no_fly",1);

        set("exits", ([
                "north"    : __DIR__"hgdadao3",
                "south"    : __DIR__"hgdadao1",
        ]));

        set("objects", ([

        ]));
        setup();
        replace_program(ROOM);
} 
