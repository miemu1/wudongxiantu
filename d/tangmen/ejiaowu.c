//ejiaowu.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�����䳡");
	set("long",
"�������ŵĶ����䳡��һƬ����ƽ̹�Ŀյأ����ʺϱ����书����Ҫ\n"
"��ƽ���������壬���Ŷ��ھ��еı����ᣬ��һ���������������С�\n"
"�ϳ����࣬�ŷ��˼��������ܡ��ϳ������棬������������̨������ʱ��\n"
"�Ǿ��춯�صĺȲ�����ȫ���������\n"
);	
	set("no_steal", "1");
	set("no_fight", "1");
	set("exits", ([
		"west" : __DIR__"ekantai2",
	]));
	set("outdoors", "����");
	setup();
	replace_program(ROOM);
}
