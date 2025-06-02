// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <room.h>
inherit CREATE_CHAT_ROOM;

int is_chat_room() { return 1; }

void create()
{
        set("short", "С��õĹ�����");
        set("long", @LONG
����û�н��칤���ҵ���ʦ����ʱס����������豸�ǳ��򵥣�ֻ��
һЩ������Ʒ��
LONG );

        set("exits", ([ /* sizeof() == 1 */
                "north" : "/d/wizard/wizard_room",
                "down" : "/d/city/wumiao",
        ]));

        set("valid_startroom", 1);
        set("no_fight", "1");
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
