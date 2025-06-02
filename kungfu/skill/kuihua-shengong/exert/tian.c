// hup.c ���˻���

#include <ansi.h>

inherit F_CLEAN_UP;

string query_name() { return "���˻���"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;
	string msg;
	mapping my;
	int rp;
	int neili_cost;
/*
	if (userp(me) && ! me->query("can_perform/kuihua-shengong/tian"))
		return notify_fail("�㻹û��ͨ�����˻����İ��ء�\n");
*/
	if (target != me)
		return notify_fail("��ֻ�������˻�����Ϊ�Լ����ˡ�\n");
	if (userp(me)) {
		if (!me->query("special_skill/ghost"))
			return notify_fail("��û�й������ԣ��޷��������˻�����\n");
		if ((int)me->query_skill("kuihua-shengong", 1) < 200)
			return notify_fail("��Ŀ����񹦲�������޷�ʹ�����˻�����\n");
		if ((int)me->query_skill("force", 1) < 200)
			return notify_fail("��Ŀ����񹦲�������޷�ʹ�����˻�����\n");
	}
	if ((int)me->query("neili") < 200) 
		return notify_fail("�����ڵ�����������\n");

	my = me->query_entire_dbase();
	if ((rp = (my["max_qi"] - my["eff_qi"])) < 1)
		return (SKILL_D("force") + "/recover")->exert(me, target);

	if (rp >= my["max_qi"] / 10)
		rp = my["max_qi"] / 10;

	skill = me->query_skill("force");
	msg = HIY "$N" HIY "��ɫ���ϱ仯�������Ļָ���ЩѪɫ��"NOR"\n";
	message_combatd(msg, me);

	neili_cost = rp + 100;
	if (neili_cost > my["neili"])
	{
		neili_cost = my["neili"];
		rp = neili_cost - 100;
	}
	rp = rp *60 /100; //Ϊ���칦hup.c��Ч��60% by jjyy 2018.5.21
	me->receive_curing("qi", rp);
	me->receive_heal("qi", rp * 3 / 2);
	me->add("neili", -neili_cost);

	me->start_busy(3);
	return 1;
}
