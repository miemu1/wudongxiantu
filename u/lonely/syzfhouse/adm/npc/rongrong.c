#include <ansi.h>
inherit NPC;

#define gold_limit  100000
#define time_limit  900
#define level_limit 800

private void add_all_inquiry();
private void greeting(object me);
private int ask_test(object me, object ob);
private int ask_money(object me, object ob);
private int ask_faction(object me, object ob);
private int ask_all_faction(object me, object ob);
private int setskills(string arg, object me, object ob);

string *all_knowledge = ({
"literate",
"buddhism",
"taoism",
"qimen-wuxing",
"dacheng-fofa",
});

void create()
{
    set_name("����", ({ "rong rong", "rong" }));
    set("nickname", HIG "ask rong about test" NOR);
    set("title", HIY "��������Ա" NOR);
    set("gender", "����");
    set("shen", 0);
    set("age", 20);
    set("per", 20);
    set("no_get", 1);
    set("wiz_tester", 1);
    set("combat_exp", 10000000);
    set("attitude", "friendly");
    set("long", "����˿���ȥ��Զ��һ��û��˯�ѵ����ӡ�\n");

    setup();
    carry_object("/clone/misc/cloth")->wear();
    add_all_inquiry();
}

void init()
{
    add_action("setskills", "setskill");
    if(this_object()->is_livings() && !wizardp(this_player()))
    {
        remove_call_out("greeting");
        call_out("greeting", 1, this_player());
    }
    ::init();
}

private void greeting(object me)
{
    if(!me || environment(me) != environment())
        return;
    tell_object(me, this_object()->name(1) + "������ƤЦ���ĵ�������λ"
                    + RANK_D->query_respect(me) + "Ҳ���μӲ���("
                    HIY "ask rong about test" NOR")�ɣ�����\n");
}

private void add_all_inquiry()
{
    int i;
    string type;
    mapping *all_skill, all_inquiry;

    all_inquiry = ([]);
    all_skill   = FACTION_D->query_all_skill();
    for(i = 0; i < sizeof(all_skill); i++)
    {
        all_inquiry += ([ all_skill[i]["name"] : (: ask_faction :)]);
    }

    all_inquiry += ([

        "test"  : (: ask_test :),
        "money" : (: ask_money :),
        "skill" : (: ask_all_faction :),
    ]);

    this_object()->set("inquiry", all_inquiry);
}

private int ask_test(object me, object ob)
{
    me = this_player();
    ob = this_object();

    message("vision", ob->name(1) + "��" + me->name() + "����С����"
                      "˵�˼��仰��\n", environment(me), ({ me, ob }));
    tell_object(me, ob->name(1) + "�ɿ���������װǻ���Ƶ�˵����\n");
    tell_object(me, HIW@TEXT

�밴�����йؼ��������������Ա���в�ѯ��

    test  ����ȡ��������Ա������Ϣ
    money ����ȡ�������õ�Ǯׯ���
    skill ����ѯ�ɹ�ѡ����书����

    ָ���ʽ��ask rong about <�ؼ���>


    ���������������õļ��ܣ���ʹ��setskillָ��

    ָ���ʽ��setskill <���ID> use <��������>

    ע�⣺�������ܽ��Ȼ�ɾ��������ԭ�е����м���

TEXT NOR);
    return 1;
}

private int ask_money(object me, object ob)
{
    me = this_player();
    ob = this_object();

    if(wizardp(me))
    {
        message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                       "����С��˵�˼��仰��\n", environment(me),
                                                 ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "ҡͷ�����㲻����ʦ��"
                                            "�Լ�call�����ˡ�\n" NOR);
        return 1;
    }

    if(time() - me->query("set_skill/money") < time_limit)
    {
        message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                       "����С��˵�˼��仰��\n", environment(me),
                                                 ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "ҡͷ������Ҫ̫̰�ģ�ǰ������"
                                            "��ȡ�����õĽ�Ǯ֮�������"
                                            + chinese_number(time_limit/60) +
                                            "�������ϡ�\n" NOR);
        return 1;
    }

    me->set("set_skill/money", time());
    me->set("bank/gold", gold_limit);
    message("vision", ob->name(1) + "���˵�ͷ����" + me->name() +
                       "����С��˵�˼��仰��\n", environment(me),
                                                 ({ me, ob }));
    tell_object(me, HIC + ob->name(1) + "��ͷ�����������õĽ�Ǯ"
                    HIY + chinese_number(gold_limit) + "���ƽ�"
                    HIC "�Ѿ������Ǯׯ�ʻ����ˡ�\n" NOR);
    return 1;
}

