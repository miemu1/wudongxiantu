// tongzhi.c ָ��ʹ֪ͬ
// By Lgg,1998.10

#include <ansi.h>;
#include "sanxiu.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name(HIC"������"NOR, ({"zhihuishi tongzhi", "tongzhi"}));
	set("gender", "����");
	set("class", "taoist");
	set("nickname", HIM"����"NOR);
	set("age", 30);
	set("long",
		HIW"�ݣ�һ��ֲ����߲�����������������ҹ��������������֪���١�\n"NOR);
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

	set_skill("force", 160);
	//set_skill("aoqi-xiushenjue", 160);
	//set_skill("qiang", 160);
	//set_skill("bawang-qiang", 160);
	//set_skill("cunxin-quan", 120);
	set_skill("dodge", 160);
	//set_skill("bawang-qiang", 160);
	set_skill("parry", 160);
	//set_skill("bawang-qiang", 160);
	set_skill("literate",160);

	//map_skill("force", "aoqi-xiushenjue");
	//map_skill("qiang", "bawang-qiang");
	//map_skill("dodge", "bawang-qiang");
	//map_skill("parry", "bawang-qiang");

	create_family("ɢ��", 2, "����");

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{

   ob=this_player();
       
      
   if ((int)ob->query("zhuanshi") < 3) 
        {
                command("say �Ҳ������ߣ�");
                return;
        }
		
	 if ((int)ob->query_skill("aoqi-xiushenjue",1) < 130) 
        {
                command("say �������ķ��ɣ�");
                return;
        }
		
		if ((int)ob->query_skill("bawang-qiang",1) < 130) 
        {
                command("say �������书�ɣ�");
                return;
        }

	command("say �ðɣ��Ҿ����������ͽ���ˡ�");
	command("recruit " + ob->query("id"));
	command("say �ã��ã���ɢ���ֶ���һ����������");
	ob->set("title", HIR "ɢ�����" NOR);
}
