// sp.c

#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string txt,*line;
	int i,k,sum=0,sum2;
	mapping m;
	if (!wizardp(me)) return 0;
	/* if(m = VIP_D->query_qian(me->query("id")))
	{ */
		if(!arg || arg!="tixian")
		{
			line = keys(m);
			for(i=0;i<sizeof(line);i++)
			{
				if(line[i]=="jf_used") continue;
				sum += (m[line[i]]-1);
			}
			if(sum<0) sum = 0;
			sum2 = VIP_D->query_qian(me->query("id")+"/jf_used");
			sum2 = sum - sum2;
			txt = ZJOBLONG"���Ѿ����ƹ�Ա�ˣ������ظ����룬Ŀǰ�ƹ��ȯ ���ã�"+sum2+"/�ܣ�"+sum+" ��"ZJBR
			"��ĵ�½�ʺ�["+me->query("id")+"]��������ƹ��룬������������������ƹ��뼴����ȡ���ƹ���У�"
			"���˳ɳ�������Ϸ�����Ѷ��������һ�����ƹ��ȯ��ÿ10��ȯ������������1��Ǯ���߶һ�15��ʯ��\n";
			txt += ZJOBACTS2+ZJMENUF(3,3,10,30);
			txt += "�һ���ʯ:tg2yb";
			txt += ZJSEP"��������:tgm tixian";
			write(txt+"\n");
			return 1;
		}
		else
			return notify_fail("��������ϵ����Ա���뾡���ۼƳ���100Ԫ�����������Լ������Ա������\n");
/*	}
	else
		return notify_fail("�ƹ�Ա����������ֹͣ,������Ҫ����ϵ����Ա��\n");
 */
	VIP_D->set_qian(me->query("id"),([]));
	write("�ƹ�Ա����ɹ�����ĵ�½�ʺ�["+me->query("id")+"]��������ƹ��룬������������������ƹ��뼴����ȡ���ƹ���У�"
		"���˳ɳ�������Ϸ�����Ѷ��������һ�����ƹ��ȯ��ÿ10��ȯ������������1��Ǯ��\n");
	VIP_D->save();
	
	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ: tgm 
�趨�ƹ�Ա
HELP );
	return 1;
}
