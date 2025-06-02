// jiutian.c ����ʽ

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "����ʽ"; }
string *pfm_type() { return ({ "strike", }); }

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	int ap, dp;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}
	if (! target || ! me->is_fighting(target))
		return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if ((int)me->query_skill("liuyang-zhang", 1) < 120)
		return notify_fail("��������Ʒ�������죬����ʹ�á�����ʽ����\n");
				
	if ((int)me->query_skill("force") < 250)
		return notify_fail("����ڹ���Ϊ�����ߣ��������á�����ʽ����\n");
			
	if ((int)me->query("neili") < 300)
		return notify_fail("��������������������ʹ�á�����ʽ����\n");
	
	if (me->query_skill_prepared("strike") != "liuyang-zhang")
		return notify_fail("��û��׼��ʹ�������ƣ��޷�ʩչ������ʽ����\n");
			
	if (me->query_skill_mapped("strike") != "liuyang-zhang")
		return notify_fail("��û�м�����ɽ�����ƣ�����ʹ�á�����ʽ����\n");

       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");



	ap = me->query_skill("force");
	dp = target->query_skill("force");
	
	if (me->query_skill("tianchang-dijiu", 1) > 49)
	{
		damage = ap;
		damage += random(damage / 2);
        msg = HIY "����$N" HIY "����ƮƮ����Ŀ����Ĭ���������������������ھ������ڣ�"
              HIY "����ϼ������˫�Ƶķ�������������Ȼ$N" HIY "�㲽ǰ�ƣ�˫���ƿջ�����Ю��˿˿���⣬ֱ��$n" HIY "˫���ȥ��\n" NOR;
        msg += HIR "$n" HIR "ֻ���ؿ�һ�ƣ�һ˿����ֱ��θ�������һƬ�հ�ãȻ��֪���룡\n" NOR;
	if (ap / 2 + random(ap) > dp)
	{
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 65,
                                           HIR "$n" HIR "��Ȼ���ѣ����´󺧣�������̧���࿹�����ϵ�$N" HIR "����֬��ѩ��˫�ƾ�Ȼ�̺�ǧ��������" HIR "һ��֮�¶����Լ�˫��������ɢ�����޵ֵ�֮�������ʵʵ�����´��С�\n" NOR);
	} else
	{
                msg += CYN "$n" CYN "�ۼ�$N" CYN "������ӿ���鼱֮������˫�ۣ�����ֿ�����Ȼδռ�·硣\n" NOR;
	}

	// �ڶ���
        msg+= HIY "$N" HIY "һ��δ�ϣ�˲��������裬���ŷ����Ƴ�һ�ƣ���������Ŀ�ģ��ǻ���Ű׺��������ھ�ȷ����ӿһ�㱼��$n"HIY"��ǰ��\n" NOR;
	if (ap / 2 + random(ap) > dp)
	{
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 65,
                                           HIR "���ƾ��������죬ȴ�ֱ��޿ɱܣ���$n" HIR "�ؿ�͸�����,ֱ���$n��Ǵ��ѡ�"HIR "$n" HIR "ֻ��������ǧ���������룬����һ��ӿ��һ��Ѫ��ӿ����缤������\n" NOR);
	} else
	{
                msg += CYN "ֻ��$n" CYN "����׼������һ�����������ӵ���ԴԴ���Ϲ�����ǻ��ס������Ӳ�������ƣ���Ҳ�����󰭡�\n" NOR;
	}

	// ������
        msg+= HIY "$N" HIY "����һԾ����Ȼ�ڿ����ɣ�����Ʈҡ���£�������Ӱ�����һ��޴��ѩ������$n" HIY "ͷ��ѹ�¡�\n" NOR;
	if (ap / 2 + random(ap) > dp)
	{
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 65,
                                           HIR "ֻ����һ�����죬һ���ۻ���ƾ�����$n" HIR "����ը����˳��й��$n" HIR "����" HIR "$n" HIR "­��һ����ʹ��ȫ�������������һ����̱���ڵأ��������á�\n" NOR);
	} else
	{
                msg += CYN "$n" CYN "������������ӿ�����óȻ�мܡ������Ʋ���һ���鶯����Ȼ��ǧ��һ��֮�ʳ��������\n" NOR;
	}

	me->start_busy(2 + random(3));
	me->add("neili", -400 - random(100));
	message_combatd(msg, me, target);
	}
else
{
	msg = HIC "$N" HIC "˫��һ�񣬻���������Ӱ����������ס$n" HIC "��"NOR"\n";
	if (ap / 2 + random(ap) > dp)
	{
		damage = me->query_skill("strike") + ap - dp;
		damage += random(damage / 2);
        damage *= (me->query_skill("tiandi-xiaoyao", 1)+200)/200;

		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 90 ,
					   HIR "$p" HIR "���Σ�ֻ��Ӳ��һ�У������$P"
					   HIR "���������������Ѫ��ֹ��"NOR"\n");
	me->add("neili", -200);
		me->start_busy(3);
	} else
	{
		msg += HIC "����$p" HIC "ǿ��������Ӳ�����ĵ�ס$P"
		       HIC "��һ�ƣ�û���ܵ��κ��˺���"NOR"\n";
	me->add("neili", -80);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
}

	return 1;
}
