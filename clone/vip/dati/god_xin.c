#include <ansi.h>
inherit ITEM;

int query_autoload() { return 1; }
void create()
{
        set_name(HIW "�ϵ�֮��" NOR, ({ "god_xin", "xin" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "�ϵ�֮�Ŀ��Խ�ʮ��������ħ�����н�һ����ǿ����jiamo����\n" NOR);
                set("unit", "��");
				set("no_get", 1);
				set("no_give", 1);
				set("shop", 1);
				set("no_drop", 1);
				set("no_sell", 1);
				set("no_steal", 1);
                set("dajif", 399);
        }
        setup();
}

void init()
{
        add_action("do_integrate", "jiamo");
}

int do_integrate(string arg)
{
        object me;
        object ob;
        string ownerid;
		int i;

        if (! arg)
                return notify_fail("��Ҫ��ʲô������ʹ���ϵ�֮�ģ�\n");

        me = this_player();
        if (! objectp(ob = present(arg, me)) &&
            ! objectp(ob = present(arg, environment(me))))
                return notify_fail("�����Ϻ͸���û���������߰���\n");

        if( ob->query("magic/power")<10 )
                return notify_fail(ob->name() + "��ʮ�����������ǣ����������\n");
		if( ob->query("magic/power")>500)
                return notify_fail(ob->name() + "�Ѿ������������ˡ�\n");

        if (!ob->is_weapon() && !ob->is_unarmed_weapon())
                return notify_fail("��ֻ���ڱ�����ʹ���ϵ�֮�ġ�\n");
		i=5+random(15);
        ownerid = ob->item_owner();

        ob->add("magic/power", i);
        ob->save();

        tell_object(me, "���" + name() + "����" + ob->name() + "�ϣ�Ȼ����������дʣ�\n"
                        "ֻ���ϵ�֮�Ļ���һ��������" + ob->name() + "���ڣ�\n");

        tell_object(me, HIC "�����" + ob->name() + HIC"�����˲��������ı仯��ħ��+"+i+"\n" NOR);

        destruct(this_object());
        return 1;
}