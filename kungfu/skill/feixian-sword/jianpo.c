// hongchen .���Ʋ��


string query_name() { return BGRN+BLK"����"ZJBR"���"NOR; }
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        string wname;
	int delta;

        int ap, dp; if (userp(me) && ! me->query("can_perform/feixian-sword/jiandao"))

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("�����Ʋ�񷡹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if(me->query("con")<120||me->query("dex")<120||me->query("str")<120)
		return notify_fail("����������Բ���ʩչ�˵ȰԵ���ʽ��\n");

 	if (target->query("no_huaxue"))
		return notify_fail("���ж�����Ч��\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("ûװ������ôʹ�á����Ʋ�񷡹��\n");
				
//	if (me->query("bieyunzsss", 1) < 10)
//		return notify_fail("��ʹ�ò������С����Ʋ�񷡹�����Ʋ������̳ǹ���\n");
		
        if (me->query_skill_mapped("sword") != "feixian-sword")
                return notify_fail("��û�м������ɽ�������ʹ�á����Ʋ�񷡹��\n");


        if ((int)me->query_skill("feixian-sword", 1) < 300)
                return notify_fail("��ķ��ɽ�������죬��ʹ���������Ʋ�񷡹��\n");
if ((int)me->query_skill("martial-cognize") < 200)
                return notify_fail("�����ѧ�������粻��������ʩչ�����Ʋ�񷡹��\n");

        if ((int)me->query("neili") < 2000)
               return notify_fail("��������������������ʩչ�����Ʋ�񷡹��"NOR"\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");
	if (me->query("gender") == "Ů��" &&
	    target->query("gender") != "����")
		delta =  me->query("per") - target->query("per") / 2;
	else
		delta = 0;
        wname = weapon->name();
       ap = me->query("per") / 20;
//       damage = ((int)me->query_skill("feixian-sword", 1) + (int)me->query_skill("sword", 1)) * 15;

 //       damage *= ap;


        // ��һ��
        ap = me->query_skill("sword"); 
        dp = target->query_skill("parry"); 
         msg = HIW "$N" HIW "��Ի��"BLK HBYEL"----------��㽣â---------- \n" NOR
	      HIW "$N" HIW "��Ի��"BLK HBYEL"---���ɽ���----- \n" NOR
              HIW "$N" HIW "����" + weapon->name() +"����" HIW "Ѫ���"HIW"����������������չ�����¡����¡����¡����µȻ�Ӱ��\n" NOR
              HIW "����ӣ������ؼ�$n" HIC" Χ����ȥ��\n" NOR;
        if (ap + random(ap) > dp)
        {
		damage = ap * 4 + random(ap * 2) + delta * 50;

                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
                                           HIW "$p" HIW "�����ֵ���ȴ�����мܵ�ס����$P"
                                           HIW "��һ�����£���ʱ����������"NOR"\n");
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
                                           HIW "$p" HIW "�����ֵ���ȴ�����мܵ�ס����$P"
                                           HIW "��һ�����£���ʱ����������"NOR"\n");
//			target->receive_damage("qi",damage+400+(me->query_temp("apply/damage")+me->query("jingmai/damage"))*2*70+(me->query("str")+me->query("dex")+me->query("con")+me->query("int"))*100);
//			target->receive_wound("qi",damage+400+(me->query_temp("apply/damage")+me->query("jingmai/damage"))*2*70+(me->query("str")+me->query("dex")+me->query("con")+me->query("int"))*100);

        } else
        {
                msg += HBWHT "$p" CYN "�ٵ�һ����Ӳ������$P"
                       HBMAG "��һ�½��£�������ǡ�����Ƿ��ɽ���Ψһ���ţ��������ӹ�һ�١�"NOR"\n";
        }

        // �ڶ���
        ap = me->query_skill("sword"); 
        dp = target->query_skill("parry"); 
  
  	msg +=  HIW "$N" HIW "��Ի��"BLK HBWHT"----------���Ʋ��---------- \n\n" NOR;
       	msg +=	HIW "$N" HIW "��Ի��"BLK HBWHT"----------���Ʋ��֮���ĵ���------ \n\n" NOR;
        msg +=  HIW "$N" HIW "��ʱ" + weapon->name() +"����һ��" HIY "��âδ������â����"HIY"��һ���ӳ����ƺ���Զû���յ㡣��\n\n" NOR;
	msg +=	BLK HBWHT "��ʥ��â��û��$n ��.\n\n" NOR;
        if (ap  + random(ap) > dp)
        {
			damage/=2;
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
                                          HIW "$p" HIW "ʼ�ϲ���������֮���Ĵ�������ɲ�Ǽ��Ѿ�����������"NOR"\n");
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
                                           HIW "$p" HIW "�����ֵ���ȴ�����мܵ�ס����$P"
                                           HIW "��һ�����£���ʱ����������"NOR"\n");
//			target->receive_damage("qi",damage+400+(me->query_temp("apply/damage")+me->query("jingmai/damage"))*2*70+(me->query("str")+me->query("dex")+me->query("con")+me->query("int"))*100);
//			target->receive_wound("qi",damage+400+(me->query_temp("apply/damage")+me->query("jingmai/damage"))*2*70+(me->query("str")+me->query("dex")+me->query("con")+me->query("int"))*100);
        } else
        {
                msg += HBWHT "$p" CYN "üͷһ�壬��Ȼ����$P"
                HBWHT "����������������У���Цһ������û�𵽰�����á�"NOR"\n";
        }

        // ������
        ap = me->query_skill("sword"); 
        dp = target->query_skill("parry"); 
     
  	msg +=  HIW "$N" HIW "�촽����" HBRED"----------���Ʋ��----------  \n\n" NOR;	
  	msg +=  HIW "$N" HIW "���ж�Ի��" HBRED"---------���ǽ���---------- \n\n" NOR;
        msg +=  HIW "$N" HIR "����" + weapon->name() +"Ѫ��һ��" HIR "�������"HIR"����ʴ����ء�\n\n" NOR;
        msg +=  HIW "��â���䣬���ǽ�������$n!\n\n" NOR;
        if (ap + random(ap) > dp)
        {
			damage /= 2;

                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
                                           HIW "$p" HIW "ֻ�������㱣�˼��ӵ����������ϰٰ���ζһһ���ԣ��ֽ��𽥻���������"NOR"\n");
//			target->receive_damage("qi",damage+(me->query_temp("apply/damage")+me->query("jingmai/damage"))*2*70+(me->query("str")+me->query("dex")+me->query("con")+me->query("int"))*100);
//			target->receive_wound("qi",damage+(me->query_temp("apply/damage")+me->query("jingmai/damage"))*2*70+(me->query("str")+me->query("dex")+me->query("con")+me->query("int"))*100);							   
        } else
        {
                msg += HIW "$p" HIW "һ�ڱ�������������$P"
                HBWHT "��֮�´���ľ����ȴδ����$p" HBWHT "�ֺ�����Ȼ�㿪�ˡ�"NOR"\n";
        }



        me->start_busy(2);
        me->add("neili", -400 - random(100));
        message_combatd(msg, me, target);
        return 1;
}
