// ����� by ����ҹ��(bianco)
#define WORK "$busy$"
#include <ansi.h>

inherit F_CLEAN_UP;
int show(object me,string where);
int work(object me,string arg,string where);
int shouhuo(object me,string arg,string oldwhere);
int jixu(object me);
int halt_working(object me);


int main(object me, string arg)
{
	object ob;
	string r,where;
where=environment(me)->query("short");
//	if (environment(me)->query("pigging"))
//		return notify_fail("�㻹�ǰ��ĵĹ���ɣ�\n");
	if (me->is_in_prison())
		return notify_fail("�úõ�������ΰɡ�\n");
		
if (environment(me)->query("close_room"))
return notify_fail("������������?��\n");

	if (me->is_ghost())
		return notify_fail("�㻹�ǵȻ�������˵�ɡ�\n");
		
		if (arg=="sell")
{
if (!me->query("life_sell"))
me->set("life_sell",1);
else
me->delete("life_sell");
me->force_me("life");
return 1;
}

	if (me->is_busy()&&arg!="cancel")
	{
		return notify_fail("��������æ�����п�����˵�ɣ�\n");
		}

	if (me->is_fighting())
		return notify_fail("�㻹�ǰ���ǰ�ĵ��˷ŵ���˵�ɣ�\n");
		
if (!arg)
show(me,where);
 else
 work(me,arg,where);
}
int show(object me,string where)
{
string msg;

msg= HIR "��"HIY "�䶯��;����ϵͳ��" HIR "��"NOR+ZJBR;
msg+=HIG"��������������������������������������������"NOR+ZJBR;
msg+=HIW"��������:"+me->query("life/cuttree")+ZJBR;
msg+="�������:"+me->query("life/fishing")+ZJBR;
msg+="��ݴ���:"+me->query("life/mowing")+ZJBR;
msg+="�������"NOR":"+me->query("life/farming")+ZJBR;
msg+=HIG"�����������������˵ؿ��Խ��С���������������"NOR"\n";
msg+=ZJOBACTS2+ZJMENUF(2,2,10,25);
if (me->is_busy())
msg+="ȡ������:life halt"ZJSEP;
else
if (strsrch(where,"����")!=-1||strsrch(where,"ɭ��")!=-1||strsrch(where,"����")!=-1)
msg+="����:life cuttree"ZJSEP;
else
 if (strsrch(where,"��")!=-1||strsrch(where,"��")!=-1||strsrch(where,"��")!=-1||strsrch(where,"��")!=-1||strsrch(where,"����")!=-1||strsrch(where,"��")!=-1)
 msg+="����:life fishing"ZJSEP;
else
 if (strsrch(where,"�ݵ�")!=-1||strsrch(where,"��ԭ")!=-1||strsrch(where,"�ݴ�")!=-1) 
msg+="���:life mowing"ZJSEP;
else
if (strsrch(where,"���")!=-1||strsrch(where,"ũ��")!=-1||strsrch(where,"��Ұ")!=-1)
msg+="����:life farming"ZJSEP;
else
msg+="�˵��޿ɽ��й���:life"ZJSEP;
if (!me->query("life_sell"))
msg+=HIY"�Զ�����"HIW"��δ����"NOR":life sell";
else
msg+=HIY"�Զ�����"HIC"���ѿ���"NOR":life sell";
write(ZJOBLONG+msg+"\n");
return 1;
}

int work(object me,string arg,string where)
{
 if (arg=="cuttree")
     {
     object weapon;
     if (!objectp(weapon = me->query_temp("weapon")))
     return notify_fail("�����һﶼû�У���ô?��������ȭͷߣ��\n");
     if (strsrch(where,"����")==-1&&strsrch(where,"ɭ��")==-1&&strsrch(where,"����")==-1)
      	return notify_fail("��Ҫ��ʲô?����������??��\n");
         write("���������е�"+weapon->name()+"��׼һ������������\n");
         
    }
    else
    if (arg=="fishing")
    {
     object handing;
     if (!objectp(handing = me->query_temp("handing"))||handing->query("id")!="diao gan")
     return notify_fail("��������?�����Ȱ������������Ȱ�\n");
     if (strsrch(where,"��")!=-1&&strsrch(where,"��")!=-1&&strsrch(where,"��")!=-1&&strsrch(where,"����")!=-1&&strsrch(where,"��")!=-1)
      	return notify_fail("��Ҫʲô����?���ط��и�ɶ�㶼û�У�\n");
         write("������е�"+handing->name()+"˦����"+where+"�£������ĵȴ�����Ϲ���\n");
             
    }
     else
    if (arg=="mowing")
    {
     object weapon;
     if (!objectp(weapon = me->query_temp("weapon")))
     return notify_fail("�����һﶼû�У���ô?��������ȭͷ�����\n");
     if (strsrch(where,"�ݵ�")==-1&&strsrch(where,"��ԭ")==-1&&strsrch(where,"�ݴ�")==-1)
      	return notify_fail("��Ҫʲô��ʲô��,����ʲô�ݶ�û�У���\n");
         write("���������е�"+weapon->name()+"��׼һ�Ѳݸ���������\n");
                      
    }
    else
    if (arg=="farming")
    {
     object handing;
     if (!objectp(handing = me->query_temp("handing"))||(handing->query("id")!="gao tou"||handing->query("id")!="chu tou"))
     return notify_fail("��ĳ�ͷ��?�����Ȱ������������Ȱɣ�\n");
     if (strsrch(where,"���")==-1&&strsrch(where,"ũ��")==-1&&strsrch(where,"��Ұ")==-1)
      	return notify_fail("��Ҫʲô��ʲô��?���ط�û�����\n");
         write("���������еĳ�ͷ����ʼ��������ջ���ʳ��\n");            
    }
    else
    return 1;
  me->set_temp("continue_life",1);    
me->set_temp("lifegz/where",where);    
me->set_temp("lifegz/arg",arg);    
if (me->is_busy()==0)
  me->start_busy(bind((: call_other, __FILE__, "jixu" :), me),
      bind((: call_other, __FILE__, "halt_working" :), me));
//    call_out("shouhuo",6,me,arg,where);        
    return 1;
}

