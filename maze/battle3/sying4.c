#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"����Ӫ"NOR);
        set("long", @LONG
������ǡ����Ρ�����ѵ����Ӫ��һ�������ξ�����ִ�����ѵ
�����������ɹž��������������棬������ʹ�������ܳ�����ʤ����
�˴���Ҳ��ǿ�˹����ֵ�ѵ����
LONG );
        set("train", "archer");
        set("no_magic", "1");
        set("exits", ([ /* sizeof() == 5 */   
               "south" :   __DIR__"syuanmen2",
               "north" :   __DIR__"sying1",
        ]));    

        set("objects", ([

        ]));
    
        setup();
        replace_program(ROOM);
}
