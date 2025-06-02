// xiang.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "riyue.h"
int ask_pfm(string);
int accept_ask(object me, string topic);

int ask_kill();

void create()
{
    set_name("������", ({ "xiang wentian", "xiang"}));
    set("nickname", HIR "��������" NOR );
    set("gender", "����");
    set("title", "������̹�����ʹ");
    set("long", "������������̵Ĺ�����ʹ��Ϊ�˼�Ϊ��ˬ��\n");
    set("age", 45);
    set("shen_type", -1);

    set("str", 21);
    set("per", 28);
    set("int", 30);
    set("con", 26);
    set("dex", 30);
    set("chat_chance", 1);
    set("inquiry", ([
      "#11-������ˮ"  : (: ask_pfm("������ˮ") :),
      "����ͤ"     : "�����ˣ���ɱ��\n",
      "��������"   : "��λ��ͽ���ҷ�ɱ�������ɣ�\n",
      "ɱ��������" : (: ask_kill() :),
      "������"     : "��������������ʮ��......\n",
    ]));
    set("qi", 4000);
    set("max_qi", 4000);
    set("jing", 1000);
    set("max_jing", 1000);
    set("neili", 3500);
    set("max_neili", 3500);
    set("jiali", 80);

    set("combat_exp", 2500000);
    set("score", 0);

    set_skill("force", 160);
    set_skill("unarmed", 160);
    set_skill("dodge", 160);
    set_skill("parry", 160);
    set_skill("sword", 160);
    set_skill("blade", 160);
    set_skill("strike", 160);
    
    set_skill("riyue-xinfa", 160);
    set_skill("tianmo-zhang", 160);
    set_skill("tianmo-dao", 160);
    set_skill("tianmo-jian", 160);
    set_skill("xuwu-piaomiao", 160);
    set_skill("piaomiao-shenfa", 160);
    set_skill("literate", 160);

    map_skill("force", "riyue-xinfa");
    map_skill("sword", "tianmo-jian");
    map_skill("blade", "tianmo-dao");
    map_skill("strike", "tianmo-zhang");
    map_skill("parry", "tianmo-gun");
    map_skill("unarmed", "xuwu-piaomiao");
    map_skill("dodge", "piaomiao-shenfa");

	/*
	set("chat_msg_combat", ({
		(: perform_action, "strike.huashen" :),
		(: perform_action, "strike.huashen" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));
	*/
    create_family("�������", 2, "������ʹ");

    setup();
    carry_object(__DIR__"obj/cloth")->wear();
}

int ask_kill()
{
   object ob,me = this_player();

   command("tell "+this_player()->query("id")+" ��Ҫȥɱ�������ܣ�\n");
   message_vision(HIC "�������$N���˵�ͷ˵��������һ��֮����"NOR"\n",this_player());
   ob=new("/d/heimuya/npc/obj/card4");
   ob->move(me);
   tell_object(me,"������ӻ�������һ����������������ϡ�\n");
   return 1;
}
void attempt_apprentice(object ob)
{
   if (! permit_recruit(ob))
		return;
   
   if (ob->query_skill("riyue-xinfa", 1) < 120) {
         tell_object(ob, "��������ķ���û�����ҡ�\n");
         return;
   }

   if (ob->query("gender", 1) =="����") {
         tell_object(ob, "����ƽ�������綫������һ�������ˣ�\n");
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
	if (me->query("family/family_name") == "�������")
	switch (topic)
	{
        case "������ˮ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/liushui-bian/wang",
                           "name"    : "������ˮ",
                           "sk1"     : "liushui-bian",
                           "lv1"     : 120,]));
                break;

        default:
			break;
	}
	tell_object(me, name()+"����˵ʲô����˵һ�飿\n");
	return 1;
}

