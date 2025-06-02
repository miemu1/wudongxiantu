#include <ansi.h> 
#include <weapon.h> 
 
inherit SWORD; 
 
void create()
{
        set_name(HIY "��������" NOR, ({ "canyang baojian", "canyang", 
                                        "sword" }));
        set_weight(8000);
        if (clonep())
                destruct(this_object());
        else {
                set("long", HIY "
�˽�����ߣ�ϸ������ͨ�巺����⡣�����������Ͽ̲���ͼ
�ƣ�����֮�ϻ�����������������Ĺ�׭���ƺ�����ѧ�йء�\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", HIC "$N" CYN "���������Х����ʱ��"
                                 "âһ����һ������ƿջ���������$N"
                                 CYN "�Ƽ䡣\n" NOR);
                set("unwield_msg", HIC "$N" CYN "һ����ߣ������е�"
                                   "�����������뽣�ʡ�\n" NOR);
                set("skill", ([
                        "name"         : "poyang-jian",
                        "exp_required" : 300000,
                        "jing_cost"    : 90,
                        "difficulty"   : 92,
                        "max_skill"    : 129,
                        "min_skill"    : 60
                ]));

                set("stable", 100);
        }
        init_sword(140);
        setup();
} 
 
int query_unique() { return 1; }

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n = me->query_skill("sword");

        if (me->query_skill("sword") < 150)
                return damage_bonus / 2;

        if (me->query_skill_mapped("sword") != "poyang-jian")
                return damage_bonus / 2;

        switch (random(4))
        {
        case 0:
                victim->receive_damage("jing", n / 2 , me);
                victim->receive_wound("jing", n / 4, me);
                return HIW "$N" HIW "��Хһ��������" HIY "��������" HIW 
                           "������ǰ���͵ػӳ���һ����ȵĽ�����$n" 
                           HIW "�Ƶ��������ˡ�\n" NOR;
        case 1:
                victim->receive_damage("qi", n, me);
                victim->receive_wound("qi", n, me);
                return HIR "$N" HIR "����" HIY "��������" HIR "ͻȻ����"
                           "һ����ҫ�۶�Ŀ��һ�����ȵĽ�������$n" HIR "��\n" NOR;
        }
        return damage_bonus;
}

void start_borrowing()  
{ 
     remove_call_out("return_to_zuo");  
     call_out("return_to_zuo", 7200+random(600));  
}  
   
void return_to_zuo()  
{  
      object me;  
 
      me = environment();  
      if (! objectp(me))  
              return;  
 
      while (objectp(environment(me)) && ! playerp(me))  
              me = environment(me);  
 
      if (playerp(me))  
      {  
              if (me->is_fight())  
              {  
                      call_out("return_to_zuo", 1);  
                      return;  
              }  
 
              message_vision("��Ȼһ����ɽ�ɵ������˹���������$N��æ�к������������������������û�"  
                             "���������������ڲ�����ô����\n"  
                             "$N���������ˣ����ˣ�����û�ȥ�ɡ���\n"  
                             "$N����������������ɽ�ɵ��Ӵ��ߡ�\n", me);  
      } else  
      {  
              message("vision", "��Ȼһ����ɽ�ɵ������˹������������������̾�˿�����ҡҡͷ���ˡ�\n",  
                      me);  
      }  
 
      destruct(this_object()); 
}
