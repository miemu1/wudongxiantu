// news_cloth.c   //angelus

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

string do_wear();

void create()
{
	set_name(HIG "绿影长衫" NOR, ({"zb3b"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是一件"+this_object()->query("name")+"，绿影套装系列。\n");
		set("material", "cloth");     //类型
	set("armor_prop/armor", 60);  //防御
	set("armor_prop/warm", 10);   //保暖
		set("value", 100000);   //价值
		set("wear_msg", (: do_wear :));  //装备信息
       //---------------------------------------------------------------
	      //套装参数
		set("suit",HIG"绿影套装"NOR);  //套装名称
		set("suit_lvl",1);	     //套装等级
		set("suit_count",4);	   //套装部件数量
	      //套装各部件
		set("suit_mod/cloth","绿影长衫");
		set("suit_mod/boots","绿影快靴");
		set("suit_mod/pants","绿影长裤");
		set("suit_mod/sword","绿影剑");
		set("suit_mod/blade","绿影刀");
//		set("suit_mod/hands","绿影手套");
	       //套装全部附加天赋效果  
		set("suit_eff/strength",1);      //两件
		set("suit_eff/intelligence",1);      //三件  
		set("suit_eff/spirituality",1);      //    一套
		set("suit_eff/constitution",1);      //三件  
		//套装全部附加技能效果     
	       set("suit_eff_skill/dodge",35);   
	       set("suit_eff_skill/sword",35);
	       set("suit_eff_skill/blade",35);
	       set("suit_eff_skill/cuff",35);
	       set("suit_eff_skill/strike",35);
	       set("suit_eff_skill/finger",35);
	       set("suit_eff_skill/claw",35);
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
			msg = HIC "$N" HIC "轻轻将一件$n" HIC "披在身上，神态曼妙之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，披在身上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "披在身上，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "披在身上。\n";
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "随手一挥，将$n" HIC "披在身上，姿势潇洒之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，披在身上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "披在身上，扯了扯衣角，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "披在身上，甚是猥琐。\n";
	}
	return msg;
}

int query_autoload()
{
	return 1;
}
