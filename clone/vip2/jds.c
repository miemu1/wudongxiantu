/*
兵器强化系统，思路来自于塞班年代的手机网游，代码本身简单，需要一定的逻辑性。
*/

#include <ansi.h>
inherit ITEM;

int query_autoload() { return 1; }
void create()
{
        set_name(HIM "鉴定开发石" NOR, ({ "jd shi", "jds" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "鉴定开发石(jds id)可以将平平无奇的自制武器开发神秘功用。\n" NOR);
                set("unit", "颗");
                set("yuanbao", 5000);
				set("no_give", 1);
				set("no_get", 1);
	//			set("no_shop", 1);
				
		set("no_drop", 1);
        }
        setup();
}

void init()
{
        add_action("do_integrate", "jds");
}

int do_integrate(string arg)
{
        object me;
        object ob;
        string ownerid,namejia;
        int jiapoint,cgl;

        if (! arg)
                return notify_fail("你要往什么道具上使用鉴定开发石？\n");

        me = this_player();
        if (! objectp(ob = present(arg, me)) &&
            ! objectp(ob = present(arg, environment(me))))
                return notify_fail("你身上和附近没有这样道具啊。\n");

        if (!ob->is_weapon() && !ob->is_unarmed_weapon())
                return notify_fail("你只能在兵器上使用鉴定开发石。\n");

     ob->set("ok_jianding",1);
     tell_object(me, HIC "你感受到" + ob->name() + HIC"变的更神圣了。\n" NOR);
        

        destruct(this_object());
        return 1;
}