// wusheng_neck.c

#include <ansi.h>
#include <armor.h>

inherit NECK;

string do_wear();

void create()
{
	set_name(HIR "邪神护符-佛" NOR, ({"sly1 neck"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "邪神级的[邪神项链-佛]\n");
		set("material", "neck");    //类型
	set("armor_prop/armor", random(50)+170);  //防御
	set("armor_prop/warm", 1);   //保暖
	       set("value", 10);   //价值
		 set("material", "crimson gold");  //原料
		set("wear_msg", (: do_wear :));  //装备信息
		set("icon","05085");
		  set("suit_point",500);
       //---------------------------------------------------------------
	      //套装参数
		 set("suit",HIR"邪神-佛"NOR);  //套装名称
		set("suit_lvl",5);	     //套装等级
		set("suit_count",7);	   //套装部件数量
	      //套装各部件
		set("suit_mod/arrmor","邪神圣袍-佛");
		set("suit_mod/finger","邪神之戒-佛");
		set("suit_mod/boots","邪神之履-佛");
//		set("suit_mod/hands","邪神之握佛");
		set("suit_mod/head","邪神凝视-佛");
		set("suit_mod/neck","邪神护符-佛");
		set("suit_mod/pants","邪神护腿-佛");			     
	    //套装全部附加天赋效果  //身法第一，根骨第二，悟性第三，臂力第四
		set("suit_eff/spirituality",random(2)+7);      //两件
		set("suit_eff/constitution",random(2)+7);       // 五件 
		set("suit_eff/intelligence",random(2)+7);      //三件  
		set("suit_eff/strength",random(2)+7);      //    一套  
	       //套装全部附加技能效果   
		set("suit_eff_skill/force",10);   //一套
		set("suit_eff_skill/dodge",15);
		set("suit_eff_skill/parry",15);
		set("suit_eff_skill/finger",15);
		set("suit_eff_skill/yijinjing",10);
		set("suit_eff_skill/buddhism",15);
		set("suit_eff_skill/jingang-quan",10);

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
			msg = HIC "$N" HIC "轻轻将一件$n" HIC "挂在胸前，神态曼妙之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，挂在胸前。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "挂在胸前，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "挂在胸前。\n";
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "随手一挥，将$n" HIC "挂在胸前，姿势潇洒之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，挂在胸前。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "挂在胸前，扯了扯衣角，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "挂在胸前，甚是猥琐。\n";
	}
	return msg;
}

int query_autoload()
{
	return 1;
}
