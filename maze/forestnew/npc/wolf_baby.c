#include <ansi.h>
inherit NPC;
void create()
{
        string *names = ({"��ë����","��ë����","��ë����"}); 
        set_name( names[random(sizeof(names))], ({ "wolf"}));
        set("vendetta_mark","wolf");
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 20);
        set("long", "����һֻ���̵Ķ��ǡ�\n");
      
        set("str", 40);
        set("cor", 10);
        set("cps", 22); 
        set("max_qi", 100);
        set("max_jing", 300);
        set("max_neili", 500);
        set("attitude", "peaceful");
        set("chat_chance", 2);

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) ); 
        set("combat_exp", 1000000);
        set("bellicosity", 5 );
        
        set_temp("apply/attack", 20);
        set_temp("apply/dodge", 20);
        set_temp("apply/parry", 20);
        set_temp("apply/unarmed_damage", 30);
        setup();
        carry_object(__DIR__"obj/wolf_skin");
} 

mixed hit_ob(object me, object victim, int damage_bonus)
{
        victim->receive_damage("qi",30+random(10), me);
        victim->receive_wound("qi",20+random(10), me);
        message_combatd(HIW"\n$N"+HIW"������צ����$n"+HIW"��������һ��Ѫ���ܵ��˿ڣ�"NOR,me,victim);
        return;
}      
