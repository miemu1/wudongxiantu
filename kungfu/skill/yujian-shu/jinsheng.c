#include <ansi.h>
#include <combat.h>

#define XIAN "��" HIM "��������" NOR "��"
string query_name() { return "����"ZJBR"����"; }

inherit F_SSERVER;

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
                return notify_fail(XIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" XIAN "��\n");
        if(me->query("family/family_name")!="��ɽ��")
                return notify_fail("������ɽ�Ĳ����á�������������\n");
        
        if(me->query("shushan/jinsheng_perform")!=1)
                return notify_fail("�㻹û��ᡸ������������\n");
        

        if ((int)me->query_skill("yujian-shu", 1) < 200)
                return notify_fail("�����ɽ�������������ң�����ʩչ" XIAN "��\n");

        if ((int)me->query_skill("xianfeng-spells", 1) < 200)
                return notify_fail("����ɷ��������������ң�����ʩչ" XIAN "��\n");

        if (me->query_skill_mapped("sword") != "yujian-shu")
                return notify_fail("��û�м�����ɽ������������ʩչ" XIAN "��\n");

        if((int)me->query("max_neili") < 1500 )
                return notify_fail("�����������������ʩչ" XIAN "��\n");

       if ((int)me->query("max_mana") < 1500)
                return notify_fail("��ķ�������������ʩչ" XIAN "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����������������ʩչ" XIAN "��\n");

        if ((int)me->query("mana") < 500)
                return notify_fail("��ķ�������������ʩչ" XIAN "��\n");        

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");
        
        msg = HIB "$N�ۼ����У������˷�����������ʫ������Ĭ�\n" NOR
              HIG "���е���һ�ж�ֻ�еȴ�������......\n"
              "$N" HIB "һ��ˣ�������"+weapon->name()+NOR+HIB"��Ϊһ��ֱ��$n���������� \n" NOR;       
        
        ap = me->query_skill("sword") * 2;
        dp = target->query_skill("dodge") + target->query_skill("parry");
             
        if (ap > dp)
        {
                damage = 0;
        me->start_busy(2);
        me->add("shushan/jinsheng_perform", -1);
        me->set_skill("force", me->query_skill("force", 1) - 100);
        me->add("mana", -100);
        me->add("neili", -500);
        me->add("max_mana", -100);
        me->add("max_neili", -500);

                        msg += HIB "$n����$N��˾�������Ȼ����������˲��һ����������$n���ϵ��ش���������\n"
                               "����д���һ����̾������ҡ��������� \n" NOR;
                        damage = -1;
                
        } else
        {
                me->start_busy(5);
                me->add("neili", -300);
                me->add("shushan/jinsheng_perform", -1);
                msg += CYN "����$p" HIB "һ�����Ʋ��ƴ�������Խ����Ȼ���Ǳ�����֮�ʽ��ҵض������ƴ����һʽ������\n" NOR;
        }
        message_combatd(msg, me, target);

        if (damage < 0)
                target->die(me);

        return 1;
}


