// by ranger_����
// banghui.c
//#include <bangpai.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", "�����ǰ��������ĵط�����Χ����¯�������������ڡ�");
	set("exits", ([
		"east" : __DIR__"guangchang",
	]));
	set("bangpai_room","1");
	set("no_fight","1");
	set("bangpai/liandan",1);
	setup();
}

