/* ������Ե¼��Ϊͻ��ָ��2.0�档
Ц������2018.6.7�߿���
�ڱ����ҵ�ǩ��������µ�Ȼ�����޸ġ�
*/

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

mapping roushen = ([
	"��" : HIW "���已̥  ",
	"һ" : HIY "���ǿ��",
	"��" : HIY "��ǹ����",
	"��" : HIR "ͭƤ����",
	"��" : HIR "��ղ���",
	"��" : HIC "��������",
]);

varargs int do_tupo(object me);
int halt_do_tupo(object me);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
if (arg=="explain")
{
string msg;
int newpoint=(me->query("blevel")+1)*(me->query("blevel")+1)*10000;
//msg  = ZJOBLONG;

msg= ZJOBLONG+HIR "��"HIY "����ϵͳ" HIR "��"NOR+ZJBR;
msg+=HIG"��������������������������������������������"NOR+ZJBR;
msg+="���������ߵĸ���������������ǿ�����ߣ���ӵ�м�Ϊǿ��������������ʥ֮ʱ�����������������ܲأ�����һ���ܹ��������������أ������ϣ���������ͨ���ϱ���������������ʱ�䣬����ĥ���˲����������־��"ZJBR;
msg+="Ŀǰ����ȼ���"+roushen[chinese_number(me->query("blevel"))]+NOR+ZJBR;
msg+="��ǰ�����ѿ���ϵ����"+chinese_number(me->query("bpoint"))+ZJBR;
msg+="������һ�����������ϵ����"+chinese_number(newpoint-me->query("bpoint"))+"\n";
msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
	msg += "����˵��:help roushen"ZJSEP;	
	msg += "��������:tupo\n";	
	message("vision", msg, me);	
}
else
{
if (me->query("blevel") >= 5)
		return notify_fail("���Ѿ����������ˣ��޷�ͨ�����������������Լ���\n");
seteuid(getuid());
	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");
	if (me->query("blevel")>2 && me->query("dajif")<1000)
		return notify_fail("����ʯ������\n");
me->set_temp("tupo",1);
	 me->start_busy(bind((: call_other, __FILE__, "do_tupo" :), me),bind((: call_other, __FILE__, "halt_do_tupo" :), me));
	 }
	return 1;
}
varargs int do_tupo(object me)  
{

string *jingjie;
	int point,skill, level,nlevel;
	jingjie = ({"���ǿ��","��ǹ����","ͭƤ����","��ղ���","��������",});
	level= me->query("blevel")+1;
	point = level*level*10000;
	if (!point)
	{
	point = 10000;
	}
	
	if( (int)me->query("qi") < level*level*5)
		return notify_fail("�����ڵ���̫���ˣ��޷�������Ϣ����������������\n");
			if ((me->query("potential") - me->query("learned_points")) < (level * level * 5))
		return notify_fail("���Ǳ�ܲ������ڴ��������ˡ�\n");
	if (!me->query_temp("tupo"))
	return 0;
	   if (level >= 6)
	   return notify_fail("���Ѿ��ﵽ����������߾��磡\n");
if (!me)  return 0;
		 //����������ʱ�����ú�����ֹ   
tell_object(me,ZJEXIT"northwest:"RED"ֹͣ����"NOR":halt\n");
switch (random(5)+1)
	{
		case 1 :  write(ZJTMPSAY+HIG"�㲻����������������Ǳ�ܣ�����ȫ����Ѫ����\n");break;   //һ��
		case 2 :  write(ZJTMPSAY+HIC"����������ڲ��ϴ���������࡭��\n");break;   //����
		case 3 :  write(ZJTMPSAY+HIR"ȫ��е�һ��һ����ʹ���������뾭������\n");break;   //����
		case 4 :  write(ZJTMPSAY+HIY"ת�����ľ������������������\n");  break;   //�Ļ�
		case 5 :  write(ZJTMPSAY+HIM"��е�Ƥ��һ����ʹ�����졭��\n");  break;   //���
		}
		 if (me->query("bpoint")>=point)
	   {
	  me->add("blevel",1);
	  me->delete("bpoint");
	  write("�������ͻ���ˣ�\n");          
	  message("channel:chat",HBRED"������"HIR"��"+me->query("name")+"�ɸж�����̤��"+jingjie[me->query("blevel")-1]+"��������!\n"NOR,users());
	  return 0;
    }
   else
    {
    nlevel = level*level+random(10);
    nlevel *= 20;
    me->add("bpoint",nlevel);
      me->add("potential",-nlevel*2);   
    }
	return 1;
}

int halt_do_tupo(object me)
{
	tell_object(me, "��������ת���ջ���ͷ�����ٴ�������\n");
	tell_room(environment(me), me->name() + "Ψһ��ü����ס�����ơ�\n", me);
me->delete_temp("tupo");
	return 1;
}


