
#include <ansi.h>
// ��Ĺ�� jueqing-quyu
inherit SKILL; 
string type() { return "knowledge"; } 

int is_fmsk() { return 1; }
string family_name() { return "��Ĺ��"; }

int valid_learn(object me)
{       
        if (me->query("family/family_name") != family_name())
                return notify_fail("����ȥ��ֻ�ܹ�Ĺ�ɵ��ӷ�����ϰ��\n");

        if (me->query_skill("yunv-xinjing", 1) < 200)
                return notify_fail("����Ů�ľ�����㣬�޷�����ȥ����\n");

        return 1;
}

int difficult_level()
{
        return 6000;
}

