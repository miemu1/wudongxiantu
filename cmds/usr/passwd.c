#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	 if(arg=="shou")
   {
	   	write(INPUTTXT("������npc��ID", "where $txt#") + "\n");
		return  0;
   }
	return 1;
}