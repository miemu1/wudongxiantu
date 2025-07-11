// news_cloth.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

string do_wear();

void create()
{
	set_name(HIG "天青快靴" NOR, ({"zb2b"}));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("long", "这是一件"+this_object()->query("name")+"，天青套装系列。\n");
		set("material", "boots");    //类型
	set("armor_prop/dodge", 35);  //防御
	set("armor_prop/warm", 5);   //保暖
		set("value", 100000);   //价值
		set("wear_msg", (: do_wear :));  //装备信息
      //---------------------------------------------------------------
	      //套装参数
		set("suit",HIG"天青套装"NOR);  //套装名称
		set("suit_lvl",1);	     //套装等级
		set("suit_count",4);	   //套装部件数量
	      //套装各部件
		set("suit_mod/cloth","天青长衫");
		set("suit_mod/boots","天青快靴");
		set("suit_mod/pants","天青长裤");
		set("suit_mod/sword","天青剑");
		set("suit_mod/blade","天青刀");
//		set("suit_mod/hands","天青手套");
	       //套装全部附加天赋效果  
		set("suit_eff/strength",1);      //两件
		set("suit_eff/intelligence",1);      //三件  
		set("suit_eff/spirituality",1);      //    一套
		set("suit_eff/constitution",1);      //三件  
		//套装全部附加技能效果     
	       set("suit_eff_skill/dodge",50);   
	       set("suit_eff_skill/sword",50);
	       set("suit_eff_skill/blade",50);
	       set("suit_eff_skill/cuff",50);
	       set("suit_eff_skill/strike",50);
	       set("suit_eff_skill/finger",50);
	       set("suit_eff_skill/claw",50);
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
			msg = HIC "$N" HIC "轻轻将一件$n" HIC "穿在脚上，神态曼妙之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，穿在脚上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "穿在脚上，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "穿在脚上。\n";
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "随手一挥，将$n" HIC "穿在脚上，姿势潇洒之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，穿在脚上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "穿在脚上，扯了扯衣角，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "穿在脚上，甚是猥琐。\n";
	}
	return msg;
}

int query_autoload()
{
	return 1;
}
