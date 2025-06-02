// YangXiao.c
// pal 1997.05.09

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_me();
string ask_ling();

void create()
{
	set_name("����", ({"yang xiao","yang","xiao",}));
	set("long",
	"����һλ�������������ײ����ۡ�\n"
	"����ò���ţ�ֻ��˫ü�����´������¶��������������ƣ������Դ�˥�����\n"
	"֮�ࡣ�����Բ�������ɫĮȻ���ƺ��ĳ�Զ����������ʲô���顣\n"
	);

	set("title",HIG "����" HIR "������ʹ" NOR);
	set("level",11);
	set("gender", "����");
	set("attitude", "peaceful");
	
	set("age", 42);
	set("shen_type", 1);
	set("per", 29);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

        set("max_qi", 3500);
        set("max_jing", 150000);
        set("neili", 300000);
        set("max_neili", 300000);
        set("jiali", 1500);
        set("combat_exp", 1000000);
        set("score", 800000);

        set_skill("force", 220);
        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("sword", 220);
        set_skill("cuff", 220);
        set_skill("strike", 220);
        set_skill("literate", 220);

        set_skill("shenghuo-xinfa", 220);
        set_skill("lingxu-bu", 220);
        set_skill("shenghuo-bu", 220);
        set_skill("pili-quan", 220);
        set_skill("shenghuo-quan", 220);
        set_skill("guangming-zhang", 220);
        set_skill("liehuo-jian", 220);
        set_skill("xiaoyao-jian", 220);
        set_skill("martial-cognize", 220);

        map_skill("force", "shenghuo-xinfa");
        map_skill("dodge", "lingxu-bu");
        map_skill("strike", "guangming-zhang");
        map_skill("cuff", "shenghuo-quan");
        map_skill("parry", "xiaoyao-jian");
        map_skill("sword", "xiaoyao-jian");

        prepare_skill("cuff", "shenghuo-quan");
        prepare_skill("strike", "guangming-zhang");

	set("inquiry", 
	([
		"����ʥ����"  : (: ask_me :),
		"����ʥ����"  : (: ask_me :),
		"ʥ����"      : (: ask_me :),
	]));

	set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: command("perform sword.kuai") :),
                (: command("perform sword.qi") :),
                (: command("perform sword.fei") :),
                (: command("perform cuff.jin") :),
        }) );
        set_temp("apply/attack", 120);
        set_temp("apply/damage", 120);
        set_temp("apply/unarmed_damage", 120);
        set_temp("apply/armor", 120);
	create_family("����", 34, "������ʹ");
	setup();
	   
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	object me,ob;
	me = this_object ();
	ob = this_player ();

	::init();

	if (interactive(ob) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}


#include "yangxiao.h"
