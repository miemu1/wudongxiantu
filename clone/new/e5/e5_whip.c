#pragma save_binary
#include <weapon.h>
#include <ansi.h>

inherit WHIP;


void create()
{
	set_name(HIG"灵动长鞭"NOR, ({"lingdong whip"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把不知道什么材料做的长鞭，发出幽幽的光芒\n");
		set("value", 2000);   //价值
		 set("material", "crimson gold");  //原料
		set("wield_msg",
"$N「唰」地一声抽出一把$n握在手中．\n");
		set("unwield_msg",
"$N将手中的$n卷入腰间，嘴角露出一丝笑意．\n");
	 set("weapon_prop/int", 2);
	 set("icon","05093");
	    set("suit_point",1000);
       //---------------------------------------------------------------
	      //套装参数
		 set("suit",HIG"灵动"NOR);  //套装名称
		set("suit_lvl",5);	     //套装等级
		set("suit_count",7);	   //套装部件数量
	      //套装各部件
		set("suit_mod/arrmor","灵动披风");
		set("suit_mod/finger","灵动指环");
		set("suit_mod/whip","灵动长鞭");
//		set("suit_mod/hands","灵动护腕");
		set("suit_mod/head","灵动发髻");
		set("suit_mod/neck","灵动护符");
		set("suit_mod/pants","灵动腿甲");
	    //套装全部附加天赋效果  //身法第一，根骨第二，悟性第三，臂力第四
		set("suit_eff/constitution",random(2)+2);       //两件
		set("suit_eff/spirituality",random(2)+2);      // 五件
		set("suit_eff/intelligence",random(2)+2);      //三件
		set("suit_eff/strength",random(2)+2);      //    一套
	       //套装全部附加技能效果
		set("suit_eff_skill/whip",10);   //一套
		set("suit_eff_skill/dodge",10);
       //---------------------------------------------------------------
	}
	init_whip(random(40)+80);
	setup();
}

int query_autoload()
{
	return 1;
}