int jixu(object me)
{
string msg;
if (!me->query_temp("lifegz/arg"))
return 0;

if (!me->query_temp("continue_life"))
{
msg = "����������";
work(me,me->query_temp("lifegz/arg"),me->query_temp("lifegz/where"));
return 1;
}
else
	switch (me->query_temp("continue_life"))
	{
	case 1:
		msg = WORK"�����С���������\n";
		break;
	case 2:
		msg = WORK"�����С���������\n";
		break;
	case 3:
		msg = WORK"�����С���������\n";
		break;
		case 4:
		msg = WORK"�����С���������\n";
		break;
		case 5:
		msg = WORK"�����С���������\n";
		break;
	default:
	msg = "��"HIR+ZJURL("cmds:halt")+"�����ֹͣ����"NOR+"��";
	write(msg+"\n");	
	shouhuo(me,me->query_temp("lifegz/arg"),me->query_temp("lifegz/where"));	
	return 1;
		break;
	}
	write(msg+"\n");	
	me->add_temp("continue_life",1);
return 1;
}


int shouhuo(object me,string arg,string oldwhere)
{

string where;
object cailiao;
int exp,pot;
if (!objectp(me))
return 1;
exp=30+random(100)+random(me->query_skill("lifeskill",1));
pot=30+random(100)+random(me->query_skill("lifeskill",1));
where=environment(me)->query("short");
if (where!=oldwhere)
{
 me->delete("continue_life",1);
 remove_call_out("shouhuo");
write(HIR"���뿪��"+oldwhere+",�����Զ�ֹͣ\n"NOR);        
return 1;    
}
if (arg=="cuttree")
{
me->add("life/cuttree",1);
cailiao = new("/clone/life/wood/wood"+(1+random(3)));
write(HIR"��������ڿ����£�һ�������ڵ����ˣ��㼱æ������������\n"NOR);            
}

if (arg=="fishing")
{
me->add("life/fishing",1);
cailiao = new("/clone/life/fish/fish"+(1+random(3)));
write(HIR"��������ã�������;��ҵİڶ�����æ������ͣ���ϲ���ջ���һ��"+cailiao->query("name")+"\n"NOR);            
}

if (arg=="mowing")
{
me->add("life/mowing",1);
cailiao = new("/clone/life/grass/grass"+(1+random(3)));
write(HIR"�����������ã�һ���ݾ۳���һ�ѣ���˼�������������ˣ���Ѳݶ�ʰ��������\n"NOR);            
}

if (arg=="farming")
{
me->add("life/farming",1);
cailiao = new("/clone/life/rice/rice"+(1+random(3)));
write(HIR"��������������£�"+where+"ӭ�����ջ�������һ�����ס�\n"NOR);            
}
cailiao->move(me);
me->add("combat_exp",exp);
me->add("potential",pot);
write(HIY"�������������õ��˶���,Ӯ����:"+exp+"����Ϊ��"+pot+"��Ǳ��\n"NOR);
me->delete_temp("continue_life");
if (me->query("life_sell"))
me->force_me("sellob "+cailiao->query("id"));
return 1;
}


int halt_working(object me)
{
me->delete_temp("lifegz/where");    
me->delete_temp("lifegz/arg");    
me->delete_temp("continue_life");
	write("��ͣ�������еĹ�����\n");
	}
int help(object me)
{
	write(@HELP
����ϵͳ��
HELP );
	return 1;
}

