// zxzt.c ����������

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW "����������" NOR, ({ "zhentian wan", "zhentian", "wan" }) );
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "���������žŰ�ʮһ����ųɵ���Ч���ء�\n" NOR);
                set("value", 0);
                set("unit", "��");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        string mapsk;
        int effect;
        int neili;

        log_file("static/using", sprintf("%s(%s) eat ���������� at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));

        effect = 0;

        // if (me->query("skybook/item/zhenyu"))
        if (! VERSION_D->is_release_server())
        {
	        message_vision(HIR "$N" HIR "һ������������һ�����������裬ȴ��$P"
                               HIR "һ�����������һ����Ѫ������㵹��\n" NOR, me);

                me->set_temp("die_reason", "̰�����������裬���Ū��ȫ���������"
                                           "����");
                me->die(); 
        } else
	{
        	message_vision(HIW "$N" HIW "һ������������һ�����������裬ֻ��$P"
                               HIW "ȫ�����˻�һ�������ܵĲ��С�\n" NOR, me);

        	me->add("combat_exp", 0 + random(0));
        	me->add("magic_points", 0);
        	me->add("potential", 0);

               	me->set_skill("force", 180);
               	me->set_skill("beiming-shengong", 180);
               	me->set_skill("dodge", 180);
               	me->set_skill("unarmed", 180);
               	me->set_skill("parry", 180);
               	me->set_skill("sword", 180);
               	me->set_skill("blade", 180);

        	me->improve_neili(0);
        	me->improve_jingli(0);
                me->add("skybook/item/zxzt", 1);
	}
        destruct(this_object());
        return 1;
}

int query_autoload()
{
        return 1;
}
