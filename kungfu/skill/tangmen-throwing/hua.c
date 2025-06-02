#include <ansi.h>
#include <combat.h>

string query_name() { return "��"ZJBR"��"; }

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, i, p, n;
        int ap, dp;
		int damage;
        string pmsg;
        string msg;
        object weapon;

        if (playerp(me) && ! me->query("can_perform/tangmen-throwing/hua"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ��\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("handing")) ||
            (string)weapon->query("id") != "tang hua")
                return notify_fail("����������û�����Ű����ƻ�������ʩչ��\n");

        if ((skill = me->query_skill("tangmen-throwing", 1)) < 180)
                return notify_fail("������Ű���������죬����ʩչ��\n");

        if ((int)me->query_skill("force") < 180)
                return notify_fail("����ڹ���Ϊ���㣬����ʩչ��\n");

        if ((int)me->query("max_neili") < 1200)
                return notify_fail("���������Ϊ���㣬����ʩչ��\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("�������������㣬����ʩչ��\n");

       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        me->add("neili", -100);

        msg = HIR "\n$N" HIR "����ͻȻ����һ֧�����������ޣ�$n" HIR "�����е���ˣ�\n$N" HIR "��$n" HIR "һЦ��һ������$n"HIR "��ȥ��\n" +
              HIG "ֻ���ǻ����ˣ�������棬���뻨�����ɷ�Ǻÿ���\n" NOR;

        ap = me->query_skill("throwing")*2+me->query_skill("aqbj");
        dp = target->query_skill("parry") +target->query_skill("dodge") +
             target->query_skill("lonely-sword", 1) / 5;

        message_combatd(msg, me, target);
        tell_object(target, HIC "\n�㼱æ�����ȥ�ӣ���ͻ�أ��㷢�����죬����һ������������һԾ��\n" NOR);
        if (ap * 2 / 3 + random(ap * 2 / 3) > dp)
//        if (ap / 2 + random(ap / 2) > dp)
        {
                msg = HIR"�ǻ�Խ��Խ�ޣ�$n" HIR "��֪�������ѳ����ˣ�����һ��,΢Ц�ŵ����ˣ��ǻ�Ҳл�ˡ�\n" NOR;
                tell_object(target, HIR "\n�㿴���ǻ���������һ��������\n���������������ժ��������"
                                        "�ǻ�������Խ��Խ���ˣ���ϡ����ǵ���������һ��СС�ġ��ơ��֡�\n" NOR);
                weapon->hit_ob(me,target,me->query("jiali") + 2000);
                weapon->move(target);

                damage = me->query_skill("throwing") + me->query_dex()*10 + me->query("jiali")*4 + me->query_skill("�����ٽ�");
                message_combatd(msg, me, target);
                target->receive_wound("qi",damage, me);
                target->receive_wound("jing",damage, me);
                COMBAT_D->clear_ahinfo();
                //target->unconcious(me);
                me->start_busy(1);
        } else
        {
                tell_object(target, HIR "�������ƻ��������е��ƻ���������ȫ��������������ӵĸ�����\n" NOR);
                msg = HIR "$n " HIR "����Ʈ�����ǻ����ն�����ֻ������һ�����죬�ǻ�л�ˣ���������ڵ����ϡ�\n" NOR;
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

