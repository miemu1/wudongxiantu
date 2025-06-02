#include <ansi.h>
inherit NPC;
void create()
{
        set_name("������", ({ "jinyi wei", "wei"}));
        set("gender", "����");
        set("age", random(20) + 20);
        set("str", 160);
        set("dex", 160);
        set("con", 160);

        set("long", 
"����һ�����ǻʹ��е�һ�������������������ݵ�Ѳ���Ź�������Ⱥ��\n");

        set("combat_exp", 8000000);
        set("attitude", "peaceful");
        set("max_qi", 40000);
        set("max_jing", 2000);
        set("max_neili",30000);
        set("neili",30000);  
        set("jiali",400);

        set_skill("unarmed", 400);
        set_skill("blade", 400);
        set_skill("parry", 400);
        set_skill("force", 400);
        set_skill("dodge", 400);
        set_skill("tiyunzong", 400);
        set_skill("taiji-quan", 400);
        set_skill("taiji-shengong", 400);
        set_skill("wuhu-duanmendao", 400);
        set_skill("wuhu-duanmendao", 400);

        map_skill("blade", "wuhu-duanmendao");
        map_skill("force", "taiji-shengong");
        map_skill("parry", "taiji-quan");
        map_skill("unarmed", "taiji-quan");
        map_skill("dodge", "tiyunzong");

        set("chat_chance_combat",50); 
        set("chat_msg_combat", ({ /* sizeof() == 3 */
              (: perform_action,   "blade.duan" :),  
              (: perform_action,   "unarmed.zhen" :),    
              (: exert_function,   "powerup" :),
        })); 

        setup();
        carry_object(__DIR__"obj/tiejia")->wear();
        carry_object(__DIR__"obj/wandao")->wield();
}     

void init()
{
     object me=this_player();
     if( me->query_condition("killer") )
     this_object()->kill_ob(me);
}
