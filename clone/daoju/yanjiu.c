// �о�ѫ��
inherit ITEM;

#include <ansi.h>

void create()
{
        set_name(HIG"�޶��о�ѫ��"NOR, ({ "yj"}) );
	        set("long", "һö�޶����о�ѫ�£����Լӳ��о�Ч�ʡ�\n");
                set("yuanbao", 30000); 
				set("unit","ö");
		    set("no_sell", 1);
                set("no_give", 1);
                set("no_steal", 1);
		    set("no_drop", 1);
	setup();
}
int query_autoload() { return 1; }
