#include <ansi.h>
#include <combat.h>

string query_name() { return "����"ZJBR"ǧǧ��"; }

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, i, p, n;
        int ap, dp;
        string pmsg;
        string msg;
        object weapon;

        if (playerp(me) && ! me->query("can_perform/tangmen-throwing/qian"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ��\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("handing")) ||
            (string)weapon->query("id") != "qianqian jie")
                return notify_fail("����������û�����Ű�������ǧǧ�ᣬ����ʩչ��\n");
                
        if ((skill = me->query_skill("tangmen-throwing", 1)) < 140)
                return notify_fail("������Ű���������죬����ʩչ��\n");
                
        if ((int)me->query_skill("force") < 140)
                return notify_fail("����ڹ���Ϊ���㣬����ʩչ��\n");

        if ((int)me->query("max_neili") < 600)
                return notify_fail("���������Ϊ���㣬����ʩչ��\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("�������������㣬����ʩչ��\n");

        if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        me->add("neili", -100);

        msg = HIR "\n$N" HIR "ͻȻ����һֹ���ӻ�������һ�����������������ᣬһ������$n " HIR "��ȥ��\n"
              "ֻ��$n" HIR "����������������Ĺ�Ӱ��һ�������ӿ����¡�\n"NOR;

        ap = me->query_skill("throwing")+me->query_skill("aqbj") / 2; 
        dp = target->query_skill("dodge") +
             target->query_skill("lonely-sword", 1) / 5; 
        
        message_combatd(msg, me, target);
        tell_object(target, HIR "\n�㼱æ��������ϣ���ܹ��㿪�������ķ�����\n"NOR);
        if (ap * 2 / 3 + random(ap) > dp)
        {
                msg = HIR"��Ȼ�������Ĺ�Ӱһ����û��$n����һ�٣����������ϣ����������\n" NOR;
                message_combatd(msg, me, target);
                tell_object(target, HIR "��ֻ����ȫ�������Խ��Խ������ͷһ��ֻ���Ƿ����Ѿ������Ƕ�����Ƥ���С�\n" NOR);
                weapon->hit_ob(me, target, me->query("jiali") + 1000); 
                weapon->move(target);              
                target->start_busy(ap / 10 + random(ap / 100));
                me->start_busy(1);
        } else
        {
                tell_object(target, HIR "��Ȼ�������Ĺ�Ӱһ����û��������һ����æ������������䡣\n" NOR);
                msg = HIR "$n" HIR "��æ���Ա�һ�ݣ��㿪�������ķ����������Ե��Ǳ�������\n" NOR;
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

