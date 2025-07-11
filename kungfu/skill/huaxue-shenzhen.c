//by mudwu
#include <combat.h>
inherit SKILL;
mapping *action = ({
([      "action":               "$N双手连环挥舞，一招「消劲针」，$w直奔$n的胸腹要害",
        "dodge":                -10,
        "damage":               200,
        "lvl" : 0,
        "skill_name" : "消劲针",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        "damage_type":  "刺伤"
]),
([      "action":               "$N身形晃动，一招「化气针」，手中$w如一串银线，往$n咽喉打去",
        "dodge":                -20,
        "damage":               300,
        "lvl" : 60,
        "skill_name" : "化气针",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        "damage_type":  "刺伤"
]),
([      "action":               "$N五指微张，一招「吸血针」，手中$w飞蚊般往$n全身叮去",
        "dodge":                -40,
        "damage":               400,
        "lvl" : 90,
        "skill_name" : "吸血针",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        "damage_type":  "刺伤"
]),
([      "action":               "$N大喝一声，一招「摄魂针」，$w幻化出夺目光亮，打向$n",
        "dodge":                -50,
        "damage":               500,
        "lvl" : 100,
        "skill_name" : "摄魂针",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        "damage_type":  "刺伤"
]),
([      "action":               "$N错步一跃，一招「夺魄针」，$w带着阵阵阴风，打向$n全身",
        "dodge":                -60,
        "damage":               600,
        "lvl" : 110,
        "skill_name" : "夺魄针",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        "damage_type":  "刺伤"
]),
([      "action":               "$N双目精芒闪动，一招「化血针」，手中$w全数脱手飞出，排山倒海般打向$n全身",
        "dodge":                -60,
        "damage":               700,
        "lvl" : 120,
        "skill_name":  "化血针",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        "damage_type":  "刺伤"
]),
([      "action":               "$N纵声长啸，一招「鬼魅针」，$w竟然带着一股强烈劲风，扫向$n",
        "dodge":                -70,
        "damage":               800,
        "lvl" : 130,
        "skill_name" : "鬼魅针",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        "damage_type":  "刺伤"
]),
([      "action":               "$N眼中杀气突然大盛，一招「杀气针」，$w飞蝗般打向$n全身",
        "dodge":                100,
        "damage":               900,
        "lvl" : 200,
        "skill_name" : "杀气针",
        "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        "damage_type":  "刺伤"
]),
});
int valid_enable(string usage) { return usage == "throwing"; }
int practice_level(){   return 200;  }
int valid_learn(object me)
{
      if (me->query_skill("throwing",1) <= me->query_skill("huaxue-shenzhen",1))
      return notify_fail("你的基础不够，无法领会更高深的技巧！\n");
    return 1;
}
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    
    level   = (int) me->query_skill("huaxue-shenzhen",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["damage"] = level+random(level);
    if ((int)me->query_temp("huaxue-shenzhen")>0)
        return (["action": BOLD "一"+weapon->query("unit")+"$w"+BOLD+"射向$n"+BOLD+"的$l" NOR,
                 "dodge": -3*random(level),
                 "damage": level,
                 "damage_type":"刺伤",
                 "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                ]);
    return a_action;

}

int practice_skill(object me)
{
    object ob;
    if( (int)me->query("qi") < 30
    ||  (int)me->query("neili") < 35 )
        return notify_fail("你的内力或气不够，没有办法练习化血神针。\n");
    if (!objectp(ob = me->query_temp("weapon"))
    || (string)ob->query("skill_type") != "throwing")
    if (!objectp(ob = me->query_temp("secondary_weapon"))
    || (string)ob->query("skill_type") != "throwing")
        return notify_fail("你装备的武器不对。\n");
    me->receive_damage("qi", 30);
    me->add("force", -20);
    me->add_temp("pratice_throwing",1);
    if (me->query_temp("pratice_throwing") > me->query_skill("huaxue-shenzhen",1)/20 ){
           if( (int)ob->query_amount()==1 ) {
                   ob->unequip();
                   tell_object(me, BOLD "\n你的" + ob->query("name") + "用完了！\n\n"+NOR);
           }
           ob->add_amount(-1);
           me->delete_temp("pratice_throwing");
    }
    write("你按著所学练了一遍化血神针。\n");
    return 1;
}

void do_interlink(object me, object victim)
{
    int skill,i,j;
    object *enemy,weapon=me->query_temp("weapon");
    string all_enemy;
    
    if (!weapon) return;
    skill=me->query_skill("huaxue-shenzhen", 1);
    if (random(skill)>250){
        enemy=me->query_enemy();
        if (!sizeof(enemy)) return;
        if (sizeof(enemy)==1 && enemy[i]->query("eff_qi")<0 ) return;
        all_enemy=enemy[0]->name();
        for (i=1;i<sizeof(enemy);i++)
            all_enemy+=("、"+enemy[i]->name());
        message_vision(BOLD+"$N纵身跃起，衣袖一挥，几"+weapon->query("unit")+weapon->name()+"同时射向"+all_enemy+"。\n\n" NOR,me);
        me->set_temp("mantianhuayu",1);
        for (i=0;i<sizeof(enemy);i++){
            for (j=0;j<(skill/(60*sizeof(enemy)));j++)
                if ((me->is_fighting(enemy[i]) || enemy[i]->is_fighting(me)) && enemy[i]->query("eff_qi")>0 ){
                    if (environment(me) == environment(enemy[i]))
                     {
                        COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"), TYPE_QUICK);
                     }
                }else break;
        }
    me->delete_temp("huaxue-shenzhen");
    }
}

