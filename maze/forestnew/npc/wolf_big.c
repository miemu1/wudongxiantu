#include <ansi.h>
#include <combat.h>
inherit NPC;
void do_attack();
void create()
{
        string *names = ({"������"}); 
        set_name( names[random(sizeof(names))], ({ "ghost wolf","wolf"}));
        set("vendetta_mark","wolf");
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 20);
        set("long", "����һֻ���µ������ǡ�\n");
      
        set("str", 50);
        set("cor", 12);
        set("cps", 22); 
        set("fle",50);
        set("resistance/qi",25);
        set("max_qi", 300);
        set("max_jing", 3000);
        set("max_neili", 3000);
        set("attitude", "peaceful");
        set("chat_chance_combat", 50);
		    set("chat_msg_combat", ({
		                (: do_attack() :),
		    }) ); 

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) ); 
                set("combat_exp", 3000000);
                set("bellicosity", 5 );
        
        set_temp("apply/attack", 30);
        set_temp("apply/dodge", 10);
        set_temp("apply/parry", 10);
        set_temp("apply/unarmed_damage", 40);
        setup();
        carry_object(__DIR__"obj/wolf_meat");
		carry_object("/clone/weapon/wolfarrow")->set_amount(1);
} 

mixed hit_ob(object me, object victim, int damage_bonus)
{
        victim->receive_damage("qi",30+random(20), me);
        victim->receive_wound("qi",20+random(20), me);
        message_combatd(HIW"\n$N"+HIW"������צ����$n"+HIW"��������һ��Ѫ���ܵ��˿ڣ�"NOR,me,victim);
        return;
}      

void do_attack() {
	object *enemies,enemy;
	string msg;
	int be_damaged,i;
	enemies = query_enemy();
	if (!enemies || sizeof(enemies)==0)
			return;
	enemy = enemies[random(sizeof(enemies))];
	msg = HIR"\n$NͻȻ���ܣ���$n���ʺ�ҧȥ��\n"NOR;
	message_combatd(msg,this_object(),enemy);

	
	
}
