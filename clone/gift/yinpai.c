// yinpai.c ��ʯ����

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIW "�������" NOR, ({ "yinpai" }) );
	set_weight(25);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIW "Я�����ƶ�������ݼ�aa,bb"
                    "���÷����������� alias aa XXXXXXXX"NOR"\n");
                set("value", 10000);
		 set("suit_point",20);
		set("unit", "��");
                set("can_be_enchased", 1);
                set("magic/type", "lighting");
                set("magic/power", 50);
                set("armor_prop/per", 3);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�"NOR"\n");
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������"NOR"\n");
	}
        setup();
}

int query_autoload() { return 1; }
