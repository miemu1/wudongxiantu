//����ɽ�ɡ�mhxy-yushu 2001/2
#include <ansi.h>
#include "shushan.h"
inherit NPC;
inherit F_MASTER;
int ask_back();
#define BHUOZHU       "/d/shushan/zhenyaota/obj/huozhu"
void create()
{
       set_name(HIW "��������" NOR, ({"master jingxu","jingxu", "master"}));
       set("title",HIC"��ɽ�ɿ�ɽ��ʦ"NOR);
       set("gender", "����");
       set("age", 220);
	set("class", "xiake");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("rank_info/respect", "��ʦ��");
       set("per", 26);
	set("long", "���������󣬲������Ʈ���𾦷ɻ��棬��Ŀ��ü�ҡ�\n");
	set("int", 30);
       set("max_qi", 500000);
       set("max_jing", 50000);
       set("neili", 500000);
       set("max_neili", 25000);
   set("neili", 20000000);
       set("jiali", 1500);
       set("max_mana", 250000);
       set("mana", 250000);
       set("combat_exp", 300000000);
       set_skill("literate", 2000);
       set_skill("dodge", 2000);
       set_skill("parry", 2000);
       set_skill("unarmed", 2000);
        set_skill("fumozhang", 2000); 
        set_skill("songhe-sword", 2000);
        set_skill("spells", 2000);
        set_skill("xianfeng-spells", 2000);
       set_skill("yujianshu", 2000);
       set_skill("shushan-force", 2000);
	set_skill("sword", 2000);
	set_skill("force", 2000);
     set_skill("zuixian-steps", 2000);
      map_skill("spells", "xianfeng-spells");
       map_skill("force", "shushan-force");
	map_skill("sword", "yujian-shu");
	map_skill("parry", "yujian-shu");
	map_skill("dodge", "zuixian-steps");
       map_skill("unarmed","fumozhang");
       set("chat_chance_combat", 10);
       set("chat_msg_combat", ({
	  (: perform_action, "sword." :),
                (: perform_action, "sword." :),
        }) );
        set("inquiry", ([
         "��ȥ" : (: ask_back :),
	  "�򽣾�" : "������ܰ����ҵ��������Ҿͽ��㣡\n",
         ]) );
        create_family("��ɽ��", 1, "����");
        setup();

       carry_object("/clone/cloth/cloth")->wear();
carry_object("/d/shushan/obj/qixing")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
       if( (string)ob->query("family/family_name")=="��ɽ��") {
        if ((int)ob->query("combat_exp") < 300000000 ) {
  	command("say ���exp�����������ҵ��з���������\n");
	return;
	}
 if( (int)ob->query_skill("zuixian-steps", 1) < 1000 ) {
command("say ��λ" + RANK_D->query_respect(ob) + "����������²����������,�㻹���ҽ�ʥ�������Ű�!\n")
;
	command("sigh");
	return;
	}
       if( (int)ob->query_skill("force", 1) < 1000 ) {
	command("say ��λ" + RANK_D->query_respect(ob) + "��Ļ����ڹ����������,�㻹���ҽ�ʥ�������Ű�!\n");
	command("sigh");
	return;
	}
       if( (int)ob->query_skill("sword", 1) < 1000 ) {
	command("say ��λ" + RANK_D->query_respect(ob) + "��Ļ����������������,�㻹���ҽ�ʥ�������Ű�!\n");
	command("sigh");
	return;
	}
       command("smile");
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
                ob->set("title", "��ɽ�������洫��");

}

        return 0;
}
int ask_back()
{

    object ob=this_player();
    if(ob->query("family/family_name") != "��ɽ��")
    {
    command("say ���ֲ�����ɽ�ɵģ������������");
    return 1;
    }
    if(ob->query("shushan/tuoqiao_cast"))
    { 
    command("say �㲻��֪������? ");
    return 1;
    }
    if(ob->query("family/master_name") == "��������" )
    {
    command("say �����ȥ�����ð�!�ҽ���һ�С�����ѿǡ�!");
    command("say ��(cast tuoqiao)���ܳ�ȥ!");
    command("say �´ν���ʱ�Ͳ�Ҫ��ô�鷳��,ȥ�ؾ���(push ���)�Ϳ����ˡ�");
    ob->set("shushan/tuoqiao_cast",1);
    return 1;
    }
}


int accept_object(object me, object obj)
{
object huozhu;
if(base_name(obj)!=BHUOZHU)
{
                command("say ��Ҫ���ǻ�����!��������û��Ȥ��\n");
                return 0;
}
	me->set("shushan/wanjian_perform", 1);
	command("say ��������ô���ĵķ��ϣ��Ҿͽ��㡸�򽣾�����\n");
destruct(obj);
return 1;

}
�
