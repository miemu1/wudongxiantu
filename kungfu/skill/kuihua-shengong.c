#include <ansi.h>
//#include <combat.h>
//�޸���������������¿ɶ�
//�޸�������Ϊ�����ȼ�
inherit FORCE;
//inherit SKILL;
//#include "force.h"
string *parry_msg = ({
"$n��һ������һ������һ������һ������$N���������������������²����������ް��������\n",
"$n���ִ�Ĵָ��ʳָ��סһ���廨�룬����һ�٣���ס���ƣ�$N����ʽ��ʹ����ȥ��\n",
"$n��������������ʳָ��������$N����Ŀ���̣��������ܾ��˵Ĵ򷨡�\n",
"$n���ҵ���أ�Ժ�����Ͼ��������$N���ޣ����ù��򣬺ù��򣡡�\n",
"$n�ӻ���ȡ��һ��ѩ�׵ĳ���������Ĩ��Ĩ������ֱ������Ϸ̨�ϵĻ�����$Nһ������ͣס���Լ�����ʽ��\n"
});
string *dodge_msg = ({
"ͻȻ֮�䣬��Ӱ���ϣ�$n��󻬳����࣬��ʱ�ֻص���ԭ�أ������$N��һ�С�\n",
"$n�ֱۻ�ת����$N������һ�ƣ�˳������һ�ԡ�\n",
"$n�����������$N������Ѹ���ޱȵ�һ����˳������һ�ԡ�\n",
"$n����Ʈ����������ȣ�ת�˼�ת���Ʋ���$N����󣬶����$N��һ�С�\n",
"$Nֻ����ǰһ�����ƺ�����$n����һ�ϣ����漴�ּ�$n�ص�ԭ�أ�ȴ�ƴ�δ�뿪��\n",
"$N�۾�һ����$n��û����Ӱ��ͻȻ$n���������һ��$N��ͷ������Ծ����\n",
"$n��ȻһЦ������֮����$N����֪����Ǻã�ͣס�˹�����\n",
"$n��һ������һ������һ������һ������$N���������������������²����������ް��������\n",
"$n���ִ�Ĵָ��ʳָ��סһ���廨�룬����һ�٣���ס���ƣ�$N����ʽ��ʹ����ȥ��\n",
"$n��������������ʳָ��������$N����Ŀ���̣��������ܾ��˵Ĵ򷨣�\n",
"$n���ҵ���أ�Ժ�����Ͼ��������$N���ޣ����ù��򣬺ù��򣡡�\n",
});
string  *msg = ({
"$N����һ�䣬��������۵�$n��ǰ����಻��һ�ߣ�����$w�Ѿ��̵�$n��$l",
"������Ӱ������$N���е�$w��$n��$lֱ�����������籼�ף��ܲ��ɱ�",
"$N������ϣ�������$n�ļ���һ���ٺ�ɳ�ȥ�������е�$wȴָ��$n��$l",
"$NͻȻԾ�����࣬$nһ̧ͷ�����ֿ��в���$N����Ӱ����һ�ɺ���ȴ�Ӻ�Ϯ��",
"$N��һ������һ������һ������һ������$n��������������������һת������$n",
"�����$N���������ϣ�˫�����õ��ģ���������֮������$n����֮�ʵ���$w����$n",
"$N����Ʈ����������ȣ�ת�˼�ת���Ʋ�������һ������$n������֮��֮�죬ֱ�Ƿ�����˼",
"$N����һ�٣�վ��Ƭ�̣�����$n����󷽻������࣬���ſ������׵Ļص�ԭ��",
"$NǱ���������������ˣ�����$n������ת������$w��ʹ����Ҳ��������һ�㣬Խ��Խ��",
"ͻȻ$N����$w����һ�ã�����$n΢һ����֮��ֱȡ$n��$l���Ƶ���������"NOR,
"����$nһ��֮�ʣ�$N����Ծ�����ߣ���������أ����Ӹ�������ˢˢ��������$n��ȥ",
"$N��Ȼ����Ϊ�����ֳ�����������Ӱ���ٻ���$n������$w�û�������ֱ��$n��$l",
"$nֻ����ǰһ�����ƺ�����$N����һ�ϣ����漴�ּ�$N�ص�ԭ�أ�ȴ�ƴ�δ�뿪",
"$Nһ����У����������ڰ����һת������ޱȵķ�������������$w�ƿ�ֱ��$n$l",
"$N��Ȼ����Ϊ�����ֳ�����������Ӱ���ٻ���$n������$w���Ī�⣬ֱ��$n��$l",
"$N������������ȣ�Ʈ����ȥ��ֱ�����̣����е�$wȴ���Ƕ���$n����",
"$Nһ����Ц������Ｒ����ǰ�������Ƕ������ã�һ˲֮�䣬��$n����Ѳ���һ�ߣ����˵ı��Ӽ���Ҫ����һ��",
"$N�����������$n������Ѹ���ޱȵ�һ���������ֱۻ�ת������$n������һ��",
"$Nһ��ͦ�̣��������ţ���̬֮�У������л�ɽ��Ů������ѧ����Ů��ʮ��ʽ���ķ��ˣ�ֻ�Ǵ���������ɭɭ��а��",
"$N����һȦ����ת$w����ش̳���ˢˢˢ������ʽ�����о���ָ��$n��Ҫ��"
});
mapping *action = ({
([
        "action":"ͻȻ֮�䣬��Ӱ���ϣ�$N��󻬳����࣬��ʱ�ֻص���ԭ��",
        "lvl" : 0,
        "skill_name" : "��Ӱ����",
        "damage_type":  "����"
]),
([
        "action":"$N�����������$n������Ѹ���ޱȵ�һ����$n��Щ�����Լ�С��",
        "lvl" : 10,
        "skill_name" : "�Լ�С��",
        "damage_type":  "����"
]),
([
        "action":"�����$N�����ϣ��ڵ�$n�����̳�һ��������˲��Ծ��ԭ��",
        "lvl" : 20,
        "skill_name" : "������",
        "damage_type":  "����"
]),
([
        "action":"$nֻ����ǰһ�����ƺ�����$N����һ�ϣ����漴�ּ�$N�ص�ԭ�أ�ȴ�ƴ�δ�뿪",
        "lvl" : 30,
        "skill_name" : "��ǰһ��",
        "damage_type":  "����"
]),
([
        "action":"$NͻȻ���з�һ�䣬һ�С�����Ū�ѡ���$w�����������ʽ������ס�$n����֮�з������",
        "lvl" : 40,
        "skill_name" : "�з�һ��",
        "damage_type":  "����"
]),
([
        "action":"$N����ˣ�$n��׷������ͻȻ��$N����$n��ǰ��һ�С��������𡹣�����$wֱָ$n��$l",
        "lvl" : 50,
        "skill_name" : "�����",
        "damage_type":  "����"
]),
([
        "action":"$N����Ʈ����������ȣ�ת�˼�ת��һ�С��������������Ʋ���$n�����",
        "lvl" : 60,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([
        "action":"$Nһ����Ц��һ�С����Ǹ��¡�������Ｒ����ǰ��һ˲֮�䣬��$n����Ѳ���һ�ߣ�$w�漴�ݳ�",
        "lvl" : 70,
        "skill_name" : "������ǰ",
        "damage_type":  "����"
]),
([
        "action":"$N�ȵ������ã������㼴�γ�$w��һ�С����ഩ���������ִ̳�������ת����ȥ",
        "lvl" : 80,
        "skill_name" : "���ִ̳�",
        "damage_type":  "����"
]),
([
        "action":"$N��س嵽$n��ǰ��һ�С���ظ��Ŀ��������$wֱ��$n���ۣ�$n��æ�мܣ�����$N��$wͻȻת��",
        "lvl" : 90,
        "skill_name" : "ֱ������",
        "damage_type":  "����"
]),
([
        "action":"$N����Ծ��$ņ��һ����������$Nһ�С����Ƿɶ项������ֱ����£�����$w����$n��$l",
        "lvl" : 100,
        "skill_name" : "����Ծ��",
        "damage_type":  "����"
]),
([
        "action":"$Nһ�С�Ⱥа���ס�����֦�Ͱڣ�$n��ǰ�·�ͻȻ�������߰˸�$N���߰�ֻ$wһ�����$n",
        "lvl" : 110,
        "skill_name" : "Ⱥа����",
        "damage_type":  "����"
]),
});

int query_neili_improve(object me)
{
	int lvl;

	lvl = (int)me->query_skill("kuihua-shengong", 1);
	if (me->query("special_skill/ghost"))
		return lvl * lvl * 21 * 15 / 100 / 200;
	else
		return lvl * lvl * 15 * 15 / 100 / 200;
}

int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "force" || usage =="parry" || usage =="dodge"; 
}
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
string query_dodge_msg(string limb)
{
    	return dodge_msg[random(sizeof(dodge_msg))];
}

mapping query_action(object me, object weapon)
{
        int i, level, j ;

        level   = (int) me->query_skill("kuihua-shengong",1);

        if (level > 120
        && me->query("max_neili") > 1200
        && random(me->query_dex(1)) > 25
        && me->query("quest2/kuihua/pass")
        && !random(3)){
                return([
                        "action":       msg[random(sizeof(msg))],
                        "force" :       400 + random(250),
                        "attack" :     100 + random(150),
                        "dodge" :       20 + random(60),
                        "parry" :       20 + random(60),
                        "damage":       me->query_temp("cimu")? 200+random(180):150+random(180),
                        "damage_type":  "����",
                ]);
        }
        for(i = sizeof(action); i > 0; i--) {
                if(level > action[i-1]["lvl"]) {
                        j = NewRandom(i, 20, level/5);
                        return ([
                                "action":       action[j]["action"],
                                "lvl":          action[j]["lvl"],
                                "damage_type":  action[j]["damage_type"],
                                "attack" :      random(50),
                                "dodge":        random(50),
                                "parry":        random(30),
                                "damage":       100 + random(180),
                                "force":        300 +random(350),
                        ]);
                }
        }
}
/*mapping query_action(object me, object weapon)
{    
           
            
      
          
                return ([
          "action":msg[random(sizeof(msg))],
          "damage":(random(4)+1)*60,
          "damage_type": "����",
          "dodge": random(30)+10,
          "force":(random(200)+60),
       ]);
}
*/
string query_parry_msg()
{
        return parry_msg[random(sizeof(parry_msg))];
}

string query_txt()
{
	return "Ҫ��̫��"ZJBR
	"��Ч����Ҫ�����츳���ܴ������Ṧ������ֵĹ������Ա�����(�Ṧ����/2+���ܵȼ�)�͹������Ṧ������ͬ�ȼ�1/2���ʴ�����"
	"�����ڹ�����Խ���������Խ��(ͬ�ȼ����ڶ���25����������)�����������Կ���";
}

mixed valid_damage(object ob, object me, int damage, object weapon) 
{
	mixed result; 
	int ap, dp, mp, ratio; 

	if ((int)me->query_skill("kuihua-shengong", 1) < 100 || 
	    ! me->query("special_skill/ghost") ||
	    ! me->query_temp("dodge_valid_damage") ||
	    me->query_skill_mapped("force") != "kuihua-shengong" ||
	    me->query_skill_mapped("parry") != "kuihua-shengong" ||
	    me->query_skill_mapped("dodge") != "kuihua-shengong" ||
	    me->query_skill_mapped("sword") != "kuihua-shengong" ||
	    ! living(me)) 
		return; 

	mp = ob->query_skill("count");
	ap = ob->query_skill("dodge") + mp; 
	dp = me->query_skill("dodge") / 2 + me->query_skill("kuihua-shengong", 1); 

	// ���ʣ��Լ����� dex �ߡ�str �ͣ��Է����� str �ߣ�dex �ͣ�����ǿ     
	ratio = me->query("dex") - ob->query("dex");

	dp = dp * (100 + ratio*2) / 100;

	if (ap / 2 + random(ap) < dp)
	{
        result = ([ "damage": -damage ]);

        result += (["msg" : dodge_msg[random(sizeof(dodge_msg))] ]);
        return result;
	} else
	if (mp >= 100)
	{
		switch (random(4))
		{
		case 0:
			result = HIY "$N" HIY "�۾�һ����$n" HIY "��û����Ӱ"
				 "������$N" HIY "��ͨ����˿����Ϊ���ң�����"
				 "���С�"NOR"\n";
			break;
		case 1:
			result = HIY "$N" HIY "��ǰһ�����ƺ�����$n" HIY "��"
				 "��һ�Ρ�$N" HIY "һ����Ц����˲�俴��������"
				 "ʵ��"NOR"\n";
			break;
		case 2:
			result = HIY "$n" HIY "����Ʈ����������ȣ�ת�˼�ת��"
				 "����$N" HIY "��Ҳ�����������о�ֱ������"NOR"\n";
			break;
		default:
			result = HIY "ͻȻ���Ӱ���Σ�$n" HIY "��󻬳����࣬"
				 "����$N" HIY "����˼����׷���ϣ�����������"
				 "����"NOR"\n";
			break;
		}
		COMBAT_D->set_bhinfo(result);
	} 
} 

int practice_skill(object me)
{
       object weapon;
/*
       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "pin")
               return notify_fail("��ʹ�õ��������ԡ�\n");
       if ((int)me->query_skill("kuihua-shengong", 1) < 180)
               return notify_fail("�㻹û���������񹦵ľ��裬����������ϰ��\n");
       if ((int)me->query("jingli") < 50)
               return notify_fail("�������̫���ˡ�\n");
       if ((int)me->query("neili") < 20)
               return notify_fail("������������ˡ�\n");
       me->receive_damage("jingli", 50);
       me->add("neili", -20);*/	 
        return notify_fail("�����񹦲�����޷��򵥵�ͨ����ϰ������\n");
        //return 1;
}
int query_effect_dodge(object attacker, object me)
{
	int lvl;
	
	if (! me->query("special_skill/ghost"))
		return 0;

	lvl = me->query_skill("kuihua-shengong", 1);
	if (lvl < 50)  return 0;
	if (lvl < 100) return 30;
	if (lvl < 150) return 40;
	if (lvl < 200) return 60;
	if (lvl < 250) return 80;
	if (lvl < 300) return 100;
	if (lvl < 350) return 120;
	return 130;
}

int valid_learn(object me)
{
        object weapon;
        if (me->query("family/family_name") != "�������")
           return notify_fail("���͵ѧ������̵��񹦣�����\n");

        if ((int)me->query_skill("kuihua-shengong", 1) < 180)
                return notify_fail("������̫���ˣ���ֻ��ͨ���ж����������䡷��ѧϰ��\n"); 
        if ((int)me->query_skill("tianmo-jian", 1) > 0)
                return notify_fail("�㲻ɢȥ��ħ�����������ϰ���������䡷����\n");
        if ((int)me->query_skill("pixie-jian", 1) > 0)
                return notify_fail("�㲻ɢȥ��а�����������ϰ���������䡷����\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "pin" )
                return notify_fail("��ʹ�õ��������ԡ�\n");
        return 1;
}
int difficult_level()
{
     object me; 
     int lv;
     me = this_player(); 
     lv = me->query_skill("kuihua-shengong", 1) - 180; 
     if (lv > 200) lv = 200; 
     
     if (! me->query("special_skill/ghost"))
	return 1000;
     else
	return 600 - lv;

}

mixed hit_ob(object me, object target)
{
    int skill,i,lvl,j;
    object weapon;
    mapping a_action;
    me=this_player();
    weapon=me->query_temp("weapon");
    
    
    if( !target ) target = me->select_opponent();
    if (!weapon) return;
       
    skill=me->query_skill("kuihua-shengong", 1);
    i = to_int(skill/100);
    if (me->query_temp("auto_hit",1)) {
         me->add_temp("auto_hit",-1);
         return;
        }
 //   if ( lvl = 1 ) message_vision(BOLD+"$N���һ��,��!����Ծ�𣬷ֳ�������Ӱ������"+weapon->name()+HIG"ͬʱ������$n��"NOR"\n""\n",me,target); 
 //   if ( lvl = i ) me->set_temp("auto_hit",1);
    if ( me->query_skill("kuihua-shengong", 1) >= 200
         && me->query_skill_mapped("sword") == "kuihua-shengong"
         && weapon->query("skill_type") == "pin" )
         {
          me->set_temp("auto_hit",i);
        for (j=0;j<i;j++){
        me->set_temp("action_flag",1);
     //   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
          me->set_temp("action_flag",0); 
//        me->add_temp("auto_hit",1);      
            }
          me->delete_temp("auto_hit",1); 
         return a_action;
        
        }
}
int valid_force(string force)
{
	return force == "xixing-dafa" ||
	       force == "guixi-gong" ||
	       force == "riyue-xinfa" ||
	       force == "jiaohua-neigong" ||
	       force == "luoying-xinfa" ||
	       force == "kuihua-xinfa";
}

string perform_action_file(string action)
{
        return __DIR__"kuihua-shengong/perform/" + action;
}

//int double_attack(object me){ return 1;}
string exert_function_file(string func)
{
       return __DIR__"kuihua-shengong/exert/" + func;
}

