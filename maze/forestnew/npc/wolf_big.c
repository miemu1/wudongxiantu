#include <ansi.h>
#include <combat.h>
inherit NPC;
void do_attack();
void create()
{
        string *names = ({"幽灵狼"}); 
        set_name( names[random(sizeof(names))], ({ "ghost wolf","wolf"}));
        set("vendetta_mark","wolf");
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 20);
        set("long", "这是一只可怕的幽灵狼。\n");
      
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

        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
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
        message_combatd(HIW"\n$N"+HIW"锋利的爪子在$n"+HIW"身上留下一道血淋淋的伤口！"NOR,me,victim);
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
	msg = HIR"\n$N突然急窜，向$n的咽喉咬去！\n"NOR;
	message_combatd(msg,this_object(),enemy);

	
	
}
