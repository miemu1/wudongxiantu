// yi.c ����

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "Ψһ"ZJBR"һ��"; }

int perform(object me, object target)
{
	object weapon;
	string msg,wn;
	int ap, dp;
	int damage;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�þ��С�\n");


	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("������û��װ����������\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("�����ڵ������������޷�ʹ��Ψһһ����\n");

	if ((int)me->query_skill("liujiu-xinjing", 1) < 120)
		return notify_fail("��������ľ��������ң��޷�ʹ��Ψһһ����\n");

	if (me->query_skill_mapped("sword") != "liujiu-xinjing")
		return notify_fail("��û�м��������ľ����޷�ʹ��Ψһһ����\n");

       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

		wn = weapon->name();
                           
        msg = HIW "\n$N" HIW "��" + wn + HIW "������ǰ��"
              + wn + HIW "ɢ����΢΢��â��" + wn + HIW
              "��Ȼһ����������$n" HIW "���ࡣ�����������ľ��ġ�" HIG "Ψһһ��" HIW "����"
              "�����Ǵ�˵�е��񹦣�����ֲ���˹��" NOR;

	ap = me->query("bodyreset") + me->query_skill("liujiu-xinjing", 1) + me->query_skill("martial-cognize", 1) + me->query_skill("force") + me->query_skill("sword")+me->query_skill("unarmed");
	dp = target->query("bodyreset") + target->query_skill("dodge") + target->query_skill("parry");	
	if (ap / 2 + random(ap) < dp)
	{
		damage = me->query_skill("liujiu-xinjing",1)*5+me->query_skill("sword-cognize",1)*5+me->query_skill("martial-cognize",1)*5+me->query_skill("sword",1)+me->query_skill("dodge")+me->query_skill("force");	
		damage=damage+random(damage);
		me->add("neili", -180);
		msg += COMBAT_D->do_damage(me,target, WEAPON_ATTACK, damage, 200,
		   HIR "$n" HIR "û��һ˿��Ӧ�Ļ���"  HIW "һ��˲�䣬�����ش���"NOR"\n");
		me->start_busy(2);
	} 
	
	else
	{	damage = me->query_skill("liujiu-xinjing",1)*me->query("int",1)*10 + me->query_skill("sword-cognize",1)*me->query("int",1) + me->query_skill("parry",1)*me->query("dex",1) + me->query_skill("martial-cognize",1)*me->query("dex",1) + me->query_skill("sword") + me->query_skill("dodge") + me->query_skill("force") + me->query_dex();
		damage=damage+random(damage);
		msg += COMBAT_D->do_damage(me,target, WEAPON_ATTACK, damage, 200,
		 CYN "ֻ��$n" CYN "����������⾳֮��"
		       CYN "��û����������أ�������\n");
		me->add("neili", -80);
		me->start_busy(3);
	} 
	message_combatd(msg, me, target);

	return 1;
}
