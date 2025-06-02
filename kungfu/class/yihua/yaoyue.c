// /NPC gongzhu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
void create()
{
	set_name("����", ({ "yao yue", "yao", "yue" }));
	set("long",
	    "�����ǡ��ƻ������Ŀ�ɽ��ʦ.\n"+
	    "���ñ�������ɴ������,����͸���ǿ���ɴ����Ȼ��ϡ�ɼ�\n"+
	    "����ɫɷ��,�Բ����˼����˿�����,�㲻�ɵö࿴��һ��.\n");
	set("title", "�ƻ�������");
	set("gender", "Ů��");
	set("age", 36);
	set("nickname", HIR "ɱ�����¸��ĺ�" NOR);
      set("shen_type",-500);
	set("attitude", "peaceful");

    set("str", 1550);
	set("int", 350);
	set("con", 400);
	set("dex", 250);

    set("max_qi", 5000000);
    set("jym_level/level",15);
	set("jing", 14000);
    set("max_jing", 3000000);
    set("neili", 4500000);
     set("max_neili", 4000000);
      set("jiali", 800);
set("no_suck",1);

      set("combat_exp", 600000000);
	set("score", 2000000);
        set_skill("force", 300);
        set_skill("strike", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("sword",300);
        set_skill("literate",300);
        set_skill("mingyu-gong",300);
        set_skill("jueqing-zhang",300);
        set_skill("mingyu-shengong",300);
        set_skill("yifeng-jian",300);
        set_skill("yihua-jiemu",300);
         set_skill("yifeng-dodge",300);



	map_skill("force", "mingyu-gong");
	map_skill("strike", "jueqing-zhang");
		map_skill("dodge", "yihua-jiemu");
	map_skill("parry", "yihua-jiemu");
         map_skill("dodge","yifeng-dodge");
        map_skill("sword","yifeng-jian");

	create_family("�ƻ���",1, "���¹���");
set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "sword.yifeng" :),
			}) );
	setup();
	carry_object("/d/city/obj/changjian")->wield();
    carry_object("/d/yihua/obj/jinlvyi")->wear();

}

void attempt_apprentice(object ob)
{

   if ((string)ob->query("gender")!="Ů��")
           {
 		command("chat* heihei");
                command("chat ����һ����޵ľ�������,��ȥ����!");
                kill_ob(this_player());
                command("perform yifeng");
		return;
	   }
   if ((int)ob->query_skill("dodge", 1) < 100)
           {
		command("say " + RANK_D->query_respect(ob) + "���������!");
		return;
	   }
   if ((int)ob->query_skill("mingyu-shengong", 1) < 150)
           {
		command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö�����ڤ���񹦣�");
		return;
	   }
   if (ob->query_per() < 19)
      	   {
		command("say ƾ����ģ���������Ϊʦ.");
		return;
	   }
   if (ob->query_con() < 20)
      	   {
		command("say ���Ź�����Ϊ����,��ĸ����ƺ�����.");
		return;
	   }
   command("recruit " + ob->query("id"));
   if((string)ob->query("class") != "chuanren")
     ob->set("class", "chuanren");
   return;
}

void init()
{
	object ob;

	::init();

	ob = this_player();

	if (interactive(ob) && (!ob->query("gender") || ob->query("gender")!="Ů��"))
	{
			command("heihei");
			command("say ��ƽ�����������ˣ��㾹Ȼ���������ðɣ��Ҿͳ�ȫ���㣡\n");
			remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                        command("perform yifeng");
	}
	else if(ob->query("gender")=="Ů��")
	{
	command("smile");
	command("say �����㲻�����˲�Ȼ������úܲҡ�");
	}
}
