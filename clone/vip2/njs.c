/*
����ǿ��ϵͳ��˼·����������������ֻ����Σ����뱾��򵥣���Ҫһ�����߼��ԡ�
*/

#include <ansi.h>
inherit ITEM;

int query_autoload() { return 1; }
void create()
{
        set_name(HIM "�����;�ʯ" NOR, ({ "nj shi", "njs" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "�;�ʯ(nj id)���Խ�����������мӹ̡�\n" NOR);
                set("unit", "��");
                set("yuanbao", 500);
				set("no_give", 1);
				set("no_get", 1);
	//			set("no_shop", 1);
				
		set("no_drop", 1);
        }
        setup();
}

void init()
{
        add_action("do_integrate", "nj");
}

int do_integrate(string arg)
{
        object me;
        object ob;
        string ownerid,namejia;
        int jiapoint,cgl;

        if (! arg)
                return notify_fail("��Ҫ��ʲô������ʹ�ñ����;�ʯ��\n");

        me = this_player();
        if (! objectp(ob = present(arg, me)) &&
            ! objectp(ob = present(arg, environment(me))))
                return notify_fail("�����Ϻ͸���û���������߰���\n");

        if (!ob->is_weapon() && !ob->is_unarmed_weapon())
                return notify_fail("��ֻ���ڱ�����ʹ�ñ����;�ʯ��\n");

     ob->add("consistence",100);
     tell_object(me, HIC "����ܵ�" + ob->name() + HIC"��ĸ������ˡ�\n" NOR);
        

        destruct(this_object());
        return 1;
}