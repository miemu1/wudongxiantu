// poison.c ��������
// Modified by Java Mar.1998
inherit SKILL;

void create() { seteuid(getuid()); }
string type() { return "poison"; }

int valid_learn(object me)
{
	if (me->query("family/family_name") != "������"
		&& me->query("family/family_name") != "ŷ������"
		&& me->query("family/family_name") != "�������"
		&& me->query("family/family_name") != "��������")
		return notify_fail("ֻ�й�����ҡ������ɡ�ŷ�����ң��������ҵĵ��Ӳ���ѧϰ�ü��ܡ�\n");
	
	if (me->query("character") == "��������")
		return notify_fail("�����а��룺�����¹������䣬ѧʲô������\n");

	return 1;
}
