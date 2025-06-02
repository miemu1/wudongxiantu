//zhangwuji.c

inherit F_MASTER;
inherit F_QUESTER;
inherit F_UNIQUE;
inherit NPC;

#include <ansi.h>
#include "mingjiao.h"

void greeting(object ob);
string ask_ling();
int ask_pfm(string);
int accept_ask2(object me, string topic);

void create()
{
    seteuid(getuid());
    set_name("���޼�", ({ "zhang wuji", "zhang", "wuji" }));
    set("long", @LONG
���̽������޼ɣ�ͳ������ʮ����ڣ��������ƣ�߳��ǧ�
�������񹦡�����Ǭ����Ų�ơ��������£��ǽ����в�������
����Ӣ�ۡ�
LONG );
    set("title",HIG "����" HIM " ����" NOR);
    set("gender", "����");
    set("age", 20);
	set("no_get", 1);
    set("shen_type",1);
    set("attitude", "friendly");
    set("class", "fighter");

    set("str", 33);
    set("int", 35);
    set("con", 38);
    set("dex", 33);

	set("qi", 580000);
	set("max_qi", 580000);
	set("jing", 27000);
	set("max_jing", 27000);
	set("neili", 80000);
	set("max_neili", 80000);
	set("jiali", 120);

    set("combat_exp", 2900000);
    set("score", 455000);
    
        set_skill("force", 3000);
        set_skill("unarmed", 3000);
        set_skill("dodge", 3000);
        set_skill("parry", 3000);
        set_skill("cuff", 3000);
        set_skill("sword", 3000);
        set_skill("blade", 3000);
        set_skill("strike", 3000);
        set_skill("claw", 3000);
        set_skill("throwing", 3000);
        // set_skill("duoming-jinhua", 450);
        set_skill("jiuyang-shengong", 3000);
        set_skill("shenghuo-xinfa", 3000);
        set_skill("shenghuo-shengong", 3000);
        set_skill("lingxu-bu", 3000);
        set_skill("shenghuo-bu", 3000);
        set_skill("qingfu-shenfa", 3000);
        set_skill("qiankun-danuoyi", 3000);
        set_skill("qishang-quan", 3000);
        set_skill("taiji-quan", 3000);
        set_skill("taiji-jian", 3000);
        set_skill("taiji-dao", 3000);
        set_skill("lieyan-dao", 3000);
        set_skill("liehuo-jian", 3000);
        // set_skill("yingzhua-shou", 450);
        // set_skill("hanbing-mianzhang", 450);
        set_skill("shenghuo-ling", 3000);
        set_skill("guangming-zhang", 3000);
        set_skill("medical", 300);
        set_skill("literate", 300);
        set_skill("martial-cognize", 3000);
        set_skill("guangming-jing", 3000);

        map_skill("force", "jiuyang-shengong");
        map_skill("dodge", "qingfu-shenfa");
        map_skill("unarmed", "jiuyang-shengong");
        map_skill("strike","guangming-zhang");
        map_skill("cuff", "qishang-quan");
        map_skill("sword","shenghuo-ling");
        map_skill("parry","qiankun-danuoyi");
        map_skill("blade","taiji-dao");
        // map_skill("claw", "yingzhua-shou");
        // map_skill("throwing", "duoming-jinhua");
        // map_skill("strike", "hanbing-mianzhang");

        prepare_skill("cuff", "qishang-quan");

    create_family("����", 34, "����");
        set_temp("apply/attack", 180);
        set_temp("apply/damage", 180);
        set_temp("apply/unarmed_damage", 180);
        set_temp("apply/armor", 180);
    
        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: command("perform sword.hua") :),
                (: command("perform sword.xi") :),
                (: command("perform sword.lian") :),
                (: command("perform sword.can") :),
                (: command("perform cuff.shang") :),
                (: command("perform cuff.fei") :),
                (: command("yun shield") :),
                (: command("yun powerup") :),
                (: command("yun recover") :),
        }) );
	   
    set("chat_chance", 1);
    set("chat_msg", ({
	"���޼ɷ�Ȼ˵�������ɷ��Թ�Ϊ��, ����ɳ��, ��Ԫ��ҵδ��, ͬ������Ŭ��!��\n",
	"���޼�̾��������ʧһ֪��, ����λ�, �������, ����, ��������?��\n",
	"���޼ɵ����ҽ��ֵ�����: ��������, ���˼�Ϊ��, ��������, ������ħ!��\n",
    }));

    set("inquiry",([
	  "����" :     "���������������ʲô����\n",
	  "��ëʨ��" : "�������常л������ְ˾��\n",
	  "лѷ" :     "���������常�Ĵ�š�\n",
	  "�Ŵ�ɽ" :   "�������Ҹ���������? \n",
	  "������" :   "����������������΢������\n",
	  "������" :   "��̫ʦ�������ɺ�? \n",
	  "����" :     "����ʧһ֪��, ����λ�, �������, ����, ��������?\n",
	  "С��" :     "С���ҿ�һֱ�������ĺô���\n",
	  "������" :   "������ȥ����ɽ, �������ҡ�\n",
		"#1-������"   : (: ask_ling :),
		"#11-���ػ���"  : (: ask_pfm("���ػ���") :),
		"#21-��������"  : (: ask_pfm("��������") :),
		"#31-����һ��"  : (: ask_pfm("����һ��") :),
		"#41-��������"  : (: ask_pfm("��������") :),
		"#51-ħ�����޼�"  : (: ask_pfm("ħ�����޼�") :),
    ]));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	// carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/book/shenghuo-ling")->wield();
	add_money("silver", 70);
}

