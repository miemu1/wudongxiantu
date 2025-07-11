// hufei.c

#include <ansi.h>;

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

string ask_jieniu();
string ask_youren();
string ask_yudi();

void create()
{
	set_name("卫悲回", ({"wei beihui", "wei", "beihui"}));
      set("title", "血河派掌门");
	set("gender", "男性");
	set("nickname", "血蹤"HIG"萬里"NOR);
	set("age", 25);
	set("long", @LONG
他生平好七好：好功、好名，好文、好武、好闹、好色、好结交天下英豪。
LONG);
	set("attitude", "peaceful");
	set("str", 200);
        set("int", 200);
        set("con", 200);
        set("dex", 200);

        set("qi", 999999999);
        set("max_qi", 999999999);
        set("jing", 999999999);
        set("max_jing", 999999999);
        set("neili", 999999999);
        set("max_neili", 999999999);
        set("jiali", 999999999);
        set("combat_exp", 999999999);
        set("score", 999999999);

	set_skill("force", 2800);
        set_skill("longmen-shengong", 2800);
        set_skill("yiqiguan-riyue", 2800);
        set_skill("huaxue-dafa", 2800);
        set_skill("dodge", 2800);
        set_skill("youran-bu", 2800);
        set_skill("parry", 2800);
        set_skill("blade", 2800);
        set_skill("jieniu-dao", 2800);
        set_skill("sword", 2800);
        set_skill("tianhe-jian", 2800);
        set_skill("throwing", 2800);
        set_skill("huaxue-shenzhen", 2800);
        set_skill("cuff", 2800);
        set_skill("feixue-quan", 2800);
        set_skill("whip", 2800);
        set_skill("yudi-bian", 2800);
        set_skill("literate", 2100);

        map_skill("force", "longmen-shengong");
        map_skill("dodge", "youran-bu");
        map_skill("cuff", "feixue-quan");
        map_skill("sword", "tianhe-jian");
        map_skill("whip", "yudi-bian");
        map_skill("throwing", "huaxue-shenzhen");
        map_skill("blade", "jieniu-dao");
        map_skill("parry", "tianhe-jian");

        prepare_skill("cuff", "feixue-quan");   

create_family("血河派", 12, "掌门");   

set("inquiry",([
		"解牛刀": (: ask_jieniu :),
		"游忍箭": (: ask_youren :),
		"余地鞭": (: ask_yudi :),
	     ]));

	set("baodao_count", 1);
	set("whip_count", 1);
	set("youren_count", 10);

        set_temp("apply/attack", 28000);
        set_temp("apply/damage", 28000);
        set_temp("apply/unarmed_damage", 28000);
        set_temp("apply/armor", 28000);


	set("chat_chance_combat", 12000);
	set("chat_msg_combat", ({
		(: perform_action, "blade.bashi" :),
		(: perform_action, "blade.huagu" :),
		(: perform_action, "cuff.xueying" :),
		(: exert_function, "xuanwo" :),
	}));

      set("chat_chance", 30);
	set("chat_msg", ({
            (: NPC_D->random_move(this_object()) :),

	}));

	setup();
	carry_object("/kungfu/class/xhp/obj/jieniu-dao")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

string ask_jieniu()
{
	object ob, me;

	me = this_player();
	if (me->query("family/family_name") !=
	    query("family/family_name"))
	{
		command("shake");
		return "先入我门来再谈这些事。\n";
	}	

	if ((int)me->query("combat_exp") < 100000)
		return "以你目前的本领还不配使用解牛刀。\n";

	if ((int)me->query("shen") < 100000)
		return "以你目前的作为还不配使用解牛刀。\n";

	if ((int)query("baodao_count") > 0)
	{
		add("baodao_count", -1);
		ob = new ("/kungfu/class/xhp/obj/jieniu-dao");
		ob->move(me);
		return " 好吧，这把解牛刀你先拿去用，希望你好好利用它。\n";
	} else
		return "你来晚了，现在这把刀已不在此处。\n";
}
string ask_yudi()
{
	object ob, me;

	me = this_player();
	if (me->query("family/family_name") !=
	    query("family/family_name"))
	{
		command("shake");
		return "先入我门来再谈这些事。\n";
	}	

	if ((int)me->query("combat_exp") < 100000)
		return "以你目前的本领还不配使用余地鞭。\n";

	if ((int)me->query("shen") < 100000)
		return "以你目前的作为还不配使用余地鞭。\n";

	if ((int)query("whip_count") > 0)
	{
		add("whip_count", -1);
		ob = new ("/kungfu/class/xhp/obj/yudi-whip");
		ob->move(me);
		return " 好吧，余地鞭你先拿去用，希望你好好利用它。\n";
	} else
		return "你来晚了，现在余地鞭已不在此处。\n";
}

string ask_youren()
{
	object ob, me;

	me = this_player();
	if (me->query("family/family_name") !=
	    query("family/family_name"))
	{
		command("shake");
		return "先入我门来再谈这些事。\n";
	}	
	
	if ((int)query("youren_count") > 0)
	{
		add("youren_count", -1);
		ob = new ("/kungfu/class/xhp/obj/youren");
		ob->move(me);
		return " 好吧，游忍箭你先拿去用，希望你好好利用它。\n";
	} else
		return "你来晚了，游忍箭已经没有了。\n";
}
void attempt_apprentice(object ob)
{
	object me;

	me = this_object();
	if (ob->name(1) == "欧阳独" || ob->name(1) == "歐陽獨")
	{
		message_vision("$N大怒：我师傅的名字也是你能取的!\n", me);
		return;
	}

	if (ob->name(1) == "卫悲回")
	{
		message_vision("$N大怒：我的名字也是你能取的!\n", me);
		return;
	}	
	command("recruit " + ob->query("id"));
      command("say 好，好，好，日后一定要光大我血河派。"); 
	return;
}

void die()
{
	object me, ob;

	me = this_object();

	set("eff_qi", 10000000);
	set("qi", 10000000);
	set("eff_jing", 10000000);
	set("jing", 10000000);
	set("neili", 90000000);
	set("max_jingli",1000000);

	say( me->name() + CYN "说道：我是被大白魔王诅咒过的。\n"NOR);
	return;
}
