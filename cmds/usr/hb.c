#include <ansi.h>
inherit F_CLEAN_UP;


int main(object me, string arg)
{
	string str;
	int shu,ge;
	if(!arg)
	{
	str= ZJOBLONG+HIR "��"HIY "���ϵͳ��" HIR "��"NOR+ZJBR;
	    str +=HIC"��"HIY"������������������������������������������"HIC"��"NOR+ZJBR;
		str +="��ӵ�е���ʯΪ��"+me->query("yuanbao")+ZJBR;
		str +="��Ŀǰ����ΪΪ��"+me->query("combat_exp")+ZJBR;
	
		 str +=HIC"��"HIY"������������������������������������������"HIC"��"NOR+ZJBR;
	
	     str +="����\n";
		str +=ZJOBACTS2+ZJMENUF(2,2,10,30);
	
		str +="�ƽ���:hb -l"ZJSEP;
		str +="��ʯ���:hongbao -t"ZJSEP;
		message("vision", str+"\n", me);
	}
	//"��ɫ�ȼ�:uplv -l"ZJSEP"���ܵȼ�:uplv -s"ZJSEP"��ɫ�츳:uplv -t"ZJSEP"
	else if(arg=="-l")
	{
		shu=1;
		
		write(INPUTTXT("�������", ""+shu+="$txt#") + "\n");
		
		return notify_fail("����̫���ӣ���"+shu+"ɨ����\n"); 
	}
	else if(arg=="-t")
		F_LEVEL->up_tianfu(me);
	else if(arg=="-s")
		F_LEVEL->up_skills(me);
		else if (sscanf(arg, "%s %s", str, arg) == 2&&str=="-t")
	F_LEVEL->up_tianfu(me,arg);
	return 1;
}
