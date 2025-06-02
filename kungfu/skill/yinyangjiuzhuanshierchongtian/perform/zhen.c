#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

#define YINYANG "��" HIW "������ѹ" NOR "��"

string query_name() { return "����"ZJBR"��ѹ"; }

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        string msg;
        int lvl;
        int ap, dp, dp1;
        int sub, damage;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(YINYANG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_skill_mapped("force") != "yinyangjiuzhuanshierchongtian")
                return notify_fail("��û�м���̫ʼ�۾�Ϊ�����ڹ����޷�ʹ��" YINYANG "��\n");

        if ((int)me->query("neili") < 2000)
	        return notify_fail("��������������޷�ʩչ" YINYANG "��\n");

        if (me->query("max_neili") < 5000)
	        return notify_fail("���������Ϊ��������ʹ��" YINYANG "��\n");

        if ((int)me->query_skill("force") < 500)
	        return notify_fail("����ڹ���򲻹�������ʩչ" YINYANG "��\n");

        if ((lvl = (int)me->query_skill("yinyangjiuzhuanshierchongtian", 1)) < 50)
	        return notify_fail("���̫ʼ�۾��������������޷�ʹ��" YINYANG "��\n");

        message_sort(HIM "\n$N" HIM "����̫ʼ�۾�������" HIB "��"
		     HIM "������" HIR "��" HIM "�����ȵ��ھ������ڶ�����"
		     HIM "����ɽ����֮�ƾ���$n" HIM "��\n" NOR, me, target);

        ap =   me->query_skill("force");

        sub = 0;
        dp1 = 0;

        if (target->query_skill_mapped("force") == "yinyangjiuzhuanshierchongtian")
        {
	        sub = 3;
	        dp1 = target->query_skill("yinyangjiuzhuanshierchongtian", 1) /2;
        } else
        if (target->query_skill_mapped("force") == "taixuan-gong")
        {
	        sub = 3;
                dp1 = target->query_skill("taixuan-gong", 1) / 2;
        } else
        if (target->query_skill_mapped("force") == "taiji-shengong")
        {
                sub = 3;
                dp1 = target->query_skill("taiji-shengong", 1) / 2;
        }else
        if (target->query_skill_mapped("force") == "jiuyin-shengong")
        {
                sub = 1;
                dp1 = target->query_skill("jiuyin-shengong", 1) /2;
        }else
        if (target->query_skill_mapped("force") == "jiuyang-shengong")
        {
                sub = 2;
                dp1 = target->query_skill("jiuyang-shengong", 1) /2;
        }

        //��һ�У���

        dp = target->query_skill("dodge");

        if (sub == 1 || sub == 3)
                dp += dp1;

        message_sort(HIB "\n$N" HIB "������ǰһ�ƣ������ޱȵ�������ӿ������"
		     "�ƺ�����������һ��ס��\n" NOR, me, target);

        if (ap * 2 / 3 + random(ap) > dp)
        {
	        damage = me->query_skill("force")*2;
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 45 + random(20),
					  HIB "$n" HIB "����$N" HIB "�����ѹ�����"
				          HIB "����������ͻȻ���ؿ�һ�𣬲��������п࣬"
                                          HIB "�ؿڴ�һ�ɺ�������ȫ���������ˡ�\n" NOR);
	        target->start_busy(3 + random(lvl / 500));
        } else
        {
                msg = CYN "$n" CYN "��$P" CYN "������ӿ���������׵�"
	              "������æ������Ų������������\n" NOR;
        }

        message_sort(msg, me, target);

        //�ڶ��У���

        dp = target->query_skill("parry");

        if (sub == 2 || sub == 3)
	        dp += dp1;

        message_sort(HIR "\n$N" HIR "���ֽ����������ȵ��������ȼ�����"
		     HIR "����֮��ɢ����һ�ɽ�����ζ����\n" NOR, me, target);

        if (ap * 2 / 3 + random(ap) > dp)
        {
                damage = me->query_skill("force")*2;
	        msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 45 + random(40),
                                          HIR "$n" HIR "��æ������ˣ���Ȼ��Ⱪ�ǣ�"
					  HIR "ֻ��$n" HIR "����ײײ�����������������"
                                          "�ڵء���ü������������һ�ɽ�����\n" NOR);
        } else
        {
                msg = CYN "����$n" CYN "��͸$P" CYN "����֮�е���������"
	              "����㣬Ӧ�����硣\n" NOR;
        }

        message_sort(msg, me, target);

	me->start_busy(3 + random(1));
	me->add("neili", -500 - random(100));
	return 1;
}

