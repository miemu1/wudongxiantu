// qianshi.c ָ������
// By Lgg,1998.10

#include <ansi.h>;
#include "sanxiu.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name(HIC"��Ц��"NOR, ({"zhihui qianshi", "qianshi"}));
	set("gender", "����");
	set("class", "taoist");
	set("nickname", HIM"����ɢ��"NOR);
	set("age", 30);
	set("long",
		HIW"�ഫ���ַ��ƹ���һ��ը���Ⱥ����Ա����������ɢ�޴���֮һ��\n"NOR);
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

	create_family("ɢ��", 3, "ά����");

	setup();

	carry_object("/clone/weapon/green_sword")->wield();
	carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{

   ob=this_player();
       
      
   if ((int)ob->query("zhuanshi") < 2) 
        {
                command("say �Ҳ���һ�����ߣ�");
                return;
        }
		
	 if ((int)ob->query_skill("aoqi-xiushenjue",1) < 90) 
        {
                command("say �������ķ��ɣ�");
                return;
        }
		
		if ((int)ob->query_skill("bawang-qiang",1) < 90) 
        {
                command("say �������书�ɣ�");
                return;
        }

	command("say �ðɣ��Ҿ����������ͽ���ˡ�");
	command("recruit " + ob->query("id"));
	command("say �ã��ǳ��ã���ɢ���ֶ���һ����������");
	ob->set("title", HIR "ɢ�޷���" NOR);
}