private int ask_faction(object me, object ob)
{
    string topic;

    me = this_player();
    ob = this_object();

    message("vision", ob->name(1) + "��" + me->name() + "����С����"
                      "˵�˼��仰��\n", environment(me), ({ me, ob }));
    tell_object(me, ob->name(1) + "�ɿ���������װǻ���Ƶ�˵����\n");

    topic = me->query_temp("last_ask/topic");
    if(me->query_temp("ask_all_faction"))
    {
        topic = "";
        FACTION_D->show_skill(me, 0);
    }
    else
    {
        FACTION_D->show_skill(me, topic);
    }

    if(me->query_temp("ask_all_faction"))
        me->delete_temp("ask_all_faction");

    return 1;
}

private int ask_all_faction(object me, object ob)
{
    me = this_player();
    ob = this_object();

    me->set_temp("ask_all_faction", 1);
    ask_faction(me, ob);
    tell_object(me, HIC + ob->name(1) + "������������ĳ��ܵ�����"
                                        "��Ϊ�ؼ������Ҳ�ѯ���Ի�ȡ"
                                        "��һ������Ϣ��\n" NOR);
    return 1;
}

private int setskills(string arg, object me, object ob)
{
    int i;
    object obj;
    string who, skill;

    me = this_player();
    ob = this_object();

    if(!arg || sscanf(arg, "%s use %s", who, skill) != 2)
        return notify_fail(HIW "ָ���ʽ��setskill <���ID> "
                               "use <��������>\n" NOR);

    obj = present(who, environment(me));
    if(!objectp(obj))
        return notify_fail(YEL + ob->name(1) + "�ɻ�ĵ�����Ҫ�趨"
                                               "˭�ļ��ܣ�\n" NOR);

    if(obj != me)
        return notify_fail(YEL + ob->name(1) + "ҡͷ������ֻ�ܸ���"
                                               "�Լ��Ĳ����ü��ܡ�\n" NOR);

    if(wizardp(me))
    {
        message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                       "����С��˵�˼��仰��\n", environment(me),
                                                 ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "ҡͷ�����㲻����ʦ��"
                                            "�Լ�call�����ˡ�\n" NOR);
        return 1;
    }

    if(time() - me->query("set_skill/time") < time_limit)
    {
        message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                       "����С��˵�˼��仰��\n", environment(me),
                                                 ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "ҡͷ������Ҫ̫Ƶ����ǰ������"
                                            "���������õļ���֮�������"
                                            + chinese_number(time_limit/60) +
                                            "�������ϡ�\n" NOR);
        return 1;
    }

    if(me->query("generation_skill/name") == skill)
        return notify_fail(YEL + ob->name(1) + "ҡͷ�����㵱ǰʹ�õļ������ǡ�"
                               + skill + "���������ظ��趨��\n" NOR);

    me->set("str", 30);
    me->set("int", 10);
    me->set("con", 60);
    me->set("dex", 30);
    me->set("con_improve_time", 50);
    me->set("food", (int)me->max_food_capacity());
    me->set("water", (int)me->max_water_capacity());

    me->set("set_skill/level", level_limit);
    FACTION_D->gen_npc(me, skill);

    for(i = 0; i < sizeof(all_knowledge); i++)
    {
        me->set_skill(all_knowledge[i], level_limit);
    }

    if(me->query("generation_skill/name") == skill)
    {
        me->set("set_skill/owner", "TEST_D");
        me->set("set_skill/time", time());
        message("vision", ob->name(1) + "���˵�ͷ����" + me->name() +
                           "����С��˵�˼��仰��\n", environment(me),
                                                     ({ me, ob }));
        tell_object(me, HIC + ob->name(1) + "��ͷ�����㹩�����õļ��ܱ��趨Ϊ��"
                        HIW + skill + HIC "�����ȼ�Ϊ"
                        HIY + chinese_number(level_limit) +
                        HIC "����\n" NOR);
        return 1;
    }
    else
    {
        message("vision", ob->name(1) + "ҡ��ҡͷ����" + me->name() +
                       "����С��˵�˼��仰��\n", environment(me),
                                                 ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "�ɻ�ĵ������ǲ��Ǹ���˰����С�"
                                          + skill + "�����ּ��ܿ�ѡ��\n" NOR);
        return 1;
    }
}
