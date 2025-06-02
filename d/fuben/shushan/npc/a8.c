// tufei.c

inherit NPC;
#include <ansi.h>
#include "/d/fuben/npc/fb_skill.h"

mixed ask_yinguo();

void create()
{
	set_name(HIY"剑"HIW"灵"NOR, ({ "a8"}) );
	set("gender", "男性");
	set("age", 30);
	set("long", "111111111111\n");

	set("combat_exp", 100000+random(300000));
	
	set("attitude", "peaceful");
	set("str", 2);
	set("int", 2);
	set("con", 2);
	set("dex", 2);
		set("max_qi", 6700);
	set("max_jing", 2400);
	set("neili", 10000);
	set("max_neili", 5000);
	set("jiali", 500);

	set("combat_exp", 1800);
	set("shen_type", -1);
	set("apprentice_available", 3);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "sword.feilong" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

	set_skill("unarmed", 310);
	set_skill("martial-cognize", 320);
	set_skill("sword-cognize", 320);
	set_skill("sword", 310);
	set_skill("force", 312);
	set_skill("parry", 310);
	set_skill("strike", 310);
	set_skill("dodge", 310);
	set_skill("literate", 310);
	set_skill("lonely-sword", 350);
	set_skill("huashan-xinfa", 350);
	set_skill("huashan-quanfa", 350);
	set_skill("huashan-zhangfa", 350);
	set_skill("huashan-shenfa", 360);

	map_skill("sword", "lonely-sword");
	map_skill("parry", "kuangfeng-jian");
	map_skill("force", "huashan-xinfa");
	map_skill("unarmed", "huashan-quanfa");
	map_skill("strike", "huashan-zhangfa");
	map_skill("dodge", "huashan-shenfa");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.yi" :),
		(: perform_action, "parry.po" :),
		(: exert_function, "recover" :),
	}) );

	set_temp("apply/attack", 520);
	set_temp("apply/defense", 520);
	set_temp("apply/damage", 500);
	set_temp("apply/unarmed_damage", 500);


	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();

	setup();

	add_money("silver", 5+random(5));
}

void die()
{

           ::die(); 
}