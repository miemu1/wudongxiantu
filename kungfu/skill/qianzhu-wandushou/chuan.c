#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";
string final(object me, object target, int lvl);
string name() { return "�򶾴���"; }
string query_name() { return "��"ZJBR"����"; }
int perform(object me, object target)
{
        string msg;
        int lvl;
        int ap, dp;
        int damage;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

       // if( userp(me) && !me->query("reborn/times") )
       //         return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (userp(me) && ! me->query("can_perform/qianzhu-wandushou/chuan"))
		return notify_fail("�㻹����ʹ����һ�У�\n");

        if( me->is_busy() )
                return notify_fail("����æ���ء�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("���򶾴��ġ�ֻ�ܿ��ֲ���ʩչ��\n");

        if (! me->is_fighting(target))
                return notify_fail("���򶾴��ġ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! target || ! target->is_character())
                return notify_fail("��Ҫ��˭ʩչ�򶾴��ģ�\n");

        if (! living(target))
                return notify_fail("��������ǲ��ǻ��ˡ�\n");

        if ((int)me->query_skill("wudu-qishu", 1 ) < 200)
                return notify_fail("����嶾�����������ʩչ�򶾴��ġ�\n");

        if ((int)me->query_skill("wudu-jing", 1 ) < 200)
                return notify_fail("����嶾��������ʩչ�򶾴��ġ�\n");

        if ((int)me->query_skill("qianzhu-wandushou", 1) < 300)
                return notify_fail("���ǧ��������Ϊ���������ڻ��޷�ʩչ�򶾴��ġ�\n");

        if (me->query_skill_prepared("hand") != "qianzhu-wandushou")
                return notify_fail("��û��׼��ǧ�����֣��޷�ʩչ�򶾴��ġ�\n");

        if( me->query("neili")<1000 )
                return notify_fail("������������������޷�ʩչ�򶾴��ġ�\n");

        msg = HIY "$N" HIY "˫����Ȼ��ת��ǰ���Ƽ�������������������ޱȣ��Ʒ絽��������"
              "�������������ֱ��$n" HIY "�ؿڡ�\n" NOR;

        ap = me->query_skill("hand");
        dp = target->query_skill("force");

        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("hand");
                damage+= me->query("jiali");
                damage *= 6;
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 400,
                                           (: final, me, target, lvl :));

                me->add("neili", -300);
                me->start_busy(2 + random(2));
        } else
        {
                msg += CYN "����$p" CYN "�����������������ڹ�"
                       "��������һָ�Ķ�����\n" NOR;
                me->start_busy(4);
                me->add("neili", -200);
        }

        message_combatd(msg, me, target);
        /*
        me->want_kill(target);
        if (! target->is_killing(me)) target->kill_ob(me);
        */
        return 1;
}

string final(object me, object target, int lvl)
{
        if (! userp(target))
                target->affect_by("wandu_chuanxin",
                                    ([ "level" : lvl * 100,
                                       "id":me->query("id"),
                                       "duration" : lvl / 10 + random(lvl / 10) ]));
        else
                target->affect_by("wandu_chuanxin",
                                    ([ "level" : lvl * 50,
                                       "id":me->query("id"),
                                       "duration" : lvl / 10 + random(lvl / 10) ]));

        return HIR "$n" HIR "ֻ�������ɶ���͸�Ķ�����˵���������ܡ�\n" NOR;
}
