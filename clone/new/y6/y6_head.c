// wusheng_head.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

string do_wear();

void create()
{
	set_name(HIR "远古凝视" NOR, ({"y6 head"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("long", "远古级的的[远古]凝视\n");
		set("material", "head");    //类型
	set("armor_prop/armor", random(299)+96000);  //防御
	set("armor_prop/warm", 10);   //保暖
		set("value", 50);   //价值
		 set("material", "crimson gold");  //原料
		set("wear_msg", (: do_wear :));  //装备信息
		set("icon","05081");  //图象
		  set("suit_point",500);
	//---------------------------------------------------------------
	      //套装参数
		 set("suit",HIR"远古"NOR);  //套装名称
		set("suit_lvl",5);	     //套装等级
		set("suit_count",7);	   //套装部件数量
	      //套装各部件
		set("suit_mod/arrmor","远古圣袍");
		set("suit_mod/finger","远古之戒");
		set("suit_mod/boots","远古之履");
//		set("suit_mod/hands","远古之握");
		set("suit_mod/head","远古凝视");
		set("suit_mod/neck","远古护符");
		set("suit_mod/pants","远古护腿");			     
	    //套装全部附加天赋效果  //身法第一，根骨第二，悟性第三，臂力第四
		set("suit_eff/spirituality",random(5)+77);      //两件
		set("suit_eff/constitution",random(5)+85);       // 五件 
		set("suit_eff/intelligence",random(5)+88);      //三件  
		set("suit_eff/strength",random(5)+90);      //    一套  
	       //套装全部附加技能效果   
		set("suit_eff_skill/force",90);   //一套
		set("suit_eff_skill/dodge",100);
		set("suit_eff_skill/parry",100);

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
			msg = HIC "$N" HIC "轻轻将一件$n" HIC "戴在头上，神态曼妙之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，戴在头上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "戴在头上，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "戴在头上。\n";
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "随手一挥，将$n" HIC "戴在头上，姿势潇洒之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，戴在头上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "戴在头上，扯了扯衣角，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "戴在头上，甚是猥琐。\n";
	}
	return msg;
}

int query_autoload()
{
	return 1;
}
