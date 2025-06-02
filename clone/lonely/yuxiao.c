 //yuxiao.c
 //�һ�����--����
 //PLZW 2003-12-22
 
#include <ansi.h>
#include <weapon.h>

inherit XSWORD;

void create()
{
        set_name(HIW "����" NOR, ({ "yu xiao", "yu", "xiao" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "֧");
                set("long", HIW "һ֧�������ɵ��������ȥ��Ө�����������˾������������\n" NOR);
                set("value", 800000);
                set("no_sell", 1);
                set("material", "stone");
                set("wield_msg", HIW "$N" HIW "����һ�ӣ������Ѷ���һ֧��Ө��������\n" NOR);
                set("unwield_msg", HIW "$N" HIW "��������һת��գ�ۼ�������Ȼ����Ӱ�١�\n" NOR);
                set("stable", 100);
        }
        init_xsword(90);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("sword") != "yuxiao-jian" ||
            me->query_skill("yuxiao-jian", 1) < 100)
                return damage_bonus / 2;

        switch (random(10))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 10 + 2);
                return HIW "ͻȻ��һ������������$N" HIW "��������$n" HIW
                       "��ʱֻ����̫��Ѩ������ʹ��\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("jing", n / 3, me);
                victim->receive_wound("jing", n / 3, me);
                return HIW "$N" HIW "������������ʽ����������������$n" HIW
                       "��ʱֻ����Ѫ��ӿ������֮����\n" NOR;
        }
        return damage_bonus;
}


void start_borrowing() 
{ 
         remove_call_out("return_to_huang"); 
         call_out("return_to_huang", 7200 + random(600)); 
} 
  
void return_to_huang() 
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
                      call_out("return_to_zhang", 1); 
                      return; 
              } 

              message_vision("��Ȼһ���һ��������˹���������$N��æ�к��������Ƶ��������������û�" 
                             "��������ڲ�����ô����\n" 
                             "$N���������ˣ����ˣ�����û�ȥ�ɡ���\n" 
                             "$N�����ｻ���һ����Ӵ��ߡ�\n", me); 
      } else 
      { 
              message("visoin", "��Ȼһ���һ��������˹������������̾�˿�����ҡҡͷ���ˡ�\n", 
                      me); 
      } 

      destruct(this_object()); 
} 
