
#include <ansi.h>

inherit EQUIP_SOUL;

void create()
{
        set_name(HIM "RP_NAME֮��" NOR, ({"RP_ID soulRP_STATUS", "RP_ID", "soulRP_STATUS"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "����һ��RP_NAME֮�ꡣ\n" NOR);
                set("unit", "��");
                set("value", 200000);
                set("no_sell", 1);
        }
        set("type", "RP_ID");
        set("status", RP_STATUS);
        set("auto_load", 1);
        set("set_data", 1);
        setup();
}

