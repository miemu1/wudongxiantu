#include <ansi.h>
inherit F_CLEAN_UP;


int main(object me, string arg)
{
	string str;
	int shu,ge;
	if(!arg)
	{
	str= ZJOBLONG+HIR "◎"HIY "红包系统：" HIR "◎"NOR+ZJBR;
	    str +=HIC"≡"HIY"─────────────────────"HIC"≡"NOR+ZJBR;
		str +="你拥有的灵石为："+me->query("yuanbao")+ZJBR;
		str +="你目前的修为为："+me->query("combat_exp")+ZJBR;
	
		 str +=HIC"≡"HIY"─────────────────────"HIC"≡"NOR+ZJBR;
	
	     str +="功能\n";
		str +=ZJOBACTS2+ZJMENUF(2,2,10,30);
	
		str +="黄金红包:hb -l"ZJSEP;
		str +="灵石红包:hongbao -t"ZJSEP;
		message("vision", str+"\n", me);
	}
	//"角色等级:uplv -l"ZJSEP"技能等级:uplv -s"ZJSEP"角色天赋:uplv -t"ZJSEP"
	else if(arg=="-l")
	{
		shu=1;
		
		write(INPUTTXT("输入次数", ""+shu+="$txt#") + "\n");
		
		return notify_fail("这里太纷杂，你"+shu+"扫荡。\n"); 
	}
	else if(arg=="-t")
		F_LEVEL->up_tianfu(me);
	else if(arg=="-s")
		F_LEVEL->up_skills(me);
		else if (sscanf(arg, "%s %s", str, arg) == 2&&str=="-t")
	F_LEVEL->up_tianfu(me,arg);
	return 1;
}
