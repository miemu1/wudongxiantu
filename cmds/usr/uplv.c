// time.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str;
	if(!arg)
	{
		str = ZJOBLONG"你可以在角色信息版块处理以下问题：\n";
		str += ZJOBACTS2+ZJMENUF(3,3,10,30);
		str += "查看等级:uplv -h"ZJSEP"奇经八脉:beat";
		if (environment(me)->query("owner_build")==getuid(me))
			str += ZJSEP"修改密码:changepasswd"ZJSEP"奇经八脉:beat"ZJSEP"建立家园:crroom"ZJSEP"扩建家园:crroom"ZJSEP"修改家园:edroom"ZJSEP"增加功能:edroom"ZJSEP"拆除场景:delroom"ZJSEP"家园开关:closeroom";
/*		if(wizardp(me))
		{
			str += ZJSEP+HIG"修改属性"NOR":wizlian"ZJSEP+HIG"复制物品"NOR":clone"ZJSEP+HIG"创建NPC"NOR":crnpc"ZJSEP+HIG"删除NPC"NOR":delnpc";
			str += ZJSEP+HIG"放置NPC"NOR":putnpc"ZJSEP+HIG"创建物品"NOR":critem";
			str += ZJSEP+HIG"创建技能"NOR":crskill"ZJSEP+HIG"编辑技能"NOR":edskill"ZJSEP+HIG"查看排行"NOR":tops";
		}*/
		message("vision", str+"\n", me);
	}
	//"角色等级:uplv -l"ZJSEP"技能等级:uplv -s"ZJSEP"角色天赋:uplv -t"ZJSEP"
	else if(arg=="-l")
		F_LEVEL->improve_level(me);
	else if(arg=="-h")
		F_LEVEL->chakan(me);
	else if(arg=="-t")
		F_LEVEL->up_tianfu(me);
	else if(arg=="-s")
		F_LEVEL->up_skills(me);
		else if (sscanf(arg, "%s %s", str, arg) == 2&&str=="-t")
	F_LEVEL->up_tianfu(me,arg);
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: uplv [-h]

这个指令让你打开等级面板。

HELP
    );
    return 1;
}
