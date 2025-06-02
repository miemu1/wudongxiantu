// Room: /guiyun/yixing.c
// Date: Nov.18 1998 by Winder

#include <ansi.h>

inherit ROOM;

int do_cut(string arg);

void create()
{
	set("short", "����");
	set("long", @LONG
������������������ն�����ɽ��ˮ֮����ӳ��һ�Ѷ���ɰ������
����һ����ɫ�����У���Զ������̫���ߡ��Ϸ����Ǻ��ݸ��ˡ�
LONG );
	set("max_room", 3);
	set("outdoors", "guiyun");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"tiandi",
		"south"     : __DIR__"nanxun",
		"northwest" : "/d/wudang/wdroad2",
	]));
		set("action_list", ([
		HIG"���"NOR:"kan grass",
	]));
	
	setup();
//	replace_program(BUILD_ROOM);
}

void init()
{
	add_action("do_kan", "kan");
}

int do_kan(string arg)
{
	object me,ob;
	me = this_player();
    
	if (! arg || arg == "")
	return 1;
	
	if (me->is_busy())
			return notify_fail("��Ķ�����û����ɣ������ƶ���\n");
			
	if (objectp(ob = present("quest grass",me))&&ob->query_amount()>=10)
		return notify_fail("��һ���Ա���ô����ϲ������´������ɣ�\n");
		
 	ob=new("/d/bangpai/obj/grass");
 	ob->move(me);
	 tell_object(me,HIW"������ĸ�ݣ������"+ob->query("name")+"��" NOR "\n");
	 me->start_busy(1+random(10));
	
	return 1;
}