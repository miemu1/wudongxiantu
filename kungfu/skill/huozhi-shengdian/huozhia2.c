#include <ansi.h>
#include <combat.h>
string query_name() { return "[��ħ��]"ZJBR"ħ������"; }
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
	object fire,weapon;
	int zhaosheshu,yangsheshu, exp, MAX_GUARD;
        if ( me->is_busy() )
        return notify_fail("��������æ���޷��ٻ���ħ����ħ������");
	if((int)me->query("neili")< 300)
	return notify_fail("��ķ���̫���ˣ�\n");
	if((int)me->query_skill("huozhi-shengdian",1)< 50)
	return notify_fail("��Ļ�֮ʥ��̫���ˣ�\n");
        if (present("fire", me))
        return notify_fail("���Ѿ��ٻ���ħ����ħ�������ˣ�\n");
        if (me->query("neili") < 400)
        return notify_fail("��ķ������㣡\n");
         if (me->is_fighting())
        return notify_fail("���������������!\n");

	me->add("neili",-150);
	me->start_busy(2);
	fire= new("/clone/magic/fire");
	fire->move(me);

	message_vision(RED "\n$N����һ�� [��������֮����!] һ��ħ������, Ư������$N��ǰ��!!\n" NOR, me);
	message_vision(RED "\n$N������ʹ����һ������������!\n" NOR, fire);
	return 1;
}
