#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"ͻ��Ӫ"NOR);
        set("long", @LONG
������ǡ��ɹš�ͻ�����Ӫ��Ӫ�ھ���˻������������ɹ�
��Ϊ�����������ѵ����������ɹ�����������ɹž�Ѹ������
������У����ɲ������ľ�������
LONG );

        set("no_magic", "1");
        set("exits", ([ /* sizeof() == 5 */   
               "east"  :   __DIR__"mying4",
        ]));    

        set("objects", ([

        ]));
    
        setup();
        replace_program(ROOM);
}
