// ban.c ���콣�������

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "����"ZJBR"����";}
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int count,ap,dp,damage;
	int i;

	if (! target ) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("���콣�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query_skill("kuangfeng-jian", 1) < 100)
		return notify_fail("��Ŀ��콣������죬����ʹ�����������\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("����ڹ������������ʹ�����������\n");

	if (me->query("neili") < 100)
		return notify_fail("�����ڵ������������޷�ʹ�����������\n");

	if (me->query_skill_mapped("sword") != "kuangfeng-jian")
		return notify_fail("��û�м������콣������ʹ�����������\n");

       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "��бб�̳�������ɹɽ������ν����ս�������һ˲�䣬��ر�ã���Ӱ��������С��"
              "�����������ŷ磬���ﺬ�Ž�Ӱ���ǽ����������������ɫ��������ǵ�Ϯ��$n��"NOR"\n";

	ap = me->query_skill("sword");
	dp = target->query_skill("force");

        if (ap / 2 + random(ap)> dp)
        {
		damage = (ap + random(ap / 2))*(me->query_skill("jianxin-tongming", 1)+100)/100;
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 90,
                                           HIR "$n" HIR "ֻ�������к��һ�£��������󵹷ɳ�ȥ�������ڵأ��������ۡ�������һ����Ѫ��" NOR"\n");
                me->start_busy(3);
		me->add("neili", -200);
        } else
        {
                msg += CYN "��$n" CYN "������$N" CYN "�ĺݶ���ͼ�����������������㿪��$N" CYN "����һ�����µĹ�����" NOR"\n";
                me->start_busy(3);
		me->add("neili", -200);
        }
        message_combatd(msg, me, target);

	return 1;
}
