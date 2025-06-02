//edit by rock
//2008.10.16

#include <ansi.h>
inherit NPC;

#define MIRROR_SYS "/d/mirror/sys/mirror_sys"

int ask_job();

void create()
{

        set_name("���ݱ���", ({ "team fuben"}));

        set("gender", "����");
        set("age", 26);
		set_temp("no_kill",1);
	set("qi",   99999);
	set("jing", 99999);
	set("eff_qi",   99999);
	set("eff_jing", 99999);
	set("max_qi",   99999);
	set("max_jing", 99999);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 0);
	set("combat_exp", 25000000);
	set("score", 50000);
        set_skill("strike",200);
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("force", 200);
	set_skill("parry", 210);
	set_skill("literate", 200);
	set_skill("canzhi-duanhun",300);
        map_skill("unarmed", "canzhi-duanhun");
        map_skill("parry", "canzhi-duanhun");
	set("inquiry", ([
        	"����(���)" : (: ask_job :),
            ]));

        setup();
      //  carry_object("/clone/misc/changpao")->wear();
}

int ask_job()
{
	object me;
	object *team,memory;
	int i,size;
	me = this_player();

	if(!me->is_team_leader())
	{
		tell_object(me,"�㲻����ӡ�\n");
		return 1;
	}
	team = me->query_team();
	size = sizeof(team);
	if(!pointerp(team) || sizeof(team) < 2)
	{
		tell_object(me,"������ֲ�����\n");
		return 1;
	}
	if(sizeof(team) > 10)
	{
		tell_object(me,"����10���޷����롣\n");
		return 1;
	}
	for(i = 0;i<size;i++)
	{
		if(!team[i]) continue;
        	if (team[i]->query("combat_exp") <= 800000)
                {
                	tell_object(me, HIG"�Ǻǡ�,���Ƕ������滹��û��80��ģ��Ժ������ɣ�\n"NOR);
                 	return 1;
                }
        	if (team[i]->query("fubentd") >= 2)
                {
                	tell_object(me, HIG"�Ǻǡ�,���Ƕ��������и�����������ģ��Ժ������ɣ�\n"NOR);
                 	return 1;
                }
                if (team[i]->is_ghost())
                {
                	tell_object(me, HIY"�Ǻǡ�,��Ķ����ﻹ�и�����!!!!!!\n"NOR);
                 	return 1;
                }
    }

	//ɾ���ɵĸ���
	memory = me->query_temp("mirror/mirror_memory");
	if(objectp(memory))
	{
		memory->delete("user_id");
	}
	//�����µĸ���
	MIRROR_SYS->mirror(team,me);
	for(i = 0;i<size;i++)
	{
   team[i]->add("fubentd",1);
    }
}