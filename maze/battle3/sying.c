#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ξ���Ӫ"NOR);
        set("long", @LONG
������ǡ����Ρ���Ӫ�ˣ�һ�����߸�������������һ����
������顸�Ρ��֣�ǰ�治Զ�����ξ�Ԫ˧����Ӫ�ˡ�
LONG );

        set("no_magic", "1");
        set("exits", ([ /* sizeof() == 5 */
               "south" :   __DIR__"sying1",
               "north" :   __DIR__"syuanmen1",
        ]));

        set("objects", ([

        ]));

        setup();
        replace_program(ROOM);
}

