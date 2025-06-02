// dongfang.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#include "riyue.h"

int ask_pfm(string);
string ask_baodian();
string ask_kuihua();
int accept_ask(object me, string topic);

void create()
{
    set_name("��������", ({"dongfang bubai", "dongfang", "bubai"}));
    set("nickname", HIY "�����޵�" NOR);
    set("title", HIM "������̽���" NOR);
    set("gender", "����");
    set("shen_type", -1);
    set("age", 42);
    set("long",
	"������������̽������ų����˿ɵУ������һ�ƺ�Ϊ���������ܡ���\n");
    set("attitude", "peaceful");

    set("per", 21);
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);

    set("chat_chance", 1);
    set("chat_msg", ({
  	"��������̾�˿����������� ���� �ҵ�����....����ô�����������Һ�\n"
 	"������ ������������������¶������ã��\n",
    }));

    set("qi", 400000);
    set("max_qi", 400000);
    set("jing", 100000);
    set("max_jing", 100000);
    set("neili", 400000);
    set("max_neili", 400000);
    set("jiali", 400);

    set("combat_exp", 5500000);
    set("score", 0);

    set_skill("force", 300);
    set_skill("unarmed", 300);
    set_skill("dodge", 300);
    set_skill("parry", 300);
    set_skill("sword", 300);
    set_skill("hand", 300);
    
    set_skill("riyue-xinfa", 300);
    set_skill("riyue-guanghua", 300);
    set_skill("pixie-jian", 300);
    set_skill("kuihua-shengong", 300);
    set_skill("xuwu-piaomiao", 300);
    set_skill("piaomiao-shenfa", 300);
    set_skill("literate", 300);

    map_skill("force", "kuihua-shengong");
    map_skill("sword", "pixie-jian");
    map_skill("parry", "pixie-jian");
    map_skill("unarmed", "pixie-jian");
    map_skill("dodge", "piaomiao-shenfa");

     set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.cimu" :),
		(: perform_action, "dodge.gui" :),
		(: perform_action, "kuihua" :),
		(: perform_action, "pi" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));
	set("inquiry", ([
		"#01-�����ؾ�"  : (: ask_kuihua() :),
		"#11-��ظ��Ŀ"  : (: ask_pfm("��ظ��Ŀ") :),
		"#21-��ħ����"  : (: ask_pfm("��ħ����") :),
		"#31-��������2"  : (: ask_baodian() :),
         "����ͤ"   : "���ֱ���Ұ��˵����֣�������ѽ�� \n",
         "�����ϲ�" : "������ܰ���ȡ�ÿ��������ϲᣬ��һ������л�㡣\n",
	]) );
	set("no_teach", ([
		"kuihua-shengong"     : "�ٺ٣���ѧ�����񹦣����ּ���ֻ�����о��Ͷ��飬�ҿɲ�����㡣",
	]));
     
    create_family("�������", 1, "�ڶ�������");

    setup();
    carry_object("/d/fuzhou/obj/xiuhua")->wield();
    carry_object("/d/wanjiegu/npc/obj/qi-dress")->wear();
}

string ask_kuihua()
{
   mapping family; 
   object ob, me;
	
   me = this_player();
   if (me->query("quest2/kuihua/pass"))
      return RANK_D->query_respect(me) + "�Ѿ��������洫������ʲô��";
   if ( !(family = me->query("family")) || family["family_name"] !=  "�������")
      return RANK_D->query_respect(me) + "�뱾��������������֪�˻��Ӻ�̸��";
   if (family["master_id"] != "dongfang bubai")
      return RANK_D->query_respect(me) + "���Һ��޹�ϵ����ʲô�ʸ�����Ҫ�ؾ���";
   if (me->query_skill("kuihua-shengong", 1) < 200)
      return RANK_D->query_respect(me) + "�Ŀ����񹦺������ò������";

   me->set("quest2/kuihua/pass", 1);
   
   command("chat �����ҽ��ؾ�������"+me->name()+"�������ܽ���������̷�����");

   return "�ã��ã��ã��Ҷ�������һ��������ں�����ˣ�";
}
string ask_baodian()
{
   mapping family; 
   object ob, me;
	
   me = this_player();
   if ( !(family = me->query("family")) || family["family_name"] !=  "�������")
      return RANK_D->query_respect(me) + "�뱾��������������֪�˻��Ӻ�̸��";
   if (family["master_id"] != "dongfang bubai")
      return RANK_D->query_respect(me) + "���Һ��޹�ϵ����ʲô�ʸ�����Ҫ������";
   if (me->query_skill("kuihua-shengong", 1) < 1 && me->query_skill("pixie-jian", 1) < 180)
      return RANK_D->query_respect(me) + "�ı�а�����������ò������";

   ob = new("/clone/book/kuihuabaodian");
   ob->move(me);
   message_vision("$N�ڶ������������õ�һ��"+ob->name()+NOR"��\n",me);

   return "�ðɣ�"+ob->name()+NOR"�ͽ������ˣ�һ��Ҫ�ú�ѧϰ��";
}
void attempt_apprentice(object ob)
{
   if (! permit_recruit(ob))
		return;
   
   if (ob->query_skill("riyue-xinfa", 1) < 0) {
         tell_object(ob, "��������ķ���û�����ҡ�\n");
         return;
   }
   if (ob->query("shen", 1) > -100000) {
         tell_object(ob, "�㻹����а������ʱ�������㡣\n");
         return;
   }
   if (ob->query("gender", 1) !="����") {
         tell_object(ob, "����Ա��ʺ������ҵ��񹦣����ǿ�ϧ��\n");
         return;
   }
   if (ob->query_skill("xixing-dafa", 1) > 1 || ob->query_skill("tianmo-jian", 1) > 1) {
         tell_object(ob, "���Ѿ�ѧ�����Ǵ󷨻�����ħ���������������㣿\n");
         return;
   }
   if (ob->query("family/master_id") == "ren woxing") {
         tell_object(ob, "�������Ҫ���ģ����������������Ե׵��𣿣�\n");
         return;
   }
   
   command("say �ðɣ��Ҿ��������ˡ�");
   command("recruit " + ob->query("id"));
}
int ask_pfm(string arg)
{
	if (arg) {
		object me = this_player();
		
		return accept_ask(me, arg);
	}
	return 1;
}

int accept_ask(object me, string topic)
{
	if (me->query("family/family_name") == "�������" && me->query("family/master_id") =="dongfang bubai")
	switch (topic)
	{
        case "��ظ��Ŀ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/kuihua-shengong/juemu",
                           "name"    : "��ظ��Ŀ",
                           "sk1"     : "kuihua-shengong",
                           "lv1"     : 150,]));
                break;

        case "��ħ����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/kuihua-shengong/luanwu",
                           "name"    : "��ħ����",
                           "sk1"     : "kuihua-shengong",
                           "lv1"     : 200,]));
                break;
        default:
			break;
	}
      tell_object(me, name()+"����˵ʲô����˵һ�飿\n");
	return 1;
}
