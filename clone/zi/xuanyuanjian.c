// �Ϲ�ʮ������֮ ��ԯ��
// Create by Rcwiz for Hero.cn 2003/09

#include <ansi.h>

#include <weapon.h>
inherit SWORD;


void create()
{
        set_name(HIY "��ԯ��" NOR, ({ "xuanyuan jian", "xuanyuan", "jian" }) );
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else
        {		
		set("gongxian",9999);
                set("unit", "��");
				set("no_sell", 1);set("value", 50000);
				set("can_summon", 1);
			set("no_give",1);
			set("no_steal",1);
			 set("no_sell", 1);
			set("no_get",1);
			 set("no_put",1);
			 set("armor_prop/sword", 1500);
                set("long", HIY "�����Ϲ�����֮�ף�ӵ�����������������˵"
                                "ӵ�д˽��߿ɳ۳��ˡ�ħ�������磬�Ʋ��ɵ���\n"
                               "����һ��������ǳ���һ���ɽ����ľ������һ����ũ������֮����һ�����ĺ�һͳ֮�ߡ������̲�����֮����Ϊն����ħ���񽣡�\n"
     NOR);

                set("material", "gold");
                set("wield_msg", HIY "$N" HIY "һ���������������������£�ӵ��һ��������\n"
                                 "�����񽣣�ɲ�Ǽ�˽�����һ�����ǻ���������$N" HIY "���С�\n" NOR);                               
                set("unwield_msg", HIY "$N" HIY "����һת����ԯ���ѹ��ʡ�\n" NOR);
                set("stable", 100);
				set("only_do_effect", 1);set("no_sell",1);
        }
        init_sword(2000);
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
                return HIY "$N" HIY "���������е���ԯ��������ʹ����ж�����ֱ�Ƶ�"
                           "$n" HIY "�������ˡ�\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n, me);
                victim->receive_wound("qi", n, me);
                return HIR "$N" HIR "��ת������ԯ������Ȼ�䣬������⻮��$n" HIY "��$n" HIY
                           "������䣬ȴ���н���\n" NOR;

        }
        return damage_bonus;
}

int do_effect(object me)
{
     

      if (me->is_busy())
                return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		    return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");

      if (me->query("xuanyuan",1))
                return notify_fail("���Ѿ���¼���ˡ�\n");
      else {
              
                me->set("xuanyuan",1);

                message_vision("$N����Ѫ������ԯ�����о�����һ˿��ϵ��\n", me);
	          write(YEL"��ϲ�����ɹ�������ʵ�֮��--��ԯ"NOR"\n");

	         
                return 1;
            }

}

int query_autoload()
{
	return 1;
}
