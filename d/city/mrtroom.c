#include <ansi.h>
inherit ROOM;
#include <room.h>
void create()
{
	set("short",HIY"��������̨"NOR);
	set("long",HIR"���Ｏ�������ָ�����֣���С�ģ�����"NOR);	
	set("action_list",([
	HIY"�˳���ս"NOR:"exit",		
	]));	
	setup();
}

void init()
{
	add_action("do_exit", "exit");
	//add_action("jinji", "stats");
}

int do_exit(object me,string arg)
{
me = this_player();
write(HIG"���˳�����ս������\n"NOR);
me->move("/d/city/mingrt");
return 1;
}

/*
void jinji(int delay)
{
    add("ceng",1);
	call_out("jinji",3);
}

int dddd()
{
	object npc,romm;	
	npc = new("/cmds/npc");
	npc->set("name",query("ceng")+"�����");
	npc->move(this_object());
	return 1;
}



*/
