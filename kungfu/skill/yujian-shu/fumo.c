// mie.c  ���ĳ��齣��������ħ��

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "����"ZJBR"��ħ"; }

int perform(object me, object target)
{
	int damage, damagea;
	string msg;
	object weapon;
	int ap, dp, cp;
      weapon = me->query_temp("weapon");
	
       if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	
	if (! target || ! me->is_fighting(target))
		return notify_fail("��������ħ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if(me->query("family/family_name")!="��ɽ��")
                return notify_fail("����ɽ�����á�������ħ����\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("ûװ������ôʹ�á�������ħ����\n");

	if ((int)me->query_skill("yujian-shu", 1) < 100 )
		return notify_fail("�����ɽ������������죬��ʹ������������ħ����\n");
	
        if((int)me->query_skill("xianfeng-spells", 1) < 50)
                return notify_fail("����ɷ��������ȼ���������ʹ������������ħ����\n");

	if ((int)me->query_skill("force") < 120)
		return notify_fail("����ڹ���򲻹�������ʩչ��������ħ����\n");

	if ((int)me->query("neili") < 200)
	       return notify_fail("��������������������ʩչ��������ħ����"NOR"\n");

        if((int)me->query("jing") < 100 )
                return notify_fail("��ľ���������ʩչ��������ħ����"NOR"\n");


       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "$N����Ĭ�������ھ�������"+weapon->name()+NOR+HIC"��ʱ��ϼ�����䣬һ�С�������ħ��ֱն$n��"NOR"\n";

	ap = me->query_skill("sword");
	dp = target->query_skill("dodge");
      cp = ap/2 + ap + dp; 
	if (random(cp) > dp)
	{
	  me->start_busy(2);
        damage =ap + random((int) me->query("max_neili"))/30;
        damagea =ap + random((int) me->query("max_neili"))/50;
        target->receive_damage("qi",damage);
        target->receive_damage("jing",damagea);
        me->receive_damage("jing", 100);
        me->receive_damage("qi", 100);
        me->add("neili", -500);
        me->add("mana", -50);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 70,
					   HIR "$n" HIR "ȫȻ�޷���ܣ�" + weapon->name() +
					   HIR "�˶�����������$n" HIR "�ؿڣ���ʱ��Ѫ�ɽ���"NOR"\n");
		me->add("neili", -150);
	} else
	{
		me->start_busy(3);
		msg += YEL "����$p" YEL "����һЦ��������ת����"
		       "����ָ��������$P" YEL "�Ľ��ϣ�" + weapon->name() +
		       YEL "��$p" YEL "��໮�����о����ա�"NOR"\n";
            me->add("neili", -100);
            me->add("mana", -50);

	}
	message_combatd(msg, me, target);
	return 1;
}
