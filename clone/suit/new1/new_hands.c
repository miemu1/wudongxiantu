// news_pants.c

#include <ansi.h>
#include <armor.h>

inherit HANDS;

string do_wear();

void create()
{
	set_name(HIG "侠义手套" NOR, ({"new hands"}));   //①表示为1阶套装
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是一件"+this_object()->query("name")+"，是地狱家族特别为新人订做的。\n");
		set("material", "hands");    //类型
	set("armor_prop/armor", 10);  //防御
	set("armor_prop/warm", 5);   //保暖
		set("value", 1000);   //价值	 
		set("wear_msg", (: do_wear :));  //装备时显示的信息
      //---------------------------------------------------------------
	      //套装参数
		set("suit",HIG"侠义套装"NOR);  //套装名称
		set("suit_lvl",1);	     //套装等级
		set("suit_count",6);	   //套装部件数量
	       //套装各部件
		set("suit_mod/cloth","侠义长衫");
		set("suit_mod/boots","侠义快靴");
		set("suit_mod/pants","侠义长裤");
		set("suit_mod/sword","侠义剑");
		set("suit_mod/blade","侠义刀");
//		set("suit_mod/hands","侠义手套");
	       //套装全部附加天赋效果  
		set("suit_eff/strength",1);      //两件
		set("suit_eff/intelligence",1);      //三件  
		set("suit_eff/spirituality",1);      //    一套
		set("suit_eff/constitution",1);      //三件  
		//套装全部附加技能效果     
	       set("suit_eff_skill/dodge",10);   
	       set("suit_eff_skill/sword",10);
	       set("suit_eff_skill/blade",10);
	       set("suit_eff_skill/cuff",10);
	       set("suit_eff_skill/strike",10);
	       set("suit_eff_skill/finger",10);
	       set("suit_eff_skill/claw",10);
       //------------------------------------------------------
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
			msg = HIC "$N" HIC "轻轻将一件$n" HIC "套在手上，神态曼妙之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，套在手上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "套在手上，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "套在手上。\n";
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "随手一挥，将$n" HIC "套在手上，姿势潇洒之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，套在手上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "套在手上，扯了扯衣角，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "套在手上，甚是猥琐。\n";
	}
	return msg;
}

int query_autoload()
{
	return 1;
}
