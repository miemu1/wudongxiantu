#include <ansi.h>
inherit "inherit/char/boss";

void set_from_me(object me);
void create()
{
        string *names = ({ "��ٸ��ʿ" });

        ::create();
        set_name( names[random(sizeof(names))], ({ "bing shi"}) );
        set("long", @LONG
����һ����˯�ڻ���ǧ����ٸ��ʿ�����������࣬���������ƶ��ɣ�������ʮ�ּ�
Ӳ�����ֳ�һ����ͭ��ì��������Ϊ���䡣�ڻ�����Ϣ�������£�������֫���Ի��
���ؽ���Ҳ��ģ���������ܹ鲻��ǳ���
LONG);
        set("title", YEL "���껤��" NOR);

        set("str", 50);
        set("con", 50);
        set("dex", 50);
        set("int", 50);
        set("max_qi", 20000);
        set("max_jing", 25000);
        set("neili", 250000);
        set("max_neili", 250000);
        set("max_jingli", 50000);
        set("attitude", "peaceful");

        set("combat_exp", 100000000);
        set("death_msg",YEL"\n$N������һ�ѻ�����\n\n"NOR);

        set("bonus", 500);
        set_temp("apply/attack", 1000);
        set_temp("apply/parry", 1000);
        set_temp("apply/damage", 500);
        set_temp("apply/unarmed_damage", 500);
        set_temp("apply/armor", 1000);
        setup();
}

void init()
{
        object me;

        ::init();
        if (! interactive(me = this_player()) ||
            this_object()->is_fighting())
                return;

        set_from_me(me);
        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
}

void set_from_me(object me)
{
        mapping my;

        NPC_D->init_npc_skill(this_object(), NPC_D->check_level(me));
        my = query_entire_dbase();
        my["eff_jing"] = my["max_jing"];
        my["jing"] = my["max_jing"];
        my["eff_qi"] = my["max_qi"];
        my["qi"] = my["max_qi"];
        set("jiali", query_skill("force") / 2);
}