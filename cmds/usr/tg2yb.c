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
	if(!(m = VIP_D->query_qian(me->query("id"))))
		return notify_fail("�㻹û���ƹ�Ա���ʣ�\n");

	line = keys(m);
	for(i=0;i<sizeof(line);i++)
	{
		if(line[i]=="jf_used") continue;
		sum += (m[line[i]]-1);
	}
	if(sum<0) sum = 0;
	sum2 = VIP_D->query_qian(me->query("id")+"/jf_used");

	if(!arg || sscanf(arg,"%d",k)!=1)
	{
		write(INPUTTXT("��Ŀǰ�ƹ��ȯ ���ã�"+(sum-sum2) + "/�ܣ�" + sum+" ��ÿ2��ȯ���Զһ�3��ʯ���������Ķ��ٵ�ȯ�һ���","tg2yb $txt#")+"\n");
		return 1;
	}

	if(k<1)
		return notify_fail("�����ʲô��\n");

	if(k>(sum-sum2))
		return notify_fail("��û����ô����õ�ȯ�ˣ�\n");

	sum2 += k;
	VIP_D->save();
	VIP_D->set_qian(me->query("id")+"/jf_used",sum2);
	me->add("yuanbao",k*3/2);
	log_ufile(me,"tg2yb","���� "+k+" �ƹ��ȯ����ʯ���� "+(k*3/2)+" ��\n");
	write("������ "+k+" �ƹ��ȯ����ʯ���� "+(k*3/2)+" ��\n");

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
