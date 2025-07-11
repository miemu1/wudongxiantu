inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force)
{
        return 1;
        return force == "tiezhang-xinfa" ||
               force == "tianlei-shengong" ||
               force == "wuqing-xinfa" ||
               force == "bingxin-jue";
}

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("tianlei-shengong", 1);
        return lvl * lvl * 15 * 10 / 100 / 200;
}

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("tianlei-shengong", 1);

        if ((int)me->query_skill("force", 1) < 70)
                return notify_fail("你的基本内功火候还不够。\n");

        if( me->query("gender") == "无性" && lvl>49 )
                return notify_fail("你无根无性，阴阳不调，难以领会高深的天雷神功。\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("天雷神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"tianlei-shengong/" + func;
}