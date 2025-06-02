#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
string name() { return "��ƾ�"; }
string query_name() { return "��ƾ�"; }
int perform(object me, object target)
{
        string msg;
        int lvl;
        int damage;
        int ap, dp;

        if (! target) target = offensive_target(me);

        if( environment(me)->query("no_fight") )
                return notify_fail("���ﲻ�ܹ������ˣ�\n");

        if (! target || ! target->is_character())
                return notify_fail("��Ҫ��˭ʩչ��ƾ���\n");

        if( target->query("not_living") )
                return notify_fail("��������ǲ��ǻ��ˡ�\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ��������ʩչ��ƾ���\n");

        if ((int)me->query_skill("qianzhu-wandushou", 1) < 130)
                return notify_fail("���ǧ��������Ϊ���������ڻ��޷�ʩչ��ƾ���\n");

        if (me->query_skill_mapped("hand") != "qianzhu-wandushou")
                return notify_fail("��û�м���ǧ�����֣��޷�ʩչ��ƾ���\n");

        if( me->query("neili")<400 )
                return notify_fail("������������������޷�ʩչ��ƾ���\n");

        msg = HIB "$N" HIB "ʩ����ƾ���ֻ��һ�ƺ�����"
              "ָ��͸����ֻһ����û����$n" HIB "��ü�ģ�\n" NOR;

        ap = me->query_skill("hand");
        dp = target->query_skill("force");

        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("hand");
                damage+= me->query("jiali");
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 50,
                                           HIR "$p" HIR "ֻ����һ����ɽ�ľ���˳ָ����"
                                           "��������ֻ����ȫ������ܣ����ۡ���һ��"
                                           "�³�һ�ں�Ѫ��\n" NOR);
                target->affect_by("qianzhu_wandushou",
                                  ([ "level" : lvl / 2 + random(lvl / 2),
                                     "id":me->query("id"),
                                     "duration" : lvl / 40 + random(lvl / 18) ]));
                me->add("neili", -220);
                me->start_busy(2);
        } else
        {
                msg += CYN "����$p" CYN "�����������������ڹ�"
                       "��������һָ�Ķ�����\n" NOR;
                me->start_busy(3);
                me->add("neili", -80);
        }
        message_combatd(msg, me, target);
        /*
        me->want_kill(target);
        if (! target->is_killing(me)) target->kill_ob(me);
        */
        return 1;
}