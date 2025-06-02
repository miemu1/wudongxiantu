// breakup.c

#include <ansi.h>

inherit F_CLEAN_UP;

int breaking(object me);
int halt_breaking(object me);

void create() { seteuid(getuid()); }
/*
	if(name=="����")
	{
		line += "�����˺����⸽��"+me->query("gain/damage")+"�㡣\n";
	}
	else if(name=="����")
	{
		line += "�����Ѫ���⸽��"+me->query("gain/max_qi")+"�㡣\n";
	}
	else if(name=="������")
	{
		line += to_chinese(me->query("meridian/ap"))+"�����ȼ����⸽��"+me->query("gain/attack")+"����\n";
	}
	else if(name=="������")
	{
		line += to_chinese(me->query("meridian/dp"))+"�����ȼ����⸽��"+me->query("gain/defense")+"����\n";
	}
	else if(name=="��ά��")
	{
		line += "��������"+me->query("gain/2ap")+"�㡣\n";
	}
	else if(name=="��ά��")
	{
		line += "��������"+me->query("gain/2dp")+"�㡣\n";
	}
	else if(name=="��������")
	{
		line += "�Ƽ�����"+me->query("gain/break")+"�㡣\n";
	}
	else if(name=="��������")
	{
		line += "��������"+me->query("gain/armor")+"�㡣\n";
	}
	*/
int main(object me, string arg)
{
	object where, *dan,yao;
	int i;
	string msg, name, dname, xue, bskill, *yang, *yin;



	seteuid(getuid());
	
	where = environment(me);
	
	if (!arg)
	{
		msg = ZJOBLONG +"                         "YEL"��"HIY"��"RED"��"GRN"��"CYN"��"HIM"��"NOR ZJBR ZJBR
		HIY"Ŀǰ��ͨѨ���ӳ�:"NOR ZJBR
		HIR"��       ����"NOR""YEL"�����Ѫ���⸽��"NOR""+me->query("gain/max_qi")+""YEL"�㡣"NOR""ZJBR
		HIR"��       ����"NOR""YEL"�����˺����⸽��"NOR""+me->query("gain/damage")+""YEL"�㡣"NOR""ZJBR
      	HIR"��  ��  ����"NOR""YEL""+((me->query("gain/attack") > 1 )?""+to_chinese(me->query("meridian/ap"))+"":"��δѡ��")+"�����ȼ����⸽��"NOR""+me->query("gain/attack")+""YEL"����"NOR""ZJBR
		HIR"��  ��  ����"NOR""YEL""+((me->query("gain/defense")> 1)?""+to_chinese(me->query("meridian/dp"))+"":"��δѡ��")+"�����ȼ����⸽��"NOR""+me->query("gain/defense")+""YEL"����"NOR""ZJBR
	    HIR"��  ά  ����"NOR""YEL"��������"NOR""+me->query("gain/2ap")+""YEL"�㡣"NOR""ZJBR
		HIR"��  ά  ����"NOR""YEL"��������"NOR""+me->query("gain/2dp")+""YEL"�㡣"NOR""ZJBR
	    HIR"�� ��������"NOR""YEL"�Ƽ�����"NOR""+me->query("gain/break")+YEL"�㡣"NOR""ZJBR
	    HIR"�� ��������"NOR""YEL"��������"NOR""+me->query("gain/armor")+YEL"�㡣"NOR"\n"
		ZJOBACTS2+ZJMENUF(4,4,10,30);
		msg += MERIDIAN_D->do_score(me);
		tell_object(me, msg+ "\n");
		return 1;
	}
	yang = ({"sword","blade","whip","staff","throwing","hammer","unarmed","strike","cuff","finger","hand","leg","claw"});
	yin = ({"force","dodge","parry"});
    if (! where->query("no_fight") && ! where->query("owner_special"))
		return notify_fail(HIR"���������澭��������̫��ȫ�ɣ�\n"NOR);

	if (! where->query("sleep_room"))
			return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");

	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail(HIR"������Լ����ڹ�������ޣ�������Ҫ�ȶ������ڹ����С�\n"NOR);

	if ((int)me->query("qi") * 100 / me->query("max_qi") < 50)
		return notify_fail(HIR"�����ڵ���̫���ˣ��޷����ĳ�����\n"NOR);

	if ((int)me->query("jing") * 100 / me->query("max_jing") < 50)
		return notify_fail(HIR"�����ڵľ�̫���ˣ��޷����ĳ�����\n"NOR);
	
	if ((int)me->query("max_neili") <100)
		return notify_fail(HIR"�����ڵ�����̫���ˣ��޷�������\n"NOR);

	if ((int)me->query("neili") * 100 / me->query("max_neili") < 50)
		return notify_fail(HIR"�����ڵ�����̫���ˣ��޷����ĳ�����\n"NOR);
	
	

	if(sscanf(arg, "%s with %s", name, dname) == 2)
	{
		xue = MERIDIAN_D->get_xue(name,me->query("meridian/" + name));
		if (xue=="")
			return notify_fail(HIG"û�пɳ����Ѩλ�ˡ�\n"NOR);
		if (((name == "������"&&!me->query("meridian/dp")) || (name == "������"&&!me->query("meridian/ap")))&&(sscanf(dname, "%s for %s", dname, bskill) != 2))
		{
			msg = "��ѡ����Ҫ������ǿ�ļ�������(һ��ѡ����ʱ���ܸ��ģ�������ѡ��)��\n"ZJOBACTS2+ZJMENUF(3,3,10,30);
			if(name == "������")
				msg += 	"����:beat "+arg+" for sword"ZJSEP
					"����:beat "+arg+" for blade"ZJSEP
					"�޷�:beat "+arg+" for whip"ZJSEP
					"�ȷ�:beat "+arg+" for staff"ZJSEP
					"����:beat "+arg+" for throwing"ZJSEP
					"����:beat "+arg+" for hammer"ZJSEP
					"ȭ��:beat "+arg+" for unarmed"ZJSEP
					"�Ʒ�:beat "+arg+" for strike"ZJSEP
					"ȭ��:beat "+arg+" for cuff"ZJSEP
					"ָ��:beat "+arg+" for finger"ZJSEP
					"�ַ�:beat "+arg+" for hand"ZJSEP
					"צ��:beat "+arg+" for claw"ZJSEP
					"�ȷ�:beat "+arg+" for leg";
			else if(name == "������")
				msg += 	"�Ṧ:beat "+arg+" for dodge"ZJSEP
					"�м�:beat "+arg+" for parry"ZJSEP
					"�ڹ�:beat "+arg+" for force";
			tell_object(me, ZJOBLONG +msg+ "\n");
			return 1;
		}
		if (!objectp(yao=present(dname,me))||!yao->query("needle/level"))
			return notify_fail(HIR"�ⶫ��������������������\n"NOR);
		if (yao->query("needle/level")<=me->query("meridian/" + name))
			return notify_fail(HIR"��ҩƷ��������������������Σ�յģ�\n"NOR);
		me->set_temp("meridian/xue",xue);
		me->set_temp("meridian/name",name);
		me->set_temp("meridian/dname",dname);
		if(bskill)
		{
			if(name == "������" && !me->query("meridian/ap"))
			{
				if(member_array(bskill,yang)==-1)
				{
					tell_object(me, "����Ĳ�����\n");
					return 1;
				}
				me->set("meridian/ap",bskill);
			}
			else if(name == "������" && !me->query("meridian/dp"))
			{
				if(member_array(bskill,yin)==-1)
				{
					tell_object(me, "����Ĳ�����\n");
					return 1;
				}
				me->set("meridian/dp",bskill);
			}
		}
	}
	else
	{
		msg = MERIDIAN_D->do_score(me,arg);
		if(msg=="")
			return notify_fail("��Ҫ���ʲô������\n");
		msg = replace_string(msg,"\n",ZJBR);
		if(msg[(strlen(msg)-4)..(strlen(msg)-1)]=="$br#")
			msg = msg[0..(strlen(msg)-5)];
		dan = filter_array(all_inventory(me),(:$1->query("needle/level")>0:));
		if(sizeof(dan))
		{
			msg += ZJBR"�����ѡ������ҩ���г�����\n"ZJOBACTS2+ZJMENUF(3,3,10,30);
			for(i=0;i<sizeof(dan);i++)
			{
				msg += dan[i]->query("name")+":beat "+arg+" with "+file_name(dan[i]);
				if(i<(sizeof(dan)-1)) msg += ZJSEP;
			}
		}
		else
		{
			msg += ZJBR"����������û�г���������ҩ�����ܽ��г�����";
		}
		tell_object(me, ZJOBLONG +msg+ "\n");
		return 1;
	}

	message_vision(HIY"$N��ϥ���£���ʼڤ���˹��������"+name+"������ͼ��ͨ��"+xue+"Ѩ����\n"NOR, me);
	me->start_busy(bind((:call_other, __FILE__, "breaking" :), me),
		       bind((:call_other, __FILE__, "halt_breaking" :), me));
	return 1;
}

