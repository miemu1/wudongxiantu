#include <ansi.h>
#include <combat.h>
inherit NPC;
void create()
{
        string *names = ({"�׶��ͻ�","�����ͻ�"}); 
        set_name( names[random(sizeof(names))], ({ "big tiger","tiger"}));
        set("vendetta_mark","tiger");
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 20);
        set("long", "����һֻ���͵��ϻ���\n");
      
        set("str", 50);
        set("cor", 12);
        set("cps", 22); 
        set("fle",50);
        set("resistance/qi",25);
        set("max_qi", 300);
        set("max_jing", 3000);
        set("max_neili", 3000);
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) ); 
        set("combat_exp", 3000000);
        set("bellicosity", 5 );
        
        set_temp("apply/attack", 40);
        set_temp("apply/parry", 40);
        set_temp("apply/unarmed_damage", 50);

        setup();
        carry_object(__DIR__"obj/tiger_bone");
		carry_object("/clone/money/silver")->set_amount(50);
} 

varargs void start_busy(mixed new_busy, mixed new_interrupt) 
{
        message_vision(HIY"\n$NͻȻ����һ���쳹ɽ�ֵ�ŭ��$n��ʱ��ʧɫ��\n"NOR,this_object());
        ::start_busy(1);
} 
