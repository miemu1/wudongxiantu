
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW "������������" NOR, ({ "tianqing miqi", "tianqing", "miqi"}));
        set_weight(500);
        if (clonep())
               set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "paper");
                set("no_sell", 1);
                set("long", HIY "\n����һ���ñ�ֽд�ɵ��飬��Ƥ��д�С�������������\n"
                                "�֡���������Ŷ���(readtq)����\n\n" NOR, );
        }
}

void init()
{
        add_action("do_du", "readtq");
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;

        string skill, book, msg;
        int lv;

        if (me->is_busy())
        {
                write("��������æ���ء�\n");
                return 1;
        }

        if (me->is_fighting())
        {
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
        }

        if (! me->query_skill("literate", 1))
        {
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        msg = HIG "$N" HIG "�����ؼ�����ϸ�о����������ص����ݣ����Ǽ�������򡭡�\n" NOR;
        message_vision(msg, me); 


        write(HIW "��ѧ���ˡ�" HIG "��������" HIW "���ؼ���\n" NOR);
        me->set("special_skill/tianqing", 1);
        destruct(this_object());
        return 1;
}

