// time.c					  
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string amr,str;
	if(!arg)
	{
		if(!me->query_temp("pindao"))
		{
			arg = "chat";
			str = "����";
		}
	}
	else if(arg=="chat")
	{
		str = "����";
	}
	else if(arg=="rumor")
	{
		str = "ҥ��";
	}
	else if(arg=="sos")
	{
		str = "����";
	}
	else if(arg=="party")
	{
		str = "����";
	}
	else if(arg=="family")
	{
		str = "ͬ��";
	}
	else if(arg=="jiaoyi")
	{
		str = "����";
	}
	else if(arg=="bill")
	{
		str = "����";
	}
	else if(arg=="ultra")
	{
		str = "����ʦ";
	}
	else if(arg=="rultra")
	{
		str = "������ʦ";
	}
	else if(arg=="inter")
	{
		str = "����";
	}
	else if(arg=="pindao")
	{
		write(ZJOBLONG"��ѡ������Ƶ����\n"+ZJOBACTS2+ZJMENUF(3,3,9,30)
				+"����:liaotian chat"ZJSEP"ҥ��:liaotian rumor"ZJSEP"����:liaotian sos"ZJSEP"ͬ��:liaotian family"ZJSEP"����:liaotian party"
				ZJSEP"����:liaotian bill"ZJSEP"����:liaotian jiaoyi"ZJSEP"��ʦ:liaotian wiz"ZJSEP"ϵͳ:liaotian sys"ZJSEP"����:liaotian debug"ZJSEP"����ʦ:liaotian ultra"ZJSEP"������ʦ:liaotian rultra"ZJSEP"����:liaotian inter"+"\n");
		return 1;
	}
	else str = arg;

	if(arg)
	{
		me->set_temp("pindao/id",arg);
		me->set_temp("pindao/name",str);
	}
	write(INPUTTXT("��ǰƵ����"+me->query_temp("pindao/name")+"�������������ݣ�",
			me->query_temp("pindao/id")+" $txt#")+"\n"+ZJOBACTS2+ZJMENUF(3,3,9,30)"ѡ��Ƶ��:liaotian pindao"ZJSEP"���鶯��:emote\n");
	return 1;
}

int help(object me)
{
     write(@HELP
ָ���ʽ: time

���ָ���������ʵ���������ڵ�ʱ�䡣

HELP
    );
    return 1;
}
