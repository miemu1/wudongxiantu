//inventory.c

#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me,string arg)
{
	int a=0;
object ob;
string liaotian;
       if(sscanf(arg, "%s",liaotian)!=1)
	   {
	  	write(INPUTTXT("请输入发送内容：""","liaota $txt# ")"\n"); 
		return 1;
	   } 
CHANNEL_D->do_channel(me, "chat", HIR"『"YEL"答案"HIR"』"HIY"是"HIG"〖"HIC+liaotian+HIG"〗"NOR"");
}
int help (object me)
{
	tell_object(me,HIY"你对说道：“”。"NOR"\n");  
	return 1;
}