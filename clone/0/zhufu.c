// dragon-blade 屠龙刀
// Modifyied by rock

//#include <weapon.h>
#include <ansi.h>
inherit ITEM;

// 函数：所属类别
int query_xy() { return 1 ; }


int do_training(string arg);


void create()
{
        set_name(HIY HIM"祝"HIY"福"HIW"宝"RED"石" NOR,({ "zhufu stone", "zhufu"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
		set("long", HIW "这是一颗无时无刻能为你获取修为潜能，还有修炼武功的宝石,""\n""开启("ZJURL("cmds:xunlian exp")ZJSIZE(20)""HIY"修炼模式"NOR")""--""("ZJURL("cmds:xunlian over")ZJSIZE(20)""HIY"结束"NOR")\n" NOR);
		set("no_drop", "这样东西不能离开你。\n");
		set("no_put",1);
		set("no_sell",1);
		set("no_save",1);
		set("no_give",1);
		set("nopaimai",1);
		set("no_get",1);
		set("credit",500);
        set("value", 100000);
		set("zhiliang",3);
		set("level",1);
		set("exp",5000);
		set("weapon_prop/baoji",10000);
                set("material", "magic");
                set("_level",20);
                set("jing",100);
                set("jingli",50);
                set("weapon_prop/strength",5);
                set("weapon_prop/dexerity",5);
                set("weapon_prop/intelligence",5);
                set("weapon_prop/constitution",5);

                set("wield_msg", HIY "$N“唰”的一声抽出$n" + HIY + "但见此刀寒芒吞吐，电闪星飞，天地变色。 ....$N不由得从心底升起一股凌云豪气。\n" NOR);
                set("unwield_msg", HIW "修炼之剑"HIY"幻作一道白光，「唰」地飞入刀鞘。\n" NOR);        }
        	set("max_lasting",100);
        	setup();
}


string check_len(string str)
{
	int max_len = 33,len;

	len = (max_len+color_len(str)) - strlen(str);
	return sprintf("%"+len+"s","│\n");
}

void init()
{
		add_action("do_training", "xunlian");
}

int do_training(string arg)
{
	object me= this_player();

	//if(me->query_temp("weapon") != this_object()) return 0;

	return "/adm/daemons/makeweapon"->call_do_training(me,arg);
}

