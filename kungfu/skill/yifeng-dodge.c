//�Ʒ绻Ӱ��  yifeng-dodge.c     2002.4.15
// written by yahoo
inherit SKILL;
string *dodge_msg = ({
        HIM"ֻ��$nһʽ��"HIW"Ʈ�������"HIM"����ȫ����һ����磬����Ķ����$N��һ�С�\n"NOR,
        HIR"$nһʽ��"HIW"����Ʈ��ˮ����"HIR"�������Ʈ������֮ң�����ŵıܿ���$N���������ơ�\n"NOR,
      HIW"$nһʽ��"HIC"���İ׷�������"HIW"����˲�����ݳ�����֮Զ���ܿ���$N������ɱ�С�\n"NOR,
       HIG"$nʹ����"HIW"�ɺ������纣"HIG"����ֻ����Ӱ�ζ�,$N�����ֲ�����ĸ�������\n"NOR,
});
int valid_enable(string usage) { return (usage == "dodge"); }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("yifeng-dodge", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
string query_dodge_msg(string limb,object me)
{
         if (me) me->set_temp("fight/dodge",me->query_skill("yifeng-dodge",1)+random(me->query_skill("yifeng-dodge",1)));
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
              return notify_fail("�������̫���ˣ��������Ʒ绻Ӱ��\n");
        me->receive_damage("qi", 30);
        return 1;
}


