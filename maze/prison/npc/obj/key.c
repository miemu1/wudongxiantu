#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL "����Կ��" NOR, ({ "tianlao key", "key" }));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�ѿ������ε�Կ�ס�\n");
                set("value", 200);
                set("maze_item", 1);
        }
        setup();
}

