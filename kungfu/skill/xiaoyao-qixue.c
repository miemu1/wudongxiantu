// xiaoyao-qixue.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage == "medical"; }

int valid_learn(object me)
{
	if (me->query("family/family_name") != "��ң��")
		return notify_fail("��ң�ɵĵ��Ӳ���ѧϰ�ü��ܡ�\n");
	
	if ((int)me->query_skill("medical", 1) < 100)
		return notify_fail("��Ļ���ҽ������̫ǳ����"
				   "�������µ���ң��ѧ��\n");

	if ((int)me->query_skill("medical", 1) < (int)me->query_skill("xiaoyao-qixue", 1))
		return notify_fail("��Ļ���ҽ��ˮƽ���ޣ���"
				   "�����ո���µ���ң��ѧ��\n");

	return 1;
}

