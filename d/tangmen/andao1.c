//andao1.c		�Ĵ����š��ص�

inherit ROOM;

void create()
{
	set("short","�ص�");
	set("long",
"����һ���ص���һ������������ͻȻ������һ�ţ���ʲô��������\n"
"�������������ܾ���������˫�۾��ڶ����㿴�����������ֺ�����Ϣ����\n"
"�����һ���붼��������������������һ˿����������\n"
);
	set("exits",([
		"south" : __DIR__"andao2",
		"north" : __DIR__"didao4",
	]));
	setup();
	replace_program(ROOM);
}
