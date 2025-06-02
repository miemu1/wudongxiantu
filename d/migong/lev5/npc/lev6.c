//by name

#include <ansi.h>
inherit NPC;
string* names = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��",
"��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��",
"��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��",
"Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��",
"��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��",
"��","��","֧","��","��","��","¬","Ӣ","��","��","��","˧",
"˾��","�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�",
"ξ��","����","�̨","����","����","���","����","����","̫��",
"����","����","����","ԯ��","���","����","����","����","Ļ��",
"˾ͽ","ʦ��","��","��ľ","����","����","���","����","����",
"����","��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��",
"��ǧ","����","����","�Ϲ�","����","�麣","����","΢��","����",
"����","����","����","����","�Ϲ�",

"��","��","��","��","��","��","��","Ĳ","��","��","ī","��",
"��","��","��","��","١","��","��","��","��","��","��","��",
"��","ʯ",
});

string* nm2 = ({
"��","Т","��","��","��","��","��","��","��","��","��","»","��","С","��",
"��","��","��","��","��","��","��","֮","��","��","ʱ","��","��","��","��",
"��","��","��","��","��","��","��","��","Ϊ","��","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm3 = ({
"��","��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","�","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","��","��","��","ǿ","��","ɽ",
"̩","��","ͦ","ΰ","��","��","��","��",
"��","�","��","��","��","��",
});


void create()
{

   int i = random(sizeof(names));
   set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], ({ "man" }));
   set("title", HIC"����ͽ"NOR);
   set("gender", "����" );
   set("long","����ʦ�ţ����������ķ�ͽ��\n");
   set("attitude", "aggressive");
  set("force_factor",50+random(200));
  set("max_qi",1500+random(1500));
  set("max_jing",1500+random(1500));
  set("max_sen",1500+random(1500));
  set("max_neili",1500+random(1500));
  set("max_mana",1500+random(1500));
  set("eff_neili",1500+random(1500));
  set("neili",2000+random(1500));
        set("per", 1);
        set("age", 22);
        set("jiali" , 50);
        set("shen", -5000);
        set("intellgent",1);
     	set("pursuer",1);
        set("combat_exp", 1000000+random(250000));
set_skill("unarmed", 250+random(50));
set_skill("hunyuan-zhang", 250+random(50));
set_skill("force", 250+random(50));
set_skill("sword", 250+random(50));
set_skill("parry", 250+random(50));
set_skill("dodge", 250+random(50));
set_skill("huashan-sword", 250+random(50));
set_skill("feiyan-huixiang", 250+random(50));
set_skill("zixia-shengong", 250+random(50));
map_skill("sword", "huashan-sword");
map_skill("parry", "huashan-sword");
map_skill("force", "zixia-shengong");
map_skill("dodge", "feiyan-huixiang");
map_skill("unarmed"  , "hunyuan-zhang");
prepare_skill("unarmed", "hunyuan-zhang");
set("chat_chance_combat", 80);
set("chat_msg_combat", ({
   (: perform_action, "sword.jianzhang" :),
   //(: exert_function, "recover" :),
}));
     set_temp("apply/attack", 100);
     set_temp("apply/defense", 100);
     set_temp("apply/armor", 100);
     set_temp("apply/damage", 100);
     set("chat_chance", 50);
     set("chat_msg", ({
		(: command("get silver") :),
		(: command("get gold") :),
		(: command("get coin") :),
                (: random_move :),
      }));
      setup();
   carry_object("/d/migong/obj/cloth")->wear();
   carry_object("/d/migong/obj/sword")->wield();
}

void init()
{	
	object ob; 

	ob = this_player();
	::init();
	if (interactive(ob) && ! is_fighting()){
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
		kill_ob(ob);
}

void die()
{
        object ob, me;
        ob = this_object();
        me=  this_object()->query_last_damage_from();
        if (!me) 
        return;            
        message_vision(WHT"$N������Ѫ����,���ض�����\n"NOR,ob,me);
        if((int)me->query("combat_exp") > 500000)   {
        message("vision", me->name() + "Ϊ��������,������500��Ϊ��500Ǳ�ܡ�\n", me);
        me->add("combat_exp",500);
        me->add("potential",500);
        }

        ::die();
}
