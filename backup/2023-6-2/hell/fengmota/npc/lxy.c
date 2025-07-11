//【蜀山剑派】dhxy-evil 2000.7.5
//yushu修改 2001.2
inherit NPC;

#define YAO       "/d/shushan/obj/lingyao"

int do_report();
void create()
{
        set_name("李逍遥", ({ "li xiaoyao", "li", "xiaoyao" }));
        set("title","蜀山剑派入门弟子");
        set("long", 
"李逍遥身材较瘦，长的浓眉阔眼，气宇暄昂。\n");
        set("gender", "男性");
        set("age", 18);
	 set("class", "xiake");
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("per", 30);
        set("qi", 2800);
        set("max_qi", 2800);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 4800);
        set("max_neili", 2400);
        set("jiali", 60);
        set("combat_exp", 38000000);
        set("max_jingli", 1000);
          set("max_neili", 10000);
        set("jingli", 100000);
        set("neili",10000000);
         set("jiali",1000);
        set_skill("force", 250);
        set_skill("dodge", 240);
        set_skill("unarmed", 230);
         set_skill("fumozhang", 230);
        set_skill("parry", 250);
        set_skill("sword", 250);
        set_skill("canxin-jian", 270);
        set_skill("shushan-force", 240);
        set_skill("zuixian-steps",240);
        set_skill("literate",120);
        map_skill("unarmed", "fumozhang");
        map_skill("force", "shushan-force");
        map_skill("dodge", "zuixian-steps");
        map_skill("parry", "canxin-jian");
        map_skill("sword", "canxin-jian");
	set("chat_chance",20);
       
    set("chat_msg",({
        "李逍遥念叨着：哎! 不知道仙女姐姐会不会给我灵药～\n",
        "李逍遥深深地叹了口气。\n",
        "李逍遥独自说道：谁能救救我婶婶～\n"
       }) );
        set("inquiry", ([
                "救出来了"    : (: do_report :),
        ]));
	 setup();
        create_family("蜀山剑派", 3, "弟子");
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
//        carry_object("/d/obj/weapon/sword/qingfeng")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="蜀山派" )
	{
		if( (int)ob->query("family/generation") < 3  )
		{
			if ( (string)ob->query("gender") == "男性" ) command("say 师叔见笑了。\n");
			else command("say 师姑见笑了。\n");
		}
		else if( (int)ob->query("family/generation") ==3  )
		{
			if ( (string)ob->query("gender") == "男性" ) command("say 师兄太客气了。\n");
			else command("say 师妹太客气了。\n");
		}
		else 
		{
			command("consider");
			command("say 看在你诚心诚意的份上,我收你为徒!\n");
			command("recruit " + ob->query("id") );
		}
	}
            else
	{
		command("say 看在你诚心诚意的份上,我收你为徒!\n");
		command("recruit " + ob->query("id") );
	}

	return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "蜀山派李逍遥弟子");
		  ob->set("shushan/xiangsi_perform", 1);
              }
              return 0;
}
void init()
{
  object ob;

  ::init();
  if( interactive(ob = this_player()) && !is_fighting() )
  {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
}
void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "李逍遥说道：这位" + RANK_D->query_respect(ob) +
"，能不能帮我救出灵儿！她被关进封魔塔里了！\n");
}


int do_report()
{
 int i=random(50000)+1;
 object me = this_player();
 if(me->query("shushan/zhanyi")) { 
 me->set("zhanyi/zhenyaota",1);
 me->delete("shushan/zhanyi");
 me->add("combat_exp",300000+i);
 me->add("potential",100000);
 me->add("max_neili",me->query("max_neili")/10);
 message("system",HIC"〖"HIW"封魔塔传讯"HIC"〗"HIY+me->query("name")+HIG"救出[1;37m封魔塔[1;32m里的赵灵儿，受到奖励！[2;37;0m\n"NOR,users());    
 tell_object(me,"你赢得了"+chinese_number(3)+"年"+chinese_number(i/4)+"天"+chinese_number((i-(i/4)*4)*3)+"时辰的道行和"+
 chinese_number(100000)+"点潜能,和增加了10%的内力\n");
 me->save();
 } 
 else 
 {
 command("say 谢谢你！不能再麻烦你啦！");
 }
 return 1;
}


int accept_object(object me, object obj)
{
object tuzhu;
if(base_name(obj)!=YAO)
{
                command("say 这东西能治好我婶婶的病吗？你不要骗我了!\n");
                return 0;
}
	tuzhu=new("/data/hell/fengmota/obj/tuzhu");
	tuzhu->move(me);
	command("say 这下我婶婶有救了!! 这颗土灵株就给你吧。\n");
return 1;

}

