//����ɽ�ɡ�mhxy-yushu 2001/2
#include <ansi.h>
#include "shushan.h"
inherit NPC;
string ask_me();
int ask_jiu();
void create()
{
       set_name("�ƽ���", ({"jiu jianxian", "jianxian", "xian"}));
       set("title", HIC"���ʿ"NOR);   
       set("long", "һ��������š��ƽ��ɡ������ٲ���������������ɽ��֮�ϣ��������ڽ�ͷ����֮�С�\n");
       set("gender", "����");
       set("age", 68);
       set("attitude", "peaceful");
       set("class", "xiake");
       set("str", 80);
       set("int", 80);
       set("per", 80);
       set("con", 80);
       set("combat_exp", 100000000);
       set("max_qi", 3700000);
       set("max_jing", 1700000);
       set("neili", 4000000);
       set("max_neili", 2000000);
       set("jiali", 1200);
       set("max_mana", 2000);
       set("mana", 4000);
       set("max_jingli", 200000);
       set("max_neili", 200000);
     set("jingli", 200000);
        set("neili",3000000);
        set_skill("shushan-force", 1000);
      set_skill("yujianshu", 1000);
      set_skill("fumozhang", 1000); 
      set_skill("zuixian-steps", 1000);
        set_skill("spells", 1000);
        set_skill("xianfeng-spells", 1000);
       set_skill("sword", 1000);
       set_skill("unarmed", 1000);
       set_skill("dodge", 1000);
       set_skill("literate", 1000);
       set_skill("force", 1000);
       set_skill("parry", 1000);
       map_skill("dodge", "zuixian-steps");
      map_skill("spells", "xianfeng-spells");
	map_skill("parry", "yujian-shu");
	map_skill("sword", "yujian-shu");
       map_skill("force", "shushan-force");
       map_skill("unarmed","fumozhang");
       set("chat_chance_combat", 60);
       set("chat_msg_combat", ({
		  (: cast_spell, "fu" :),
                (: perform_action, "sword", "fumo" :),
        }) );
       set("inquiry", ([
        "����" : (: ask_jiu :),
	  "����" : (: ask_me :),

       ]) );
       create_family("��ɽ��", 2, "����");
set("book_count", 1);
       setup();
      carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="��ɽ��") {
         if ((int)ob->query("combat_exp") < 10000000 ) {
  	command("say ���exp��������" + RANK_D->query_respect(ob) + "������Ŭ�����С�\n");
	return;
	}
       if( (int)ob->query_skill("force", 1) < 750 ) {
        command("say ��λ" + RANK_D->query_respect(ob) + "�㿴��ĺ����������Ұ�ʦ? �㻹����׷�����������Ű�!\n");
	command("sigh");
	return;
	}
       command("haha");
       command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
       command("recruit " + ob->query("id") );
	return;
	}
       command("shake");
       command("say ���Ǳ��ɵ���?��" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
       return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "��ɽ�ƽ��ɵ���");

               } 
}

int ask_jiu()
{

    object ob=this_player();
    if(ob->query("family/family_name") != "��ɽ��")
    {
    command("say ���ֲ�����ɽ�ɵģ�˭���㣡");
    return 1;
    }
    if(ob->query("shushan/jiushen_cast"))
    { 
    command("say �㲻���ʹ�����? ");
    return 1;
    }
    if(ob->query("family/master_name") == "�ƽ���" )
    {
    command("say ��һ�о�����ΪʦΨһ�ܸ���ģ��������κη������Ӧ�ÿ��԰��㱣���ģ�");
    ob->set("shushan/jiushen_cast",1);
    return 1;
    }
}


string ask_me()
{
        mapping fam; 
        object ob;
        if (!(fam = this_player()->query("family")) 
        || fam["family_name"] != "��ɽ��")
                return RANK_D->query_respect(this_player()) + 
                "�ֲ�����ɽ�ɵģ�˭���㣡";
        if (query("book_count") < 1)
                return "��������";
        add("book_count", -1);
        ob = new("/d/shushan/obj/xfbook");
        ob->move(this_player());
        return "�ðɣ������û�ȥ�ú����С�";
}

�
