// berserk.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str,name,type,*pfms;
	mapping pfm;
	int i;

	if (!arg)
		return notify_fail("����鿴ʲô���ϵ���ϸ���ϣ�\n");

	if (file_size(SKILL_D(arg) + ".c") <= 0)
		return notify_fail("ϵͳ��û����Ҫ������ּ��ܡ�\n");
	str = ZJOBLONG"�������֣�"+to_chinese(arg)+"["+arg+"]";
	if(SKILL_D(arg)->query_txt())
		str += ZJBR + SKILL_D(arg)->query_txt();
	str += ZJBR"һһһһһһһһһһһһһһһһһһһһ";
	str += ZJBR"������";
	if(mapp(pfm = SKILL_D(arg)->query_pfm()))
		pfms = keys(pfm);
	for(i=0;i<sizeof(pfms);i++)
	{
		sscanf(pfm[pfms[i]],"%s:%s",name,type);
		str += ZJBR + replace_string(name,ZJBR,"") + "[" + pfms[i] + "]";
		if(file_size(SKILL_D(arg+"/perform/"+pfms[i])+".c")>0 && SKILL_D(arg+"/perform/"+pfms[i])->query_txt())
			str += ZJBR + SKILL_D(arg+"/perform/"+pfms[i])->query_txt();
		else if(file_size(SKILL_D(arg+"/exert/"+pfms[i])+".c")>0 && SKILL_D(arg+"/exert/"+pfms[i])->query_txt())
			str += ZJBR + SKILL_D(arg+"/exert/"+pfms[i])->query_txt();
		else if(file_size(SKILL_D(arg+"/"+pfms[i])+".c")>0 && SKILL_D(arg+"/"+pfms[i])->query_txt())
			str += ZJBR + SKILL_D(arg+"/"+pfms[i])->query_txt();
	}
	if(!i)
		str += "��";
	write(str + "\n");

	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ: chaski
 
���ָ������鿴���ܵ���ϸ���ϡ�

HELP );
	return 1;
}