void init()
{
	object ob;

	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		this_player()->add_temp("beat_count", 1);
	}       
	if (interactive(ob=this_player()) && ! is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}
int ask_pfm(string arg)
{
	if (arg) {
		object me = this_player();
		
		return accept_ask2(me, arg);
	}
	return 1;
}

void greeting(object ob)
{
	if (! ob || environment(ob)!=environment()) return;
	if ((int)ob->query("shen") < -50000)
	{
		command("wield yitian jian");
		command("hit" + (string)ob->query("id"));
		command("unwield yitian jian");
	} else
	if ((int)ob->query("shen") < -5000)
	{
		command("say ħ����������ѧ������������Ȱ������������"
			"���سɷ�");
	} else
	if((int)ob->query("shen") < -100)
	{
		command("say ��λ���ѣ����н��������е����������߽�аħ�����");
	} else
	if((int)ob->query("shen") >= 0)
	{
		command("say �������������ߣ�Ȱ����ӱ��ء�");
	} else
	if((int)ob->query("shen") > 50000)
	{
		command("say �������ϣ����޼�һ�񣬴������ձ�Ϊ�����̳���");
	}
	return;
}
void attempt_apprentice(object ob)
{
        object me  = this_object();
        mapping ob_fam;
        mapping my_fam = me->query("family");

        string name, new_name;

        if (! permit_recruit(ob))
                return;

        if( !(ob_fam=ob->query("family")) || ob_fam["family_name"] != "����" )
        {
                command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
                return;
        }
/*
        if ( ob_fam["generation"] > my_fam["generation"] + 2)
        {
                command("say " + RANK_D->query_respect(ob) + "������ȥ�ҽ��������ֵܺú�ѧѧ�书�ɡ�");
                return;
        }
*/
        if( ob->query("shen")<100000 )
        {
                command("say ����������������û�������������ذɡ�");
                return;
        }

        if( ob->query("combat_exp")<1000000 )
        {
                command("say �����Ϊ̫�٣��ú���ȥ���������������ɱ�������̶����� !");
                return;
        }

        command("say �����ã�������������һλ�������֣����ǿ�ϲ�ɺ� !");

        command("say ��ϲ������Ϊ���̹���ʹ�ߣ�");
        command("recruit "+ob->query("id"));

        return;
}

int accept_fight(object ob)
{
	if ((ob->query("combat_exp") < 30000) && (ob->query("shen") > 0))
	{
		message_vision("�������������ǿ���ݣ��㲻���ҵĶ��֣�"
			       "��ȥ�ɡ�\n",ob);
		return 0;
	}
	message_vision("���޼�һ����˵������λ" + RANK_D->query_respect(ob) +
		       "����������ˡ�\n", ob);
	return 1;
}
string ask_ling()
{
	mapping family, skl; 
	string *sname;
	object ob;
	int i;
	
	if ( !(family = this_player()->query("family")) || family["family_name"] !=  "����" )
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";

	skl = this_player()->query_skills();
	sname  = sort_array( keys(skl), (: strcmp :) );

	ob = new("d/mingjiao/obj/tieyanling");
	ob->move(this_player());
	message_vision("$NҪ��һ�������\n",this_player());

	return "�ðɣ�ƾ�������������������������ս��";

}

int accept_ask2(object me, string topic)
{
	int gongxian = me->query("gongxians");
	if(!gongxian>20000)
		return notify_fail("��ʦ�Ź��ײ�����");
	if (me->query("can_skill/jiuyang-shengong") && me->query("family/family_name") == "����")
	switch (topic)
	{
        case "���ػ���" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jiuyang-shengong/jiu",
                           "name"    : "���ػ���",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 80,]));
                break;

        case "��������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jiuyang-shengong/pi",
                           "name"    : "��������",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 120,]));
                break;
        case "����һ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jiuyang-shengong/hun",
                           "name"    : "����һ��",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 180,]));
                break;
        case "��������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jiuyang-shengong/po",
                           "name"    : "��������",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 200,
                           "sk2"     : "martial-cognize",
                           "lv2"     : 200,]));
                break;
        case "ħ�����޼�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jiuyang-shengong/ri",
                           "name"    : "ħ�����޼�",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 250,
                           "sk2"     : "martial-cognize",
                           "lv2"     : 250,]));
                break;

        default:
			break;
	}
	tell_object(me, name()+"����˵ʲô����˵һ�飿\n");
	return 1;
}
