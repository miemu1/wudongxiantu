// migong lev9 ������ һָ��

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
 ({ "man" }));

set("title", HIB"���ְ���"NOR);
   set("gender", "����" );
 set("long",
"�޶����Ľ������ࡣ\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",5000+random(2000));
  set("max_jing",5000+random(2000));
  set("max_sen",5000+random(2000));
  set("max_neili",5000+random(2000));
  set("max_mana",2000+random(2000));
  set("eff_neili",5000+random(2000));
  set("neili",2000+random(2000));
        set("per", 1);
        set("age", 32);

       set("jiali" , 100);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 3500000+random(1200000));
                 set_skill("strike", 330+random(50));

 set_skill("finger", 330+random(50));

set_skill("hunyuan-yiqi", 330+random(50));

set_skill("yijinjing", 330+random(50));

set_skill("force", 330+random(50));
set_skill("banruo-zhang", 330+random(50));

set_skill("parry", 330+random(50));

set_skill("dodge", 330+random(50));

set_skill("shaolin-shenfa", 330+random(50));

set_skill("yizhi-chan", 330+random(50));


        map_skill("strike", "banruo-zhang");

      map_skill("parry", "banruo-zhang");

 map_skill("force", "yijinjing");

 map_skill("dodge", "shaolin-shenfa");

map_skill("finger"  , "yizhi-chan");
prepare_skill("finger", "yizhi-chan");
prepare_skill("strike", "banruo-zhang");
set("chat_chance_combat", 80);
        set("chat_msg_combat", ({

      (: perform_action, "strike.san" :),

       (: perform_action, "finger.dian" :),

      (: perform_action, "finger.jingmo" :),

     //(: exert_function, "recover" :),
    (: exert_function, "jingang" :),
 }) );
            set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);

          set_temp("apply/armor", 150);
        set_temp("apply/damage", 150);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();

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