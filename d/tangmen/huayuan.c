//huayuan.c		�Ĵ����š���԰

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long",
"����ڵĵص��г���,�㷢���Լ�����������һ�������µ�С��԰��,\n"
"��÷����,���ɴ��,���õ��ľ߽���,����ȥ��һ����ʯС�ݡ�\n"
);
	set("exits", ([
			"east" : __DIR__"andao2",
			"south" : __DIR__"shiwu",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
