//by 游侠 ranger's ednpc tools.
// shanzei1.c

#include <ansi.h>
inherit NPC;

string *random_ob = ({
"/fuben/box/box3",
"/fuben/box/box3",
"/fuben/box/box3",
"/fuben/box/box4",
"/fuben/box/box4",
});

void create()
{
object ob = this_player();
int lvl = ob->query("qi");
int sklv;
sklv = to_int(pow(to_float(ob->query("combat_exp")*10),0.333333333)+random(15));
if (ob->query("combat_exp")<100000){
sklv = 100;
}
if (lvl > 7000){
lvl = 7000;
}
	set_name(HIM"金国将军"NOR,({"gaoshou"}));
	set("gender", "男性");
	set("per",20);
	set("age", 30);
	set("combat_exp", 1000000+random(3000000));
	set("str", 250);
	set("int", 250);
	set("con", 250);
	set("dex", 100);
	set("chat_chance", 1);
    set("quest2/kuihua/pass", 1);

	set("qi", 7500000);
	set("max_qi", 7500000);
	set("jing", 100000);
	set("max_jing", 100000);
	set("neili", 100000);
	set("max_neili", 100000);
	set("jiali", 2500);
	set("combat_exp", 5000000);
	set("score", 2500);
    set_skill("force", 2500+random(2500));
    set_skill("unarmed", 2500+random(2500));
    set_skill("dodge", 2500+random(2500));
    set_skill("parry", 2500+random(2500));
    set_skill("sword", 2500+random(2500));
    set_skill("hand", 2500+random(2500));
    set_skill("cuff", 2500+random(2500));
    set_skill("strike", 2500+random(2500));
    set_skill("finger", 2500+random(2500));
    set_skill("claw", 2500+random(2500));
    set_skill("blade", 2500+random(2500));
    set_skill("staff", 2500+random(2500));
    set_skill("hammer", 2500+random(2500));
    set_skill("club", 2500+random(2500));
    set_skill("whip", 2500+random(2500));
    
    set_skill("wushang-jianjing", 2500+random(2500));
    set_skill("wushang-jianjing", 2500+random(2500));
    set_skill("wushang-jianjing", 2500+random(2500));
    set_skill("wushang-jianjing", 2500+random(2500));
    set_skill("wushang-jianjing", 2500+random(2500));
    set_skill("wushang-jianjing", 2500+random(2500));
    set_skill("wushang-jianjing", 2500+random(2500));
		
	map_skill("force", "wushang-jianjing");
    map_skill("sword", "wushang-jianjing");
    map_skill("parry", "wushang-jianjing");
    map_skill("unarmed", "wushang-jianjing");
    map_skill("dodge", "wushang-jianjing");
	map_skill("hand", "wushang-jianjing");
    map_skill("cuff", "wushang-jianjing");
    map_skill("strike", "wushang-jianjing");
    map_skill("finger", "wushang-jianjingsA");
    map_skill("claw", "wushang-jianjing");
	map_skill("blade", "wushang-jianjing");
    map_skill("staff", "wushang-jianjing");
    map_skill("hammer", "wushang-jianjing");
    map_skill("club", "wushang-jianjing");
    map_skill("whip", "wushang-jianjing");

    set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "force.wushangb1" :),
		(: perform_action, "force.wushangb2" :),
		(: perform_action, "force.wushangb3" :),
		(: perform_action, "force.wushangb4" :),
		(: perform_action, "force.wushangb5" :),
		(: perform_action, "force.wushangb6" :),
		(: perform_action, "force.wushangb7" :),
		(: exert_function, "force.wushanga1" :),
	}));
	set_temp("apply/attack", 10000);
	set_temp("apply/defense", 2000);
	set_temp("apply/unarmed_damage", 10000);
	set_temp("apply/armor", 2000);

    setup();
}

void die()
{
	string id = random_ob[random(sizeof(random_ob))];//随机物品
	object killer,ob;
	int exp;

	if (objectp(killer = query_last_damage_from()))
	{
		killer->add("combat_exp",350000);
		tell_object(killer,"你杀死"+name()+"，获得35万点修为。\n");
		if(killer->query("zhanling/s2") < 1000)
		{
		killer->add("zhanling/a2",75);
		killer->add("zhanling/s2",75);
		tell_object(killer,"你杀死"+name()+"，获得75战令修为。\n");
		}
	}
	
	switch (random(11))
	{
		case 0 : 
			new(id)->move(killer);
			new(id)->move(killer);
		break;

		case 5 :
			new(id)->move(killer);
			new(id)->move(killer);
		break;

		case 9 :
			new(id)->move(killer);
			new(id)->move(killer);

//CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"在伏击金兵副本中获得了"+id->short()+"。");
		break;
//CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"在伏击金兵副本中获得了"+id->short()+"。");
message("channel:chat",HIW"伏击金兵"HIR"："+killer->query("name")+"击败敌军"+id->short()+"\n"NOR,users());											
		break;
	}
	::die();
}

void unconcious()
{
	die();
}