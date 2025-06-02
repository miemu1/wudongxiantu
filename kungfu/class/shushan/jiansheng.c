//jiansheng.c by yushu 2000.11
#include <ansi.h>
#include "shushan.h"
inherit NPC;
int ask_jianshen();
inherit F_QUESTER;

#include <ansi.h>
void create()
{
       set_name("¶À¹ÂÓîÔÆ", ({"shushan jiansheng","jiansheng", "master"}));
       set("title", "ÊñÉ½ÅÉ½£·¨Ö®Ê¥");
       set("gender", "ÄÐÐÔ");
       set("age", 120);
	set("class", "xiake");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "ÀÏÊ¦×æ");
       set("per", 999);
	set("looking", "ÓñÃæ¶à¹âÈó£¬²Ô÷×ò¢ÏÂÆ®£¬½ð¾¦·É»ðÑæ£¬³¤Ä¿¹ýÃ¼ÉÒ¡£");
	set("int", 999);
       set("max_qi", 5000000);
       set("max_gin", 5000000);
       set("max_jing", 5000000);
       set("neili", 5000000);
       set("max_neili", 5000000);
       set("jiali", 150);
       set("max_mana", 5000000);
       set("mana", 5000);
         set("combat_exp", 200000000);
        set("max_jingli", 5000000);
        set("max_neili", 5000000);
        set("jingli", 5000000);
        set("neili",5000000);
         set("jiali",5000000);
       set_skill("literate", 9999);
       set_skill("dodge", 9999);
       set_skill("parry", 9999);
        set_skill("spells", 9999);
        set_skill("xianfeng-spells", 9999);
       set_skill("unarmed", 9999);
       set_skill("fumozhang",9999); 
	set_skill("sword", 9999);
     set_skill("songhe-sword", 9999);
        set_skill("shushan-force", 9999);
	set_skill("force", 9999);
      set_skill("zuixian-steps", 9999);
       map_skill("force", "shushan-force");
      map_skill("spells", "xianfeng-spells");
	map_skill("sword", "songhe-sword");
	map_skill("parry", "songhe-sword");
	map_skill("dodge", "zuixian-steps");
       map_skill("unarmed","fumozhang");
       set("chat_chance_combat", 60);
       set("chat_msg_combat", ({
		  (: cast_spell, "fu" :),
        }) );

       set("inquiry", ([
        "½£Éñ" : (: ask_jianshen :),
       ]) );
        create_family("ÊñÉ½ÅÉ", 2, "µÜ×Ó");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{	ob=this_player();
       if ( !((string)ob->query("gender")=="ÄÐÐÔ")){
       command("shake");
       command("say ÎÒÖ»ÊÕÄÐÍ½£¬ÕâÎ»" +RANK_D->query_respect(ob) + "»¹ÊÇÈ¥ÕÒ¾Æ½£ÏÉ°É¡£\n");
       return;
       }
       if( (string)ob->query("family/family_name")=="ÊñÉ½ÅÉ") {
         if ((int)ob->query("combat_exp") < 10000000 ) {
  	command("say ÄãµÄexp»¹²»¹»£¬¶ÔÎÒµÄÕÐ·¨ÄÑÒÔÁìÎò¡£\n");
	return;
	}
        if( (int)ob->query_skill("force", 1) < 550 ) {
      command("say ÕâÎ»" + RANK_D->query_respect(ob) + "ÄãµÄÉíÌåÕâÃ´²î,Äã»¹ÊÇÕÒ×·ÔÆ×ÓËûÃÇÔÙÁ·×Å°É!\n");
	command("sigh");
	return;
	}
       command("smile");
       command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) + "¶à¼ÓÅ¬Á¦£¬ÎªÊñÉ½Õù¹â¡£");
       command("recruit " + ob->query("id") );
	return;
	}
       command("shake");
       command("say ÄãÊÇ±¾ÅÉµÄÂð?£¬" + RANK_D->query_respect(ob) + "»¹ÊÇÁíÑ°ËûÈË°É£¡\n");
       return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "½£Ê¥Ç×´«");

}

        return 0;
}

int ask_jianshen()
{

    object ob=this_player();
    if(ob->query("family/family_name") != "ÊñÉ½ÅÉ")
    {
    command("say ÄãÓÖ²»ÊÇÊñÉ½ÅÉµÄ£¬Ë­¹ÜÄã£¡");
    return 1;
    }
    if(ob->query("shushan/jianshen_cast"))
    { 
    command("say Äã²»ÊÇÎÊ¹ýÁËÂð? ");
    return 1;
    }
    if(ob->query("family/master_name") == "ÊñÉ½½£Ê¥" )
    {
    command("say ÕâÒ»ÕÐ½£Éñ£¬ÊÇÎªÊ¦Î¨Ò»ÄÜ¸øÄãµÄ£¬¾ø²»±ÈÈÎºÎ·¨Êõ²î£¡ËüÓ¦¸Ã¿ÉÒÔ°ïÄã±£ÃüµÄ£¡");
    ob->set("shushan/jianshen_cast",1);
    return 1;
    }
}



ÿ
