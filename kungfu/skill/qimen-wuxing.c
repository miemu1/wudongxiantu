// qimen-wuxing

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int practice_skill(object me)
{	
	return notify_fail("��������ֻ�ܿ�ѧ(learn)����ߡ�\n");
}
int valid_learn(object me)
{
	if (me->query("family/family_name") != "�һ���")
		return notify_fail("�һ����ĵ��Ӳ���ѧϰ�ü��ܡ�\n");
	return 1;
}