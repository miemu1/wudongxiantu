// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <room.h>
inherit CREATE_CHAT_ROOM;


void create()
{
        set("short", "����");
        set("long", @LONG
�˴����һƬ�����ֲ�����ָ������������ۣ�һ˿����Ҳ͸��������
������ˣ���ȴһ��Ҳ�����£��Ҹе��Լ���˼��ǰ��δ�е�ͨ͸��
LONG );

        set("exits", ([ /* sizeof() == 1 */
                "out" : "/u/gigi/swing",
        ]));

        set("no_fight", "1");
        set("no_rideto", 1);
        set("no_flyto", 1);

             set("sleep_room", 1); 
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" && ! wizardp(me))
                return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");

        return ::valid_leave(me, dir);
}

void init()
{
        add_all_action();
}
