#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ԯ����"NOR);
        set("long", @LONG
������ǡ����Ρ���Ӫפ�����ˣ�ԶԶ�ؿ��Կ���һ����죬��
������һ����������顸�Ρ��֣����߽�Щ�͵���Ӫ�ˣ�Ѱ���˻���
��Ҫ�����ĺã�ʡ�ñ�����ϸ��׽������
LONG );

        set("no_magic", "1");
        set("exits", ([ /* sizeof() == 5 */   
               "north" :   __DIR__"sying4",
               "west"  :   __DIR__"yidao",
        ]));    

        set("objects", ([

        ]));
    
        setup();
        replace_program(ROOM);
}
