#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return "������"; }
string query_name() { return "����"ZJBR"��"; }
int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int damage, skill;
        int n;

        if (! target) target = offensive_target(me);

      if( me->query("family/family_name") != "���ϻ���"  ) 
               // return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->is_busy() )
                return notify_fail("����æ���ء�\n");

        if (me->query_skill_prepared("finger") != "six-finger")
                return notify_fail("��û��׼��ʹ�������񽣣��޷�ʩչ" + name() + "��\n");

        skill = me->query_skill("six-finger", 1);

        if (skill < 800)
                return notify_fail("�����������Ϊ���ޣ��޷�ʹ��" + name() + "��\n");

        if (me->query_skill("force", 1) < 800)
                return notify_fail("����ڹ���򲻹�������ʩչ" + name() + "��\n");

        if( me->query("max_neili")<12000 )
                return notify_fail("���������Ϊ����,�޷�ʩչ" + name() + "��\n");

        if( me->query("neili")<1000 )
                return notify_fail("������������������޷�ʩչ" + name() + "��\n");

        if( me->query_temp("weapon") )
                return notify_fail("������ǿ��ֲ���ʩչ" + name() + "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");


        msg = HIM "$N" HIM "һ����Х��������ָ�׵����پ�����������ӿ����ͷ������"
              "�˷������಻����\n��ʱ�����籼�������޾������������Ȼ����$n" HIM
              "��\n" NOR;

        ap = me->query_skill("finger");
        dp = target->query_skill("force");

        // ���20%
        ap = ap + ap / 5 + me->query_skill("martial-cognize", 1) + me->query_skill("jingluo-xue", 1);

        // ��20%����ʩչ��BUSY
        if (random(5) != 1) me->start_busy(2 + random(3));

        if ((int)target->query_skill("martial-cognize", 1) >= 2000
            && target->query_skill("dodge", 1) >= me->query_skill("six-finger", 1)
            && random (10) == 1 )
        {
                me->add("neili", -2000);
                msg += HIY "����$n" HIY "����һЦ��������䣬���׵Ķ����һ�У�\n"NOR;
        } else
        if (ap + random(ap) > dp)
        {
                damage = me->query_skill("finger") + me->query_skill("martial-cognize", 1) + me->query_skill("jingluo-xue", 1);
                damage *= 3;
                if( (n = me->query_skill("qimai-liuzhuan", 1) / 100) >= 1 )
                {
                        damage += damage*n*15/100;
                        msg += HIM"$N"HIM"����������ת�ĸ�����ʹ���������˺���ǿ��\n"NOR;
                }

                me->add("neili", -1800);
                msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 300 + random(200),
                                           HIR "ֻ��$n" HIR "һ���ҽУ����������"
                                           "͸��������˿ڴ���Ѫ��ʱ��ӿ��ʹ���ѵ���\n" NOR);
                target->set_weak(5);
                if( !target->is_busy() ) target->start_busy(8);
        } else
        {
                me->add("neili", -400);
                msg += CYN "$n" CYN "��$N" CYN "������ӿ����������"
                       "�мܣ���æ����Ծ����\n" NOR;
        }

        msg += HIG "\n�����ţ�$N" HIG "һ����Х��������ָ�׵����پ�����������ӿ����ͷ������"
              "�˷������಻����\n��ʱ�����籼�������޾������������Ȼ����$n" HIG
              "��\n" NOR;

        // �ٷ�һ��
        if ((int)target->query_skill("martial-cognize", 1) >= 2000
            && target->query_skill("dodge", 1) >= me->query_skill("six-finger", 1)
            && random (10) == 1 )
        {
                me->add("neili", -600);
                msg += HIY "����$n" HIY "����һЦ��������䣬���׵Ķ����һ�У�\n"NOR;
        } else
        if (ap + random(ap) > dp)
        {
                damage = me->query_skill("finger") * 3;
                if( (n = me->query_skill("qimai-liuzhuan", 1) / 100) >= 1 )
                {
                        damage += damage*n*15/100;
                        msg += HIM"$N"HIM"����������ת�ĸ�����ʹ���������˺���ǿ��\n"NOR;
                }

                me->add("neili", -800);
                msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 300 + random(200),
                                           HIR "ֻ��$n" HIR "һ���ҽУ����������"
                                           "͸��������˿ڴ���Ѫ��ʱ��ӿ��ʹ���ѵ���\n" NOR);
                target->set_weak(5);
                if( !target->is_busy() ) target->start_busy(8);
        } else
        {
                me->add("neili", -400);
                if (random(5) != 1)me->start_busy(5);
                msg += CYN "$n" CYN "��$N" CYN "������ӿ����������"
                       "�мܣ���æ����Ծ����\n" NOR;
        }
        message_combatd(msg, me, target);


        return 1;
}
