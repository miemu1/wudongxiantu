// kumu-shengong.c ��ľ��
// cleansword
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit FORCE;
int valid_enable(string usage)
{
    return usage == "force";
}
int valid_learn(object me)
{
    mapping skl;
    string *sname,master;
    int i;
    int lvl = (int)me->query_skill("kumu-shengong", 1);
    master=me->query("family/master_id");
    
                    
    if ( me->query("gender") == "����" && lvl > 49)
        return notify_fail("���޸����ԣ���������������������Ŀ�ľ�񹦡�\n");
    if ((int)me->query_skill("force", 1) < 30)
        return notify_fail("��Ļ����ڹ���򻹲������޷�����ľ�񹦡�\n");
    if (me->query_skill("force",1)<=lvl)
        return notify_fail("��Ļ����ڹ�����������ʵ����ѧ��ȥ���߻���ħ�ġ�\n");
    if (me->query("family/family_name")!="����μ�")
   return notify_fail("�㲻�Ǵ���μҵ��ӣ��޷�ѧϰ���ż��ܡ�\n");		
skl = this_player()->query_skills();	
sname  = keys(skl);	
for (i=0;i<sizeof(skl);i++){	
if (sname[i]=="yijing-force") continue;	
if (sname[i]=="kumu-shengong") continue;	
if (sname[i]=="xixing-dafa") continue;	
if( SKILL_D(sname[i])->valid_enable("force") )	
return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��ľ�񹦣���\n");	
}
 return 1;
}
string exert_function_file(string func)
{
    return __DIR__"kumu-shengong/" + func;
}
int practice_skill(object me)
{
        return notify_fail("��ľ��ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int damage2,ap,dp;
	damage2 = (int)me->query_skill("kumu-shengong",1);
	ap = me->query_skill("kumu-shengong",1);
	dp = victim->query_skill("force",1);
    if( damage_bonus < 100 ) return 0;
	if ( me->query_skill("kumu-shengong",1) < 100)	 return 0;
	if ( me->query("neili") < 100 || me->query_skill_mapped("force") != "kumu-shengong") return 0;	
	if (damage2<10) damage2=10;	
	if ( random(ap) > dp/20 && random(6)==0 && me->query("jiali") > 0) 
	{
		victim->receive_wound("qi", 100+damage2+damage_bonus/2,me);
		me->add("neili", -100 );
		return HIB "$N���ӳ�"+HIR+"��ľ��"NOR HIB"�ľ���,$n��ʱ���ݿ��£���Ԫ���𣡣�����\n" NOR;
	}
}
