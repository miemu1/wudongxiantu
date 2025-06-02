//jiansheng.c by yushu 2000.11
#include <ansi.h>
#include "shushan.h"
inherit NPC;
int ask_jianshen();
inherit F_QUESTER;

#include <ansi.h>
void create()
{
       set_name("��������", ({"shushan jiansheng","jiansheng", "master"}));
       set("title", "��ɽ�ɽ���֮ʥ");
       set("gender", "����");
       set("age", 120);
	set("class", "xiake");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "��ʦ��");
       set("per", 999);
	set("looking", "�������󣬲������Ʈ���𾦷ɻ��棬��Ŀ��ü�ҡ�");
	set("int", 999);
       set("max_qi", 5000000);
       set("max_gin", 5000000);
       set("max_jing", 5000000);
       set("neili", 5000000);
       set("max_neili", 5000000);
       set("jiali", 150);
       set("max_mana", 5000000);
       set("mana", 5000);
         set("combat_exp", 200000000);
        set("max_jingli", 5000000);
        set("max_neili", 5000000);
        set("jingli", 5000000);
        set("neili",5000000);
         set("jiali",5000000);
       set_skill("literate", 9999);
       set_skill("dodge", 9999);
       set_skill("parry", 9999);
        set_skill("spells", 9999);
        set_skill("xianfeng-spells", 9999);
       set_skill("unarmed", 9999);
       set_skill("fumozhang",9999); 
	set_skill("sword", 9999);
     set_skill("songhe-sword", 9999);
        set_skill("shushan-force", 9999);
	set_skill("force", 9999);
      set_skill("zuixian-steps", 9999);
       map_skill("force", "shushan-force");
      map_skill("spells", "xianfeng-spells");
	map_skill("sword", "songhe-sword");
	map_skill("parry", "songhe-sword");
	map_skill("dodge", "zuixian-steps");
       map_skill("unarmed","fumozhang");
       set("chat_chance_combat", 60);
       set("chat_msg_combat", ({
		  (: cast_spell, "fu" :),
        }) );

       set("inquiry", ([
        "����" : (: ask_jianshen :),
       ]) );
        create_family("��ɽ��", 2, "����");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{	ob=this_player();
       if ( !((string)ob->query("gender")=="����")){
       command("shake");
       command("say ��ֻ����ͽ����λ" +RANK_D->query_respect(ob) + "����ȥ�Ҿƽ��ɰɡ�\n");
       return;
       }
       if( (string)ob->query("family/family_name")=="��ɽ��") {
         if ((int)ob->query("combat_exp") < 10000000 ) {
  	command("say ���exp�����������ҵ��з���������\n");
	return;
	}
        if( (int)ob->query_skill("force", 1) < 550 ) {
      command("say ��λ" + RANK_D->query_respect(ob) + "���������ô��,�㻹����׷�������������Ű�!\n");
	command("sigh");
	return;
	}
       command("smile");
       command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ����Ϊ��ɽ���⡣");
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
                ob->set("title", "��ʥ�״�");

}

        return 0;
}

int ask_jianshen()
{

    object ob=this_player();
    if(ob->query("family/family_name") != "��ɽ��")
    {
    command("say ���ֲ�����ɽ�ɵģ�˭���㣡");
    return 1;
    }
    if(ob->query("shushan/jianshen_cast"))
    { 
    command("say �㲻���ʹ�����? ");
    return 1;
    }
    if(ob->query("family/master_name") == "��ɽ��ʥ" )
    {
    command("say ��һ�н�����ΪʦΨһ�ܸ���ģ��������κη������Ӧ�ÿ��԰��㱣���ģ�");
    ob->set("shushan/jianshen_cast",1);
    return 1;
    }
}



�
