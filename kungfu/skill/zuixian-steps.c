// chaos-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$nһ���������ƶˡ��������$N��һ�С�\n",
	"$n�������һ�ݣ�ʹ��һ�С��������ӡ����ܹ���$N�Ĺ�����\n",
	"$nʹ����ǧ����������ǡ�ö����$N�Ĺ��ơ�\n"
       "����$n����Ʈ��,һ�С�Ц���쳾��,����һ�ݣ����ѱܿ���\n",
       "$nʹ�������¹�����,������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
       "$nһ�����������ʡ�,����΢�Σ��о����յرܿ���$N��һ�С�\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge");
}
int query_effect_dodge(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("zuixian-steps", 1);
        if (lvl < 50)  return 0;
        if (lvl < 100) return 30;
        if (lvl < 150) return 50;
        if (lvl < 200) return 80;
        if (lvl < 250) return 100;
        if (lvl < 300) return 120;
        if (lvl < 350) return 140;
        return 150;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30
	||	(int)me->query("neili") < 3 )
		return notify_fail("������������������������������²���\n");
	me->receive_damage("qi", 30);
	me->add("force", -3);
	return 1;
}
