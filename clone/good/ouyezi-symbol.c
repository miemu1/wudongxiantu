#include <ansi.h>
inherit ITEM;

int query_autoload() { return 1; }
void create()
{
        set_name(HIM "ŷұ��ʥ��" NOR, ({ "ouyezi symbol", "symbol" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "ŷұ��ʥ�����Խ�����װ���ĳɹ���������90%��\n" NOR);
                set("unit", "��");
                set("value", 500000);
        }
        setup();
}

