// minju2.c ���
// By Lgg,1998.10

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��֪�Ǻ�ʱ�������书���ϵ�һ�����ӣ���Դ���壬�������ϵ��˶��տڲ�̸�����Ŵ�˵����������һ���ˣ���Ϊ
�����������ԣ�����Ҫ������ͷѪ���ѵ�������������
LONG
	);
	set("exits", ([
		"south" : __DIR__"xijie",
	]));

	set("objects", ([
		__DIR__"npc/tiejiang" : 1,
	]));
	set("no_clean_up", 0);
	setup();
}
