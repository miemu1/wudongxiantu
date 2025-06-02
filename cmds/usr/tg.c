// sp.c

#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string msg,type,tx_id;
	int num1,num2,tx_num;
	mapping jfs;
	
	if(!arg) 
	{
		msg = ZJOBLONG"��ѡ��������е����²�����\n";
		if( !VIP_D->query_tgy(me->query("id")) )
		{
			msg += ZJOBACTS2+ZJMENUF(1,1,10,30);
			if(!me->query("tgy_id"))
			msg += "��д�ƹ���:tg -lb"ZJSEP;
			msg += "�����ƹ���:tg -app";
			msg += ZJSEP"�ƹ㸣��:help tg";
		}
		else
		{
			msg += ZJOBACTS2+ZJMENUF(2,2,10,30);
			if(!me->query("tgy_id"))
			msg += "��д�ƹ�����:tg -lb"ZJSEP;
			msg += "��ѯ�ƹ��ȯ:tg -query";
			msg += ZJSEP"��ȯ�һ���ʯ:tg -convert";
			msg += ZJSEP"��ȯ����:tg -tixian";
		}
		if(SECURITY_D->valid_grant(me, "(admin)"))
			msg += ZJSEP+HIM"�����ƹ�"NOR":tg -reset";
		
		write(msg+"\n");
		return 1;
	}
	
	if(arg == "-reset")
	{
		if(!SECURITY_D->valid_grant(me, "(admin)") ) return notify_fail("�㲻�������޷�ʹ���ƹ��ȯ���ù���\n");
		else VIP_D->reset_tg(me);
		return 1;
	}
	
	
	if(sscanf(arg,"-wiz_tixian %s %d",tx_id,tx_num) == 2)
	{//��ʦ�������ֵ�ȯ�۳�
		if(!wizardp(me)) return notify_fail("�㲻����Ϸ����Ա����Ҫ������~\n");
		if(tx_num <= 0) return notify_fail("��ȯ����ֻ����ID�����������0��������\n");
		tx_num = 0-tx_num;
		num1 = VIP_D->add_tgy_jf(tx_id,tx_num);
		if(num1 == -1) return notify_fail("û�����("+tx_id+")�ƹ�Ա\n");
		if(num1 == -2) return notify_fail("�ƹ�Ա("+tx_id+")�ĵ�ȯ����"+tx_num+"��\n");
		
		tell_object(me,"�ɹ��۳�("+tx_id+")�ƹ��ȯ"+tx_num+"��\n");
		return 1;
	}
	else if(sscanf(arg,"%s %d",type,num1) != 2)
		type = arg;
	// write("��ǰtype"+type+"| num1=="+num1+"| arg=="+arg+"\n");
	
	switch(type)
	{
		case "-lb":
			return notify_fail(INPUTTXT("����д��Ҫʹ�õ��ƹ��룺","tg $txt#")+"\n");
			break;
		case "-app"://�����Ϊ�ƹ�Ա
			num1 = VIP_D->set_tgy(me);
			if(num1 == 0)
				return notify_fail("��ǰ���״̬�����ж�Ϊ��������\n");
			else if(num1 == -1)
				return notify_fail("���Ѿ������ƹ�Ա�ˣ������ظ�����\n");
			else if(num1 == 1)
				write("��ϲ���Ϊ���ƹ�Ա�������ϷID("+me->query("id")+")��������ƹ���롣\n");
			break;
		case "-query"://��ѯ�ƹ��ȯ
			jfs = VIP_D->query_tgy(me->query("id"));
			num1 = jfs["jf_all"];
			num2 = jfs["jf_use"];
			write("�㵱ǰ���ƹ��ȯ���£�\n�ƹ��ܵ�ȯ��"+num1+"\nʣ���ȯ��"+(num1-num2)+"\n��ʹ�õ�ȯ��"+num2+"��\n");
			break;
		case "-convert"://��ȯ�һ���ʯ
			if(!num1 || num1 <= 0)
				return notify_fail(INPUTTXT("��������Ҫ�һ����ٵ�ȯ����ʯ��","tg -convert $txt#")+"\n");
			
			num2 = VIP_D->tgy_convert(me,num1);
			if(num2 == -1) return notify_fail("�㻹�����ƹ�Ա���޷��һ���ʯ\n");
			if(num2 == -2) return notify_fail("����ƹ��ȯ����"+num1+"��\n");
			tell_object(me,"�ɹ��һ��ƹ��ȯ"+num1+"�㣬�����ʯ"+num2+"\n");
			break;
		case "-tixian"://��ȯ����
			if(!wizardp(me))
				return notify_fail("��������ϵ����Ա���뾡���ۼƳ���100Ԫ�����������Լ������Ա������\n");
			else
				return notify_fail(INPUTTXT("����д��Ҫ���ֵ�ID�������Կո���������£�"ZJBR"abc123 500","tg -wiz_tixian $txt#")+"\n");
			break;
		default ://��д�ƹ�����ȡ���
			//��ȡ����
			if(!VIP_D->query_tgy(type))
				return notify_fail("��ǰ�ƹ����Ӧ��ID��δ�����Ϊ�ƹ�Ա���޷���ȡ�ƹ����\n");
			if(type == me->query("id"))
				return notify_fail("���޷�ʹ���Լ����ƹ�������ȡ�ƹ����\n");
			if(me->query("tgy_id"))
				return notify_fail("���Ѿ���ȡ���ƹ�������޷��ظ���ȡ\n");
			//�����ƹ������д
			VIP_D->use_tgm(type,me);
			break;
	}

	return 1;
}

int help (object me)
{
	write(@HELP
�ƹ㸣����ÿ2��ȯ���Ի�3��ʯ�����ƹ��߿�����ȡ���
HELP );
	return 1;
}
