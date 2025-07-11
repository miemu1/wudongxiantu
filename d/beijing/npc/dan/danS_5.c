#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
	set_name(HIC"青龙" NOR HIY "神农丹"NOR, ({ "qinglong dan", "dan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "增加350点修为和潜能，并补满精力和内力，冷却30秒。\n");
		set("base_unit", "粒");
		set("no_drop", "这样东西不能离开你。\n");
		set("no_sell", "这样东西不能离开你。\n");
		set("no_put", "这样东西不能放在那儿。\n");
		set("no_get", "这样东西不能离开那儿。\n");
		set("no_steal", "这样东西不能离开那儿。\n");
		set("no_beg", "这样东西不能离开那儿。\n");
		set("base_value", 0);
		set("only_do_effect", 1);
	}
	setup();
	set_amount(1);
}

int do_effect(object me)
{
	mapping my;

	if (time() - me->query_temp("last_eat/dan(S)") < 30)
	{
		write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
		return 1;
	}

	my = me->query_entire_dbase();

	me->set_temp("last_eat/dan(S)", time());

	message_sort(HIC "$N" HIC "吃下一颗$n" HIC "，只觉"
		     "全身筋脉逆流而上，内力源源不断的涌入"
		     "丹田，说不出的舒服受用。顿时感到灵台"
		     "处如湖面一般平静，以往所学的武学知识"
		     "一一涌向心头，在灵台处交融贯通。$N" HIC
		     "感到的修为和潜能有了一定的进展。"NOR"\n", me, this_object());
	me->set("jingli", me->query("max_jingli"));
	me->set("neili", me->query("max_neili"));
	me->add("combat_exp", 350);
	me->add("potential", 350);

	me->start_busy(2);

	add_amount(-1);
	if (query_amount() < 1)
		destruct(this_object());

	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
