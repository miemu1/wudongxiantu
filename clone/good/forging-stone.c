#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL "����ʯ" NOR, ({ "forging stone", "forging", "stone" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", YEL "һ��ӵ������ħ���Ķ���ʯ����װ��һ����������װ����\n" NOR);
                set("unit", "��");
                set("value", 500000);
                set("no_sell", 1);
        }
        setup();
}
