// fonxanforce.c
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) 
{
    mapping skl;
    string *sname;
    int i;
        int lvl = (int)me->query_skill("jingyi-shengong", 1);
//	if (!wizardp(me))
//		return notify_fail("��ʦͻȻ�Ӻڰ��г��˳�����������һ����������û���š�\n");			
        if ( me->query("gender") == "����" && lvl > 49)
                return notify_fail("���޸����ԣ���������������������ľ����񹦡�\n");
//        if( (string)me->query("gender") != "Ů��" )
//                return notify_fail("�̲�����ֻ��Ů�Ӳ��������书��\n");			
    if (me->query("family/family_name")!="���Ƴ�" && me->query("family/family_name")!="���Ƴ�")
   return notify_fail("�㲻���뱾�ţ��޷����ڱ��ż��ܵľ��衣\n");			
    if (me->query_skill("force",1)<100)
        return notify_fail("��Ļ����ڹ���������������ѧ�����񹦡�\n");
   
    skl = this_player()->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
      
    }
    return 1;
}



int practice_skill(object me)
{
        return notify_fail("������ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}
string exert_function_file(string func)
{
return __DIR__"jingyi-shengong/"+func;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int damage2,ap,dp;
	damage2 = (int)me->query_skill("jingyi-shengong",1);
	ap = me->query_skill("jingyi-shengong",1);
	dp = victim->query_skill("force",1);
    if( damage_bonus < 100 ) return 0;
	if ( me->query_skill("jingyi-shengong",1) < 100)	 return 0;
	if ( me->query("jiali") < 1 || me->query("neili") < 100 || me->query_skill_mapped("force") != "jingyi-shengong") return 0;	
	if (damage2<10) damage2=10;
	if ( random(ap) > dp/20 && random(8)==0 && me->query("jiali") > 0) 
	{
		victim->receive_wound("qi", 100+damage2+damage_bonus,me);
		me->add("neili", -100 );
		return HIB "$N���ӳ�"+HIR+"������"NOR HIB"������,���ι����ݻ���$n����Ԫ��������\n" NOR;
	}
}

mapping exercise_msg(object me)
{
  return ([
        "status_msg" : "����������֣������纣��֮��ʯ��\n" ,
        "start_my_msg" : "��ϥ���£�˫�Ʋ�£��ƽ����С���ϣ��ؿ������������һ��һ�ϣ����а�ɫ��Ȧ�³���\n",
        "start_other_msg" :  me->name() + "��ϥ���£��ؿ������������һ��һ�ϣ����а�ɫ��Ȧ�³���\n",
        "heal_my_msg" : "�³����İ�ɫ��Ȧһ����һ����������һ�㻺��Ʈ��Զ�������к�����������\n",
        "heal_other_msg" :  me->name() + "�³������³����İ�ɫ��Ȧһ����һ����������һ�㻺��Ʈ��Զ����"+ me->name() + "�ƺ������к����İ���������\n",
        "halt_msg" :  "����������һ��������ɫ��Ȧ����������վ��������\n",
        "end_my_msg" : "����������һ����������ɫ��Ȧ�����ظ���������˫�ۣ�����վ��\n",
        "end_other_msg" : me->name()+"���в��������ɫ��Ȧ�����ð���������"+me->name()+"����˫�ۣ�����վ��\n",		
        "hover_my_msg" : "�����İ���һ����һ�����������ã�������Խ��ԽԶ���������Ű�ɫ��ȦҲ������ʧ�ˡ�\n",
        "hover_other_msg" : me->name()+"һ��һ��֮�䣬ֻ���ú����İ���һ�˸߹�һ�ˡ��������ã�������Խ��ԽԶ���������Ű�ɫ��ȦҲ������ʧ�ˡ�\n",	
    ]);
}
