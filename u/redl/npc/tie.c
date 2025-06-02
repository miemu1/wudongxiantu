// This program is a part of NITAN MudLIB 
// redl 2012/12/1 
// tie-ren.c ����

#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIR "��������" NOR, ({ "tie ren", "ren", "tie" }) );
        set("gender", "Ů��" );
        set("age", 30);
        set("long", "һ�������õı������ˣ��Ƿ���ľ�������ģ������Ǿ�\n"
                    "��redl�����ģ����Ծ��и��־õ�����������ͬʱҲ\n"
                    "���и�ǿ��Ĺ�������������Ҳ�͸��пᡣ\n");
        set("scale", 200);
        set("min_exp", 1000000000);

        set("str", 35 + random(10));
        set("con", 35 + random(10));
        set("dex", 25 + random(10));
        set("int", 25 + random(10));

        set_skill("force",   1000); 
        set_skill("unarmed", 1000);
        set_skill("dodge",   1000);
        set_skill("parry",   1000);
        set_skill("mingyu-gong",   1000);
        map_skill("force", "mingyu-gong");
        map_skill("unarmed", "mingyu-gong");
        map_skill("dodge", "mingyu-gong");
        map_skill("parry", "mingyu-gong");
        prepare_skill("unarmed", "mingyu-gong"); 
        set("chat_chance_combat", 30);
                set("chat_msg_combat", ({
                (: perform_action, "unarmed.moqi" :),
                }) );
        
        set("max_qi", 10000000000000);
        set("eff_qi", 10000000000000);
        set("qi", 10000000000000);
        set("max_jing", 10000000000000);
        set("jing", 10000000000000);
        set("neili", 10000000000000);
        set("max_neili", 10000000000000);
        set("jiali", 50);
        set("shen_type", 0);


        set("combat_exp", 5000000000);
        
        set_temp("apply/damage",  5);
        set_temp("apply/armor",   5);
        set_temp("apply/attack",  5);
        set_temp("apply/defense", 5);
        set_temp("apply/str",5);
        
        set("not_living", 1);
        
        setup();
}



int do_preskhand(string arg)
{
        int nlv;
        string bhand, shand, strpfm;

        //write("��ȷ��ʽ��ss �ȼ� �������ּ����� ������ּ����� ������\n");

        if (!arg || arg==""){
                write("��ȷ��ʽ��ss �ȼ� �������ּ����� ������ּ����� ������\n");
                return 1;
        }

        if (sscanf(arg, "%d %s %s %s",nlv, bhand, shand, strpfm) != 4){
                write("��ȷ��ʽ��ss �ȼ� �������ּ����� ������ּ����� ������\n");
                return 1;
        }
        set_skill(bhand, nlv);
        set_skill(shand, nlv);
        map_skill(bhand, shand);
        prepare_skill(bhand, shand); 
                    set("chat_chance_combat", 120);
                set("chat_msg_combat", ({
                (: perform_action, strpfm :),
                }) );
    this_object()->reset_action();
        command("fight " + query("id", this_player()));
    return 1;
}


void init()
{
        add_action("do_preskhand", "ss");       
}


      
      
      
