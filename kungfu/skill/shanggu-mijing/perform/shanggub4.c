#include <ansi.h>
#include <combat.h> 
	 
inherit F_SSERVER; 
	 
string query_name() { return "��������"ZJBR"����ָ"; }
string *pfm_type() { return ({ "finger", }); }

int perform(object me, object target) 
{ 
	object weapon; 
	string msg; 
	int ap, dp; 
	int damage; 
	
	if (! target) target = offensive_target(me); 
	
	if (! target || ! me->is_fighting(target)) 
		return notify_fail("��������������ָ��ֻ����ս���жԶ���ʹ�á�\n"); 
	 
	if (me->query_skill("force") < 600) 
		return notify_fail("����ڹ�����Ϊ����������ʹ�á�������������ָ����\n"); 
	
	if (me->query_skill("shanggu-mijing", 1) < 100) 
		return notify_fail("����Ϲ��ؾ���Ϊ������Ŀǰ����ʹ�á�������������ָ����\n"); 

       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "$N" HIY "�������տտ��˫��ƽ�죬��Ȼʹ����" HIR "������������ָ" HIY "��������ֻ����ؼ�ֻʣһֻ��ָ����"
              "$n��\n" NOR;
	 
	ap = me->query_skill("finger") + me->query_skill("force"); 
	dp = target->query_skill("dodge") + target->query_skill("parry"); 
	 
	if (ap / 2 + random(ap) > dp) 
	{ 
		damage = ap *100 + random(ap / 3*100); 
		me->add("neili", -500);
		me->start_busy(1);
		msg +=HIM "$n�ۼ���ָϮ�������޿ɱܣ����޿ɶ㣬ֻ�ñ�Ŀ������ɲ�Ǽ䱻��ָ��û����̱�ڵء�\n" NOR;
	} else 
	{ 
		me->add("neili", -100); 
		me->start_busy(1);
		msg += NOR + CYN "$n�ۼ���ָϮ����������η�壬˫��ץ���ָ������ʹ��֮�£��Ǿ�ָ���ʹ�ɢ���ˡ�\n" NOR;
	} 
	message_combatd(msg, me, target); 
	 
	return 1; 
}