int breaking(object me)
{
	string msg,name,dname,xue;

	name = me->query_temp("meridian/name");
	dname = me->query_temp("meridian/dname");
	xue = me->query_temp("meridian/xue");
	if (random(60) < 30)
	{
		tell_object(me, HIR "����������ڵ���ԴԴ���������ϳ����"+name+"���ġ�"+xue+"Ѩ�������������ѵ�����������������"NOR"\n");
		MERIDIAN_D->do_through(me);
		return 0;
	}

	switch (random(5))
	{
	case 0:
		msg = ""HIY"��ĬĬ��ת������������Щ�о���"NOR"\n";
		break;

	case 1:
		msg = ""HIC"�㽫�����˳�������Ϲ��������衢͸ʮ����¥���鲼��"+name+"����Ȼ���ջص��"NOR"\n";
		break;

	case 2:
		msg = ""MAG"�㽫�����˾���Ѩ������֫�ٺ���Ȼ���ֻ��յ��"NOR"\n";
		break;

	case 3:
		msg = ""HIR"���ڵ����в��ϻ���������ֻ���û������ȡ�"NOR"\n";
		break;

	default:
		msg = ""HIW"�㻺���������ɣ���������ˮ¶����Ϊ���á�"NOR"\n";
		break;
	}

	tell_object(me, msg);
	return 1;
}

int halt_breaking(object me)
{
	CLOSE_D->user_opened(me);
	tell_object(me, HIW"����ֹ�˳��������"NOR"\n");
	message_vision(HIY "$N" HIY "����̾��һ�����������������ۡ�"NOR"\n", me);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : breakup

�չ������Դ�ͨ�ζ���������Ҫ�ǳ������������ڹ����ײ���������
���һ�����Ǳ�ܡ�һ����ͨ���ζ���������ͬʱ��չ��������������
���������ޡ�

HELP );
	return 1;
}
