#include <ansi.h>
inherit F_SSERVER;
string query_name() { return "����"ZJBR"һ��"; }
int perform(object me, object target)
{
        int lvl, j,i;
	object weapon;
	lvl = me->query_skill("sword", 1);

	if( !target ) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ������һ����\n");

	if( me->query_skill("liujiu-xinjing", 1) < 160 )
		return notify_fail("��������ľ�������죬�޷�ʩչ������һ����\n");

	weapon = me->query_temp("weapon");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	      (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");


	if ( me->query("max_neili") < 2000)
		return notify_fail("��������������޷�ʩչ������һ����\n");

	if ( me->query("neili") < 1000)
		return notify_fail("��������������޷�ʩչ������һ����\n");

	if ( me->query("jingli") < 1000)
		return notify_fail("��ľ����������޷�ʩչ������һ����\n");
	if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	message_vision(HIB"$Nʹ�������ľ�������һ������Ѹ���ޱȵĹ���$n��\n"NOR,me, target);

	j = lvl*10;

	if ( lvl > 200 )
		j = (lvl+me->query("bodyreset") + me->query_skill("liujiu-xinjing", 1) + me->query_skill("martial-cognize", 1) + me->query_skill("force") + me->query_skill("sword")+me->query_skill("unarmed"))*5;

	me->add_temp("apply/attack", j);
	me->add_temp("apply/sword", j);
	me->add_temp("apply/damage", j);

        message_vision(HIB"$N����������һ����һ��������\n"NOR,me,target);
        i=0;
        if(random(me->query("combat_exp"))>target->query("combat_exp"))
        {
        	message_vision(HIB"$n�������ˣ�����һƬ����֮�У�����˵�����ˡ�\n"NOR,me,target);
        	i=1;
        }
        else
        message_vision(HIB"$n�������ˣ������������ѣ�����˵�����ˡ�\n"NOR,me,target);
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        
	if ( me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);

	if ( me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

        me->add_temp("apply/attack", -j );
        me->add_temp("apply/sword", -j);
        me->add_temp("apply/damage",-j);

        me->start_perform(3+random(2), "������һ����");
		me->start_busy( 1+random(2) );
	me->add("neili", -400);
	me->add("jingli", -150);
	if(i==1) target->start_busy( lvl/50 ); 
	return 1;
}

string perform_name(){ return HIB"����һ��"NOR; }

