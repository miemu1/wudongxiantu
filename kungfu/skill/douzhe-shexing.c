#include <ansi.h>
// �������� 
inherit SKILL; 
string type() { return "knowledge"; } 

int is_fmsk() { return 1; }
string family_name() { return "������"; }

int valid_learn(object me)
{        
        if (me->query_skill("shedao-qigong", 1) < 180)
                return notify_fail("���ߵ��湦����㣬�޷���ϰ�������С�\n");        
        
        if( me->query("family/family_name") != family_name() )
                return notify_fail("������תֻ�ܶ��ϻ�����ӷ�����ϰ��\n");

        if (me->query_skill("shedao-qigong", 1) < 
            me->query_skill("douzhe-shexing", 1) * 60 /100)
                return notify_fail("���ߵ��湦��Ϊ���㣬�޷�������ϰ�������С�\n");

        return 1;
}

int difficult_level()
{
        return 2000;
}
