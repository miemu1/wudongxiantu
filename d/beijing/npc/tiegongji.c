inherit NPC;
inherit F_BANKER;

void create()
{
	set_name("铁公鸡", ({"tie gongji", "tie", "gongji"}));
	set("title", "钱庄老板");
	set("gender", "男性");
	set("age", 999);
	set("str", 999);
	set("int", 999);
	set("dex", 999);
	set("con", 999);
	set("qi", 999999);
    set("dealer", "bank");
       set("max_qi", 999999);
	set("jing", 100);
	set("max_jing", 100);
	set("shen", 0);

	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 2);
	set("chat_msg", ({
	"铁公鸡白眼一翻，说道：本钱庄是京城中最大的钱庄。\n",
	}));
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);

	setup();
	 carry_object("/d/beijing/npc/obj/cloth")->wear();
	add_money("silver", 30);
}

void init()
{
	add_action("do_check", "check");
	add_action("do_convert", "duihuan");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "qu");
	delete_temp("busy");
}
