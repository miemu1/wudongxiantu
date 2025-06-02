#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_GUARDER;
inherit F_QUESTER;

#include "xuanming.h"

void create()
{
        set_name("�������", ({ "baisun daoren", "baisun", "daoren" }));
        set("gender", "����");
        set("long", @LONG
��������ڤ�ȿ�ɽ��ʦ������ˣ�ֻ�����ٷ�Ʈ����˫��������䣬���˾�η��
LONG);
        set("shen_type", -1);
        set("age", 72);
        set("str", 40);
        set("con", 38);
        set("int", 40);
        set("dex", 46);
        set("max_qi", 7650);
        set("max_jing", 3650);
        set("qi", 7650);
        set("jing", 3650);
        set("neili", 8500);
        set("max_neili", 8500);
        set("jiali", 250);
        set("combat_exp", 6500000);

        set_skill("force", 600);
        set_skill("xuanming-shengong", 600);
        set_skill("dodge", 600);
        set_skill("strike", 600);
        set_skill("lingxu-bu", 600);
        set_skill("hexing-bifa", 600);
        set_skill("strike", 600);
        set_skill("feihua-zhang", 600);
        set_skill("xuanming-zhang", 600);
        set_skill("cuff", 600);
        set_skill("piaofeng-quan", 600);
        set_skill("parry", 600);
        set_skill("claw", 600);
        set_skill("dulong-shenzhua", 600);
        set_skill("sword", 600);        
        set_skill("literate", 220);
        set_skill("martial-cognize", 200);
        
        map_skill("sword",  "hexing-bifa");
        map_skill("strike", "xuanming-zhang");
        map_skill("force",  "xuanming-shengong");
        map_skill("dodge",  "liuying-bu");
        map_skill("parry",  "xuanming-zhang");
        map_skill("cuff",  "piaofeng-quan");
        map_skill("claw",  "dulong-shenzhua");

        prepare_skill("strike", "xuanming-zhang");

        create_family("��ڤ��", 1, "��ɽ��ʦ");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "strike.ying" :),
                (: perform_action, "strike.lang" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set("inquiry", ([
                "¹�ȿ�"    :   "�����Ұ�ͽ��\n",
                "�ױ���"    :   "������ʦ�ܡ�\n",
        ]));

        set("master_ob", 5);
        setup();

        carry_object("/clone/cloth/baipao")->wear();
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if ((int)ob->query_skill("xuanming-zhang", 1) < 120 &&
	    (int)ob->query_skill("xuanming-shengong", 1) < 120) {
		command("say ������ڤ�񹦶�ûѧ͸���������Ϊʦ��"); 
		return;
	}

	if ((int)ob->query_skill("force", 1) < 120) {
		command("say ����ڤ�ȵĵ��书���������ڹ������Ȱ��ڹ�������á�"); 
		return;
	}

	if (ob->query("combat_exp") < 250000)
	{
		command("say �����ΪҲ߯���˵㣬�úö���������˵�ɡ�");
		return;
	}

	command("smile");
	command("chat ����ڤ���ƺ�������ˣ�");
	command("recruit " + ob->query("id"));
}

void unconcious()
{
	die();
}
