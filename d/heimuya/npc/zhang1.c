// zhang1.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

#include "riyue.h"

int shang_ya();
int ask_pfm(string arg);
int accept_ask2(object me, string topic);

void create()
{
    set_name("�ų˷�", ({"zhang chengfeng", "zhang", "chengfeng"}));
    set("nickname", HIY "�����ħ" NOR );
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
    set("inquiry", ([
    "#11-������ת"  : (: ask_pfm("������ת") :),
	"��ľ��" : "���̵��ӻ�ֽ������Ʒ������£�\n",
	"�������" : "���̵��ӻ�ֽ������Ʒ������£�\n",
	"���½�" : "���̵��ӻ�ֽ������Ʒ������£�\n",
	"��ľ��" : "���Ǳ��̽������ƣ���������������٣�\n",
	"����" :   (: shang_ya :),
    ]) );

    set_skill("force", 160);
    set_skill("unarmed", 160);
    set_skill("dodge", 160);
    set_skill("parry", 160);
    set_skill("club", 160);
    
    
    set_skill("riyue-xinfa", 160);
    set_skill("tianmo-gun", 160);
    set_skill("xuwu-piaomiao", 160);
    set_skill("piaomiao-shenfa", 160);
    set_skill("literate", 120);

    map_skill("force", "riyue-xinfa");
    map_skill("club", "tianmo-gun");
    map_skill("parry", "tianmo-gun");
    map_skill("unarmed", "xuwu-piaomiao");
    map_skill("dodge", "piaomiao-shenfa");

	/*
	set("chat_msg_combat", ({
		(: perform_action, "club.tian" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));
	*/


    create_family("�������", 2, "����");

    setup();
    carry_object(__DIR__"obj/shutonggun")->wield();
    carry_object("/clone/misc/cloth")->wear();
}

int shang_ya()
{
    object ob, myenv ;
    ob = this_player ( ) ;
    if (ob->query("family/family_name") == "�������")
    {
	message_vision("�ų˷�һ���֣���������һ���������\n",ob);
	message_vision("$Nһ�������˵��������������ؽ�����ȥ......\n", ob);
	myenv = environment (ob) ;
	ob->move ("/d/heimuya/basket");
	call_out("goto_heimuya", 10, ob) ;
       	return 1;
    }
    else  
    message_vision("�ų˷��������´�����$Nһ�£�ʲô�����£���ĺ�ľ���أ���\n",ob);
    return 1;
}

int accept_object(object who, object ob)
{
    object myenv ;
    if (ob->query("id") == "heimu ling")
    {
	message_vision("�ų˷��$N˵���ã���λ" + RANK_D->query_respect(who) + "�����Ǿ���ɣ�\n" , who);
	message_vision("�ų˷�һ���֣���������һ���������\n", who);
	message_vision("$Nһ�������˵��������������ؽ�����ȥ......\n", who);
	myenv = environment (who) ;
	who->move ("/d/heimuya/basket");
	call_out("goto_heimuya",10,who) ;
       	return 1;
    }
    else  if (! ::accept_object(who,ob))
    {
        message_vision("�ų˷��$N˵�����ˣ�ң���\n", who);
        this_object()->kill_ob(who);
        return -1;
    }
    return 1;
}

void goto_heimuya (object ob)
{
    tell_object(ob , "����ǰһ����һ������ɫ����������ǰ�����ǻԻ͡�\n");
    ob->move ("/d/heimuya/chengdedian") ;
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
		
		return accept_ask2(me, arg);
	}
	return 1;
}
int accept_ask2(object me, string topic)
{
	if (me->query("family/family_name") == "�������")
	switch (topic)
	{
        case "������ת" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tianmo-gun/tian",
                           "name"    : "������ת",
                           "sk1"     : "tianmo-gun",
                           "lv1"     : 100,]));
                break;

        default:
            break;
	}
    tell_object(me, name()+"����˵ʲô����˵һ�飿\n");
	return 1;
}
