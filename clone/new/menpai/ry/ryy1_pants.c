// wusheng_pants.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;

string do_wear();

void create()
{
	set_name(HIR "地狱腿绑-日月" NOR, ({"ryy1 pants"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "邪神级的[地狱腿绑-日月]\n");
		set("material", "pants");    //类型
	set("armor_prop/armor", random(50)+170);  //防御
	set("armor_prop/warm", 1);   //保暖   地狱中的，这个没有用
		set("value", 10);   //价值
		set("material", "crimson gold");  //原料
		set("wear_msg", (: do_wear :));  //装备信息
		set("icon","05083");
		  set("suit_point",500);
	//---------------------------------------------------------------
	      //套装参数
		 set("suit",HIR"地狱-日月"NOR);  //套装名称
		set("suit_lvl",5);	     //套装等级
		set("suit_count",7);	   //套装部件数量
	      //套装各部件
		set("suit_mod/arrmor","地狱正装-日月");
		set("suit_mod/finger","地狱之戒-日月");
		set("suit_mod/boots","地狱步履-日月");
//		set("suit_mod/hands","地狱之握-日月");
		set("suit_mod/head","地狱头冠-日月");
		set("suit_mod/neck","地狱之锁-日月");
		set("suit_mod/pants","地狱腿绑-日月");			     
	    //套装全部附加天赋效果  //身法第一，根骨第二，悟性第三，臂力第四
		set("suit_eff/spirituality",random(1)+5);      //两件
		set("suit_eff/constitution",random(1)+8);       // 五件 
		set("suit_eff/intelligence",random(1)+8);      //三件  
		set("suit_eff/strength",random(1)+8);      //    一套  
	       //套装全部附加技能效果   
		set("suit_eff_skill/pixie-jian",10);   //一套
		set("suit_eff_skill/dodge",15);
		set("suit_eff_skill/parry",15);
		set("suit_eff_skill/force",15);
		set("suit_eff_skill/huntian-qigong",10);
		set("suit_eff_skill/huanmo-longtianwu",9);
		set("suit_eff_skill/xixing-dafa",15);

       //---------------------------------------------------------------
	}
	setup();
}

string do_wear()
{
	object me;
	string msg;
	int per;

	me = this_player();
	per = me->query("per");
	if (me->query("gender") == "女性")
	{
		if (per >= 30)
			msg = HIC "$N" HIC "轻轻将一件$n" HIC "绑在腰上，神态曼妙之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，绑在腰上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "绑在腰上，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "绑在腰上。\n";
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "随手一挥，将$n" HIC "绑在腰上，姿势潇洒之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，绑在腰上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "绑在腰上，扯了扯衣角，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "绑在腰上，甚是猥琐。\n";
	}
	return msg;
}

int query_autoload()
{
	return 1;
}
