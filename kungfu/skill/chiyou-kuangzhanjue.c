// This program is a part of NITAN MudLIB

inherit FORCE;

int valid_enable(string usage)
{
            return usage == "force";
}

int valid_force(string force)
{
        return 1;
}

int valid_learn(object me)
{
       if( me->query_skill("tiandao-shengong",1))
                return notify_fail("�㲻ɢ������񹦣��޷�ר����ϰ��ȿ�ս����\n");
            return ::valid_learn(me);
}

int practice_skill(object me)
{
            return notify_fail("��ȿ�ս��ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
            return __DIR__"chiyou-kuangzhanjue/" + func;
}
