

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long","���ַ������Һθɣ������ڴ�̸���۵ء�");
	set("close_room", 1);
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);
	set("exits", ([
		
		"up"   : __DIR__"tingyvge2",
		
	]));

	set("valid_startroom", 1);
	set("action_list", ([
		//HIY"���������"NOR:"update /d/city/tingyvge",
	]));
	set("objects", ([
	
		//"/clone/board/anonymous_b" : 1,
		
	  
	]));
	set("no_sleep_room",1);
	setup();
}
int valid_leave(object me, string dir)
{
	 int ge;
	  ge=1* 24 * 3600;
	   if ((int)me->query("lenque") && dir == "up")
		return notify_fail(HIY"��Ҫ��ʮ����Сʱ���ܽ���\n"NOR);
	if (!me->query("tingyvge") && dir == "up")
		return notify_fail(HIY"��û���ʸ���룡\n"NOR);
	else if(me->query("tingyvge") && dir == "up")
		me->add("lenque",ge);
	  
	return ::valid_leave(me, dir);
}