// huntian-qigong.c   ��������

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int query_neili_improve(object me)
{
	int lvl;
        lvl = (int)me->query_skill("shushan-force", 1);
        return lvl / 10 * lvl / 10 * 15 * 28 / 10 / 20;
}

int valid_learn(object me)
{
        int level;
        
        if (me->query("gender") == "����")
                return notify_fail("���޸����ԣ������������������������ɽ"
                                   "�ķ���\n");

        if( me->query("int")<30 )
                return notify_fail("����������Ȼ�������е㲻���ס�\n");

        if( me->query("dex")<30 )
                return notify_fail("���о��˰��죬ֻ����ʽʼ���޷�����ʩչ��\n");

        if( me->query("con")<30 )
                return notify_fail("���о��˰��죬ֻ���ø�����Щ���ʽʼ���޷�����ʩչ��\n");

        if( me->query("str")<30 )
                return notify_fail("���о��˰��죬�о�������Щ�ͣ�ʼ���޷�����ʩչ��\n");

        level = me->query_skill("shushan-force", 1);

        if ((int)me->query_skill("martial-cognize", 1) < 100)
                return notify_fail("�������ɽ�ķ�������£����Լ�����ѧ����"
                                   "ȫȻ�޷����ס�\n");

        if ((int)me->query_skill("force", 1) < 200)
                return notify_fail("��Ļ����ڹ���Ϊ���㣬������ת��ɽ�ķ���\n");

        if (me->query_skill("force", 1) < level)
                return notify_fail("��Ի����ڹ�����⻹�������޷���������"
        
                           "�������ɽ�ķ���\n");
return ::valid_learn(me);
        
}

int practice_skill(object me)
{
	    return notify_fail("��ɽ�ķ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"shushan-force/" + func;
}
