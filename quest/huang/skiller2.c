#include <ansi.h>
 
inherit NPC;
 
void create()
{
	set_name("ǿ��", ({ "robber"}));

	set("gender", "����");
	set("age", 56);
	set("attitude", "peaceful");
	set("shen", -15000);
	set("str", 35);
	set("int", 20);
      set("con", 35);
	set("dex", 27);
	
	set("max_qi", 2500);
	set("max_jing", 2500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 120);
	set("combat_exp", 10000); 
	set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.jingang" :),
         })); 
         set_skill("force", 180);
         set_skill("hunyuan-yiqi", 180);
         set_skill("dodge", 180);
         set_skill("shaolin-shenfa", 180);
         set_skill("cuff", 180);
         set_skill("jingang-quan", 210);
         set_skill("parry", 170);
         set_skill("literate", 150);


      
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "jingang-quan");
  	map_skill("parry", "jingang-quan");
  	prepare_skill("cuff", "jingang-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold", 1);
}
#include "killer.h"
