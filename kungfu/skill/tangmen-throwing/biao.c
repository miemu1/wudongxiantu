#include <ansi.h>
#include <combat.h>

string query_name() { return "����"ZJBR"����"; }

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, i, p, n;
        int ap, dp;
        int damage;
        string pmsg;
        string msg;
        object weapon;

        if (playerp(me) && ! me->query("can_perform/tangmen-throwing/biao"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ��\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("handing")) ||
            (string)weapon->query("id") != "qizi gangbiao")
                return notify_fail("����������û�����Ű������Ӹ��ڣ�����ʩչ��\n");

        if ((skill = me->query_skill("tangmen-throwing", 1)) < 120)
                return notify_fail("������Ű���������죬����ʩչ��\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ���Ϊ���㣬����ʩչ��\n");

        if ((int)me->query("max_neili") < 600)
                return notify_fail("���������Ϊ���㣬����ʩչ��\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("�������������㣬����ʩչ��\n");

       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        me->add("neili", -100);

        msg = HIR "\n$N" HIR "ͻȻ����һֹ���ӻ���������ö���ƴ�С�ĸ��ڣ�һ������$n " HIR "��ȥ��\n"
              "ֻ����ö���ڣ����������$n" HIR "����������������Ĺ�Ӱ��ȴ������һ˿������\n"NOR;

        ap = me->query_skill("throwing")+me->query_skill("aqbj")/2;
        dp = target->query_skill("parry") +
             target->query_skill("lonely-sword", 1) / 5;

        message_combatd(msg, me, target);
        tell_object(target, HIR "\n�㼱æ��������ϣ���ܹ��м���������һ����\n"NOR);
        if (ap * 2 / 3 + random(ap / 2) > dp)
        {
                msg = HIR "��Ȼ�������Ĺ�Ӱһ����û��$n����һ�٣����һ����Ѫ�����������\n" NOR;
                message_combatd(msg, me, target);
                tell_object(target, HIR "��ֻ�����ؿ�һ�����ĵ���ʹ����ͷһ��ֻ������ö�����Ѿ������Ƕ������Ŀڡ�\n"
                                    "Ѫ������Լ�м���С��[���Ӹ���...]��\n"NOR);
                weapon->hit_ob(me, target, me->query("jiali") + 1000);
                weapon->move(environment(me));

                damage = me->query_skill("throwing") + me->query_dex()*5 + me->query("jiali")*2 + me->query_skill("aqbj");
                target->receive_wound("qi", damage, me);
                COMBAT_D->clear_ahinfo();
                //target->unconcious();
                me->start_busy(1);
        } else
        {
                tell_object(target, HIR "��Ȼ�������Ĺ�Ӱһ����û��������һ����æ��������ȫ��\n" NOR);
                msg = HIR "$n" HIR "˫�ۼ��裬��������Ʒ�֮����ֻ������һ�����죬��������ö�����ķɿ�ȥ��\n" NOR;
                message_combatd(msg, me, target);
                if ( target->query("neili") < 10000 )
                        target->set("neili", 0);
                else
                        target->add("neili", -1000);
                weapon->move(environment(me));
                me->start_busy(3);
        }
        return 1;
}

