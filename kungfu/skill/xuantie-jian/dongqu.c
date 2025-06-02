// dongqu.c �󽭶�ȥ

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "��"ZJBR"��ȥ"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	int damage;
	int ap, dp, pp;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("�󽭶�ȥֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query_skill("xuantie-jian", 1) < 100)
		return notify_fail("�����������������죬����ʹ�ô󽭶�ȥ��\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("����ڹ���򲻹�������ʹ�ô󽭶�ȥ��\n");

	if ((int)me->query("neili") < 300 )
		return notify_fail("����������̫��������ʹ�ô󽭶�ȥ��\n");

	if (me->query_skill_mapped("sword") != "xuantie-jian")
		return notify_fail("��û�м�����������������ʩչ�󽭶�ȥ��\n");

       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "$N" HIW "һ���ͺȣ�һ��������������ȱŷ�������" +
	      weapon->name() + HIW "��ջӾ�������������������"
	      "��������������������һ�����$n" HIW "��"NOR"\n";

	me->start_busy(3);
	ap = me->query_skill("sword") + me->query_str() * 5;
	pp = target->query_skill("force") + target->query_str() * 5;
	dp = target->query_skill("force") + target->query_dex() * 5;
	if (me->query("character") == "��������")
		ap += ap / 10;
	if (ap / 2 + random(ap) < pp)
	{
		msg += CYN "Ȼ��$p" CYN "�ڹ�������񣬷������´˽�����Ȼ�������·硣"NOR"\n";
		me->add("neili", -100);
	} else
	if (ap / 2 + random(ap) < dp)
	{
		msg += CYN "$p" CYN "��$P" CYN "�˽��Ʋ��ɵ�����æ����Ծ����"NOR"\n";
	} else
	{
		damage = (ap + random(ap/2));
		me->add("neili", -200);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 90,
					   HIR "$p" HIR "�������ܣ�ֻ�÷����мܣ�ȴ��$P" HIR
					   "��һ����ķ��𣬿�����Ѫ���²�ֹ��"NOR"\n");
	}

	message_combatd(msg, me, target);
	
	if (me->query_skill("taishang-wangqing", 1) > 49 ) 
	{
        msg=HIB"��Ȼ�䣬$N"HIB"����" + weapon->name() + HIB "����һ�����������¡¡�ķ���֮����Ю�������֮�ƣ�һʽ��"HIR"����Ⱥħ"HIB"����" + weapon->name() + HIB "��$n"HIB"��ͷֱѹ��ȥ��\n";

	if (ap / 2 + random(ap) > dp)
	{
		damage = (ap + random(ap / 2))*(me->query_skill("taishang-wangqing", 1)+100)/100;
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 35,
                                          HIR "$n�����мܣ���ʱ��$N�������ѹ����Ѫ���ڣ�����ס���ۡ����³�һ����Ѫ��"NOR"\n");

		me->add("neili", -300);
		message_combatd(msg, me, target);

		return 1;
	}

                msg += HIW"$p��æȫ��һ�������项��һ�����죬$P������о�Ȼ��$p����������\n" NOR;
	message_combatd(msg, me, target);
	}

	return 1;
}
