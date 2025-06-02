// renying.c

inherit NPC;
inherit F_MASTER;
#include "riyue.h"

string inquiry_linghuchong();

void create()
{
	set_name("��ӯӯ", ({ "ren yingying","ren","ying"}) );
	set("gender", "Ů��" );
	set("title", "ʥ��" );
	set("age", 20);
	set("shen_type", 1);
	set("combat_exp", 500000);
	set("per", 30);
	set("str", 16);
	set("dex", 27);
	set("con", 17);
	set("int", 18);
	set("attitude", "friendly");
	
	set("qi", 500);
	set("max_qi", 500);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 10);
	
	set_skill("force", 120);
	set_skill("sword", 120);
	set_skill("unarmed", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("whip", 120);
	
	set_skill("riyue-xinfa", 120);
	set_skill("liushui-bian", 120);
	set_skill("piaomiao-shenfa", 120);
	set_skill("riyue-jian", 120);
	set_skill("literate", 120);
	
	map_skill("force", "riyue-xinfa");
	map_skill("whip", "liushui-bian");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("parry", "liushui-bian");
	map_skill("sword", "riyue-jian");
	/*
	set("chat_msg_combat", ({
		(: perform_action, "whip.liuxing" :),
		(: perform_action, "whip.wang" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));
	*/
	set("chat_chance",60);
    	set("chat_msg",({
	"��ӯӯ˵������֪��������������ˣ��Ƿ��ֺ���С������һ��......\n",
	"��ӯӯ˵���������ܰ�������Ӹ�������̫лл����.............\n",
	"��ӯӯ˵����Ҳ��֪����˼�û�����������漱������.......\n",
	   }) );
       
	   create_family("�������", 3, "����");
       set("inquiry",([
		"�����" : (: inquiry_linghuchong:),
	   ]) );
       set_temp("letter",1);
       setup();
       carry_object("/clone/cloth/female5-cloth")->wear();
       carry_object("/clone/weapon/changbian")->wield();
       carry_object("/d/heimuya/npc/obj/letter");
}

string inquiry_linghuchong()
{
 object me=this_player();
 object obn;

 message_vision("��ӯӯ˵����ȥ���ϻ�ɽһȥ���������ţ������������Ұ�......\n", me );
 if(query_temp("letter")==0)
 {  message_vision("��ӯӯ��˵������λ"+ RANK_D->query_respect(me)+"�����Ѿ���
�����ȥѰ���ˣ�Ҳ��֪����ô���ˡ�\n",me);
   return "";
 }
   message_vision("��ӯӯ��˵������λ"+ RANK_D->query_respect(me)+"����������
�ţ���Ҫ���ҵ�����壬�Ͱ��Ž��������������׵ġ�\n" , me);
   obn=new("/d/heimuya/npc/obj/letter");
   obn->move(me);
   set_temp("letter",0);
   
   return ("����ŷ��㽻������塣\n");
}
void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	command("say �ðɣ�����ʥ�õ������������ˡ�");
	command("recruit " + ob->query("id"));
}
