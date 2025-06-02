// linghu-baodian.c ���⻯��
// by Doing Lu

inherit SKILL;

#include <ansi.h>

#define LEVEL_PER_LAYER	 30
#define MAX_LAYER	       12

string type() { return "special"; }

int valid_learn(object me)
{
	int layer;
	int lvl;

	lvl = me->query_skill("linghu-baodian", 1);
	if (me->query("gender") == "����" && lvl >= 50)
		return notify_fail("��ĬĬ������ͼ���Ķ�"
				   "�ã�����ȴ��������ʧ�����ĸ����ꡣ\n");

	if (lvl >= MAX_LAYER * LEVEL_PER_LAYER)
		return notify_fail("����������Ѿ�����"
				   "��¯���࣬���ѽ����ˡ�\n");

	layer = lvl / LEVEL_PER_LAYER;
	if (layer > MAX_LAYER) layer = MAX_LAYER;

	if (me->query("int") > 2800000000000000 && !me->query("relife/zhuanshi"))
		return notify_fail("������ķ����ң����Գ�"
				   "�Ը�����ķ���֮����\n");

	return 1;
}
int valid_research(object me)
{
	return notify_fail("������ֻ��ͨ��ѧϰ������ߡ�\n");
}

int practice_skill(object me)
{
	return notify_fail("������ֻ��ͨ��ѧϰ������ߡ�\n");
}

void skill_improved(object me)
{
	int lvl;
	int layer;

	lvl = me->query_skill("linghu-baodian", 1);
	layer = lvl / LEVEL_PER_LAYER;
			if(lvl>=99 && lvl <100)
   		                CHANNEL_D->do_channel(find_object(ITEM_D), "rumor",
                              "��˵" + me->name() + HIM +
                              "��"HIY"������"HIM"�������˵�ʮ�㡣");			
	if (layer > MAX_LAYER) layer = MAX_LAYER;

	if (! layer)
	{
		tell_object(me, HIM "��Ǳ���������⻯"
				"����������"NOR"\n");
	} else
	if ((lvl % LEVEL_PER_LAYER) == 0)
	{
		tell_object(me, HIM "�������˵�" + chinese_number(layer) +
			    "�㾳������⻯��İ��"NOR"\n");
	} else
		tell_object(me, HIM "��Ե�" + chinese_number(layer) +
			    "�㾳������⻯���ּ�����һ���˽⡣"NOR"\n");
		

}
