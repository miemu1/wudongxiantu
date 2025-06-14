// huanong.c

#include <ansi.h>
#include <command.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("老农", ({ "lao nong", "nong" }));
	set("nickname","老实人"); 

	set("gender", "男性");
	set("long",
		"一位饱经风霜，对选种播种都颇有心得的老农。\n");
	set("str", 100);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 800000);
	set("attitude", "friendly");

	set("vendor_goods", ([
		"/clone/wine/yuanliao/yumizhong": 10000,//5
		"/clone/wine/yuanliao/xiaomaizhong": 10000,//5
		"/clone/wine/yuanliao/putaozhong": 1000,//10
		"/clone/wine/yuanliao/nuomizhong": 2000,//10
		"/clone/wine/yuanliao/lvdouzhong": 5000,//5
		"/clone/wine/yuanliao/lihuazhong": 5000,//5
		"/clone/wine/yuanliao/gaoliangzhong": 1000,//10
		"/clone/wine/yuanliao/damizhong": 2000,//10							
	]));

	setup();
	set("chat_chance", 5);
	set("chat_msg", ({
		"老农十分诚恳地说：“锄禾日当午，汗滴禾下土。谁知盘中餐，粒粒皆辛苦。”\n",
		"老农叹了口气说：”春种一粒粟，秋收万颗子。四海无闲田，农夫犹饿死。“\n",
	}));

	carry_object("/clone/cloth/cloth")->wear();
	set_max_encumbrance(100000000);
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
