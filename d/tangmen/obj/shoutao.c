// shoutao.c  ����

#include <armor.h>

inherit HANDS;

void create()
{
        set_name( "¹Ƥ����", ({ "lupi shoutao", "shoutao" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("long", "����һ˫¹Ƥ���ף�������Ӳ����յĺۼ������Աܶ���\n");
                set("value", 10000);
                set("material", "leather");
                set("armor_prop/armor", 10);
        }
        setup();
}
