//modified by hanchat@txwx2005
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

//inherit F_UNIQUE;
inherit NECK;

int do_wear(string arg);
int do_remove(string arg);
int do_study(string arg);
object offensive_target(object me);

void create()
{
        set_name(HIW"ʥ����"NOR, ({"sheng lingzhu"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "crystal");
                set("value",10000);
set("no_steal",1);
                set("no_drop", "��˱���ı����������󰡡�\n");
                set("no_get", "���ˣ�������ĳ�����\n");
//                set("no_give", "����ϡ��֮����ô������������?\n");
                set("no_sell", "��?����ϡ��֮��˭�����!\n");
                set("long","��س���ʱ�����߹����ϣ����߹����£���һ�ְ�����ǹ����У���Ϊ�˱�!
������н�Ϊ���ӡ�/n��������Ϊһ���ʥ����,�ƺ�����(touch)֮�»ᷢ�����صı仯��\n");
//                set("replace_file", "/d/obj/flower/rose");
                set("armor_prop/armor", 1);
                set("spells/fire", 1);
                set("spells/thunder",1);
                set("spells/water",1);
                set("spells/wind",1);
                set("spells/earth",1);
        }
        setup();
}

int init()
{
        object who = this_player();
/*        {
        if ( interactive(environment()) && 
        environment()->query("combat_exp") < 800000 )
        this_object()->move("/obj/empty"); 
         }
*/
//modified by hanchat@txwx2005
	 add_action("do_study","touch");
        add_action("do_wear","wear");
        add_action("do_remove", "remove");

}

// This function selects a random target for offensive spells/functions.
object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}

int do_wear (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if(arg!="all"&&arg != "sheng lingzhu" )
    return notify_fail("��Ҫ���ʲô��\n");
  msg = "$N����һ��"+name+"���ٸ�������ˬ��\n"; 
  zhu->set("wear_msg",msg);
remove_call_out("shengzhuconditions");
call_out("shengzhuconditions",1,me,zhu);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if ( arg!= "all" && arg != "sheng lingzhu")
    return notify_fail("��Ҫժ��ʲô��\n");

  msg = "$N��"+name+"�����ժ��������\n"; 
  zhu->set("unequip_msg",msg);
remove_call_out("shengzhuconditions");
  return 0;
}

void shengzhuconditions(object who,object ob)
{
     object target;
     int ap,dp,damage;
     string msg;
          
string type;
type = ob->query("armor_type");
if( who->query_temp("armor/" + type) && ob->query("equipped")!="worn")
return;
  if( who->is_fighting())
     {
        target = offensive_target(who);
  if( ! target ) return ;      
 if( ! present( target,environment(who)) ) return ;    
        msg = HIR"ʥ������ʺ�����Ȼ���䣬ɲʱ�����׵�������ɽ�����ѣ�\n"NOR;
//divid by 10;

                ap = who->query("combat_exp");
                dp = target->query("combat_exp");
                        
                        
                if( random(dp) < ap/2 )
                 {
                        damage = 500+random(300)+who->query_skill("xianfeng-spells", 1);
                        damage -= random((int)target->query("eff_jing") / 100);

                        if( damage > 0 ) 
                        {
                                msg += HIC "���$n��ܲ��������׵��������ţ��ֱ��ػ��յ�Ƥ�����á�\n
��ɽʯ�ҵ�Ƥ��Ѫ��������������˫�ۣ��ֱ�ˮ����͸�������������ѡ�\n" NOR;

                                target->receive_damage("jing", damage*8/5);
                                target->receive_wound("jing", damage*2/3);
                                target->receive_damage("qi", damage*8/5);
                                target->receive_wound("qi", damage/2);
                                target->start_busy(5);
				    ob->add("use_times", 1);
                        } 
            else
//here, cast failed and the target's mana_factor will be added to the previous
//damage to hurt yourself:(...note damage<0.
                msg += HIC "\n˭֪$n���޷�Ӧ��\n" NOR;   
                }
                else
                        msg += "���Ǳ�$n�㿪�ˡ�\n";

                message_vision(msg, who, target); 
        }
if(ob->query("use_times")>15)
{
message_vision("$N���е�ʥ����ͻ���߲�֮�⣬һ��ϼ������ʧȥ����ɫ��\n", who, target); 
remove_call_out("shengzhuconditions");
}
else
call_out("shengzhuconditions",30,who,ob);
}


int do_study(string arg)
{
	object me,pearl;
	int i;
	me=this_player();

	if( !arg || (arg!="ling zhu"
			&& arg!="zhu"
			&& arg!="pearl") )
		return notify_fail("��Ҫ��ʲô��\n");

	if( (int)me->query_skill("xianfeng-spells",1) < 100)
		return notify_fail("����ɷ������������������ܲ��������ڵ�ħ����\n");
	if( (int)me->query_skill("xianfeng-spells",1) >= 500)
		return notify_fail("����ɷ����������ߣ������ڵ�ħ���Զ�����������ˡ�\n");
	if( (int)me->query_skill("taoism",1) < 500)
		return notify_fail("��ķ������������������򲻵������ڵ�ħ����\n");
	if( (int)me->query("qi") < 500)
		return notify_fail("�����Ѫ���㣬�������ε���ȥ��\n");
	if( (int)me->query("jing") < 500)
		return notify_fail("��ľ��񲻼ã���������Թ�ȥ��\n");
	if( (int)me->query("neili") <50000)
		return notify_fail("����������㣬�����к����档\n");

	message_vision("$N˫������$n��ֻ�����Ƶ���ϼ���������С�\n",me,this_object());
	me->improve_skill("xianfeng-spells", random( (int)me->query_int()/4 )+10+random(10) );
	me->receive_damage("qi",30+random(300));
	me->receive_damage("jing",30+random(300));
	me->add("neili",-500-random(500));
	me->start_busy(2+random(5));

	write("����ɷ��������������ƺ�������һ�㡣\n");
	return 1;
}



void owner_is_killed()
{
write(HIY"ֻ����ǰ���һ��....ʥ����ͻȻ������!\n"NOR);
destruct(this_object());
}