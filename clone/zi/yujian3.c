// sunfenger.c

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(HIY "蜀山神剑", ({ "shushan jian" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "蜀山派的镇派之宝。\n");
                set("no_put", 1);
				set("no_give", 1);
				set("no_drop", 1);
				set("no_sell", 1);
                set("no_sun", 1);
                set("no_get", 1);
				set("no_steal", 1);
                set("xy_money", 650);
                set("base_weight", 10);
                set("base_unit", "把");
        }
        set_amount(1);
        setup();
}

void init()
{
        add_action("do_flyto", "flyto");
}

int do_flyto(string arg)
{
        object me;
        object who;
        object env;

        if (! query_amount())
                return 0;
        me = this_player();
        if (! arg)
                return notify_fail("你想往那扔？\n");

        who = find_player(arg);
        if (! objectp(who)) who = find_living(arg);
        if (! objectp(who))
                return notify_fail("找不到位置扔不过去！\n");

        if (! objectp(env = environment(who)))
                return notify_fail("还是先留着吧找不到目标！\n");

		if (me->is_ghost())
			return notify_fail("等你把鬼气散掉在用吧。\n");

		if (! wizardp(me) && wizardp(who))
			return notify_fail("你想被踢吗。\n");

		if (! wizardp(me) && userp(who))
			return notify_fail("你不能扔到玩家身上。\n");

        if (env == environment(me))
                return notify_fail("不想活了？\n");

		if (who->query("newbie") && !(who->query("born")))
		{
			tell_object(me,"想死用suicide快点！\n");
			return 1;
		}


	if (who->query("combat_exp") <= 100000)
	{
		tell_object(me,"不能扔新手！\n");
		return 1;
	}

	if (environment(who)->query("no_magic"))
		return notify_fail("你扔不了那地方。\n");

	if (me->is_busy())
		return notify_fail("等你忙完了再说。\n");

	if (me->query("doing"))
		return notify_fail("等你计划完了再说。\n");

        message_vision(HIM "$N" HIM "召唤出一把大剑默念口诀，"
                       "只见飞剑扶摇之上，冲天而去！\n"
                       "只听“嗖”的一下，$N" HIM "御剑而去！"NOR"\n",
                       me);
        message("vision", HIM "忽见时空一阵扭曲，" + me->name() + HIM
                              "跳下来收起飞剑。"NOR"\n", env);
        tell_object(me, HIM "愉快的向前奔跑着。。但是你没注意前方是出口..."NOR"\n");
        me->move(env);

        return 1;
}

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
        int amt;

        if (sscanf(param, "%d", amt) == 1)
                set_amount(amt);
}
