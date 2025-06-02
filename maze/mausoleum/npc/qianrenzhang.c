#include <ansi.h>
inherit "inherit/char/boss";

void set_from_me(object me);
void create()
{
        string *names = ({ "��ٸǧ�˳�" });

        ::create();
        set_name( names[random(sizeof(names))], ({ "qian renzhang"}));
        set("long", @LONG
����һ����˯�ڻ���ǧ����ٸǧ�˳�������߳����࣬���������ƶ��ɣ�������ʮ��
��Ӳ�����ֳ�һ����ͭ�޴���������Ϊ���䡣�ڻ�����Ϣ�������£�������֫���Ի�
�������ؽ���Ҳ��ģ���������ܹ鲻��ǳ���
LONG);
        set("title", YEL"������Ʒ����" NOR);

        set("str", 80);
        set("con", 80);
        set("dex", 80);
        set("int", 80);
        set("max_qi", 1000000);
        set("max_jing", 500000);
        set("neili", 500000);
        set("max_neili", 500000);
        set("max_jingli", 500000);
        set("attitude", "killer");
        set("auto_perfrom", 1);
				set_skill("force", 1000);
        set_skill("dodge", 1000);
        set_skill("parry", 1000);

        set("combat_exp", 100000000);
        set("death_msg",YEL"\n$N������һ�ѻ�����\n\n"NOR);

        set("bonus", 10000);
        set_temp("apply/attack", 5000);
        set_temp("apply/parry", 5000);
        set_temp("apply/damage", 5000);
        set_temp("apply/unarmed_damage", 5000);
        set_temp("apply/armor", 5000);
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

