
//#include <bangpai.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", "�������ֵ��Ƕ����书�ĵط�������ټ��");
	set("exits", ([
		"north" : __DIR__"guangchang",
	]));
set("practice_room", 1);
	set("no_fight","1");
		set("bangpai_room","1");
		set("bangpai/liangong",1);
	setup();
}

