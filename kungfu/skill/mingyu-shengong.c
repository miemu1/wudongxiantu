// mingyu-shengong.c ڤ����
// By rock

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("yihua-force", 1);

       if ( !wizardp(this_player()) && (me->query("family/family_name") != "�ƻ���"))
                return notify_fail("�㲻���ƻ������Ӳ���ʹ��ڤ����.\n
                                    Ҫ������λ����֪������ɲ���.\n");
    if ( me->query("gender") != "Ů��")
		return notify_fail("�ƻ���������������,����֪���˿ɲ�����!\n");

/*	if ( me->query_skill("bibo-shengong",1)
	|| me->query_skill("bahuang-gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("zixia-shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧڤ���񹦣���\n");*/

	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    if( damage_bonus < 100 ) return 0;
    if( random(me->query_skill("mingyu-shengong",1)) > 100
    && me->query_temp("rock_yihua")) {
                        victim->receive_wound("qi", (damage_bonus ));
                victim->add("neili", -(int)me->query("jiali"));
return HIM "$N�߶�"HIG"ڤ����"HIM"��һ�������"HIW"�ھ�"HIM"��֮�����������$n��"HIB"��Ԫ"HIM"��������\n" NOR;
        }
}

int practice_skill(object me)
{
    return notify_fail("ڤ����ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
    return __DIR__"mingyu-shengong/" + func;
}
