#include <ansi.h>
inherit ROOM;
inherit __DIR__"jiguan_room.c";

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����һ�����ʯ�ң�ֻ�����ܿտ��ޱȣ���Զ����һ����״��
�ص�ʯ����desk����
LONG );
        set("maze", 1);
        set("no_magic", 1);
        set("virtual_room", 1);
        set("no_clean_up", 1);       
        set("room_id", "number/d");
        set("item_desc", ([
                "desk" : NOR + WHT "һ����״���ص�ʯ�����ƺ�������ʲô���أ�\n" NOR,
        ]));
        setup();
}
