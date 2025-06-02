#include <ansi.h>
#include <combat.h>
inherit NPC;
void do_stun();
void do_attack();
void create()
{
        string *names = ({"������","������","������"}); 
        set_name( names[random(sizeof(names))], ({ "bear king","bear"}));
        set("vendetta_mark","bear");
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 20);
        set("long", "����һֻ���͵�������\n");
      
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("resistance/qi",50);
        set("max_qi", 200);
        set("max_jing", 200);
        set("neili", 200);
        set("max_neili", 200);
        set("attitude", "peaceful");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
	        (: do_attack() :),
        }) ); 

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) ); 
        set("combat_exp", 60000);
        
        set_temp("apply/attack", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/unarmed_damage", 60);
        setup();
		carry_object("/clone/drug/shanshen")->set_amount(1);
        carry_object(__DIR__"obj/bear_dan");
} 

void do_stun() 
{
	object *enemies,enemy;
	string msg;
	int be_damaged;
	
	enemies = query_enemy();
	if (!enemies || sizeof(enemies)==0)
	        return;
	enemy = enemies[random(sizeof(enemies))];
	msg = HIC"\n$NͻȻվ���������������Ƴ�$n������\n"NOR;
	message_combatd(msg, this_object(), enemy);
	COMBAT_D->do_attack(this_object(),enemy, 0, 0);
	start_busy(2);
}

void do_attack() 
{
	object *enemies,enemy;
	string msg;
	int be_damaged,i;
	
	enemies = query_enemy();
	if (!enemies || sizeof(enemies)==0)
                return;
	enemy = enemies[random(sizeof(enemies))];
	msg = HIB"\n$NͻȻ���Դ󷢣��������Ƴ�$n������\n"NOR;
	message_combatd(msg,this_object(),enemy);
	i = 2+random(3);
	while (i--)
	        COMBAT_D->do_attack(this_object(),enemy, 0, 0);

	start_busy(2);
}
