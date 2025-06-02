// fansong.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "riyue.h"
int ask_pfm(string arg);
int accept_ask(object me, string topic);

void create()
{
    set_name("����", ({"fan song", "fan", "song"}));
    set("nickname", HIW "������ħ" NOR );
    set("title", "������̳���");
    set("gender", "����");
    set("age", 42);
    set("shen_type", -1);
    set("long",
	"����������̳��ϡ�\n");
    set("attitude", "peaceful");

    set("per", 21);
    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);

    set("qi", 3000);
    set("max_qi", 3000);
    set("jing", 1000);
    set("max_jing", 1000);
    set("neili", 3000);
    set("max_neili", 3000);
    set("jiali", 300);

    set("combat_exp", 1500000);
    set("score", 0);

    set_skill("force", 160);
    set_skill("unarmed", 160);
    set_skill("dodge", 160);
    set_skill("parry", 160);
    set_skill("blade", 160);
    
    
    set_skill("riyue-xinfa", 160);
    set_skill("pili-daofa", 160);
    set_skill("xuwu-piaomiao", 160);
    set_skill("piaomiao-shenfa", 160);
    set_skill("literate", 120);

    map_skill("force", "riyue-xinfa");
    map_skill("blade", "pili-daofa");
    map_skill("parry", "pili-daofa");
    map_skill("unarmed", "xuwu-piaomiao");
    map_skill("dodge", "piaomiao-shenfa");

	/*
	set("chat_msg_combat", ({
		(: perform_action, "blade.ying" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));
	*/
    set("inquiry", ([
    "#11-��Ӱ����"  : (: ask_pfm("��Ӱ����") :),
    ]) );
    create_family("�������", 2, "����");

    setup();
    carry_object("/clone/weapon/blade")->wield();
    carry_object("/clone/misc/cloth")->wear();
}
void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;
    if (ob->query_skill("riyue-xinfa", 1) < 120) {
         tell_object(ob, "��������ķ���û�����ҡ�\n");
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
        case "��Ӱ����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/pili-daofa/ying",
                           "name"    : "��Ӱ����",
                           "sk1"     : "pili-daofa",
                           "lv1"     : 100,]));
                break;

        default:
			break;
	}
    tell_object(me, name()+"����˵ʲô����˵һ�飿\n");
	return 1;
}
