// migong lev9 �����潣 ��÷ ����

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
  set("max_qi",2000+random(2000));
  set("max_jing",2000+random(2000));
  set("max_sen",2000+random(2000));
  set("max_neili",2000+random(2000));
  set("max_mana",2000+random(2000));
  set("eff_neili",2000+random(2000));
  set("neili",2000+random(2000));
        set("per", 1);
        set("age", 32);

       set("jiali" , 100);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 3500000+random(1200000));
                 set_skill("strike", 330+random(50));

 set_skill("unarmed", 330+random(50));

set_skill("bahuang-gong", 330+random(50));

set_skill("tianyu-qijian", 330+random(50));

set_skill("force", 330+random(50));
set_skill("sword", 330+random(50));
set_skill("liuyang-zhang", 330+random(50));

set_skill("parry", 330+random(50));

set_skill("dodge", 330+random(50));

set_skill("yueying-wubu", 330+random(50));

set_skill("zhemei-shou", 330+random(50));


        map_skill("strike", "liuyang-zhang");

          map_skill("sword", "tianyu-qijian");

      map_skill("parry", "tianyu-qijian");

 map_skill("force", "bahuang-gong");

 map_skill("dodge", "yueying-wubu");

map_skill("unarmed"  , "zhemei-shou");
prepare_skill("unarmed", "zhemei-shou");
prepare_skill("strike", "liuyang-zhang");
set("chat_chance_combat", 80);
        set("chat_msg_combat", ({

      (: perform_action, "unarmed.duo" :),

       (: perform_action, "unarmed.zhemei" :),

      (: perform_action, "sword.san" :),

     (: perform_action, "sword.kuangwu" :),

     //(: exert_function, "recover" :),
    (: exert_function, "powerup" :),
 }) );
            set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);

          set_temp("apply/armor", 150);
        set_temp("apply/damage", 150);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();

carry_object("/d/migong/obj/sword")->wield();



}

void init( )
{
	object ob;
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

void die()
{
        object ob, me, corpse;

        ob = this_object();
        me = query_temp("last_damage_from");
        if (!me) return;
             me->add("score",1);
        me->add("shen",10);

        message_vision(WHT"$N������Ѫ����,���ض�����\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
        if((int)me->query("combat_exp") > 500000)   {
        message("vision", me->name() + "Ϊ��������,������800��Ϊ��500Ǳ�ܡ�\n", me);
        me->add("combat_exp",800);
        me->add("potential",500);
        destruct(ob);
        }
        destruct(ob);
        return;
}
