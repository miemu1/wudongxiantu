// beiming-zhenqi.c ��ڤ����
// by QingP

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        if ( me->query("gender") == "����" && (int)me->query_skill("beiming-zhenqi", 1) > 49)
                return notify_fail("���޸����ԣ���������������������ı�ڤ������\n");

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ�����㣬����ѧ��ڤ������\n");

        if ( me->query_skill("bibo-shengong",1)
        || me->query_skill("beiming-shengong",1)
        || me->query_skill("bahuang-gong",1)
        || me->query_skill("hamagong",1)
//      || me->query_skill("beiming-zhenqi",1)
        || me->query_skill("huntian-qigong",1)
        || me->query_skill("hunyuan-yiqi",1)
        || me->query_skill("longxiang",1)
        || me->query_skill("jiuyang-shengong",1)
        || me->query_skill("taiji-shengong",1)
        || me->query_skill("xiaowuxiang",1)
        || me->query_skill("yunlong-shengong",1)
        || me->query_skill("zixia-shengong",1) )
                return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��ڤ��������\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("��ڤ����ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"beiming-zhenqi/" + func;
}
