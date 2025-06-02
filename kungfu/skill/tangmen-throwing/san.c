#include <ansi.h>
#include <combat.h>

string query_name() { return "ɢ��"ZJBR"��Ů"; }

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, i, p, n;
        int ap, dp;
        int damage;
        string pmsg;
        string msg;
        object weapon;

        if (playerp(me) && ! me->query("can_perform/tangmen-throwing/san"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ��\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("handing")) ||
            (string)weapon->query("id") != "sanhua tianyu")
                return notify_fail("����������û�����Ű���ɢ����Ů������ʩչ��\n");

        if ((skill = me->query_skill("tangmen-throwing", 1)) < 160)
                return notify_fail("������Ű���������죬����ʩչ��\n");

        if ((int)me->query_skill("force") < 160)
                return notify_fail("����ڹ���Ϊ���㣬����ʩչ��\n");

        if ((int)me->query("max_neili") < 1200)
                return notify_fail("���������Ϊ���㣬����ʩչ��\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("�������������㣬����ʩչ��\n");

        if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        me->add("neili", -100);

        msg = HIG "$N" HIG "���п�סһö" + weapon->name() + "��������˵Ĺ��������弱����ת����������һ����Х�����磡\n" NOR
              HIG "ͻȻ�������зɳ�������" HIC "����" NOR + HIG "������һ�������������ķ���$n" HIG "�����壡\n" NOR;

        ap = me->query_skill("throwing") + me->query_skill("force");
        dp = target->query_skill("parry") + target->query_skill("dodge") ;

        message_combatd(msg, me, target);
        tell_object(target, HIR "\n�㼱æ��������ϣ���ܹ��м���������һ����\n"NOR);
//        if (ap * 11 / 20 + random(ap / 2) > dp)
        if (ap * 2 / 5 + random(ap * 3 / 5) > dp)
        {
                msg = HIR "��Ȼ�������Ĺ�Ӱһ����û��$n����һ�٣����һ����Ѫ�����������\n" NOR;
                message_combatd(msg, me, target);
                tell_object(target, HIR "��ֻ�����ؿ�һ�����ĵ���ʹ����ͷһ��ֻ��������ö�����Ѿ������Ƕ������Ŀڡ�\n"
                                    "Ѫ������Լ�м���С��[ɢ������...]��\n"NOR);
                weapon->hit_ob(me, target, me->query("jiali") + 10000);
                weapon->move(environment(me));

                damage = me->query_skill("throwing") * 2 + me->query_dex()*20 + me->query("jiali")*8 + me->query_skill("�����ٽ�");
                COMBAT_D->clear_ahinfo();
                //target->die();
                me->start_busy(1);
        } else
        {
                tell_object(target, HIR "��Ȼ�������Ĺ�Ӱһ����û��������һ����æ��������ȫ��\n" NOR);
                msg = HIR "$n" HIR "˫�ۼ��裬��������Ʒ�֮����ֻ������һ�����죬����������ö�����ķɿ�ȥ��\n" NOR;
                message_combatd(msg, me, target);
                if ( target->query("neili") < 20000 )
                        target->set("neili", 0);
                else
                        target->add("neili", -5000);
                weapon->move(environment(me));
                me->start_busy(4);
        }
        return 1;
}

