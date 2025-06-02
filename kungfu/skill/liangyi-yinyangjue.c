// liangyi-yinyangjue.c ��������
// cleansword
// Modified by Venus Oct.1997
// Updated by Doing Lu for Hell

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int query_neili_improve(object me)
{
	int lvl;

	lvl = (int)me->query_skill("liangyi-yinyangjue", 1);
	return lvl * lvl * 15 * 30 / 100 / 200;
}

int valid_force(string force)
{
	return 1;
}

string main_skill() { return "liangyi-yinyangjue"; }

mapping sub_skills = ([
	"jiuyin-shengong"  : 300,
	"jiuyang-shengong"  : 300,
	]);
	
	int get_finish(object me)
{
	if (me->query("int") < 50)
	{
		tell_object(me, "��������ϣ��������򲻵�ʲô������һƬãȻ��\n");
		return 0;
	}

	if (me->query("con") < 50)
	{
		tell_object(me, "��������ϣ��;�����ǰ������ð��̫��Ѩͻͻ������\n");
		return 0;
	}

	if ((int)me->query("max_neili") < 1000)
	{
		tell_object(me, "������������̣��޷��ڻ��ͨ��������\n");
		return 0;
	}

	if (random(10) < 7)
	{
		tell_object(me, "������������򣬻���������һ�ξ����ڻ��ͨ����������������\n");
		return 0;
	}

	tell_object(me, HIY "һ�󷲳�����ӿ����ͷ���㼸��������̾����ǰ�������ֳ�����������\n"
			    "���Ǽ䣬������ͨ������������"NOR"\n");
            message("channel:chat",BYEL"�����;"HIM"��"+me->query("name")+"��������������֮�֣�̫������֮�⣬�������ھ��Ž������������\n"NOR,users());
	return 1;
}

mapping query_sub_skills()
{
	return sub_skills;
}

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("liangyi-yinyangjue", 1);

	if (me->query("gender") == "����" && (int)me->query_skill("liangyi-yinyangjue", 1) > 49)
		return notify_fail("���޸����ԣ��������������������������������\n");

	if ((int)me->query_skill("force", 1) < 50)
		return notify_fail("��Ļ����ڹ���򻹲�����������ѧϰ����������\n");

	if (me->query("int") < 20)
		return notify_fail("����������������ڼ��������⡣\n");

	if (me->query("con") < 20)
		return notify_fail("��ĸ��ǲ��ã�������ת����������\n");

	return ::valid_learn(me);
}

int practice_skill(object me)
{
	return notify_fail("��������ֻ����ѧ(learn)�������������ȡ�\n");
}
void skill_improved(object me)
{
	int i;
	string *sub_skillnames;
	sub_skillnames = keys(sub_skills);
	for (i = 0; i < sizeof(sub_skillnames); i++)
		me->delete_skill(sub_skillnames[i]);
}


string exert_function_file(string func)
{
	return __DIR__"liangyi-yinyangjue/" + func;
}

