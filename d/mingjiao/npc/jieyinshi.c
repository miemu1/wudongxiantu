// JieYinShi
// pal 1997.05.11

#include "ansi.h"

inherit NPC;
inherit F_UNIQUE;

string ask_for_join();

void create()
{
	set_name("����ʹ", ({"jieyin shi","jieyin","shi",}));
	set("long",
		"����һλ�����������ˣ���һ���ײ����ۡ�\n"
		"���������´������㡣\n"
		);

	set("title", HIG "����" NOR);

	set("gender", "����");
	set("attitude", "friendly");

	set("inquiry",([
		"����"	: (: ask_for_join :),
		]));

	set("age", 30);
	set("shen_type", 1);
	set("str", 25);
	set("int", 17);
	set("con", 50);
	set("dex", 21);
	set("max_qi", 450);
	set("max_jing", 200);
	set("neili", 350);
	set("max_neili", 350);
	set("jiali", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("hunyuan-yiqi", 30);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("cuff", 50);
	set_skill("jingang-quan", 50);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "jingang-quan");

	prepare_skill("cuff", "jingang-quan");

	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
}


void init()
{
	::init();
}

string ask_for_join()
{
	return "�н����žͿ��Լ��������̡�\n";
}

int accept_object(object ob, object obj)
{
	object me ;
	string men ;
	mapping family;

	me = this_object ();
	ob = this_player ();

	if (obj->query("id") == "tuijian xin1" &&
	    ob->query_temp("have_letter") )
	{
		if (ob->query("can_apprentice_tuoba"))
			return notify_fail("�����Ͽ�ȥ�ҷ����������ذ�ѧ�ҹ���ʥ�̵������书!\n");

   		if (! mapp(family = ob->query("family")))
   		{
			ob->delete_temp("have_letter");

			if ((string)ob->query("gender") == "Ů��")
				command("say �������ֵ�һŮ�к��ܣ����ǿ�"
					"ϲ�ɺأ�");
			else 
				command("say �������ֵ�һӢ�ۺú������ǿ�"
					"ϲ�ɺأ�");

			ob->set("can_apprentice_menzhu", "������");

			command("smile");
			tell_object(ob,"����ʹ�߶���˵��������ʥ�̹�����ʹ�������졢�ء��硢�����ţ����ȵ������������ذ�����ѧ�����书�ɣ�\n");
			destruct(obj);
			return 1;
		}

   		if (family["family_name"] != "����")
		{
			message_vision("$N��$nҡҡͷ��˵�������Ѿ�����"
				       "���������ˣ��������������̡�\n",
				       me, ob);
			return 1;
		} else
			message_vision("$Nҡҡͷ����$n˵�������Ѿ���������"
				       "�����ˡ�\n", me, ob);
	}
        command("?");
        command("say �ⶫ�����ҿ�û��ʲ���á�");
	return 0;
}

