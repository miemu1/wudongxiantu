// ��ȡѫ��
inherit ITEM;

#include <ansi.h>

void create()
{
        set_name(HIG"�޶���ȡѫ��"NOR, ({ "jiqu xunzhang" }) );
	        set("long", "һö�޶��漳ȡѫ�£����Լӿ켳ȡ�ٶȡ�\n");
                set("yuanbao", 300000); 
				set("unit","ö");
		    set("no_sell", 1);
                set("no_give", 1);
                set("no_steal", 1);
		    set("no_drop", 1);
	setup();
}
int query_autoload() { return 1; }
