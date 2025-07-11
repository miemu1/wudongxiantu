// yang.c 杨老板 

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("杨永福", ({ "yang yongfu", "yang" }));
	set("title", "杂货铺老板");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 45);
	set("long",
		"杨老板是土生土长的扬州人，做了几十年的小买卖。\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({  
	      "/clone/cloth/cuttonp",
	      "/clone/pants/piqun",
	      "/clone/misc/sleepbag",
		__DIR__"obj/mabudai",
	      __DIR__"obj/baoguo",
		__DIR__"obj/beixin",
		__DIR__"obj/toukui",
		__DIR__"obj/cycle",
		__DIR__"obj/huwan",
		__DIR__"obj/zhitao",
		__DIR__"obj/huyao",
		__DIR__"obj/caoxie",  
		"d/fuben_huanjing/diaogan",//鱼竿
		}));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

