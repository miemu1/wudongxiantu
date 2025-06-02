// hufei.c

#include <ansi.h>;

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

string ask_jieniu();
string ask_youren();
string ask_yudi();

void create()
{
	set_name("������", ({"wei beihui", "wei", "beihui"}));
      set("title", "Ѫ��������");
	set("gender", "����");
	set("nickname", "Ѫۙ"HIG"�f��"NOR);
	set("age", 25);
	set("long", @LONG
����ƽ���ߺã��ù������������ġ����䡢���֡���ɫ���ýύ����Ӣ����
LONG);
	set("attitude", "peaceful");
	set("str", 200);
        set("int", 200);
        set("con", 200);
        set("dex", 200);

        set("qi", 999999999);
        set("max_qi", 999999999);
        set("jing", 999999999);
        set("max_jing", 999999999);
        set("neili", 999999999);
        set("max_neili", 999999999);
        set("jiali", 999999999);
        set("combat_exp", 999999999);
        set("score", 999999999);

	set_skill("force", 2800);
        set_skill("longmen-shengong", 2800);
        set_skill("yiqiguan-riyue", 2800);
        set_skill("huaxue-dafa", 2800);
        set_skill("dodge", 2800);
        set_skill("youran-bu", 2800);
        set_skill("parry", 2800);
        set_skill("blade", 2800);
        set_skill("jieniu-dao", 2800);
        set_skill("sword", 2800);
        set_skill("tianhe-jian", 2800);
        set_skill("throwing", 2800);
        set_skill("huaxue-shenzhen", 2800);
        set_skill("cuff", 2800);
        set_skill("feixue-quan", 2800);
        set_skill("whip", 2800);
        set_skill("yudi-bian", 2800);
        set_skill("literate", 2100);

        map_skill("force", "longmen-shengong");
        map_skill("dodge", "youran-bu");
        map_skill("cuff", "feixue-quan");
        map_skill("sword", "tianhe-jian");
        map_skill("whip", "yudi-bian");
        map_skill("throwing", "huaxue-shenzhen");
        map_skill("blade", "jieniu-dao");
        map_skill("parry", "tianhe-jian");

        prepare_skill("cuff", "feixue-quan");   

create_family("Ѫ����", 12, "����");   

set("inquiry",([
		"��ţ��": (: ask_jieniu :),
		"���̼�": (: ask_youren :),
		"��ر�": (: ask_yudi :),
	     ]));

	set("baodao_count", 1);
	set("whip_count", 1);
	set("youren_count", 10);

        set_temp("apply/attack", 28000);
        set_temp("apply/damage", 28000);
        set_temp("apply/unarmed_damage", 28000);
        set_temp("apply/armor", 28000);


	set("chat_chance_combat", 12000);
	set("chat_msg_combat", ({
		(: perform_action, "blade.bashi" :),
		(: perform_action, "blade.huagu" :),
		(: perform_action, "cuff.xueying" :),
		(: exert_function, "xuanwo" :),
	}));

      set("chat_chance", 30);
	set("chat_msg", ({
            (: NPC_D->random_move(this_object()) :),

	}));

	setup();
	carry_object("/kungfu/class/xhp/obj/jieniu-dao")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

string ask_jieniu()
{
	object ob, me;

	me = this_player();
	if (me->query("family/family_name") !=
	    query("family/family_name"))
	{
		command("shake");
		return "������������̸��Щ�¡�\n";
	}	

	if ((int)me->query("combat_exp") < 100000)
		return "����Ŀǰ�ı��컹����ʹ�ý�ţ����\n";

	if ((int)me->query("shen") < 100000)
		return "����Ŀǰ����Ϊ������ʹ�ý�ţ����\n";

	if ((int)query("baodao_count") > 0)
	{
		add("baodao_count", -1);
		ob = new ("/kungfu/class/xhp/obj/jieniu-dao");
		ob->move(me);
		return " �ðɣ���ѽ�ţ��������ȥ�ã�ϣ����ú���������\n";
	} else
		return "�������ˣ�������ѵ��Ѳ��ڴ˴���\n";
}
string ask_yudi()
{
	object ob, me;

	me = this_player();
	if (me->query("family/family_name") !=
	    query("family/family_name"))
	{
		command("shake");
		return "������������̸��Щ�¡�\n";
	}	

	if ((int)me->query("combat_exp") < 100000)
		return "����Ŀǰ�ı��컹����ʹ����رޡ�\n";

	if ((int)me->query("shen") < 100000)
		return "����Ŀǰ����Ϊ������ʹ����رޡ�\n";

	if ((int)query("whip_count") > 0)
	{
		add("whip_count", -1);
		ob = new ("/kungfu/class/xhp/obj/yudi-whip");
		ob->move(me);
		return " �ðɣ���ر�������ȥ�ã�ϣ����ú���������\n";
	} else
		return "�������ˣ�������ر��Ѳ��ڴ˴���\n";
}

string ask_youren()
{
	object ob, me;

	me = this_player();
	if (me->query("family/family_name") !=
	    query("family/family_name"))
	{
		command("shake");
		return "������������̸��Щ�¡�\n";
	}	
	
	if ((int)query("youren_count") > 0)
	{
		add("youren_count", -1);
		ob = new ("/kungfu/class/xhp/obj/youren");
		ob->move(me);
		return " �ðɣ����̼�������ȥ�ã�ϣ����ú���������\n";
	} else
		return "�������ˣ����̼��Ѿ�û���ˡ�\n";
}
void attempt_apprentice(object ob)
{
	object me;

	me = this_object();
	if (ob->name(1) == "ŷ����" || ob->name(1) == "�Wꖪ�")
	{
		message_vision("$N��ŭ����ʦ��������Ҳ������ȡ��!\n", me);
		return;
	}

	if (ob->name(1) == "������")
	{
		message_vision("$N��ŭ���ҵ�����Ҳ������ȡ��!\n", me);
		return;
	}	
	command("recruit " + ob->query("id"));
      command("say �ã��ã��ã��պ�һ��Ҫ�����Ѫ���ɡ�"); 
	return;
}

void die()
{
	object me, ob;

	me = this_object();

	set("eff_qi", 10000000);
	set("qi", 10000000);
	set("eff_jing", 10000000);
	set("jing", 10000000);
	set("neili", 90000000);
	set("max_jingli",1000000);

	say( me->name() + CYN "˵�������Ǳ����ħ��������ġ�\n"NOR);
	return;
}
