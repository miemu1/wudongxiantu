
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL "�չط�" NOR, ({ "closed charm", "charm" }) );
        set_weight(30);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", YEL "���������л������Դ����ϣ��ӿ�չص��ٶ�...��\n" NOR);
                set("value", 1);
                set("no_sell", 1);
                set("autoload", 1);
                set("unit", "��");
        }

        setup();
}


