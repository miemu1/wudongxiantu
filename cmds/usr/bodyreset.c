// derive.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

mapping roushen = ([
	"��" : HIW "��������  ",
	"һ" : HIY "���ǿ��",
	"��" : HIY "��ǹ����",
	"��" : HIR "ͭƤ����",
	"��" : HIR "��ղ���",
	"��" : HIC "��������",
	"��" : HIC "�����ʥ",
]);

varargs int deriving(object me);
int halt_deriving(object me);
int dest_room(object me,object room);
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
int zon,reset;
string* sk,map_skill;
int i;
int j;

reset=me->query("bodyreset")*100+500;

if (arg=="explain")
{

string msg;

msg= ZJOBLONG+HIR "��"HIY "����ϵͳ" HIR "��"NOR+ZJBR;

msg+=HIG"��������������������������������������������"NOR+ZJBR;

msg+="�������޿���ʹ���ͷ���棬�����������ȫ���书�ͳԵ���¼�Լ�������Ǳ�ܡ���������ۡ�����������������30w��Ϊ��ȫ�����ԣ������˹��̣����������°�ʦѧ�պ������Լ����������ԡ�"ZJBR;
msg+=HIG"��������������������������������������������"NOR+ZJBR;
msg+="Ŀǰ���޴�����("HIM+me->query("bodyreset")+NOR")"ZJBR;
msg+="��ǰ����������ʦ�Ź���һ�򣨲����ģ�����ʯһǧ�������Ṧ�������ڹ��������м��Լ���Ӧ���Ѽ����������书�ﵽ"+chinese_number(reset)+"��"ZJBR;
msg+="��Ҫ���֧������ȼ���"+roushen[chinese_number(me->query("bodyreset")+1)]+NOR"\n";

msg += ZJOBACTS2+ZJMENUF(2,2,9,30);

	msg += "ȷ������:bodyreset"ZJSEP;		
	msg += "��������:tupo explain\n";	
	
	message("vision", msg, me);	
	return 1;
}

zon = 200;

if (me->query("bodyreset")>=5)
return notify_fail("���Ѿ����������ˣ���\n");	  

if (me->query("blevel")<=me->query("bodyreset"))
return notify_fail("�����ܲػ�û�������Ǹ���Σ������������ޣ�\n");	       

sk = keys(me->query_skills());		  // ��ѧ�书�����Ƽ���

		if (me->query("gongxian") < 10000)
	    return notify_fail("���ײ���10000��ǿ��������Ȼ��\n");
		if (me->query("dajif") < 1000)
	    return notify_fail("��ʯ����1000��ǿ��������Ȼ��\n");
	

 if (me->query("max_neili") < 10000)
	    return notify_fail("��������10000��ǿ��������Ȼ��\n");	       
	    
	       if (me->query_skill("dodge",1)  < reset)
	       return notify_fail("�����Ṧ���㣬ǿ��������Ȼ��\n");
	       
	          if (me->query_skill("parry",1)  < reset)
	       return notify_fail("�����мܲ��㣬ǿ��������Ȼ��\n");
	       
	    if (me->query_skill("force",1)  < reset)
	       return notify_fail("�����ڹ����㣬ǿ��������Ȼ��\n");	
	  //     reset-=500;	      
	       	 if (me->query_skill("martial-cognize",1)  < zon+reset-500)
	       return notify_fail("��ѧ�������㣬ǿ��������Ȼ��\n");	    
	       
	       map_skill = me->query_skill_mapped("force");
        if (me->query_skill("force", 1) < reset ||me->query_skill(map_skill, 1) < reset)        
               return notify_fail("�����ڹ����㣬ǿ��������Ȼ��\n");        
               
        map_skill = me->query_skill_mapped("dodge");
        if (me->query_skill("dodge", 1) < reset ||
            me->query_skill(map_skill, 1) < reset)
                        return notify_fail("�����Ṧ���㣬ǿ��������Ȼ��\n");         
                                       
        map_skill = me->query_skill_mapped("parry");
        if (me->query_skill("parry", 1) < reset || me->query_skill(map_skill, 1) < reset)  
                              return notify_fail("�����Ṧ���㣬ǿ��������Ȼ��\n");                           	       	 	       	       
foreach (map_skill in sk)
	me->delete_skill(map_skill);

me->delete("family");
me->set("combat_exp",300000);
me->delete("gift/xisuidan");
me->delete("gift/unknowdan");
me->delete("gift/shenliwan");
me->delete("gift/xiandan");
me->delete("potential");
me->delete("learned_points");
me->delete("max_neili");
me->delete("magic_learned");
me->delete("story");
me->delete("score");
me->delete("weiwang");
me->delete("magic_points");
me->add("dajif",-1000);
me->add("bodyreset",1);
me->set("max_qi",2000);
me->set("title", "ת��֮��");
	
/* 	new("/clone/bodyreset/xidian")->move(me);
	new("/clone/bodyreset/xinggedan")->move(me); */
	
message("channel:chat",HIW"��������"HIR"��"+me->query("name")+"�������ޣ������츳��ø��Ӹ���\n"NOR,users());
write(HIR"��·�е�����һ�����ɣ������츳��ø��ߣ���������Ҫ�����µ���������ɢ��ȫ����Ϊ���������ʱ�ø���һ�㣬��������Ҳ�ڲ����ų���\n");
  
	return 1;
}


int dest_room(object me,object room)
{
if (environment(me)==room)
me->move("/d/city/kedian");
destruct(room);
}