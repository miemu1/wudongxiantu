// magic-fire
inherit SKILL;
int valid_enable(string usage) { return usage=="spells" ;}
int valid_learn(object me)
{
if( (int)me->query_skill("spells",1)*2 < (int)me->query_skill("bingzhi-shengdian",1))
return notify_fail("��Ļ���������Ϊ�������޷����������ı�֮ʥ�䡣\n");
return 1;
}
string perform_action_file(string action)
{
return __DIR__"bingzhi-shengdian/" + action;
}
int practice_skill(object me)
{
return notify_fail("ħ���޷�ͨ����ϰ���ɳ���\n");
}

