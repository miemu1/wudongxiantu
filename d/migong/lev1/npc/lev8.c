// migong lev1
//by name

#include <ansi.h>
inherit NPC;
void create()
{

   set_name("����", ({ "ye shou"}));
   set("race", "Ұ��");
   set("long","����һֻ"+name()+"����С�ġ�\n");
   set("attitude", "aggressive");
   set("limbs", ({ "ͷ��", "����", "ǰצ", "��ץ", "β��" }) );
   set("max_qi",500+random(500));
   set("max_jing",500+random(500));
   set("max_sen",500+random(500));
   set("max_mana",500+random(500));
   
     set("age", 30);
     set("dex",30);
     set("str",30);     
     set_temp("apply/attack", 30);
     set_temp("apply/damage", 30);
     set_temp("apply/armor", 30);
     set_temp("apply/defence",30);    
     set("combat_exp", 500000);
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
        if((int)me->query("combat_exp") > 100000){
        message("vision", me->name() + "�ɹ�������"+name()+"������100��Ϊ��100Ǳ�ܡ�\n", me);
        me->add("combat_exp",100);
        me->add("potential",100);
        }
       ::die();
}
