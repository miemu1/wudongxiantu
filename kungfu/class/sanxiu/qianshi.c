// qianshi.c 指挥佥事
// By Lgg,1998.10

#include <ansi.h>;
#include "sanxiu.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name(HIC"萌笑仙"NOR, ({"zhihui qianshi", "qianshi"}));
	set("gender", "男性");
	set("class", "taoist");
	set("nickname", HIM"二阶散修"NOR);
	set("age", 30);
	set("long",
		HIW"相传武林风云过后，一帮炸天帮群众演员组立起来的散修大佬之一。\n"NOR);
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 500);
	set("int", 500);
	set("con", 500);
	set("dex", 500);

	set("chat_chance_combat", 60);

	set("qi", 200000000);
	set("max_qi", 200000000);
	set("jing", 200000000);
	set("max_jing", 200000000);
	set("neili", 30000);
	set("max_neili", 30000);
	set("jiali", 600);

	set("combat_exp", 220000);

	set_skill("force", 130);
	//set_skill("aoqi-xiushenjue", 130);
	//set_skill("qiang", 130);
	//set_skill("bawang-qiang", 130);
	//set_skill("cunxin-quan", 120);
	set_skill("dodge", 130);
	//set_skill("bawang-qiang", 130);
	set_skill("parry", 130);
	//set_skill("bawang-qiang", 130);
	set_skill("literate",130);

	//map_skill("force", "aoqi-xiushenjue");
	//map_skill("qiang", "bawang-qiang");
	//map_skill("dodge", "bawang-qiang");
//	map_skill("parry", "bawang-qiang");

	create_family("散修", 3, "维护仙");

	setup();

	carry_object("/clone/weapon/green_sword")->wield();
	carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{

   ob=this_player();
       
      
   if ((int)ob->query("zhuanshi") < 2) 
        {
                command("say 我不收一阶弱者！");
                return;
        }
		
	 if ((int)ob->query_skill("aoqi-xiushenjue",1) < 90) 
        {
                command("say 多练练心法吧！");
                return;
        }
		
		if ((int)ob->query_skill("bawang-qiang",1) < 90) 
        {
                command("say 多练练武功吧！");
                return;
        }

	command("say 好吧，我就收下你这个徒弟了。");
	command("recruit " + ob->query("id"));
	command("say 好！非常好！我散修又多了一大助力。！");
	ob->set("title", HIR "散修风云" NOR);
}
