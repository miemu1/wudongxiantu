// �Ϲ�ʮ������֮ ��ԯ��
// Create by Rcwiz for Hero.cn 2003/09

#include <ansi.h>

#include <weapon.h>
inherit BLADE;


void create()
{
        set_name(HIR "������" NOR, ({ "dalong dao", "dalong", "dao" }) );
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else
        {		
		set("gongxian",9999);
                set("unit", "��");
				set("no_sell", 1);set("value", 50000);
			set("no_give",1);
			 set("no_put",1);
			set("no_get",1);
			set("no_steal",1);
			 set("no_sell", 1);
		set("armor_prop/blade", 1500);
                set("long", HIY "�������񵶣���Ի������\n"
                            HIR"�������ųƹ屦�еĹ屦����Զ��ʱ����ǰ��һֱ��������ʥ������\n"
                               "��˵�����������һ�������쿹�����ϴ������������ʲ������壬��ȡ�������벿�ֹ�֮�������ķ�ǧ��֮�òŴ�����������������ɻ�����ء�\n"
      NOR);

                set("material", "gold");
                set("wield_msg", HIY "$N" HIW "һ����ȣ���������У�ӵ��ȡ��һ��������\n"
                                 "������쵶��ɲ�Ǽ�˵�����Զ����ħ����������"HIY"$N" HIW "���С�\n" NOR);                               
                set("unwield_msg", HIY "$N" HIW "����һת��������������ʧ������С�\n" NOR);
                set("stable", 100);
				set("only_do_effect", 1);set("no_sell",1);

        }
        init_blade(2000);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;
        
        switch (random(10))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(20 + random(20));
                return HIC "$N" HIR "���������еĴ�����������ʹ����ж�����ֱ�Ƶ�"
                           "$n" HIY "�������ˡ�\n" NOR;

        case 1:
                n = me->query_skill("blade");
                victim->receive_damage("qi", n, me);
                victim->receive_wound("qi", n, me);
                return HIC "$N" HIR "��ת���д���������Ȼ�䣬����Ѫ��ն��$n" HIC "��$n" HIY
                           "������䣬ȴ����������\n" NOR;

        }
        return damage_bonus;
}
int do_effect(object me)
{
     

      if (me->is_busy())
                return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		    return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");

      if (me->query("dalong")>0)
                return notify_fail("���Ѿ���¼���ˡ�\n");
      else {
              
                me->set("dalong",1);

                message_vision("$N����Ѫ������������о�����һ˿��ϵ��\n", me);
	          write(YEL"��ϲ�����ɹ����Ϲ�����--������"NOR"\n");

	         
                return 1;
            }

}
int query_autoload()
{
	return 1;
}
