// renwoxing.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#include "riyue.h"

int ask_pfm(string arg);
int accept_ask(object me, string topic);
int ask_bijian();

void create()
{
	set_name("������", ({ "ren woxing", "ren","woxing" }));
	set("title", BLU "������̽���"NOR );
	set("long", "ֻ����һ�ų��������ף���ɫѩ�ף����ް��Ѫɫ��üĿ���㣬
������ߣ�һͷ�ڷ���������һϮ������\n");
	set("gender", "����");
	set("class", "scholar");
	set("age", 55);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 30);
	set("per", 27);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 500000);
	set("max_jing", 300000);
	set("neili", 500000);
	set("max_neili", 500000);
	set("jiali", 400);
	set("combat_exp", 5000000);
	set("score", 500000);

    set_skill("force", 280);
    set_skill("unarmed", 280);
    set_skill("dodge", 280);
    set_skill("parry", 280);
    set_skill("sword", 280);
    set_skill("blade", 280);
    set_skill("strike", 280);
    
    set_skill("riyue-xinfa", 280);
    set_skill("tianmo-zhang", 280);
    set_skill("tianmo-dao", 280);
    set_skill("tianmo-jian", 280);
    set_skill("xuwu-piaomiao", 280);
    set_skill("piaomiao-shenfa", 280);
    set_skill("xixing-dafa", 280);
    set_skill("literate", 300);
    /*
    set_skill("taiji-jian", 100);
    set_skill("huifeng-jian", 100);
    set_skill("songshan-sword", 100);
    set_skill("taishan-sword", 100);
    set_skill("huashan-sword", 100);
    set_skill("hengshan-sword", 100);
    set_skill("hengshan-jian", 100);
    set_skill("damo-jian", 100);
*/
    map_skill("force", "riyue-xinfa");
    map_skill("sword", "tianmo-jian");
    map_skill("blade", "tianmo-dao");
    map_skill("strike", "tianmo-zhang");
    map_skill("parry", "tianmo-gun");
    map_skill("unarmed", "xuwu-piaomiao");
    map_skill("dodge", "piaomiao-shenfa");
    
	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.chuanxin" :),
		(: perform_action, "sword.moxiao" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));

	set("inquiry", ([
    "#11-һ������"  : (: ask_pfm("һ������") :),
		/*"�Ƚ�" :  (: ask_bijian :),
		"����" :  (: ask_bijian :),*/
		"��ľ��" : "Ҫ�ú�ľ��Ϸ����ȿ�����Ľ�����\n",
	]) );
     create_family("�������", 1, "��һ������");
 	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
void reset_skill()
{
	command("enable sword tianmo-jian");
}
int ask_bijian()
{
	object obj, me = this_player(), ob = this_object();
	message_vision("$N����˵���������������Ұݼ�����ǰ�����������ָ�̡���\n
$nЦ���������ÿ������������Ҽ�į���ɶ�л��������\n", me, ob );
	message_vision("$N���������ҡ���\n
$n���˵�ͷ��˵��������ֻ��������Ľ�����������Ĺ�
�У���˵����Ҳδ����ʤ�����㡣��\n\n", me, ob);
	command("enable sword damo-jian");
	say(HIR"�����д��һ���������ֽ�������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵��������һ�С���\n");
		reset_skill();
		return 1;
	}
	command("enable sword taiji-jian");
	say(HIR"�����д��һ�������䵱��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		reset_skill();
		return 1;
	}
	command("enable sword huifeng-jian");
	say(HIR"�����д��һ���������ҽ�������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		reset_skill();
		return 1;
	}
	command("enable sword songshan-sword");
	say(HIR"�����д��һ��������ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		reset_skill();
		return 1;
	}
	command("enable sword taishan-sword");
	say(HIR"�����д��һ������̩ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		reset_skill();
		return 1;
	}
	command("enable sword huashan-sword");
	say(HIR"�����д��һ��������ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		reset_skill();
		return 1;
	}
	command("enable sword hengshan-sword");
	say(HIR"�����д��һ��������ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		reset_skill();
		return 1;
	}
	command("enable sword hengshan-jian");
	say(HIR"�����д��һ��������ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵����������û�����С���\n");
		reset_skill();
		return 1;
	}

	obj = new("/d/heimuya/obj/heimu-ling");
	obj -> move(me);
	say("������˵��������λ" + RANK_D->query_respect(me)+"�����Ҿ�����һ���ľ��ɡ���\n");
	reset_skill();
	return 1;
}
void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;
	
	if (ob->query("gender", 1) =="����") {
		tell_object(ob, "��ƽ��������ľ������ˣ�������\n");
		return;
	}
	if (ob->query("shen", 1) > -100000) {
		tell_object(ob, "�㻹����а������ʱ�������㡣\n");
		return;
	}
	if (ob->query_skill("riyue-xinfa", 1) < 160) {
		tell_object(ob, "��������ķ���û�����ҡ�\n");
		return;
	}
	if (ob->query_skill("kuihua-shengong", 1) > 1 ) {
		tell_object(ob, "���Ѿ�ѧ�ᶫ�������Ŀ����񹦣����������㣿\n");
		return;
	}
	if (ob->query("family/master_id") == "dongfang bubai") {
		tell_object(ob, "�������Ҫ���ģ������������������Ե׵��𣿣�\n");
		return;
	}
	if (ob->query("family/master_id") != "xiang wentian") {
		tell_object(ob, "��һ��ֻ���������Ƽ������ĵ��ӣ���ϧ�㲻�ǡ�\n");
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
        case "һ������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tianmo-jian/chuanxin",
                           "name"    : "һ������",
                           "sk1"     : "tianmo-jian",
                           "lv1"     : 200,]));
                break;

        default:
			break;
	}
	tell_object(me, name()+"����˵ʲô����˵һ�飿\n");
	return 1;
}

