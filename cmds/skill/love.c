// arg.c
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object where = environment(me);
	int cishu;
	int shengyu;//ʣ��ʦ�Ŵ���
    int GMT = time() + localtime(0)[8];
	string d, times;
	int h, s;
    int jiacheng,fanbei;
	int suanfa;
	 shengyu=(10000-me->query("shimen/today"));//ʣ�����Ϊ

	jiacheng=me->query_temp("shimenjiacheng");
	fanbei=me->query_temp("shimenfanbei");
	times = ctime(GMT);
	//Sun(������) Mon(����һ)  Tue(���ڶ�)  Wed(������)  Thu(������)  Fri(������)  Sat(������)
	d = times[0..2];//����
	h = to_int(times[10..12]);//ʱ
	s = to_int(times[14..15]);//��


	jiacheng = 1;
	fanbei = 1;

	if (arg=="xianshi")
	{
		
		string msg;
		msg  = ZJOBLONG;
		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");

		msg= ZJOBLONG+HIR "��"HIY "ʦ��ɨ��ϵͳ" HIR "��"NOR+ZJBR;
		msg+=HIG"��������������������������������������������"NOR+ZJBR;
		msg+=HIW"ʦ��ɨ������10000�Σ��㻹��ɨ��"+shengyu+"��\n"NOR;
		msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "һ��ɨ��:saodang yijian"ZJSEP;
	//	msg += "ˢ��ɨ��:saodang shuaxin"ZJSEP;
		msg += "ѡ��ɨ��:saodang\n";
		message("vision", msg, me);
	}

	if (arg=="shuaxin")//ˢ��
	{
  
		if (!(d == "Sun")) 
			return notify_fail("���ɨ��ֻ����������ˢ�¡�\n");

		me->set("saodang",0);
		me->set("xianzhi",0);
	
		return  notify_fail("ˢ�³ɹ���\n");
	}	
	if (arg=="ce")
	{
		notify_fail("������������ǰ���ٻ���һ��Բ����"
			"һ����������������\n");
		return notify_fail("������������ǰ���ٻ���һ��Բ����"
			"һ����������������\n");
	}
	if (arg=="yijian")//һ��ɨ��
	{
		if(me->query("combat_exp") < 2000000)
			return notify_fail("��Ϊ��������ܿ�ʼɨ����\n");
		if(me->query("xianzhi")==1)
			return notify_fail("���Ѿ�ɨ�����ˡ�\n");
   		if (me->is_busy())
			return notify_fail("��������æ���ء�\n");
		if (environment(me)->query("no_learn") || environment(me)->query("no_fight") && (me->query("doing") != "scheme" || this_player(1)))
			return notify_fail("����̫���ӣ���û����ɨ����\n"); 
		if (me->is_fighting())
			return notify_fail("����ĥǹ������������\n");
		if (me->query("saodang")>=1)
			return notify_fail("���Ѿ��ù�ѡ��ɨ���ˡ�\n");
		
		if (me->query("shimen/today")>=10000)
		{
			return notify_fail("���ɨ����ʱ�Ѿ���������\n");
		}
		
       
		suanfa=shengyu*fanbei;
		me->add("shimen/today",shengyu);
		me->add("combat_exp",(1000+jiacheng)*suanfa);//��Ϊ
		me->add("potential",(1000+jiacheng)*suanfa);//Ǳ��
	    me->add("experience", (25+jiacheng)*suanfa);//���
		if(me->query("shen")>0)
		{
	    me->add("shen", (10+jiacheng)*suanfa);//����
		}
	    else
		{
			me->add("shen", -(10+jiacheng)*suanfa);//����
		}
	    me->add("score", (25+jiacheng)*suanfa);//����
		me->add("xianzhi",1);
	    me->add("weiwang", (10+jiacheng)*suanfa);//����		
 		me->add("jifeng",(3+jiacheng)*suanfa);
 me->start_busy(5);		
		tell_object(me, HIW"ɨ���ɹ�����һ��ɨ����"+shengyu+"��\n�����"+(3+jiacheng)*suanfa+"��ȯ\n"+(1000+jiacheng)*suanfa+"��Ϊ\n"+(1000+jiacheng)*suanfa+"Ǳ��\n"+(25+jiacheng)*suanfa+"���\n"+(10+jiacheng)*suanfa+"����\n"+(25+jiacheng)*suanfa+"����\n"+(10+jiacheng)*suanfa+"����\n"NOR);
		
		return  1;

		//if ((time() / 86400 - me->query("arg_last_time") / 86400)<=7)//ʱ��Ϊ����һѭ��
		//	return notify_fail("��û�е�����Ŷ���޷�����ɨ��\n");
		return  notify_fail("ɨ���ɹ���\n");
	}
	
	if (!arg || arg == "")
	{
		if (!me->query("tingyvge"))
		{
			return notify_fail("�㲻��������ÿ������������޷�ʹ��.\n");
		}
		write(INPUTTXT("�������", "saodang $txt#") + "\n");//����ɨ���Ĵ���
		return 0;
	}

	//if (sscanf(arg, "%d", cishu) == 1)//��ȡargΪ���� ��ֵcishu ����ֵΪ1
	if (sscanf(arg, "%d", cishu) != 1) return 1;//��������ھ�ֱ�ӷ���

	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");

	if (environment(me)->query("no_learn") || environment(me)->query("no_fight") && (me->query("doing") != "scheme" || this_player(1)))
		return notify_fail("����̫���ӣ���û����ɨ����\n"); 

	if (cishu < 1 || cishu > 1000)
		return notify_fail("ɨ����������һ�Σ����Ҳ���ܳ���1000�Ρ�\n");

	if (shengyu>cishu)
	return notify_fail("ɨ���������ܴ���ʦ��ʣ�����\n");
	if (me->query("shimen/today")>=10000)
			return notify_fail(HIW"��ħ�����㣺���ɨ����ʱ�Ѿ���������\n"NOR);

	if (me->is_fighting())
		return notify_fail("����ĥǹ������������\n");

	suanfa=cishu*fanbei;
    me->add("shimen/today",cishu);
	me->add("saodang",cishu);
	me->add("combat_exp",(5000+jiacheng)*suanfa);//��Ϊ
	me->add("potential",(5000+jiacheng)*suanfa);//Ǳ��
	me->add("experience", (15+jiacheng)*suanfa);//���
	if(me->query("shen")>0)
	{
	me->add("shen", (15+jiacheng)*suanfa);//����
	}
    else
	{
    me->add("shen", -(15+jiacheng)*suanfa);//����
	}
	me->add("score", (15+jiacheng)*suanfa);//����
	me->add("weiwang", (15+jiacheng)*suanfa);//����				
		me->add("jifeng",(4+jiacheng)*suanfa);
	tell_object(me, "ɨ���ɹ�����ɨ����"+cishu+"�Σ����"+(4+jiacheng)*suanfa+"��ȯ"+(5000+jiacheng)*suanfa+"��Ϊ"+(5000+jiacheng)*suanfa+"Ǳ��"+(15+jiacheng)*suanfa+"���"+(15+jiacheng)*suanfa+"����"+(15+jiacheng)*suanfa+"����"+(15+jiacheng)*suanfa+"����\n");
	return 1;
}



int help(object me)
{
	write(@HELP
ָ���ʽ : arg  <����>

���ָ���������ɨ��ʦ�Ŵ��� ����ȡ���� �����޷�������Ʒ����Ŷ
HELP
	);
	return 1;
}
