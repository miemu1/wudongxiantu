#include <ansi.h>
inherit F_SSERVER;
string query_name() { return "���־�"; }
int perform(object me)
{
    string msg;
    object weapon;
    int skill, jing_cost;
//    mapping my_fam  = me->query("family");
    skill = me->query_skill("yifeng-jian",1);
    if (me->query_int()<50)
        jing_cost = (int)me->query_int() - 50;
    else    jing_cost=1;
    if( me->is_fighting() )
        return notify_fail("�����־���������ս����������\n");
 
 if ( (string)me->query("family/family_name") != "�ƻ���") 
     return notify_fail("ֻ���ƻ������Ӳ���ʹ�ø�PFM��\n");

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("�������ȥ��һ�ѽ���\n");
    if( !skill || (skill < 60))
        return notify_fail("����Ʒ罣���ȼ�������\n");
    if( me->query("neili") < 50 )
        return notify_fail("�������������\n");
    if (me->query_skill("sword",1)<= skill)
        return notify_fail("��Ļ��������������޷�ͨ�����������־�������Ʒ罣���ļ��ɣ�\n");
    if( me->query("jing") < -jing_cost )
        return notify_fail("������̫���ˣ��޷����о������������־�����\n");
 write(HIW "��ʹ���Ʒ罣��֮�����־�����������" + weapon->name() + HIW "�����˼��£��Ʒ罣���ƺ��������һЩ��\n" + NOR);

    me->add("neili", -150);
    me->add("jing", jing_cost);
    if ( skill < 60)
        me->improve_skill("yifeng-jian", 10);
    else if (skill < 90)
        me->improve_skill("yifeng-jian", 10 + random((int)me->query_int() - 9));
    else if (skill < 140)
        me->improve_skill("yifeng-jian", 10 + random((int)me->query_int() * 2 - 9));
    else if (skill < 200)
        me->improve_skill("yifeng-jian", 10 + random((int)me->query_int() * 3 - 9));
    else
        me->improve_skill("yifeng-jian", 10 + random((int)me->query_int() * 4 - 9));
//write(HIG"��ġ��Ʒ罣���������ˣ�\n" + NOR);

      if (random(10)>8)    me->start_busy(1);
    return 1;
}

