//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("ԩ��", ({ "yuan hun", "yuanhun" }));
        set("title", "��ɽǰ��");
        set("race","����");
        set("age", 99);
        set("attitude", "aggressive");
        set("str", 100);
        set("int", 25);
        set("con", 40);
        set("cor", 40);
        
        set("max_qi", 20000);
        set("max_jing", 20000);
        set("neili", 30000);
        set("max_neili", 20000);
        set("jiali", 60);
        set("combat_exp", 50000000);
         set("max_neili", 70000);
         set("max_jingli", 70000);
         set("jingli", 70000);
         set("jiali", 7000);
         set("neili", 7000);

        set_skill("force", 1500);
        set_skill("dodge", 1500);
        set_skill("parry", 1500);
        set_skill("sword", 1500);
        set_skill("taiji-shengong", 1500);
        set_skill("zuixian-steps", 1500);
        set_skill("yujianshu",1500);
        map_skill("dodge", "zuixian-steps");
        map_skill("force", "taiji-shengong");
        map_skill("parry", "yujianshu");
        map_skill("sword", "yujianshu");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
        }) );
   add_temp("apply/damage", 20);
   add_temp("apply/armor", 20);

        setup();
        carry_object("/clone/cloth/cloth")->wear();
          carry_object("/clone/weapon/changjian")->wield();

}

void die()
{
        object me = this_player();
        object ob = new("/d/shushan/zhenyaota/obj/qxsword");
        ob->move("/d/shushan/zhenyaota/stairs1");

        if( environment() ) {
        message("sound", CYN"\nԩ��ɢ��...", environment());
        message("sound", "\nһ������Ů��������������...", environment());
        message("sound", "\nŮ����������ʮ���ˣ��������ڿ��԰�Ϣ�ˣ�������ǽ����͸���������", environment());
        message("sound", "\nŮ��˵����ʧ��������...\n"NOR, environment());
        }
        destruct(this_object());
		::die();
}
