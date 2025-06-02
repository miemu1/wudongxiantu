#include <ansi.h>;
inherit ITEM;

void create()
{
        set_name(HIG "�������ɾ���" NOR, ({ "badao book", "badao", "book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "paper");
               // set("no_sell", 1);
                set("long", HIG "\n����һ���ñ�ֽд�ɵ��飬��Ƥ��д�С������ɾ������֡�\n"
                            "��������Ŷ���(read)����\n\n" NOR, );
        }

}


void init()
{
        add_action("do_du", "read");
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        string msg;

        if (! arg)
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }

        if (me->is_fighting())
        {
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
        }

        if (where->query("no_fight")
           && me->query("doing") != "scheme")
        {
                write("���޷������ﾲ�������ж������ɾ���\n");
                return 1;
        }


        if (me->query("str") < 35)
        {
                write("������������㣬�޷����������ɾ���\n");
                return 1;
        }
/*
        if (me->query("con") < 35)
        {
                write("������������㣬�޷����������ɾ���\n");
                return 1;
        }

        if ((int)me->query_skill("sword", 1) )
        {
                write("����ѧ����ѧ̫���ˣ��޷�ר����ϰ�����ɾ���\n");
                return 1;
        }

        if ((int)me->query_skill("club", 1) )
        {
                write("����ѧ����ѧ̫���ˣ��޷�ר����ϰ�����ɾ���\n");
                return 1;
        }

        if ((int)me->query_skill("staff", 1) )
        {
                write("����ѧ����ѧ̫���ˣ��޷�ר����ϰ�����ɾ���\n");
                return 1;
        }

        if ((int)me->query_skill("whip", 1) )
        {
                write("����ѧ����ѧ̫���ˣ��޷�ר����ϰ�����ɾ���\n");
                return 1;
        }

        if ((int)me->query_skill("dagger", 1) )
        {
                write("����ѧ����ѧ̫���ˣ��޷�ר����ϰ�����ɾ���\n");
                return 1;
        }

        if ((int)me->query_skill("hammer", 1) )
        {
                write("����ѧ����ѧ̫���ˣ��޷�ר����ϰ�����ɾ���\n");
                return 1;
        }

        if ((int)me->query("max_neili") < 10000)
        {
                write("���������Ϊ���㡣\n");
                return 1;
        }

        if ((int)me->query_skill("force", 1) < 500)
        {
                write("����ڹ����̫ǳ��\n");
                return 1;
        }

        if ((int)me->query_skill("martial-cognize", 1) < 300)
        {
                write("�����ѧ�������㡣\n");
                return 1;
        }

        if ((int)me->query_skill("blade", 1) < 400)
        {
                write("��Ļ���������򲻹����޷�ѧϰ�����ɾ���\n");
                return 1;
        }

        if (! me->query_skill("literate", 1))
        {
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }
*/
 /*       if (me->query_skill("sanscrit", 1) < 200)
        {
                write("�������ˮƽ̫�ͣ��޷��������������ص����ݡ�\n");
                return 1;
        }*/

/*if (! id(arg))
        {
                write("����û���Ȿ�顣\n");
                return 1;
        }

     /*   if (me->query_skill("yinyang-shiertian", 1) )
        {
                write("�����ڵ����������޷��뿪���ɾ�����ݡ�\n");
                return 1;
        }

        if (me->query_skill("lunhui-sword", 1) )
        {
                write("�����ڵ������ֻ������޷��뿪���ɾ�����ݡ�\n");
                return 1;
        }
*/
  /*      if ((int)me->query("combat_exp") < 10000000)
        {
                write("���ʵս��Ϊ���㣬����ô��Ҳû�á�\n");
                return 1;
        }*/

        if ((int)me->query("jing") < 100
           || (int)me->query("qi") < 100
           || (int)me->query("neili") < 200)
        {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }

        msg = HIG "$N" HIG "�����������ɾ�������ϸ�о����������ص���ѧ�����Ǽ��������򡭡�\n" NOR;
        msg += HIG "$N" HIG "���������������ҿ�������üͷ������������Ŀ��˼��\n" NOR;
        msg += HIG "$N" HIG "��̾һ�����п���ǧ���ƺ�������ʲô ����\n" NOR;
        message_vision(msg, me);

        if (me->query_skill("badao", 1) < 180)
        {
                write(HIW "��ԡ�" HIG "�����ɾ�" HIW "�������µ�����\n" NOR);

                if (! me->query_skill("badao", 1))
                {
                        me->set_skill("badao", 40 + random(21));
                        me->save();
                }
                else
                        me->set_skill("badao", me->query_skill("badao", 1) + 40 + random(21));

                destruct(this_object());
        }
        else
        {
                write(HIR "�㿪���ɾ������Ѿ��޷���ͨ���ж��ؼ��������ˡ�\n" NOR);
                return 1;
        }

        return 1;
}
