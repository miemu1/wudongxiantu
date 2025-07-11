// beiming-zhenqi.c 北冥真气
// by QingP

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        if ( me->query("gender") == "无性" && (int)me->query_skill("beiming-zhenqi", 1) > 49)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的北冥真气。\n");

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候不足，不能学北冥真气。\n");

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
                return notify_fail("你不先散了别派内功，怎能学北冥真气？！\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("北冥真气只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"beiming-zhenqi/" + func;
}
