// migong lev1
//by name

#include <ansi.h>
inherit NPC;
void create()
{

   set_name(HIG"����", ({ "ye shou"}));
   set("race", "Ұ��");
   set("long","����һֻ"+name()+"����С�ġ�\n");
   set("attitude", "aggressive");
   set("limbs", ({ "ͷ��", "����", "ǰצ", "��ץ", "β��" }) );
   set("max_qi",1500+random(1500));
   set("max_jing",1500+random(1500));
   set("max_sen",1500+random(1500));
   set("max_mana",1500+random(1500));
   
     set("age", 50);
     set("dex",50);
     set("str",50);     
     set_temp("apply/attack", 50);
     set_temp("apply/damage", 50);
     set_temp("apply/armor", 50);
     set_temp("apply/defence",50);    
     set("combat_exp", 1500000);
     setup();
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
        message_vision(WHT"$Nһ���ҽ�,���ڵ��ϣ����˸���ͷ�Ͳ������ˡ�\n"NOR,ob,me);
        if((int)me->query("combat_exp") > 500000){
        message("vision", me->name() + "�ɹ�������"+name()+"������150��Ϊ��150Ǳ�ܡ�\n", me);
        me->add("combat_exp",150);
        me->add("potential",150);
        }
       ::die();
}
