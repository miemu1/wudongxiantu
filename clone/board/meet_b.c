#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�����¼��", ({ "board" }));
        set("location", "/d/wizard/meeting_room");
        set("board_id", "meet_b");
        set("long", HIY "���ǽ�Ͽ�����ϣ��Źֵ����ģ�Ҳ��֪��������Щʲô��\n" NOR);
        setup();
        set("capacity", 1000);
        replace_program(ITEM);
}

