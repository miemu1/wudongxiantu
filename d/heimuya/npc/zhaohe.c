// zhaohe.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "riyue.h"

void create()
{
    set_name("�Ժ�", ({"zhao he", "zhao", "he"}));
    set("nickname", HIC "������ħ" NOR );
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
    set_skill("hand", 160);
    
    set_skill("riyue-xinfa", 160);
    set_skill("huanmo-longtianwu", 160);
    set_skill("xuwu-piaomiao", 160);
    set_skill("piaomiao-shenfa", 160);
    set_skill("literate", 120);

    map_skill("force", "riyue-xinfa");
    map_skill("hand", "huanmo-longtianwu");
    map_skill("parry", "tianmo-gun");
    map_skill("unarmed", "xuwu-piaomiao");
    map_skill("dodge", "piaomiao-shenfa");

	/*
	set("chat_msg_combat", ({
		(: perform_action, "blade.ying" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));
	*/


    create_family("�������", 2, "����");

    setup();
   //carry_object(__DIR__"obj/leizhendang")->wield();
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
