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
	  	write(INPUTTXT("�����뷢�����ݣ�""","liaota $txt# ")"\n"); 
		return 1;
	   } 
CHANNEL_D->do_channel(me, "chat", HIR"��"YEL"��"HIR"��"HIY"��"HIG"��"HIC+liaotian+HIG"��"NOR"");
}
int help (object me)
{
	tell_object(me,HIY"���˵����������"NOR"\n");  
	return 1;
}