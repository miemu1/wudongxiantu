//yaoguai.c by yushu@SHXY 2001.1
inherit NPC;
#include <ansi.h>
void create()
{
       set_name("����", ({"yao guai", "guai"}));
       set("long", "�������ﱻ���ŵ����֡�\n");
       set("age", 32);
       set("attitude", "aggressive");
       set("str", 30);
       set("int", 30);
       set("per", 10);
       set("con", 30);
       set("combat_exp", 1500000+random(2000000));
         set("max_jingli",20000 );
         set("max_neili",20000 );
         set("neili",20000 );
         set("jingli",20000 );
         set("jiali",20000 );
       set("max_qi", 20000+random(10000));
       set("max_jing", 30000+random(100000));
       set("neili", 400000);
       set("max_neili", 20000);
       set("jiali", 100+random(50));
         set_skill("taiji-shengong", 150+random(60));
      set_skill("taiji-jian", 150+random(60));
       set_skill("dodge", 150+random(600));
       set_skill("literate", 150+random(60));
       set_skill("sword", 150+random(60));
       set_skill("force", 150+random(60));
       set_skill("parry", 150+random(60));
       set_skill("xiaoyaoyou", 150+random(60));
       map_skill("dodge", "xiaoyaoyou");
          map_skill("parry", "taiji-jian");
          map_skill("sword", "taiji-jian");
       map_skill("force", "taiji-shengong");
       set("chat_chance_combat", 20);
       set("chat_msg_combat", ({
                (: perform_action, "sword", "lian" :),
       }) );
       setup();
         carry_object("/clone/weapon/changjian")->wield();
}
void die()
{
     object ob;
     ob = query_temp("last_damage_from");
     ob->add("combat_exp",10000);
     ob->add("potential",2000);
     message("system",HIC"��"HIW"��������Ѷ"HIC"��"HIY+ob->query("name")+HIG"ɱ��[1;37m������[1;32m������֣��ܵ�������[2;37;0m\n"NOR,users());    
     tell_object (ob,"��Ӯ����"+chinese_number(10000)+"����ѧ"+
                               chinese_number(100)+"�����"+chinese_number(2000)+"��Ǳ�ܣ�\n");

        ::die();
}
