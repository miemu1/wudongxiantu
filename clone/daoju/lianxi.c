// �о�ѫ��
inherit ITEM;

#include <ansi.h>

void create()
{
        set_name(HIG"��ϰѫ��"NOR, ({ "lian xi" }) );
	        set("long", "һö�޶�����ϰѫ�£����Լӳ���ϰЧ�ʡ�\n");
                set("yuanbao", 3000); 
				set("unit","ö");
		    set("no_sell", 1);
                set("no_give", 1);
                set("no_steal", 1);
		    set("no_drop", 1);
	setup();
}
int query_autoload() { return 1; }
