// migong lev11 �ط罣 ������

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
   set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))],
 ({ "mo tou" , "tou" }));

set("title", WHT"а��ħͷ"NOR);
   set("gender", "����" );
 set("long",
"�书��ǿ���ĺ����������ְ��ࡣ\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",3000+random(2500));
  set("max_jing",2500+random(2500));
  set("max_sen",3000+random(2500));
  set("max_neili",3000+random(2500));
  set("max_mana",3000+random(2500));
  set("eff_neili",3000+random(2500));
  set("neili",3000+random(2500));
        set("per", 1);
        set("age", 50);

       set("jiali" , 100);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 5000000+random(2000000));
                 set_skill("sword", 360+random(60));

set_skill("huifeng-jian", 360+random(60));

set_skill("linji-zhuang", 360+random(60));

set_skill("force", 360+random(60));
set_skill("jinding-zhang", 360+random(60));
set_skill("strike", 360+random(60));
set_skill("parry", 360+random(60));

set_skill("dodge", 360+random(60));

set_skill("zhutian-bu", 360+random(60));


        map_skill("sword", "huifeng-jian");

      map_skill("parry", "huifeng-jian");

 map_skill("force", "linji-zhuang");

 map_skill("dodge", "zhutian-bu");

map_skill("strike"  , "jinding-zhang");
prepare_skill("strike", "jinding-zhang");
set("chat_chance_combat", 80);
        set("chat_msg_combat", ({

   (: perform_action, "sword.sanqing" :),

   (: perform_action, "sword.mie" :),

  (: perform_action, "sword.mie" :),

(: perform_action, "strike.puzhao" :),

     //(: exert_function, "recover" :),
         (: exert_function, "powerup" :),
 }) );
            set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);

          set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);

      set("chat_chance", 20);
        set("chat_msg", ({
		(: command("get silver") :),
		(: command("get coin") :),
                (: random_move :),
           }) );
        setup();
        setup();

        carry_object("/d/migong/obj/cloth")->wear();
        carry_object("/d/migong/obj/sword")->wield();

add_money("silver", random(10));


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