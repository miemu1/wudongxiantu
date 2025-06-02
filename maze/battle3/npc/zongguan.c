#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�����ܹ�", ({ "shiwei zongguan", "zongguan"}));

        set("gender", "����");
        set("age", random(20) + 20);
        set("str", 200);
        set("dex", 200);
        set("con", 200);
        set("long", "����������ܹܴ��ˣ���˵���˹���һλ������һ���书��δ��¶����Ҳ��֪��ǳ��\n");   

        set("combat_exp", 15000000);
        set("attitude", "peaceful");
        set("max_qi", 80000);
        set("max_jing", 40000);
        set("max_neili",100000);
        set("neili",120000);
        set("jiali",500);

        set_skill("unarmed", 500);
        set_skill("sword", 500);
        set_skill("parry", 500);
        set_skill("force", 500);
        set_skill("dodge", 500);
        set_skill("dodge", 500);
        set_skill("finger", 500);
        set_skill("pixie-jian", 500);
        set_skill("kuihua-mogong", 500);

        map_skill("sword", "pixie-jian");
        map_skill("finger", "pixie-jian");
        map_skill("parry", "kuihua-dafa");
        map_skill("dodge", "pixie-jian");
        set("chat_chance",5);
        set("chat_msg", ({ 
                  (: random_move :)
        }));                   

        set("chat_chance_combat",50); 
        set("chat_msg_combat", ({ /* sizeof() == 3 */
              (: perform_action,   "finger.cimu" :),  
              (: perform_action,   "parry.tonggui" :),    
              (: exert_function,   "sneaky" :),
        })); 

        setup();
        carry_object(__DIR__"obj/tiejia")->wear();
        carry_object(__DIR__"obj/gangjian")->wield();
}

void init()
{
     object me=this_player();
     if( me->query_condition("tongji") )
     {
      this_object()->set_leader(me);
      this_object()->kill_ob(me);
      if( !query_temp("tongji", me) )
      {
       set_temp("tongji", 1, me);
       command("chat "+"�������������׽��ͼı����֮�̿͡���"
             +query("name", me)+"�����бӻ�֮����\nһ����ͬı������ɱ���ۣ�");
      }
     }
}
