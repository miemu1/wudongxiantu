#include <ansi.h>
inherit ITEM;

int query_autoload() { return 1; }
void create()
{
        set_name(HIM "ŷұ�ӻ��" NOR, ({ "ouyezi fire", "symbol" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "ŷұ�ӻ�����Խ���ͨ�����������(upd)Ϊ׼����״̬��ӵ�л����ԡ�\n" NOR);
                set("unit", "��");
                set("value", 500000);
        }
        setup();
}

void init()
{
        add_action("do_integrate", "upd");
}

int do_integrate(string arg)
{
        object me;
        object ob;
        string ownerid;

        if (! arg)
                return notify_fail("��Ҫ��ʲô������ʹ�ø�ʥ����\n");

        me = this_player();
        if (! objectp(ob = present(arg, me)) &&
            ! objectp(ob = present(arg, environment(me))))
                return notify_fail("�����Ϻ͸���û���������߰���\n");

        if( ob->query("magic/imbue_ok") )
                return notify_fail(name() + "�Ѿ���׼10LVL���ϱ�����û�������Ҫ�ɡ�\n");

        if (ob->is_weapon() || ob->is_unarmed_weapon())
                return notify_fail("��ֻ���ڷ�����ʹ�ø�ʥ����\n");

        ownerid = ob->item_owner();

        ob->set("magic/imbue_ok", 1);
        ob->set("magic/type", "fire");
        ob->save();

        tell_object(me, "���" + name() + "����" + ob->name() + "�ϣ�Ȼ����������дʣ�\n"
                        "ֻ��ʥ������һ��������" + ob->name() + "���ڣ�\n");

        tell_object(me, HIC "�����" + ob->name() + HIC"�����˲��������ı仯��\n" NOR);

        destruct(this_object());
        return 1;
}