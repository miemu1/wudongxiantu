// migong lev8 baidu

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
 ({ "shenjun dizi" , "dizi" }));

set("title", HIC"�ٶ���������"NOR);
   set("gender", "����" );
 set("long",
"�ٶ������Ψһ�״����ӣ��Եõ��˷��洫��\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",23000+random(20000));
  set("max_jing",23000+random(20000));
  set("max_sen",23000+random(2000));
  set("max_neili",13000+random(2000));
  set("max_mana",23000+random(2000));
  set("eff_neili",13000+random(2000));
  set("neili",13000+random(3000));
        set("per", 1);
        set("age", 33);

       set("jiali" , 100);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 3500000+random(800000));
                 set_skill("unarmed", 300+random(50));

set_skill("huagong-dafa", 300+random(50));

set_skill("poison", 300+random(50));

set_skill("force", 300+random(50));
set_skill("claw", 300+random(50));

set_skill("parry", 300+random(50));

set_skill("dodge", 300+random(50));

set_skill("chousui-zhang", 300+random(50));

set_skill("sanyin-wugongzhao", 300+random(50));

set_skill("zhaixinggong", 300+random(50));


        map_skill("parry", "chousui-zhang");

 map_skill("force", "huagong-dafa");

 map_skill("dodge", "zhaixinggong");

map_skill("unarmed"  , "chousui-zhang");
map_skill("claw"  , "sanyin-wugongzhao");
prepare_skill("unarmed", "chousui-zhang");
prepare_skill("claw", "sanyin-wugongzhao");
set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
               (:     perform_action, "unarmed.zhaohuo" :),

      (:     perform_action, "unarmed.huoqiang" :),

           (:     perform_action, "unarmed.yinhuo" :),

          (:     perform_action, "unarmed.biyan" :),

    (:     perform_action, "unarmed.zhaohuo" :),

    //(: exert_function, "recover" :),
    }) );
            set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);

          set_temp("apply/armor", 150);
        set_temp("apply/damage", 150);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();

  	add_money("gold", random(5));


}

void init( )
{
	object ob;
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        ob->start_busy(1);
        call_out("hunting",1);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",1);
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
void unconcious()
{
    die();
}
void die()
{
        object ob, me, corpse;

        ob = this_object();
       // me = query_temp("last_damage_from");
       me=  this_object()->query_last_damage_from();
    //            me = this_player();
        if (!me) return;
             me->add("score",1);
        me->add("shen",10);

        message_vision(WHT"$N������Ѫ����,���ض�����\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
        if((int)me->query("combat_exp")< 550000)   {

        message("vision", me->name() + "Ϊ��������,������5000��Ϊ��1500Ǳ�ܡ�\n", me);
        me->add("combat_exp",5000);
        me->add("potential",1500);
        destruct(ob);
        }
        destruct(ob);
        return;
}
