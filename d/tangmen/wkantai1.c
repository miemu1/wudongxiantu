//wkantai1.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�����䳡��̨");
	set("long",
"�������ŵ������䳡��̨����Ȼ���ڿ����������˵�����ﲻ�����\n"
"��λ�ã����������ǺȲ�������ĵط�����Ϊ��������ģ�ͨ�������ŵ�\n"
"�����ӣ�����㣬��嶯��Ҳ���м��顣���棬�������䳡���м俴̨��\n"
);	
	set("no_steal", "1");
	set("no_fight", "1");
	set("exits", ([
		"south" : __DIR__"wkantai2",
	]));
	setup();
	replace_program(ROOM);
}
