/*
����ǿ��ϵͳ��˼·����������������ֻ����Σ����뱾��򵥣���Ҫһ�����߼��ԡ�
*/

#include <ansi.h>
inherit ITEM;

int query_autoload() { return 1; }
void create()
{
        set_name(HIM "��������ʯ" NOR, ({ "jd shi", "jds" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "��������ʯ(jds id)���Խ�ƽƽ��������������������ع��á�\n" NOR);
                set("unit", "��");
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
                return notify_fail("��Ҫ��ʲô������ʹ�ü�������ʯ��\n");

        me = this_player();
        if (! objectp(ob = present(arg, me)) &&
            ! objectp(ob = present(arg, environment(me))))
                return notify_fail("�����Ϻ͸���û���������߰���\n");

        if (!ob->is_weapon() && !ob->is_unarmed_weapon())
                return notify_fail("��ֻ���ڱ�����ʹ�ü�������ʯ��\n");

     ob->set("ok_jianding",1);
     tell_object(me, HIC "����ܵ�" + ob->name() + HIC"��ĸ���ʥ�ˡ�\n" NOR);
        

        destruct(this_object());
        return 1;
}