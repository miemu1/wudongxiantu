// zangfoyin.c ���ӡ

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "���ӡ"; }
string *pfm_type() { return ({ "hand", }); }

int perform(object me, object target)
{
	object weapon, weapon2;
	int damage;
	int count, wx;
	string msg;
	int ap, dp;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("�����ӡ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if ((int)me->query_skill("anyezangdi-jing", 1) < 100)
		return notify_fail("��İ�ҹ�ᾭ������죬����ʹ�á����ӡ����\n");
				
	if ((int)me->query_skill("force") < 100)
		return notify_fail("����ڹ���Ϊ�����ߣ��������á����ӡ����\n");

	if (me->query_skill_mapped("hand") != "anyezangdi-jing")
		return notify_fail("��û�м�����ҹ�ᾭ������ʹ�á����ӡ����\n");

       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "���������ִ��һ����ʹ����ҹ�ᾭ��ѧ�����ӡ����$n��ȥ��ֻ��$n����ǰ������һ������Ѫ���ʮ�ɴ��"NOR"\n";

	me->add("neili", -50);
	ap = me->query_skill("hand")+ me->query_skill("force"); 
	dp = target->query_skill("dodge") + target->query_skill("force");
			  
	if (ap / 2 + random(ap) > dp/2+random(dp/2))
	{		
		damage = me->query_skill("anyezangdi-jing", 1);
		wx = me->query("int")+me->query_int()/2;
		damage = damage*(1000+wx-20)/100;
		
		me->add_temp("apply/attack", damage);
		me->add_temp("apply/damage", damage);
		
		me->add("neili", -100);

		for(int i =0;i<18;i++) {
			if (! me->is_fighting(target))
				break;
			COMBAT_D->do_attack(me, target, weapon, 0);
		}
		me->add_temp("apply/attack", -damage);
		me->add_temp("apply/damage", -damage);
				
		if (objectp(weapon2=target->query_temp("weapon")) && random(100) < (wx/2+10)) {
			msg += HIR "$n" HIR "һ���ҽп�����Ѫ����ȥ�����б���Ӧ�����䡣"NOR"\n";
			weapon2->move(environment(target), 1);
		}
		else
			msg += HIR "$n" HIR "һ���ҽп�����Ѫ����ȥ��"NOR"\n";
		
		me->start_busy(random(1)+1);
	} else 
	{
		msg += HIC "����$p" HIC "�������ݣ�����Ķ����$P"
		       HIC "�Ĺ�����"NOR"\n";
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}
