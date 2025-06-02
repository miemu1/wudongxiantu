// shi.c ָ��ʹ
// By Lgg,1998.10

#include <ansi.h>;
#include "sanxiu.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

void create()
{
	set_name(HIC"����"NOR, ({"zhihui shi", "shi"}));
	set("gender", "����");
	set("class", "taoist");
	set("nickname", HIM"��Ʒ����"NOR);
	set("age", 30);
	set("long",
		HIW"��������ɢ�Ʒɣ�����ը���һͳ������ը�������\n"NOR);
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

	set_skill("force", 180);
	//set_skill("aoqi-xiushenjue", 180);
	//set_skill("qiang", 180);
	//set_skill("bawang-qiang", 180);
	//set_skill("cunxin-quan", 120);
	set_skill("dodge", 180);
	//set_skill("bawang-qiang", 180);
	set_skill("parry", 180);
	//set_skill("bawang-qiang", 180);
	set_skill("literate",160);

	//map_skill("force", "aoqi-xiushenjue");
	//map_skill("qiang", "bawang-qiang");
	//map_skill("dodge", "bawang-qiang");
	//map_skill("parry", "bawang-qiang");

	create_family("ɢ��", 0, "���");

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{

   ob=this_player();
       
      
   if ((int)ob->query("zhuanshi") < 5) 
        {
                command("say �Ҳ��ն������ߣ�");
                return;
        }
		
	/* if ((int)ob->query_skill("aoqi-xiushenjue",1) < 160) 
        {
                command("say �������ķ��ɣ�");
                return;
        }
		
		if ((int)ob->query_skill("bawang-qiang",1) < 160) 
        {
                command("say �������书�ɣ�");
                return;
        }*/

	command("say �ðɣ��Ҿ����������ͽ���ˡ�");
	command("recruit " + ob->query("id"));
	command("say �ã��ã���ɢ���ֶ���һ����������");
	ob->set("title", HIR "ɢ�޴���" NOR);
}
