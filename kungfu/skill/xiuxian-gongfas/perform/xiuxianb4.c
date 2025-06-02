#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

#define YINYANG "��" HIW "�ɷ�����������" NOR "��"

string query_name() { return "[�ɷ�]"ZJBR"��������"; }

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

        message_sort(HIM "\n$N" HIM "���������淨������" HIB "��"
		     HIM "������" HIR "��" HIM "�����ȵ��ھ������ڶ�����"
		     HIM "����ɽ����֮�ƾ���$n" HIM "��\n" NOR, me, target);

        ap =   me->query_skill("force");

        sub = 0;
        dp1 = 0;

        if (target->query_skill_mapped("force") == "xiuxian-gongfas")
        {
	        sub = 3;
	        dp1 = target->query_skill("xiuxian-gongfas", 1)*5;
        } else
        if (target->query_skill_mapped("force") == "taixuan-gong")
        {
	        sub = 3;
                dp1 = target->query_skill("taixuan-gong", 1)*5;
        } else
        if (target->query_skill_mapped("force") == "taiji-shengong")
        {
                sub = 3;
                dp1 = target->query_skill("taiji-shengong", 1)*5;
        }else
        if (target->query_skill_mapped("force") == "jiuyin-shengong")
        {
                sub = 1;
                dp1 = target->query_skill("jiuyin-shengong", 1)*5;
        }else
        if (target->query_skill_mapped("force") == "jiuyang-shengong")
        {
                sub = 2;
                dp1 = target->query_skill("jiuyang-shengong", 1)*5;
        }

        //��һ�У���

        dp = target->query_skill("dodge");

        if (sub == 1 || sub == 3)
                dp += dp1;

        message_sort(HIB "\n$N" HIB "������ǰһ�ƣ������ޱȵ�������ӿ������"
		     "�ƺ�����������һ��ס��\n" NOR, me, target);

        if (ap * 25 / 3 + random(ap) > dp)
        {
	        damage = me->query_skill("force")*25;
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 800 + random(20),
					  HIB "$n" HIB "����$N" HIB "�����ѹ�����"
				          HIB "����������ͻȻ���ؿ�һ�𣬲��������п࣬"
                                          HIB "�ؿڴ�һ�ɺ�������ȫ���������ˡ�\n" NOR);
	        target->start_busy(3 + random(lvl / 350));
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

        if (ap * 35 / 3 + random(ap) > dp)
        {
                damage = me->query_skill("force")*35;
	        msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 800 + random(40),
                                          HIR "$n" HIR "��æ������ˣ���Ȼ��Ⱪ�ǣ�"
					  HIR "ֻ��$n" HIR "����ײײ�����������������"
                                          "�ڵء���ü������������һ�ɽ�����\n" NOR);
        } else
        {
                msg = CYN "����$n" CYN "��͸$P" CYN "����֮�е���������"
	              "����㣬Ӧ�����硣\n" NOR;
        }

        message_sort(msg, me, target);

	me->start_busy(1 + random(1));
	me->add("neili", -1 - random(500));
	return 1;
}

