// liuhe.c��������
// bye jfeng
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;

	if (!target ) target = offensive_target(me);
	if (!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("������������ֻ����ս����ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
		if (me->is_busy()) 
		return notify_fail("��������æ���أ�\n");
	if((int)me->query_str() < 40)
		return notify_fail("��ı�������, ������ʹ���������! \n");
	if((int)me->query_skill("huntian-qigong",1) < 150)
		return notify_fail("��Ļ��������Ļ�򻹲�����, ����ʹ����һ���� !\n");
	if((int)me->query_skill("liuhe-dao",1) < 350)
		return notify_fail("������ϵ����Ļ�򻹲�����, ����ʹ����һ���� !\n");
	if ( !wizardp(me) && me->query_skill_mapped("force") != "huntian-qigong")
		return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");	
		if (me->query_skill_mapped("blade") != "liuhe-dao")
		return notify_fail("��û��ȷ�����ü��� ��\n");
	if( (int)me->query("neili") < 2000 )
		return notify_fail("�������������\n");
	if( (int)me->query("max_neili") < 5000 )
		return notify_fail("���������Ϊ������\n");
	message_vision(HIY "\n$N������ţ���������������Ӵ����������������������ˢ...ˢ...ˢ...�����Ӳ�ͬ�ط�ն��������\n" NOR, me, target);

	me->clean_up_enemy();
	ob = me->select_opponent();
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

	me->add("neili",-random(2000));
	me->start_busy(3);
	return 1;
}
