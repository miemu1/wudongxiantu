// time.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if(!arg)
	{
		write("����Ԫ���ָ���� yuanshen up");
	}
	else if(arg=="up")
		F_LEVELL->improve_levell(me);

	return 1;
}

