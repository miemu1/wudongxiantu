#include <ansi.h>
#include <combat.h>
string query_name() { return "[��ħ��]"ZJBR"��ѩ����"; }
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
	object fire,weapon;
	int zhaosheshu,yangsheshu, exp, MAX_GUARD;
        if ( me->is_busy() )
        return notify_fail("��������æ���޷��ٻ���ħ������ѩ����");
	if((int)me->query("neili")< 1000)
	return notify_fail("��ķ���̫���ˣ�\n");
	if((int)me->query_skill("bingzhi-shengdian",1)< 250)
	return notify_fail("��ı�֮ʥ��̫���ˣ�\n");
        if ((int)me->query("magicgift")==2)
        return notify_fail("���Ѿ�ʹ�ñ�ħ������ѩ�����ˣ�\n");
	me->add("neili",-1000);
	me->start_busy(2);
    me->set("magicgift",2);
	message_vision(WHT "\n$N"WHT"����� ��Խ����Լ���ص��������������ĺ�����!!!\n" NOR, me);
	message_vision(WHT "\n$N"WHT"� ���е��ҵ���������Ϊ�ҵ������ɣ���������\n" NOR, me);
	message_vision(WHT "\n$N"WHT"����Χ���������εı�ѩ����!\n" NOR, me);
	return 1;
}
