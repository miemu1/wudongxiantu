#include <ansi.h>
// ���� guangming-jing
inherit SKILL;
string type() { return "knowledge"; }

int is_fmsk() { return 1; }
string family_name() { return "����"; }

int valid_learn(object me)
{
        if (me->query_skill("jiuyang-shengong", 1) < 120)
                return notify_fail("������񹦻���㣬�޷���ϰ���ƹ�������\n");

        if( me->query("family/family_name") != family_name() )
                return notify_fail("���ƹ�����ֻ�����̵��ӷ�����ϰ��\n");

        if (me->query_skill("qiankun-danuoyi", 1) < 150)
                return notify_fail("��Ǭ����Ų����Ϊ���㣬�޷�������ϰ���ƹ�������\n");

        return 1;
}

int difficult_level()
{
        return 2000;
}
