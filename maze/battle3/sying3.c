#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"�����Ӫ"NOR);
        set("long", @LONG
������ǡ����Ρ������Ӫ��Ӫ�ھ���˻�����������Ϊ��Ӧ
���ɹž����������������ѿ�ʼ�������ѵ�����ϳ�����ָ�ӵĽ�
����Ȼ���Ѻ���䤱�������˿��Ҳ����и����
LONG );
        set("train", "cavalry");  
        set("no_magic", "1");
        set("exits", ([ /* sizeof() == 5 */
               "west"  :   __DIR__"sying1",
        ]));

        set("objects", ([

        ]));

        setup();
}
