
inherit NPC;
#include <ansi.h>

string ask_baibao();
int ask_character(string arg);
int ask_fanli();
int ask_xiandan();
int ask_illness();
int ask_kuilei();
int ask_mengzi();
int ask_buchang();
int ask_gift();

void create()
{
        set_name(HIY"历史活动记录员"NOR,({  "ls", "lshd" }) );
        set("gender", "男性" );
        set("age", 20);
        set("long", HIC "他一脸喜庆洋洋！\n");
       set("str", 3700);
        set("dex", 3600);
        set("con", 3500);
        set("int", 3700);
		set("max_qi", 10607);
		set("max_jing", 10607);
		set("gain/damage", 14);
        set("shen_type", 1);
		set("gain/2ap",55584);
        set("combat_exp", 100000);
        set("attitude", "peaceful");
        setup();

        set("inquiry", ([
              //"新手见面礼": (: ask_gift :),
             // "领取红包": (: ask_buchang :),
              //"花间使者": (: ask_baibao :),
              "风调雨顺": (: ask_fanli :),
              "灯火璀璨": (: ask_xiandan :),
              //"后悔了" : (: ask_character(0) :),
              "人间万事喜": (: ask_illness :),
              //"入魂一发": (: ask_mengzi :),
              //"人间万事喜": (: ask_kuilei :),
        ]) );

        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("ask_character","washme");
}

int ask_gift()
{

        
}

int ask_buchang()
{

}

int ask_character(string arg)
{

}


int ask_fanli()
{
        object ob = this_player();
		if(ob->query("ftysyyy")==1)
		{
		 tell_object(ob,HIY"你已经领取过了！"NOR"\n"); 
			return 1;
		}
     if(ob->query("chunjiecz")<2000)
	 {
		 tell_object(ob,HIY"你的历史贡献不足2000，你目前已有"+ob->query("chunjiecz")+"点历史贡献！"NOR"\n");
		 return 1;
	 }
	 
	 	 ob->set("ftysyyy", 1);
		 ob->add("gain/max_qi",2000);
		 ob->add("texxiaopojia",3);
		 ob->set("ftys",1);
		 tell_object(ob,HIY"你领取了风调雨顺称号！"NOR"\n"); 
        return 1;
}

int ask_xiandan()
{
        object ob = this_player();
		if(ob->query("hsahidadh")==1)
		{
		 tell_object(ob,HIY"你已经领取过了！"NOR"\n"); 
			return 1;
		}
     if(ob->query("chunjiecz")<1500)
	 {
		 tell_object(ob,HIY"你的贡献不足1500，你目前已有"+ob->query("chunjiecz")+"点贡献！"NOR"\n");
		 return 1;
	 }
	 
	 	 ob->set("hsahidadh", 1);
		 ob->add("gain/max_qi",1500);
		 ob->add("gain/2ap",10);
		 ob->set("dhcc",1);
		 tell_object(ob,HIY"你领取了灯火璀璨称号！"NOR"\n"); 
        return 1;
}

int ask_illness()
{
        object ob = this_player();
		if(ob->query("gdcsaqq2")==1)
		{
		 tell_object(ob,HIY"你已经领取过了！"NOR"\n"); 
			return 1;
		}
     if(ob->query("chunjiecz")<1000)
	 {
		 tell_object(ob,HIY"你的贡献不足1000，你目前已有"+ob->query("chunjiecz")+"点贡献！"NOR"\n");
		 return 1;
	 }
	 
	 	 ob->set("gdcsaqq2", 1);
		 ob->add("gain/max_qi",2000);
		 ob->set("xcunsz",1);
		 tell_object(ob,HIY"你领取了人间万事喜称号！"NOR"\n"); 
        return 1;
}

string ask_baibao()
{
}


int ask_kuilei()
{

}

int ask_mengzi()
{

}