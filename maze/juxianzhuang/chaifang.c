#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��");
        set("long", @LONG
����һ�䰫С���߷���ƽʱ��Ϊ�ѷ��������á������ﲼ
�����������������ǻҳ����������Ѿ��ܾ�û���˴�ɨ�ˡ���
����һ��б���ż����ɲ�
LONG);
        set("exits", ([
                "east" : __DIR__"houyuan",
        ]));
        set("region", "luoyang");
        set("no_clean_up", 0);
        set("objects", ([
                "/d/wudu/obj/ganchai" : 2,
        ]));
        set("coor/x", 40);
        set("coor/y", 40);
        set("coor/z", 0);
        setup();
}
